#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <poll.h>
#include <curses.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <strings.h>
#include <string>
#include <pthread.h>
#include <iomanip>
#include <semaphore.h>
#include <unistd.h>
#include <netdb.h> 
#include <time.h>
#include <vector>

#include "Card.h"
#include "Player.h"
#include "Card.h"
#include "global.h"
#include "Deck.h"
#include "gameScreen.h"


#define TRUE             1
#define FALSE            0
int portNumber;
int    len, rc, on = 1;
int    listen_sd = -1, new_sd = -1;
int    desc_ready, end_server = FALSE, compress_array = FALSE;
int    close_conn;
struct sockaddr_in6   addr;
struct pollfd fds[13];
int    nfds = 1, current_size = 0, i, j;
pthread_t threadA[13];
//void *task1(void *);
int clientCount=0;
int polling;
ssize_t readFromClient = 1;
int timer;
vector<Player> playerVector;
map<char, Card> screenMap;
int flag;

char buffer2[80];
char nameBuffer[12];

string nameArray[13];
int vectorSize;
unsigned int deckSeed;

void *timerTask(void *);


main (int argc, char *argv[])
{

  int    timeout;
  portNumber = atoi(argv[1]);
  Deck deck(cardArray);
  if (argv[2] == NULL)
	  {
	    timer = 15;
	  }  
  else{
    timer = atoi(argv[2]);
  }


  std:: cout << "Timer = " << timer << "\n";

  pthread_create(&threadA[1], NULL, timerTask, NULL);
 
  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  deckSeed = rand() % 100 + 1; 
  
 std::cout<<"SEED: " << deckSeed << "\n";
  

  /* Create an AF_INET6 stream socket to receive incoming */
  listen_sd = socket(AF_INET6, SOCK_STREAM, 0);
  if (listen_sd < 0)
    {
      perror("socket() failed");
      exit(-1);
    }
  rc = setsockopt(listen_sd, SOL_SOCKET,  SO_REUSEADDR,
                  (char *)&on, sizeof(on));
  if (rc < 0)
    {
      perror("setsockopt() failed");
      close(listen_sd);
      exit(-1);
    }
  rc = ioctl(listen_sd, FIONBIO, (char *)&on);
  if (rc < 0)
    {
      perror("ioctl() failed");
      close(listen_sd);
      exit(-1);
    }
  memset(&addr, 0, sizeof(addr));
  addr.sin6_family      = AF_INET6;
  memcpy(&addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));
  addr.sin6_port        = htons(portNumber);
  rc = bind(listen_sd,
            (struct sockaddr *)&addr, sizeof(addr));
  if (rc < 0)
    {
      perror("bind() failed");
      close(listen_sd);
      exit(-1);
    }
  rc = listen(listen_sd, 32);
  if (rc < 0)
    {
      perror("listen() failed");
      close(listen_sd);
      exit(-1);
    }
  memset(fds, 0 , sizeof(fds));
  fds[0].fd = listen_sd;
  fds[0].events = POLLIN;
  timeout = (3 * 60 * 1000);
  do
    {
      rc = poll(fds, nfds, timeout);
      if (rc < 0)
	{
	  perror("  poll() failed");
	  break;
	}

      if (rc == 0)
	{
	  printf("  poll() timed out.  End program.\n");
	  break;
	}

      current_size = nfds;
      for (i = 0; i < current_size; i++)
	{
	  if(fds[i].revents == 0)
	    continue;
	  if(fds[i].revents != POLLIN)
	    {
	      printf("  Error! revents = %d\n", fds[i].revents);
	      end_server = TRUE;
	      break;

	    }
	  if (fds[i].fd == listen_sd)
	    {
        do
	  {
	   
	    new_sd = accept(listen_sd, NULL, NULL);
	    if (new_sd < 0)
	      {
		if (errno != EWOULDBLOCK)
		  {
		    perror("  accept() failed");
		    end_server = TRUE;
		  }
		break;
	      }

	    printf("  New incoming connection - %d\n", new_sd);
	   
	    fds[nfds].fd = new_sd;
	    fds[nfds].events = POLLIN;
	   
	     if(vectorSize < 12)
	      {
	    		std:: string success = "SUCCESS";
	      send(fds[nfds].fd, success.c_str(), success.size(), 0);

		
		clientCount = clientCount + 1;
		std::cout << "CLIENTCOUNT = " << clientCount << "\n";

		for(int m = 0; m < 80; m++)
		  {
		    buffer2[m] = '\0';
		  }

		for(int m =0; m < 12; m++)
		  {
		    nameBuffer[m] = '\0';
		  }
    
	    	   
		std:: string appendedName;
		
		recv(new_sd, buffer2, sizeof(buffer2), 0);
		
		for(int b = 0; b<12; b++)
		  {
		    nameBuffer[b] = buffer2[b];
		  }	    
		std:: string appendage = "1";
	    
		std:: string name = (nameBuffer + '\0');
       
		int result = 1;
		int counter = 1;

		while(result == 1)
		  {
		    result = 0;
		    for(int j=0; j<12;j++)
		      {
			if(name == nameArray[j])
			  {
			    name = name + to_string(counter);
			    counter = counter + 1;
			    result = 1;
			    //printf("name appended");
			  }
		      }

		
		  }
		send(fds[nfds].fd, name.c_str(), name.size(), 0);
	    
		nameArray[current_size] = name;
		for(int j=0; j <= current_size; j++)
		  {
		    std::cout << nameArray[j] << "\n";
		  }
		
		Player p1(name);
		playerVector.push_back(p1);
		vectorSize = playerVector.size();
		std::cout << "VECTOR SIZE = " << vectorSize << "\n";
		
		if(vectorSize == 3)
		  {
		    std:: cout << "MADE IT INTO VECTOR FLAG\n";
		    flag = 1;
		  }
		std::string seed = to_string(deckSeed);
		send(fds[nfds].fd, seed.c_str(), seed.size(), 0); 

	       }
	   else{
	      std:: string failMessage = "FAILURE";
	      send(fds[nfds].fd, failMessage.c_str(), failMessage.size(), 0); 
	      }
		nfds++;
    
	    //string message = "You have joined as ";
	    //string end2 = "\n";
	    //string message2 = message + name + end2;
	    //std::cout << message2.c_str() << "\n";
	    // write(1, message2.c_str(), message2.size());
	    // send(fds[i].fd, message2.c_str(), message2.size(), 0);
	    // }

	  } while (new_sd != -1);
	    }


	  else
	    {
	      std::cout << "MADE IT INTO ELSE\n";
	      //      printf("  Descriptor %d is readable\n", fds[i].fd);
	      close_conn = FALSE;

	      void *task1(void *);

	      pthread_create(&threadA[nfds+1], NULL, task1, NULL);


	    }
	} 

      if (compress_array)
	{
	  compress_array = FALSE;
	  for (i = 0; i < nfds; i++)
	    {
	      if (fds[i].fd == -1)
		{
		  for(j = i; j < nfds; j++)
		    {
		      fds[j].fd = fds[j+1].fd;
		    }
		  i--;
		  nfds--;
		}
	    }
	}

    } while (end_server == FALSE); /* End of serving running.    */
  for (i = 0; i < nfds; i++)
    {
      if(fds[i].fd >= 0)
	close(fds[i].fd);
    }
}


