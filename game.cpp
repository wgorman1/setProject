//Lavender Team
//Charles Eswine

#define _POSIX_C_SOURCE >= 200112L

#include <algorithm>
#include <vector>
#include <sstream>
#include <curses.h>
#include <time.h>
#include <iostream>
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
#include <time.h>
#include <errno.h>
#include <cctype>
#include <map>

#define SOCKET_ERROR        -1
#define BUFFER_SIZE         100
#define HOST_NAME_SIZE      255


Card c;
//map<char, Card> screenMap { {'a',c}, {'b',c}, {'c',c}, {'d',c}, {'e',c}, {'f',c}, {'g',c}, {'h',c}, {'i',c}, {'j',c}, {'k',c}, {'l',c} };

map<char, Card> screenMap;
vector<Player> playerVector;

//int idn=1;

int millisleep(unsigned msecs) {
  struct timespec t = {msecs / 1000, (msecs % 1000) * 1000000};
  return clock_nanosleep(CLOCK_REALTIME, 0, &t, nullptr);
}



void animate()
{

  struct itimerval value;

  int which= ITIMER_REAL;

  int time1= getitimer(which, &value);

  value.it_value.tv_sec=0;
  value.it_value.tv_usec=50;

  cout<<"1 is "<<time1<<endl;

  int time2= setitimer(which, &value, NULL);

  cout<<"2 is "<<time2<<endl;  


  string frame1l1="xxxxxxxxxxxxxx";
  string frame1l2="xxxxxxxxxxxxxxx";
  string frame1l3="xxxxxxxxxxxxxxx";
  string frame1l4="xxxxxxxxxxxxxxx";
  string frame1l5="xxxxxxxxxxxxxxx";

  string frame2l1=" xxxxxxxxxxxxx ";
  string frame2l2=" xxxxxxxxxxxxx ";
  string frame2l3=" xxxxxxxxxxxxx ";
  string frame2l4=" xxxxxxxxxxxxx ";
  string frame2l5=" xxxxxxxxxxxxx ";

  string frame3l1="  xxxxxxxxxxx  ";
  string frame3l2="  xxxxxxxxxxx  ";
  string frame3l3="  xxxxxxxxxxx  ";
  string frame3l4="  xxxxxxxxxxx  ";
  string frame3l5="  xxxxxxxxxxx  ";

  string frame4l1="   xxxxxxxxx   ";
  string frame4l2="   xxxxxxxxx   ";
  string frame4l3="   xxxxxxxxx   ";
  string frame4l4="   xxxxxxxxx   ";
  string frame4l5="   xxxxxxxxx   ";

  string frame5l1="    xxxxxxx    ";
  string frame5l2="    xxxxxxx    ";
  string frame5l3="    xxxxxxx    ";
  string frame5l4="    xxxxxxx    ";
  string frame5l5="    xxxxxxx    ";

  string frame6l1="     xxxxx     ";
  string frame6l2="     xxxxx     ";
  string frame6l3="     xxxxx     ";
  string frame6l4="     xxxxx     ";
  string frame6l5="     xxxxx     ";

  string frame7l1="      xxx      ";
  string frame7l2="      xxx      ";
  string frame7l3="      xxx      ";
  string frame7l4="      xxx      ";
  string frame7l5="      xxx      ";

  string frame8l1="       x       ";
  string frame8l2="       x       ";
  string frame8l3="       x       ";
  string frame8l4="       x       ";
  string frame8l5="       x       ";

}


bool isMatch(vector<char> selectedCards, gameScreen screen)
{
  int matches=0;
  
  for (int i=0; i<4; i++)
    {
      /*
      if ((screen.screenMap[selectedCards[0]].properties[i]==screen.screenMap[selectedCards[1]].properties[i] && screen.screenMap[selectedCards[1]].properties[i]==screen.screenMap[selectedCards[2]].properties[i]) || (screen.screenMap[selectedCards[0]].properties[i]!=screen.screenMap[selectedCards[1]].properties[i] && screen.screenMap[selectedCards[0]].properties[i]!=screen.screenMap[selectedCards[2]].properties[i] && screen.screenMap[selectedCards[1]].properties[i]!=screen.screenMap[selectedCards[2]].properties[i]))
	{
	  matches+=1;
	}
      */
            
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
		  
		  if ((test[x].properties[i]==test[y].properties[i] && test[y].properties[i]==test[z].properties[i]) || (test[x].properties[i]!=test[y].properties[i] && test[x].properties[i]!=test[z].properties[i] && test[y].properties[i]!=test[z].properties[i]))
		  
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

void printMap()
{
  //screenMap['b']=deck.nextCard();
  screenMap.erase('a');
  //cout<<screenMap['a']<<endl;
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

}


void giveScore(Player &player, int scorei)
{
  player.score= player.score+ scorei;

}


int  main(int argc, char* argv[])
{
  //map<char, Card> screenMap;
  //string d="...............";

  //int ch;  

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



  Deck deck(cardArray);
  
  //deck.shuffle();
 

  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);  
  init_pair(6, COLOR_BLACK, COLOR_BLACK);

  gameScreen screen;
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

	  
	case 'p':
	  endwin();
	  printMap();
	  //cout<<p1.score<<endl;
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
          q= getch();

	  //for (;;)
	    {
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
	    }
	  break;	  

	case 'x':
	  if(noSet())
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
	      
		  for (int k=0; k<3; k++)
		    {
		      //screen.clearCard(screen.getHighlights()[k]);
		      screen.replaceCard(screen.getHighlights()[k],deck.nextCard());
		      screen.unhighlightCard(screen.highlightVector[k]);
		      //screen.unhighlightCard(screen.getHighlights()[k]);
		      //screen.onOffHighlight(screen.highlightVector[k]);
		    }
		  screen.highlightVector.clear();
		  screen.updateDeckSize(deck);
		  //reward
		  giveScore(playerVector[0],5);
		  screen.updatePlayerScores();
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
    }
  while(c != '\r');

  endwin();  

}
