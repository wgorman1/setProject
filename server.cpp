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
struct pollfd fds[14];
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

string nameArray[30];

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
  
  /*
  for(int i = timer; i > 0; i--)
    {
      std:: cout << i << endl;
      Sleep(1000);
      }*/
  //  std:: cout << "Start!" << endl;

  /*************************************************************/
  /* Create an AF_INET6 stream socket to receive incoming      */
  /* connections on                                            */
  /*************************************************************/
  listen_sd = socket(AF_INET6, SOCK_STREAM, 0);
  if (listen_sd < 0)
    {
      perror("socket() failed");
      exit(-1);
    }

  /*************************************************************/
  /* Allow socket descriptor to be reuseable                   */
  /*************************************************************/
  rc = setsockopt(listen_sd, SOL_SOCKET,  SO_REUSEADDR,
                  (char *)&on, sizeof(on));
  if (rc < 0)
    {
      perror("setsockopt() failed");
      close(listen_sd);
      exit(-1);
    }

  /*************************************************************/
  /* Set socket to be nonblocking. All of the sockets for      */
  /* the incoming connections will also be nonblocking since   */
  /* they will inherit that state from the listening socket.   */
  /*************************************************************/
  rc = ioctl(listen_sd, FIONBIO, (char *)&on);
  if (rc < 0)
    {
      perror("ioctl() failed");
      close(listen_sd);
      exit(-1);
    }

  /*************************************************************/
  /* Bind the socket                                           */
  /*************************************************************/
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

  /*************************************************************/
  /* Set the listen back log                                   */
  /*************************************************************/
  rc = listen(listen_sd, 32);
  if (rc < 0)
    {
      perror("listen() failed");
      close(listen_sd);
      exit(-1);
    }

  /*************************************************************/
  /* Initialize the pollfd structure                           */
  /*************************************************************/
  memset(fds, 0 , sizeof(fds));

  /*************************************************************/
  /* Set up the initial listening socket                        */
  /*************************************************************/
  fds[0].fd = listen_sd;
  fds[0].events = POLLIN;
  /*************************************************************/
  /* Initialize the timeout to 3 minutes. If no                */
  /* activity after 3 minutes this program will end.           */
  /* timeout value is based on milliseconds.                   */
  /*************************************************************/
  timeout = (3 * 60 * 1000);

  /*************************************************************/
  /* Loop waiting for incoming connects or for incoming data   */
  /* on any of the connected sockets.                          */
  /*************************************************************/
  do
    {
      /***********************************************************/
      /* Call poll() and wait 3 minutes for it to complete.      */
      /***********************************************************/
      //      printf("Waiting on poll()...\n");
      rc = poll(fds, nfds, timeout);

      /***********************************************************/
      /* Check to see if the poll call failed.                   */
      /***********************************************************/
      if (rc < 0)
	{
	  perror("  poll() failed");
	  break;
	}

      /***********************************************************/
      /* Check to see if the 3 minute time out expired.          */
      /***********************************************************/
      if (rc == 0)
	{
	  printf("  poll() timed out.  End program.\n");
	  break;
	}


      /***********************************************************/
      /* One or more descriptors are readable.  Need to          */
      /* determine which ones they are.                          */
      /***********************************************************/
      current_size = nfds;
      for (i = 0; i < current_size; i++)
	{
	  /*********************************************************/
	  /* Loop through to find the descriptors that returned    */
	  /* POLLIN and determine whether it's the listening       */
	  /* or the active connection.                             */
	  /*********************************************************/
	  if(fds[i].revents == 0)
	    continue;

	  /*********************************************************/
	  /* If revents is not POLLIN, it's an unexpected result,  */
	  /* log and end the server.                               */
	  /*********************************************************/
	  if(fds[i].revents != POLLIN)
	    {
	      printf("  Error! revents = %d\n", fds[i].revents);
	      end_server = TRUE;
	      break;

	    }
	  if (fds[i].fd == listen_sd)
	    {
	      /*******************************************************/
	      /* Listening descriptor is readable.                   */
	      /*******************************************************/
	      //      printf("  Listening socket is readable\n");

	      /*******************************************************/
	      /* Accept all incoming connections that are            */
	      /* queued up on the listening socket before we         */
	      /* loop back and call poll again.                      */
	      /*******************************************************/
        do
	  {
	    /*****************************************************/
	    /* Accept each incoming connection. If               */
	    /* accept fails with EWOULDBLOCK, then we            */
	    /* have accepted all of them. Any other              */
	    /* failure on accept will cause us to end the        */
	    /* server.                                           */
	    /*****************************************************/
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

	    /*****************************************************/
	    /* Add the new incoming connection to the            */
	    /* pollfd structure                                  */
	    /*****************************************************/
	    printf("  New incoming connection - %d\n", new_sd);
	   
	    //	    if(current_size < 13)
	    // {
	    fds[nfds].fd = new_sd;
	    fds[nfds].events = POLLIN;
	    //	    printf("inside if statement");
	    //    printf("nfds = %d", nfds);
	    nfds++;
	    
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
	      { nameBuffer[b] = buffer2[b];
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
	    
	    nameArray[current_size] = name;
	    for(int j=0; j <= current_size; j++)
	      {
		std::cout << nameArray[j] << "\n";
	      }
	   
	    Player p1(name);
	    playerVector.push_back(p1);
	    int vectorSize = playerVector.size();
	    std::cout << "VECTOR SIZE = " << vectorSize << "\n";

	    if(vectorSize == 3)
	      {
		std:: cout << "MADE IT INTO VECTOR FLAG\n";
		flag = 1;
	      }
	   
	    // std:: string startMessage = "Start";
	    // int vectorSize = playerVector.size();
	    
	    // if(vectorSize == 3)
	    //  {
	    //	for(int j =0; j < current_size; j++)
	    //  {
	    // send(fds[j].fd, startMessage.c_str(), startMessage.size(), 0);
	    //	  }
		// }
	   
 //	    std::cout << "Vector has " << playerVector.size() << " elements.\n";

	    // std::cout << "myvector contains:";

	    /*	    for (std::vector<int>::iterator it = playerVector.begin() ; it != playerVector.end(); ++it)
	      std::cout << ' ' << *it;
	    std::cout << '\n';
	    */
	    //string message = "You have joined as ";
	    //string end2 = "\n";
	    //string message2 = message + name + end2;
	    //std::cout << message2.c_str() << "\n";
	    // write(1, message2.c_str(), message2.size());
	    // send(fds[i].fd, message2.c_str(), message2.size(), 0);
	    // }

	    //    else{
	    //  nfds++;
	    // }
	    /*****************************************************/
	    /* Loop back up and accept another incoming          */
	    /* connection                                        */
	    /*****************************************************/
	  } while (new_sd != -1);
	    }

	  /*********************************************************/
	  /* This is not the listening socket, therefore an        */
	  /* existing connection must be readable                  */
	  /*********************************************************/

	  else
	    {
	      std::cout << "MADE IT INTO ELSE\n";
	      //      printf("  Descriptor %d is readable\n", fds[i].fd);
	      close_conn = FALSE;
	      /*******************************************************/
	      /* Receive all incoming data on this socket            */
	      /* before we loop back and call poll again.            */
	      /*******************************************************/

	      //        do
	      //  {
	      /*****************************************************/
	      /* Receive data on this connection until the         */
	      /* recv fails with EWOULDBLOCK. If any other         */
	      /* failure occurs, we will close the                 */
	      /* connection.                                       */
	      /*****************************************************/

	      void *task1(void *);

	      pthread_create(&threadA[nfds+1], NULL, task1, NULL);

	      //  } while(TRUE);

	      /*******************************************************/
	      /* If the close_conn flag was turned on, we need       */
	      /* to clean up this active connection. This            */
	      /* clean up process includes removing the              */
	      /* descriptor.                                         */
	      /*******************************************************/
    


	    }  /* End of existing connection is readable             */
	} /* End of loop through pollable descriptors              */

      /***********************************************************/
      /* If the compress_array flag was turned on, we need       */
      /* to squeeze together the array and decrement the number  */
      /* of file descriptors. We do not need to move back the    */
      /* events and revents fields because the events will always*/
      /* be POLLIN in this case, and revents is output.          */
      /***********************************************************/
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

  /*************************************************************/
  /* Clean up all of the sockets that are open                 */
  /*************************************************************/
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
      for(int j = 1; j <= clientCount ; j++)
	{
	  
	  send(fds[j].fd, time.c_str(), time.size(), 0);
	}

      std:: cout << i << endl;
      sleep(1);
    }
   
  
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

  std:: string startGame = "Start";

  if(flag == 1)
    {
      std::cout << "2nd Check for clientCount = "<< clientCount << "\n";
        for(int j = 1; j <= clientCount ; j++)
       {
      std::cout << "SENDING MESSAGE\n";
      send(fds[j].fd, startGame.c_str(), startGame.size(), 0);
       }
    }
  //  printf("sent to clients: %s \n", startGame.c_str());



  /*
  char   buffer[80];



 
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
  
 std:: string startGame = "Start";
 
 if(flag == 1)
  {
    std::cout << "MADE IT INTO FLAG\n";
  for(int j = 0; j < nfds; j++)
   { 
     send(fds[j].fd, startGame.c_str(), startGame.size(), 0);      
   }  
      }

    printf("sent to clients: %s \n", startGame.c_str());
  */
  if (close_conn)
    {
      close(fds[i].fd);
      fds[i].fd = -1;
      compress_array = TRUE;
    }

}