void *timerTask(void *p)
{
  
  std:: cout<< "TIMER STARTING\n";
  for(int i = timer; i >= 0; i--)
    {
      std:: string time = to_string(i);
      for(int j = 1; j <= clientCount; j++)
	{
	  
	  send(fds[j].fd, time.c_str(), time.size(), 0);
	}

      std:: cout << i << endl;
      sleep(1);
    }
 
  std::string nameString;
  std::string nameSize = to_string(vectorSize);
  std::cout << "IN TIMER VECTOR SIZE IS: " << vectorSize << "\n";
   if(vectorSize < 12)
    {
      for(int m=vectorSize+1; m<=12;m++)
	{
	  nameArray[m] = "Robot";
  	}
	}
   
     for(int k=1; k<=vectorSize; k++)
       {	
	for(int j = 1; j <= 12; j++)
	  {
	    if(j == k)
	      {

	      }
	    else{
	    nameString = nameArray[j];
	    std::cout << "NAME BEING SENT: "<< nameString << "\n";
	    
	send(fds[k].fd, nameString.c_str(), nameString.size(), 0);
	char b[10];
	recv(fds[k].fd, b, sizeof(b), 0); 
	    }
	    }
	       }
          return 0;
       }


void *task1(void *p)
{
  std::cout << "MADE IT INTO TASK1\n";  
  
  char buffer[80];

  rc = recv(fds[i].fd, buffer, sizeof(buffer), 0);

  std:: string header = (buffer + '\0');
  write(1, header.c_str(), header.size());

  printf("\n");

  if (rc < 0)
    {
      if (errno != EWOULDBLOCK)
        {
	  close_conn = TRUE;
        }
    }


  if (close_conn)
    {
      close(fds[i].fd);
      fds[i].fd = -1;
      compress_array = TRUE;
    }
  return 0;
}


