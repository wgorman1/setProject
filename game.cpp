//Lavender Team
//Charles Eswine

#define _POSIX_C_SOURCE >= 200112L
#define _BSD_SOURCE
#include <algorithm>
#include <vector>
#include <sstream>
#include <curses.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#include "Player.h"
#include "Card.h"
#include "global.h"
#include "Deck.h"
#include "gameScreen.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <cctype>
#include <map>
#include <pthread.h>

#define SOCKET_ERROR        -1
#define BUFFER_SIZE         100
#define HOST_NAME_SIZE      255


Card c;

map<char, Card> screenMap;
vector<Player> playerVector;
gameScreen screen;

void finishGame()
{
  endwin();
  sort(playerVector.begin(), playerVector.end());

  int rank=1;

  for (int i=(int)playerVector.size()-1; i>=0; i--)
    {
      if (i==(int)playerVector.size()-1 || playerVector[i].score == playerVector[i+1].score)
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

void findPlayer(string name, int score)
{
  for (int i=0; i<(int)playerVector.size(); i++)
    {
      if (playerVector[i].name==name)
        {
          //Player *retp= (*Player)malloc(sizeof *retp);
          //*retp= playerVector[i];
          //return retp;
          giveScore(playerVector[i],score);

        }


    }

  //Player p1;
  //return p1;
  //Player p1= find(playerVector.begin(), playerVector.end(), name);
  //return p1;
}



struct cardStruct
{
  vector<char> highlightVector;
  //char letter;
  //Card card;
  //gameScreen scren;
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


int  main(int argc, char* argv[])
{

  pthread_t thread1;  

  //map<char, Card> screenMap;
  //string d="...............";

  //int ch;  

  for (int m=0; m<12; m++)
    {
      Player p1(to_string(m));
      playerVector.push_back(p1);


    }

  /*
  Player p1("Chuck");
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
  */

  int seed=time(0);

  Deck deck(cardArray);
  
  deck.shuffle(seed);

  vector<char> allScreen;
  allScreen.push_back('a');
  allScreen.push_back('b');
  allScreen.push_back('c');
  allScreen.push_back('d');
  allScreen.push_back('e');
  allScreen.push_back('f');
  allScreen.push_back('g');
  allScreen.push_back('h');
  allScreen.push_back('i');
  allScreen.push_back('j'); 
  allScreen.push_back('k');
  allScreen.push_back('l');

  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);  
  init_pair(6, COLOR_BLACK, COLOR_BLACK);

  //gameScreen screen;
  //attrset(COLOR_PAIR(1));
  //bkgd(COLOR_PAIR(1));
  //populateScreen();

  screen.initializeScreen();

  refresh();
  sleep(1);

  screen.deal(deck);

  screen.updateDeckSize(deck);
  
  refresh();
  //sleep(1);

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

	  /*	  	  
	case 'p':
	  endwin();
	  //animate();
	  printMap(deck);
	  //cout<<p1.score<<endl;
	  break;
	  */

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


	      /*
	      switch(q)
		{
		case 'y':
		  endwin();
		  exit(0);
		  break;

		case 'n':
		  move(29,4);
		  addstr("                          ");
		  break;

		}
	      */
	    }
	    while (q!='y' || q!='n');
	    break;	  

	case 'x':
	  if(noSet())
	    {
	      if (deck.deckSize()<=12)
		{
		  //Player pp1=findPlayer("0");
		  //giveScore(findPlayer("0"),10);
		  findPlayer("0", 10);
		  finishGame();
		}
	      else
		{
		  cardStruct bs;
                  bs.highlightVector=allScreen;

		  pthread_create(&thread1, NULL, threadedReplace, (void*)&bs);
                  pthread_join(thread1,NULL);

		  deck.clearAndReshuffle(seed);
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
	      //Player pp1=findPlayer("0");
	      //giveScore(&pp1,-5);
	      findPlayer("0",-5);
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
		  //Player pp1=findPlayer("0");
		  findPlayer("0",5);
		  //giveScore(&findPlayer("0"),5);
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
		  findPlayer("0",-3);
		  //Player pp1=findPlayer("0");
		  //giveScore(&findPlayer("0"),-3);
		  screen.updatePlayerScores();
		}
	    }
	  break;

   
	default:
	  {

	    break;     
	  }      
	}
    }
  while(c != '\r');

  endwin();  

}
