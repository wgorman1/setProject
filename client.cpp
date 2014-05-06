#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <poll.h>
#include <curses.h>

#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iostream>
/*
#include "Card.h"
#include "Player.h"
#include "Card.h"
#include "global.h"
#include "Deck.h"
#include "gameScreen.h"
*/
using namespace std;


int main (int argc, char* argv[])
{

  

  int listenFd, portNo;
  struct pollfd myPoll[2];
  struct sockaddr_in svrAdd;
  struct hostent *server;
    
  //if(argc != 3)
  //{
  //  cerr<<"Syntax : ./play <port> [name]"<<endl;
  //  return 0;
  //}
    
  portNo = atoi(argv[1]);
    
  if((portNo > 65535) || (portNo < 2000))
    {
      cerr<<"Please enter port number between 2000 - 65535"<<endl;
      return 0;
    }       
    
  //create client skt
  listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
  if(listenFd < 0)
    {
      cerr << "Cannot open socket" << endl;
      return 0;
    }
    
  server = gethostbyname("localhost");
       
  bzero((char *) &svrAdd, sizeof(svrAdd));
  svrAdd.sin_family = AF_INET;
    
  bcopy((char *) server -> h_addr, (char *) &svrAdd.sin_addr.s_addr, server -> h_length);
    
  svrAdd.sin_port = htons(portNo);
    
  int checker = connect(listenFd,(struct sockaddr *) &svrAdd, sizeof(svrAdd));
    
  if (checker < 0)
    {
      cerr << "Cannot connect!" << endl;
      return 0;
    }
  char nameB[20];
  string name;  
  char newName[5];
  if(argv[2] == NULL){
    getlogin_r(nameB, sizeof(nameB));
   
    newName[0] = nameB[0];
    newName[1] = nameB[1];
    newName[2] = ' ';
    name = (newName + '\0');
    }
  else{
    name = argv[2];
  }

 
  send(listenFd, name.c_str(), name.length(), 0); 
  
  

  myPoll[0].fd = listenFd;
  myPoll[0].events = POLLIN;

  myPoll[1].fd = STDIN_FILENO;
  myPoll[1].events = POLLIN;
  

  std:: cout << "Type go and press enter when ready\n";

  for(;;)
    {
      poll(myPoll, 2, -1);
      
       
      char s[300];
      char v[300];
      
      //      cout << "Enter stuff: ";
      bzero(s, 301);
      bzero(v, 301);
    
      //           cin.getline(s, 300);
      
      
      if(myPoll[1].revents & POLLIN)
      	{
	  cin.getline(s, 300);
	  write(listenFd, s, strlen(s));
	}
      if(myPoll[0].revents & POLLIN)
	{
        
	  ssize_t br = recv(listenFd, v, sizeof(v),0);
	   if(br > 0)
	    {
	  std:: string message = (v + '\0');
	  printf("Message received: %s\n", message.c_str());
	    }
     	}
   }
  
}