bool isMatch(vector<char> selectedCards, gameScreen screen)
{
  int matches=0;

  for (int i=0; i<4; i++)
    {

      if ((screenMap[selectedCards[0]].properties[i]==screenMap[selectedCards[1]].properties[i] && screenMap[selectedCards[1]].properties[i]==screenMap[selectedCards[2]].properties[i]) || (screenMap[selectedCards[0]].properties[i]!=screenMap[selectedCards[1]].properties[i] && screenMap[selectedCards[0]].properties[i]!=screenMap[selectedCards[2]].properties[i] && screenMap[selectedCards[1]].properties[i]!=screenMap[selectedCards[2]].properties[i]))
        {
          matches+=1;
        }

    }

  if (matches>=4)
    {
      return true;
    }

  else
    {
      return false;
    }
}


bool noSet()
{
  int matches=0;

  Card test[12];
  test[0]=screenMap['a'];
  test[1]=screenMap['b'];
  test[2]=screenMap['c'];
  test[3]=screenMap['d'];
  test[4]=screenMap['e'];
  test[5]=screenMap['f'];
  test[6]=screenMap['g'];
  test[7]=screenMap['h'];
  test[8]=screenMap['i'];
  test[9]=screenMap['j'];
  test[10]=screenMap['k'];
  test[11]=screenMap['l'];
  for (int x=0; x<12; x++)
    {
      for (int y=x+1; y<12; y++)
        {
          for (int z=y+1; z<12; z++)
            {
              matches=0;
              for (int i=0; i<4; i++)
                {

                  if ((test[x].properties[i]==test[y].properties[i] && test[y].properties[i]==test[z].properties[i] && test[x].id!= 99) || (test[x].properties[i]!=test[y].properties[i] && test[x].properties[i]!=test[z].properties[i] && test[y].properties[i]!=test[z].properties[i] && test[x].id!= 99))

                    {
                      matches+=1;
                    }

                }
              if (matches==4)
                {
                  move(38,0);
                  //addstr(test[x].id.c_str());
                  move(39,0);
                  //addstr(test[y].id.c_str());
                  move(40,0);
                  //addstr(test[z].id.c_str());
                  return false;
                }
            }

        }
    }

  return true;
}

int fibonacci(int streak)
{
  int c, first =0, second=1, next;
  for ( c = 0 ; c <= streak ; c++ )
    {
      if ( c < 1 )
        next = c;
      else
        {
          next = first + second;
          first = second;
          second = next;
        }
      //cout << next << endl;
    }
  return next;


}
