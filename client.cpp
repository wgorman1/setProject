//#define _POSIX_C_SOURCE >= 200112L


#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <signal.h>
#include <vector>
#include <poll.h>
#include <curses.h>
#include <pthread.h>
#include <errno.h>


#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iostream>

//#include "Card.h"
//#include "Player.h"
//#include "Card.h"
//#include "global.h"
//#include "Deck.h"
//#include "gameScreen.h"
//#include "game.cpp"

#include "Player.h"
#include "Card.h"
#include "global.h"
#include "Deck.h"
#include "gameScreen.h"


using namespace std;
//map<char, Card> screenMap;
//vector<Player> playerVector;
map<char, Card> screenMap;
vector<Player> playerVector;
gameScreen screen;
Card c;


void finishGame()
{
  endwin();
  sort(playerVector.begin(), playerVector.end());

  int rank=1;

  for (unsigned int i=playerVector.size()-1; i>0; i--)
    {
    if (i==playerVector.size()-1 || playerVector[i].score == playerVector[i+1].score)
        {
          cout<<rank<<". "<<playerVector[i].name;

          for (int k=playerVector[i].name.length(); k<14 ; k++)
            {

              cout<<" ";
            }

          cout<<playerVector[i].score<<endl;
        }

      else
        {
          rank+=1;
          cout<<rank<<". "<<playerVector[i].name;

          for (int k=playerVector[i].name.length(); k<14 ; k++)
            {

              cout<<" ";
            }

          cout<<playerVector[i].score<<endl;

        }

    }
  exit(0);
}

