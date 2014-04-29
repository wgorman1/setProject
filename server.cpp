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
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>

using namespace std;

static int conn;
int polling;

struct pollfd myPoll[14];
int flag = 2;

constexpr int BUFFER_SIZE = 4096;
char buffer[BUFFER_SIZE];
 
void *task1(void *); 
int main(int argc, char* argv[])
{
  int portNumber, initSocket;
   struct sockaddr_in svrAdd, clntAdd;
    
  pthread_t threadA[12];
    
  if (argc < 2)
    {
      cerr << "Syntax : ./server <port>" << endl;
      return 0;
    }
    
  portNumber = atoi(argv[1]);
    
  if((portNumber < 2000) || (portNumber > 65535))
    {
      cerr << "Please enter a port number between 2000 - 65535" << endl;
      return 0;
    }
    
  //create socket
  initSocket = socket(AF_INET, SOCK_STREAM, 0);
    
  if(initSocket < 0)
    {
      cerr << "Cannot open socket" << endl;
      return 0;
    }
    
  bzero((char*) &svrAdd, sizeof(svrAdd));
    
  svrAdd.sin_family = AF_INET;
  svrAdd.sin_addr.s_addr = INADDR_ANY;
  svrAdd.sin_port = htons(portNumber);
    
  //bind socket
  if(bind(initSocket, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
      cerr << "Cannot bind" << endl;
      return 0;
    }
    
  listen(initSocket, 12);
    
  //  len = sizeof(clntAdd);
    
  int noThread = 2;
  myPoll[0].fd = initSocket;
  myPoll[0].events = POLLIN;
 
  myPoll[1].fd = STDIN_FILENO;
  myPoll[1].events = POLLIN;


  while (noThread < 12)
    {
      socklen_t len = sizeof(clntAdd);

      cout << "Server has started, waiting for players." << endl;

      //server will hang in this mode until players connect
      conn = accept(initSocket, (struct sockaddr *)&clntAdd, &len);

      if (conn < 0)
        {
	  cerr << "Connection unsuccessful" << endl;
	  return 0;
        }

      else
        {
	  cout << "Connection successful" << endl;
	  myPoll[noThread].fd = conn;
	  myPoll[noThread].events = POLLIN;
	  flag = flag + 1;
	}
        
      pthread_create(&threadA[noThread], NULL, task1, NULL); 
        
      noThread++;
    }
}


void *task1 (void *dummyPt)
{
  char test[300];
  read(conn, test, 300);
  string input (test);


  cout << input << " has joined the game." << endl;
  
  bzero(test, 301);

    for(;;){    
    //    bzero(test, 301);
      switch( poll(myPoll, flag, -1))
	{
	case -1:
	  break;

	case 0:
	  break;
	default:
	  /*	  if(myPoll[0].revents & POLLIN)
	    {
	      ssize_t bytes = read(initSocket, buffer, sizeof buffer);
	      if(bytes>0)
		{
		  printw("Server: ");
		  printw(buffer + '\0');
		  printw("\n");
		  refresh();
		  break;
		}
		}*/
	  for(int i=3; i < flag; i++){
	  if(myPoll[i].revents & POLLIN)
            {
              ssize_t bytes = read(conn, buffer, sizeof buffer);
              if(bytes>0)
                {
    
                  printw("Server: ");
                  printw(buffer + '\0');
                  printw("\n");
                  refresh();
                  break;
                }
            }
	  }

	}
     
      //  if(input == "6")
      //  break;
    }
  cout << "\nClosing thread and connection" << endl;
  close(conn);

}
