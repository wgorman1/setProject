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

#define SOCKET_ERROR        -1
#define BUFFER_SIZE         100
#define HOST_NAME_SIZE      255


Card c;
map<char, Card> screenMap { {'a',c} {'b',c} {'c',c} {'d',c} {'e',c} {'f',c} {'g',c} {'h',c} {'i',c} {'j',c} {'k',c} {'l',c} };


int idn=1;

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

  for (int i=0; i<12; i++)
    {
      for (int j=i+1; j<12; j++)
	{
	  for (int k=j+1; k<12; k++)
	    {
	      
	      for (int i=0; i<4; i++)
		{
		  /*
		  if ((screen.screenMap[selectedCards[0]].properties[i]==screen.screenMap[selectedCards[1]].properties[i] && screen.screenMap[selectedCards[1]].properties[i]==screen.screenMap[selectedCards[2]].properties[i]) || (screen.screenMap[selectedCards[0]].properties[i]!=screen.screenMap[selectedCards[1]].properties[i] && screen.screenMap[selectedCards[0]].properties[i]!=screen.screenMap[selectedCards[2]].properties[i] && screen.screenMap[selectedCards[1]].properties[i]!=screen.screenMap[selectedCards[2]].properties[i]))
		  */
		    {
		      matches+=1;
		    }

		}

	    }
	}
    }
  return true;
}

void printMap()
{
  cout<<screenMap['a']<<endl;
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


}

int  main(int argc, char* argv[])
{
  //map<char, Card> screenMap;
  //string d="...............";

  //int ch;  

  Deck deck(cardArray);
  //deck.shuffle();
 

 /*
  initscr();
  start_color();
  */


  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  

  gameScreen screen;
  //attrset(COLOR_PAIR(1));
  //bkgd(COLOR_PAIR(1));
  //populateScreen();

  screen.initializeScreen();

  refresh();
  sleep(1);

  
  screen.replaceCard('a',deck.nextCard());
  screen.replaceCard('b',deck.nextCard());
  screen.replaceCard('c',deck.nextCard());
  screen.replaceCard('d',deck.nextCard());
  screen.replaceCard('e',deck.nextCard());
  screen.replaceCard('f',deck.nextCard());
  screen.replaceCard('g',deck.nextCard());
  screen.replaceCard('h',deck.nextCard());
  screen.replaceCard('i',deck.nextCard());
  screen.replaceCard('j',deck.nextCard());
  screen.replaceCard('k',deck.nextCard());
  screen.replaceCard('l',deck.nextCard());
  

  //screen.deal(deck);

  screen.updateDeckSize(deck);
  
  refresh();
  sleep(1);

  //screen.highlightCard('b');
  //refresh();
  //sleep(2);
  //screen.unhighlightCard('b');
  //refresh();
  //sleep(2);
  /*
  highlightCard('a');
  highlightCard('b');
  highlightCard('c');
  highlightCard('d');
  highlightCard('e');
  highlightCard('f');
  highlightCard('g');
  highlightCard('h');
  highlightCard('i');
  highlightCard('j');
  highlightCard('k');
  highlightCard('l');
  refresh();
  */


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
	  break;

	case 'x':
	  if(noSet())
	    {
	      deck.clearAndReshuffle();
	      //deck.shuffle();
	      //screen.deal(deck);
	      screen.replaceCard('a',deck.nextCard());
	      screen.replaceCard('b',deck.nextCard());
	      screen.replaceCard('c',deck.nextCard());
	      screen.replaceCard('d',deck.nextCard());
	      screen.replaceCard('e',deck.nextCard());
	      screen.replaceCard('f',deck.nextCard());
	      screen.replaceCard('g',deck.nextCard());
	      screen.replaceCard('h',deck.nextCard());
	      screen.replaceCard('i',deck.nextCard());
	      screen.replaceCard('j',deck.nextCard());
	      screen.replaceCard('k',deck.nextCard());
	      screen.replaceCard('l',deck.nextCard());
	      screen.updateDeckSize(deck);
	      //give points
	      break;
	    }

	  else if (!noSet())
	    {
	      //penalize
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
		}

	      else
		{
	      
		  for (int k=0; k<3; k++)
		    {
		      screen.unhighlightCard(screen.highlightVector[k]);

		    }
		  screen.highlightVector.clear();
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