void endGameCheck()
{
  int count=0;

  map<char, Card>::iterator it;

  for (it=screenMap.begin(); it!=screenMap.end(); ++it)
    {
      if (it->second.id!=99)
        {
          count+=1;

        }

    }

  if (count==0)
    {
      //END GAME STUFF
      finishGame();
      //endwin();
      //cout<<"DONE"<<endl;
      //exit(0);
    }
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


void printMap( Deck deck)
{
  //screenMap['b']=deck.nextCard();
  //screenMap.erase('a');
  //cout<<screenMap['a']<<endl;
  /*
    cout<<screenMap['b']<<endl;
    cout<<screenMap['c']<<endl;
    cout<<screenMap['d']<<endl;
    cout<<screenMap['e']<<endl;
    cout<<screenMap['f']<<endl;
    cout<<screenMap['g']<<endl;
    cout<<screenMap['h']<<endl;
    cout<<screenMap['i']<<endl;
    cout<<screenMap['j']<<endl;
    cout<<screenMap['k']<<endl;
    cout<<screenMap['l']<<endl;
    cout<<screenMap.size()<<endl;
  */

  //cout<<sizeof(deck);
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


void giveScore(Player &player, int scorei)
{
  //player.score= player.score+ scorei;

  if (scorei<0)
    {
      player.streak=0;
      player.score+= scorei;
    }

  else if (scorei>0 && player.streak>0)
    {
      player.streak+=1;
      player.score+= scorei + (fibonacci(player.streak));
      //player.streak+=1;
    }
  else if (scorei>0 && player.streak==0)
    {
      //reset all other players streaks

      for (unsigned int i=0; i< playerVector.size(); i++)
        {
          playerVector[i].streak=0;
        }
      player.score+= scorei;
      player.streak=1;
    }
}
 

struct cardStruct
{
  vector<char> highlightVector;
};

void* threadedReplace(void *cardStructi)
{
  //struct cardStruct* crd = (struct cardStruct*) cardStructi;

  struct cardStruct *crd= (cardStruct*)cardStructi;

  //char let= crd->letter;
  //Card car= crd->card;
  //gameScreen scr= crd->scren;
  vector<char> vec= crd->highlightVector;
  //cout<<let<<endl;
  //free(crd);
  //endwin();
  //screen.replaceCard(screen.getHighlights()[let],car);
  //screen.unhighlightCard(screen.highlightVector[let]);
  screen.animate(vec);
  //screen.unhighlightCard(let);
  //screen.replaceCard(let,car);
  //screen.unhighlightCard(let);
  //refresh();
  return 0;

}


int main (int argc, char* argv[])
{
 
  pthread_t thread1;

  int listenFd, portNo;
  //  struct pollfd myPoll[2];
  struct sockaddr_in svrAdd;
  struct hostent *server;
    
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


  char status[7];
  recv(listenFd, status, sizeof(status),0);
  std:: string st = (status + '\0');
  if(st == "FAILURE")
    {
      endwin();
      std:: cout<< "CANNOT CONNECT - GAME FULL\n";
      exit (EXIT_FAILURE);
    }


  char nameB[20];
  string name;  
  char newName[3];
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
 
  char myName[12];
  for(int i = 0; i < 12; i++)
    {

      myName[i] = '\0';
    }


  recv(listenFd, myName, sizeof(myName),0);
 
  std:: string nameMessage = (myName);
  
 

  /*  
  myPoll[0].fd = listenFd;
  myPoll[0].events = POLLIN;

  myPoll[1].fd = STDIN_FILENO;
  myPoll[1].events = POLLIN;
  */
  
          initscr();
 	  cbreak();
          refresh();


       

	  	  
       
	  printw("You have joined the game as: ");
	  printw(myName+'\0');
	  printw("\n");
	  printw("Time until game starts:\n");

          int flag = 0;
	  while(flag == 0)
	    {
	      refresh();
	
	      char v[2];

	      recv(listenFd, v, sizeof(v),0);
	      
	  
	      std:: string message = (v + '\0');

		  if(message == "0  ")
		    {
		      break;
		    }
		  else
		    {
		  
		      printw(v);
      
		      printw("\r");
		    }


		  v[0] = ' ';
		  v[1] = ' ';
		  v[2] = ' ';
		  //		   clear();
		}

	  clear();
	  

	  Player p1(nameMessage);
	  playerVector.push_back(p1);

	  Player p2("Will");
	  playerVector.push_back(p2);

	  Player p3("Stephen");
	  playerVector.push_back(p3);

	  Player p4("Taylor");
	  playerVector.push_back(p4);

	  Player p5("Rick");
	  playerVector.push_back(p5);

	  Player p6("Steve");
	  playerVector.push_back(p6);

	  Deck deck(cardArray);

	  init_pair(1, COLOR_RED, COLOR_WHITE);
	  init_pair(2, COLOR_BLUE, COLOR_WHITE);
	  init_pair(3, COLOR_BLACK, COLOR_WHITE);
	  init_pair(4, COLOR_GREEN, COLOR_BLACK);
	  init_pair(5, COLOR_WHITE, COLOR_BLACK);
	  init_pair(6, COLOR_BLACK, COLOR_BLACK);

	  //	  gameScreen screen;

          screen.initializeScreen();
	 
          refresh();

          screen.deal(deck);
          screen.updateDeckSize(deck);
          refresh();

	  int c;

	  do   //Loop until 'Enter' is pressed
	    {
	      noecho();
	      c = getch();
	      switch(c)
		{
		case 0:
		  {
		    break;
		  }
		case '\b':
		  {

		    break;
		  }

		case 'a':
		  screen.onOffHighlight('a');
		  break;

		case 'b':
		  screen.onOffHighlight('b');
		  break;

		case 'c':
		  screen.onOffHighlight('c');
		  break;

		case 'd':
		  screen.onOffHighlight('d');
		  break;

		case 'e':
		  screen.onOffHighlight('e');
		  break;

		case 'f':
		  screen.onOffHighlight('f');
		  break;

		case 'g':
		  screen.onOffHighlight('g');
		  break;
		case 'h':
		  screen.onOffHighlight('h');
		  break;

		case 'i':
		  screen.onOffHighlight('i');
		  break;

		case 'j':
		  screen.onOffHighlight('j');
		  break;

		case 'k':
		  screen.onOffHighlight('k');
		  break;
		case 'l':
		  screen.onOffHighlight('l');
		  break;


		

		case '6':
		  //quit out of game
		  attrset(COLOR_PAIR(5));
		  //int q;
		  //q= getch();
		  move(29,4);
		  addstr("Do you want to quit? (y/n)");
		  refresh();
		  int q;
		  //q= getch();

		  do
		 {
		   q=getch();

		   if (q=='y')
		     {
		       endwin();
		       exit(0);
		       break;

		     }
		   else if (q=='n')
		     {
		       move(29,4);
		       addstr("                          ");
		       break;

		     }
		   
		 }
		  while (q!='y' || q!='n');
		  break;

		case 'x':
		  if(noSet())
		    {
		      if (deck.deckSize()<=12)
			{
			  giveScore(playerVector[0],10);
			  finishGame();
			}
		      else
			{
			  deck.clearAndReshuffle();
			  //deck.shuffle();
			  screen.deal(deck);
			  screen.updateDeckSize(deck);
			  //give points
			  giveScore(playerVector[0],10);
			  screen.updatePlayerScores();
			  break;
			}
		    }

		  else if (!noSet())
		    {
		      //penalize
		      giveScore(playerVector[0],-5);
		      screen.updatePlayerScores();
		      break;
		    }
		case ' ':
		  if(screen.getHighlights().size()==3)
		    {
		      if(isMatch(screen.getHighlights(),screen))
			{


			  //char a=screen.getHighlights()[0];
			  //Card a1=deck.nextCard();
			  cardStruct as;
			  //as.letter=a;
			  //as.card=a1;
			  //as.scren=screen;
			  as.highlightVector=screen.getHighlights();

			  for (int k=0; k<3; k++)
			    {
			      //screen.replaceCard(screen.getHighlights()[k],deck.nextCard());
			      screen.unhighlightCard(screen.highlightVector[k]);
			    }


		  pthread_create(&thread1, NULL, threadedReplace, (void*)&as);
			  pthread_join(thread1,NULL);

			  for (int k=0; k<3; k++)
			    {
			      screen.replaceCard(screen.getHighlights()[k],deck.nextCard());
			      //screen.unhighlightCard(screen.highlightVector[k]);
			    }
			  screen.highlightVector.clear();
			  screen.updateDeckSize(deck);
			  //reward
			  //playerVector[0].giveScore(5);
			  giveScore(playerVector[0],5);
			  screen.updatePlayerScores();
			  endGameCheck();
			}

		      else
			{

			  for (int k=0; k<3; k++)
			    {
			      screen.unhighlightCard(screen.highlightVector[k]);

			    }
			  screen.highlightVector.clear();
			  //penalize
			  giveScore(playerVector[0],-3);
			  screen.updatePlayerScores();
			}
		    }
		  break;



		default:
		  {

		    break;
		  }
		}
	    }while(c != '\r');

	  endwin();
	  return 0;

  
        }
