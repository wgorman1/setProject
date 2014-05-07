//Team Lavender
//Charles Eswine

#ifndef GAMESCREEN
#define GAMESCREEN

//#define _POSIX_C_SOURCE >= 200112L

using namespace std;
#include <curses.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unistd.h>
//#define _BSD_SOURCE
#include <list>
#include <iostream>
#include "global.h"
//#include "game.cpp"

int xSpace=3;
int ySpace=2;

//map<char,Card> screenMap;

class gameScreen
{
 public:
  void initializeScreen();
  void replaceCard(char letter, Card card);
  void placeCard(char letter, Card card);
  void highlightCard(char letter);
  void unhighlightCard(char letter);
  void onOffHighlight(char letter);
  void clearCard(char letter);
  //map<char, Card> screenMap;
  vector<char> getHighlights();
  gameScreen();
  vector <char> highlightVector;
  void updateDeckSize(Deck deck);
  void updatePlayerScores();
  void deal(Deck &deck);
  //void animate(char letter);
  void animate(vector<char> highlightVector);
  //void mapSize();
  //map<char, Card> getScreenMap();
};

int millisleep(unsigned msecs) {
  struct timespec t = {msecs / 1000, (msecs % 1000) * 1000000};
  return clock_nanosleep(CLOCK_REALTIME, 0, &t, nullptr);
}

void gameScreen::deal(Deck &deck)
{
  placeCard('a',deck.nextCard());
  placeCard('b',deck.nextCard());
  placeCard('c',deck.nextCard());
  placeCard('d',deck.nextCard());
  placeCard('e',deck.nextCard());
  placeCard('f',deck.nextCard());
  placeCard('g',deck.nextCard());
  placeCard('h',deck.nextCard());
  placeCard('i',deck.nextCard());
  placeCard('j',deck.nextCard());
  placeCard('k',deck.nextCard());
  placeCard('l',deck.nextCard());

}

void gameScreen::placeCard(char letter, Card card)
{
  string blankCardLine="               ";
  //attrset(COLOR_PAIR(card.color));
  int row= 1;
  int col= 5;

  screenMap[letter]=card;

  switch(letter)
    {

    case 'a':
      //screenMap['a']= card;
      clearCard('a');
      attrset(COLOR_PAIR(card.color));
      move(row,5);
      addch('a');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {     
                      mvaddch(row+k, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          //move(3,5);
          //addch('a');
          move(row,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,5);
          addstr(card.lines[1].c_str());
          move(row+2,5);
          addstr(card.lines[2].c_str());
          move(row+3,5);
          addstr(card.lines[3].c_str());
          move(row+4,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;
      
    case 'b':
      //screenMap['b']= card;
      clearCard('b');
      attrset(COLOR_PAIR(card.color));
      move(row,25);
      addch('b');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          //move(3,25);
          //addch('b');
          move(row,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,25);
          addstr(card.lines[1].c_str());
          move(row+2,25);
          addstr(card.lines[2].c_str());
          move(row+3,25);
          addstr(card.lines[3].c_str());
          move(row+4,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'c':
      //screenMap['c']= card;
      clearCard('c');
      attrset(COLOR_PAIR(card.color));
      move(row,45);
      addch('c');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,45);
          addstr(card.lines[1].c_str());
          move(row+2,45);
          addstr(card.lines[2].c_str());
          move(row+3,45);
          addstr(card.lines[3].c_str());
          move(row+4,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'd':
      //screenMap['d']= card;
      clearCard('d');
      attrset(COLOR_PAIR(card.color));
      move(row+7,5);
      addch('d');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,5);
          addstr(card.lines[1].c_str());
          move(row+9,5);
          addstr(card.lines[2].c_str());
          move(row+10,5);
          addstr(card.lines[3].c_str());
          move(row+11,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'e':
      //screenMap['e']= card;
      clearCard('e');
      attrset(COLOR_PAIR(card.color));
      move(row+7,25);
      addch('e');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,25);
          addstr(card.lines[1].c_str());
          move(row+9,25);
          addstr(card.lines[2].c_str());
          move(row+10,25);
          addstr(card.lines[3].c_str());
          move(row+11,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'f':
      //screenMap['f']= card;
      clearCard('f');
      attrset(COLOR_PAIR(card.color));
      move(row+7,45);
      addch('f');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,45);
          addstr(card.lines[1].c_str());
          move(row+9,45);
          addstr(card.lines[2].c_str());
          move(row+10,45);
          addstr(card.lines[3].c_str());
          move(row+11,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'g':
      //screenMap['g']= card;
      clearCard('g');
      attrset(COLOR_PAIR(card.color));
      move(row+14,5);
      addch('g');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+14,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,5);
          addstr(card.lines[1].c_str());
          move(row+16,5);
          addstr(card.lines[2].c_str());
          move(row+17,5);
          addstr(card.lines[3].c_str());
          move(row+18,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'h':
      //screenMap['h']= card;
      clearCard('h');
      attrset(COLOR_PAIR(card.color));
      move(row+14,25);
      addch('h');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i+20, ' '|A_REVERSE);
                    }

                }
            }
          break;
        }
      else
        {
          move(row+14,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,25);
          addstr(card.lines[1].c_str());
          move(row+16,25);
          addstr(card.lines[2].c_str());
          move(row+17,25);
          addstr(card.lines[3].c_str());
          move(row+18,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'i':
      //screenMap['i']= card;
      clearCard('i');
      attrset(COLOR_PAIR(card.color));
      move(row+14,45);
      addch('i');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i+40, ' '|A_REVERSE);

                    }
                }
            }
          break;
        }
      else
        {
          move(row+14,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,45);
          addstr(card.lines[1].c_str());
          move(row+16,45);
          addstr(card.lines[2].c_str());
          move(row+17,45);
          addstr(card.lines[3].c_str());
          move(row+18,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'j':
      //screenMap['j']= card;
      clearCard('j');
      attrset(COLOR_PAIR(card.color));
      move(row+21,5);
      addch('j');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,5);
          addstr(card.lines[1].c_str());
          move(row+23,5);
          addstr(card.lines[2].c_str());
          move(row+24,5);
          addstr(card.lines[3].c_str());
          move(row+25,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'k':
      //screenMap['k']= card;
      clearCard('k');
      attrset(COLOR_PAIR(card.color));
      move(row+21,25);
      addch('k');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,25);
          addstr(card.lines[1].c_str());
          move(row+23,25);
          addstr(card.lines[2].c_str());
          move(row+24,25);
          addstr(card.lines[3].c_str());
          move(row+25,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'l':
      //screenMap['l']= card;
      clearCard('l');
      attrset(COLOR_PAIR(card.color));
      move(row+21,45);
      addch('l');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,45);
          addstr(card.lines[1].c_str());
          move(row+23,45);
          addstr(card.lines[2].c_str());
          move(row+24,45);
          addstr(card.lines[3].c_str());
          move(row+25,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;
      
    default:
      break;
    }
  //}

}

/*
map<char, Card> gameScreen::getScreenMap()
{
  return screenMap;
}
*/

vector<char> gameScreen::getHighlights()
{
  return highlightVector;
}

void gameScreen::updateDeckSize(Deck deck)
{
  attrset(COLOR_PAIR(5));
  int size=deck.deckSize();
  string cardNo= to_string(size);
  move(1,77);
  addstr("   ");
  move(1,77);
  addstr(cardNo.c_str());
}

void gameScreen::updatePlayerScores()
{
  attrset(COLOR_PAIR(5));
  for (unsigned int i=0; i<playerVector.size(); i++)
    {
      move(5+i,75);
      addstr("     ");
      move(5+i,75);
      addstr(to_string(playerVector[i].score).c_str());

    }
  refresh();
}


void gameScreen::onOffHighlight(char letter)
{
  if (screenMap[letter].id != 99)
    {
      if (highlightVector.size()<3)
	{
	  vector<char>::iterator loc;
	  loc=find(highlightVector.begin(), highlightVector.end(), letter);  
	  

	  if (loc==highlightVector.end())
	    {
	      highlightVector.push_back(letter);
	      highlightCard(letter);
	      
	    }

	  else if (loc!=highlightVector.end())
	    {
	      highlightVector.erase(loc);
	      
	      unhighlightCard(letter);
	      
	    }
	}

      else if (highlightVector.size()==3)
	{
	  vector<char>::iterator loc;
	  loc=find(highlightVector.begin(), highlightVector.end(), letter);
	  if (loc!=highlightVector.end())
	    {
	      highlightVector.erase(loc);
	      unhighlightCard(letter);
	    }
        
	}

    }
}

void gameScreen::unhighlightCard(char letter)
{
  string highlightl1="xxxxxxxxxxxxxxxxx";
  string highlightl2="x               x";
  string highlightl3="x               x";
  string highlightl4="x               x";
  string highlightl5="x               x";
  string highlightl6="x               x";
  string highlightl7="xxxxxxxxxxxxxxxxx";

  string highlight [7]= {highlightl1, highlightl2, highlightl3, highlightl4, highlightl5, highlightl6, highlightl7};
  attrset(COLOR_PAIR(4));
  int row=0;
  int col=4;


  switch(letter)
    {
      
    case 'a':
      row+=0;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;
      

    case 'b':
      row+=0;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;
      
    case 'c':
      row+=0;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'd':
      row+=7;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'e':
      row+=7;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'f':
      row+=7;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'g':
      row+=14;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'h':
      row+=14;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'i':
      row+=14;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'j':
      row+=21;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'k':
      row+=21;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    case 'l':
      row+=21;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' ');

                }

            }
        }
      break;

    default:
      break;


    }

}

gameScreen::gameScreen()
{
  initscr();
  start_color();
  curs_set(0);
  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

void gameScreen::highlightCard(char letter)
{
  string highlightl1="xxxxxxxxxxxxxxxxx";
  string highlightl2="x               x";
  string highlightl3="x               x";
  string highlightl4="x               x";
  string highlightl5="x               x";
  string highlightl6="x               x";
  string highlightl7="xxxxxxxxxxxxxxxxx";

  string highlight [7]= {highlightl1, highlightl2, highlightl3, highlightl4, highlightl5, highlightl6, highlightl7};
  attrset(COLOR_PAIR(4));
  int row=0;
  int col=4;

  switch(letter)
    {

    case 'a':
      row+=0;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;


    case 'b':
      row+=0;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'c':
      row+=0;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'd':
      row+=7;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'e':
      row+=7;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'f':
      row+=7;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'g':
      row+=14;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'h':
      row+=14;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'i':
      row+=14;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'j':
      row+=21;
      col+=0;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'k':
      row+=21;
      col+=20;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    case 'l':
      row+=21;
      col+=40;
      for (int k=0; k < 7; k++)
        {
          for (unsigned int i=0; i<highlight[k].length(); i++)
            {
              if (highlight[k][i]=='x')
                {
                  mvaddch(row+k, col+i, ' '|A_REVERSE);

                }

            }
        }
      break;

    default:
      break;


    }

}



void gameScreen::replaceCard(char letter, Card card)
{
  string blankCardLine="               ";
  //attrset(COLOR_PAIR(card.color));
  int row= 1;
  int col= 5;

  screenMap[letter]=card;
  //animate(letter);
  //sleep(1);
  /*
  if (card.id==99)
    {
      //map<char, Card>::iterator it;
      //it= screenMap.find(letter);
      clearCard(letter);
      screenMap.erase(letter);
    }
  */
  //else {
    //screenMap[letter]=card;

  switch(letter)
    {

    case 'a':
      //screenMap['a']= card;
      //clearCard('a');
      attrset(COLOR_PAIR(card.color));
      move(row,5);
      addch('a');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {     
                      mvaddch(row+k, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          //move(3,5);
          //addch('a');
          move(row,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,5);
          addstr(card.lines[1].c_str());
          move(row+2,5);
          addstr(card.lines[2].c_str());
          move(row+3,5);
          addstr(card.lines[3].c_str());
          move(row+4,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;
      
    case 'b':
      //screenMap['b']= card;
      //clearCard('b');
      attrset(COLOR_PAIR(card.color));
      move(row,25);
      addch('b');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          //move(3,25);
          //addch('b');
          move(row,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,25);
          addstr(card.lines[1].c_str());
          move(row+2,25);
          addstr(card.lines[2].c_str());
          move(row+3,25);
          addstr(card.lines[3].c_str());
          move(row+4,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'c':
      //screenMap['c']= card;
      //clearCard('c');
      attrset(COLOR_PAIR(card.color));
      move(row,45);
      addch('c');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+1,45);
          addstr(card.lines[1].c_str());
          move(row+2,45);
          addstr(card.lines[2].c_str());
          move(row+3,45);
          addstr(card.lines[3].c_str());
          move(row+4,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'd':
      //screenMap['d']= card;
      //clearCard('d');
      attrset(COLOR_PAIR(card.color));
      move(row+7,5);
      addch('d');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,5);
          addstr(card.lines[1].c_str());
          move(row+9,5);
          addstr(card.lines[2].c_str());
          move(row+10,5);
          addstr(card.lines[3].c_str());
          move(row+11,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'e':
      //screenMap['e']= card;
      //clearCard('e');
      attrset(COLOR_PAIR(card.color));
      move(row+7,25);
      addch('e');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,25);
          addstr(card.lines[1].c_str());
          move(row+9,25);
          addstr(card.lines[2].c_str());
          move(row+10,25);
          addstr(card.lines[3].c_str());
          move(row+11,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'f':
      //screenMap['f']= card;
      //clearCard('f');
      attrset(COLOR_PAIR(card.color));
      move(row+7,45);
      addch('f');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+7, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+7,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+8,45);
          addstr(card.lines[1].c_str());
          move(row+9,45);
          addstr(card.lines[2].c_str());
          move(row+10,45);
          addstr(card.lines[3].c_str());
          move(row+11,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'g':
      //screenMap['g']= card;
      //clearCard('g');
      attrset(COLOR_PAIR(card.color));
      move(row+14,5);
      addch('g');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+14,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,5);
          addstr(card.lines[1].c_str());
          move(row+16,5);
          addstr(card.lines[2].c_str());
          move(row+17,5);
          addstr(card.lines[3].c_str());
          move(row+18,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'h':
      //screenMap['h']= card;
      //clearCard('h');
      attrset(COLOR_PAIR(card.color));
      move(row+14,25);
      addch('h');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i+20, ' '|A_REVERSE);
                    }

                }
            }
          break;
        }
      else
        {
          move(row+14,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,25);
          addstr(card.lines[1].c_str());
          move(row+16,25);
          addstr(card.lines[2].c_str());
          move(row+17,25);
          addstr(card.lines[3].c_str());
          move(row+18,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'i':
      //screenMap['i']= card;
      //clearCard('i');
      attrset(COLOR_PAIR(card.color));
      move(row+14,45);
      addch('i');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+14, col+i+40, ' '|A_REVERSE);

                    }
                }
            }
          break;
        }
      else
        {
          move(row+14,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+15,45);
          addstr(card.lines[1].c_str());
          move(row+16,45);
          addstr(card.lines[2].c_str());
          move(row+17,45);
          addstr(card.lines[3].c_str());
          move(row+18,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'j':
      //screenMap['j']= card;
      //clearCard('j');
      attrset(COLOR_PAIR(card.color));
      move(row+21,5);
      addch('j');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,6);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,5);
          addstr(card.lines[1].c_str());
          move(row+23,5);
          addstr(card.lines[2].c_str());
          move(row+24,5);
          addstr(card.lines[3].c_str());
          move(row+25,5);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'k':
      //screenMap['k']= card;
      //clearCard('k');
      attrset(COLOR_PAIR(card.color));
      move(row+21,25);
      addch('k');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i+20, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,26);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,25);
          addstr(card.lines[1].c_str());
          move(row+23,25);
          addstr(card.lines[2].c_str());
          move(row+24,25);
          addstr(card.lines[3].c_str());
          move(row+25,25);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;

    case 'l':
      //screenMap['l']= card;
      //clearCard('l');
      attrset(COLOR_PAIR(card.color));
      move(row+21,45);
      addch('l');
      if (card.symbol==0)
        {
          for (int k=0; k < 5; k++)
            {
              for (unsigned int i=0; i<card.lines[k].length(); i++)
                {
                  if (card.lines[k][i]=='x')
                    {
                      mvaddch(row+k+21, col+i+40, ' '|A_REVERSE);

                    }

                }
            }
          break;
        }
      else
        {
          move(row+21,46);
          //string line1="a"+card.l1;
          addstr(card.lines[0].c_str());
          move(row+22,45);
          addstr(card.lines[1].c_str());
          move(row+23,45);
          addstr(card.lines[2].c_str());
          move(row+24,45);
          addstr(card.lines[3].c_str());
          move(row+25,45);
          addstr(card.lines[4].c_str());
          //refresh();
          break;
        }
      break;
      
    default:
      break;
    }
  //}

}

void gameScreen::clearCard(char letter)
{
  
  attrset(COLOR_PAIR(1));
  string blankCardLine="               ";
  switch(letter)
    {
    case 'a':
      {
      move(1,5);
      addstr(blankCardLine.c_str());
      move(2,5);
      addstr(blankCardLine.c_str());
      move(3,5);
      addstr(blankCardLine.c_str());
      move(4,5);
      addstr(blankCardLine.c_str());
      move(5,5);
      addstr(blankCardLine.c_str());
      break;
      }

    case 'b':
      {
	move(1,25);
	addstr(blankCardLine.c_str());
	move(2,25);
	addstr(blankCardLine.c_str());
	move(3,25);
	addstr(blankCardLine.c_str());
	move(4,25);
	addstr(blankCardLine.c_str());
	move(5,25);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'c':
      {
	move(1,45);
	addstr(blankCardLine.c_str());
	move(2,45);
	addstr(blankCardLine.c_str());
	move(3,45);
	addstr(blankCardLine.c_str());
	move(4,45);
	addstr(blankCardLine.c_str());
	move(5,45);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'd':
      {
	move(8,5);
	addstr(blankCardLine.c_str());
	move(9,5);
	addstr(blankCardLine.c_str());
	move(10,5);
	addstr(blankCardLine.c_str());
	move(11,5);
	addstr(blankCardLine.c_str());
	move(12,5);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'e':
      {
	move(8,25);
	addstr(blankCardLine.c_str());
	move(9,25);
	addstr(blankCardLine.c_str());
	move(10,25);
	addstr(blankCardLine.c_str());
	move(11,25);
	addstr(blankCardLine.c_str());
	move(12,25);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'f':
      {
	move(8,45);
	addstr(blankCardLine.c_str());
	move(9,45);
	addstr(blankCardLine.c_str());
	move(10,45);
	addstr(blankCardLine.c_str());
	move(11,45);
	addstr(blankCardLine.c_str());
	move(12,45);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'g':
      {
	move(15,5);
	addstr(blankCardLine.c_str());
	move(16,5);
	addstr(blankCardLine.c_str());
	move(17,5);
	addstr(blankCardLine.c_str());
	move(18,5);
	addstr(blankCardLine.c_str());
	move(19,5);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'h':
      {
	move(15,25);
	addstr(blankCardLine.c_str());
	move(16,25);
	addstr(blankCardLine.c_str());
	move(17,25);
	addstr(blankCardLine.c_str());
	move(18,25);
	addstr(blankCardLine.c_str());
	move(19,25);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'i':
      {
	move(15,45);
	addstr(blankCardLine.c_str());
	move(16,45);
	addstr(blankCardLine.c_str());
	move(17,45);
	addstr(blankCardLine.c_str());
	move(18,45);
	addstr(blankCardLine.c_str());
	move(19,45);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'j':
      {
	move(22,5);
	addstr(blankCardLine.c_str());
	move(23,5);
	addstr(blankCardLine.c_str());
	move(24,5);
	addstr(blankCardLine.c_str());
	move(25,5);
	addstr(blankCardLine.c_str());
	move(26,5);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'k':
      {
	move(22,25);
	addstr(blankCardLine.c_str());
	move(23,25);
	addstr(blankCardLine.c_str());
	move(24,25);
	addstr(blankCardLine.c_str());
	move(25,25);
	addstr(blankCardLine.c_str());
	move(26,25);
	addstr(blankCardLine.c_str());
	break;
      }

    case 'l':
      {
	move(22,45);
	addstr(blankCardLine.c_str());
	move(23,45);
	addstr(blankCardLine.c_str());
	move(24,45);
	addstr(blankCardLine.c_str());
	move(25,45);
	addstr(blankCardLine.c_str());
	move(26,45);
	addstr(blankCardLine.c_str());
	break;
      }
    }
  
}

void gameScreen::initializeScreen()
{
  attrset(COLOR_PAIR(1));
  string blankCardLine="               ";
  Card card;

  screenMap['a']=card;
  screenMap['b']=card;
  screenMap['c']=card;
  screenMap['d']=card;
  screenMap['e']=card;
  screenMap['f']=card;
  screenMap['g']=card;
  screenMap['h']=card;
  screenMap['i']=card;
  screenMap['j']=card;
  screenMap['k']=card;
  screenMap['l']=card;

    
  move(1,5);
  addstr(blankCardLine.c_str());
  move(1,25);
  addstr(blankCardLine.c_str());
  move(1,45);
  addstr(blankCardLine.c_str());
  move(2,5);
  addstr(blankCardLine.c_str());
  move(2,25);
  addstr(blankCardLine.c_str());
  move(2,45);
  addstr(blankCardLine.c_str());
  move(3,5);
  addstr(blankCardLine.c_str());
  move(3,25);
  addstr(blankCardLine.c_str());
  move(3,45);
  addstr(blankCardLine.c_str());
  move(4,5);
  addstr(blankCardLine.c_str());
  move(4,25);
  addstr(blankCardLine.c_str());
  move(4,45);
  addstr(blankCardLine.c_str());
  move(5,5);
  addstr(blankCardLine.c_str());
  move(5,25);
  addstr(blankCardLine.c_str());
  move(5,45);
  addstr(blankCardLine.c_str());

  move(8,5);
  addstr(blankCardLine.c_str());
  move(8,25);
  addstr(blankCardLine.c_str());
  move(8,45);
  addstr(blankCardLine.c_str());
  move(9,5);
  addstr(blankCardLine.c_str());
  move(9,25);
  addstr(blankCardLine.c_str());
  move(9,45);
  addstr(blankCardLine.c_str());
  move(10,5);
  addstr(blankCardLine.c_str());
  move(10,25);
  addstr(blankCardLine.c_str());
  move(10,45);
  addstr(blankCardLine.c_str());
  move(11,5);
  addstr(blankCardLine.c_str());
  move(11,25);
  addstr(blankCardLine.c_str());
  move(11,45);
  addstr(blankCardLine.c_str());
  move(12,5);
  addstr(blankCardLine.c_str());
  move(12,25);
  addstr(blankCardLine.c_str());
  move(12,45);
  addstr(blankCardLine.c_str());

  move(15,5);
  addstr(blankCardLine.c_str());
  move(15,25);
  addstr(blankCardLine.c_str());
  move(15,45);
  addstr(blankCardLine.c_str());
  move(16,5);
  addstr(blankCardLine.c_str());
  move(16,25);
  addstr(blankCardLine.c_str());
  move(16,45);
  addstr(blankCardLine.c_str());
  move(17,5);
  addstr(blankCardLine.c_str());
  move(17,25);
  addstr(blankCardLine.c_str());
  move(17,45);
  addstr(blankCardLine.c_str());
  move(18,5);
  addstr(blankCardLine.c_str());
  move(18,25);
  addstr(blankCardLine.c_str());
  move(18,45);
  addstr(blankCardLine.c_str());
  move(19,5);
  addstr(blankCardLine.c_str());
  move(19,25);
  addstr(blankCardLine.c_str());
  move(19,45);
  addstr(blankCardLine.c_str());

  move(22,5);
  addstr(blankCardLine.c_str());
  move(22,25);
  addstr(blankCardLine.c_str());
  move(22,45);
  addstr(blankCardLine.c_str());
  move(23,5);
  addstr(blankCardLine.c_str());
  move(23,25);
  addstr(blankCardLine.c_str());
  move(23,45);
  addstr(blankCardLine.c_str());
  move(24,5);
  addstr(blankCardLine.c_str());
  move(24,25);
  addstr(blankCardLine.c_str());
  move(24,45);
  addstr(blankCardLine.c_str());
  move(25,5);
  addstr(blankCardLine.c_str());
  move(25,25);
  addstr(blankCardLine.c_str());
  move(25,45);
  addstr(blankCardLine.c_str());
  move(26,5);
  addstr(blankCardLine.c_str());
  move(26,25);
  addstr(blankCardLine.c_str());
  move(26,45);
  addstr(blankCardLine.c_str());
  
  attrset(COLOR_PAIR(5));

  move(1,61);
  addstr("Cards Remaining: ");

  move(3,63);
  addstr("    SCORES    ");
  move(4,63);
  addstr("--------------");

  for (unsigned int i=0; i<playerVector.size(); i++)
    {
      move(5+i,63);
      addstr(playerVector[i].name.c_str());
      move(5+i,75);
      addstr(to_string(playerVector[i].score).c_str());

    }

  refresh();
  //sleep(2);


}


string frame1l1="xxxxxxxxxxxxxxx";
string frame1l2="xxxxxxxxxxxxxxx";
string frame1l3="xxxxxxxxxxxxxxx";
string frame1l4="xxxxxxxxxxxxxxx";
string frame1l5="xxxxxxxxxxxxxxx";
  
string frame1 [5]= {frame1l1, frame1l2, frame1l3,frame1l4, frame1l5};

string frame2l1=" xxxxxxxxxxxxx ";
string frame2l2=" xxxxxxxxxxxxx ";
string frame2l3=" xxxxxxxxxxxxx ";
string frame2l4=" xxxxxxxxxxxxx ";
string frame2l5=" xxxxxxxxxxxxx ";
  
string frame2 [5]= {frame2l1, frame2l2, frame2l3,frame2l4, frame2l5};

string frame3l1="  xxxxxxxxxxx  ";
string frame3l2="  xxxxxxxxxxx  ";
string frame3l3="  xxxxxxxxxxx  ";
string frame3l4="  xxxxxxxxxxx  ";
string frame3l5="  xxxxxxxxxxx  ";
  
string frame3 [5]= {frame3l1, frame3l2, frame3l3,frame3l4, frame3l5};

string frame4l1="   xxxxxxxxx   ";
string frame4l2="   xxxxxxxxx   ";
string frame4l3="   xxxxxxxxx   ";
string frame4l4="   xxxxxxxxx   ";
string frame4l5="   xxxxxxxxx   ";

string frame4 [5]= {frame4l1, frame4l2, frame4l3,frame4l4, frame4l5};
  
string frame5l1="    xxxxxxx    ";
string frame5l2="    xxxxxxx    ";
string frame5l3="    xxxxxxx    ";
string frame5l4="    xxxxxxx    ";
string frame5l5="    xxxxxxx    ";

string frame5 [5]= {frame5l1, frame5l2, frame5l3,frame5l4, frame5l5};
  
string frame6l1="     xxxxx     ";
string frame6l2="     xxxxx     ";
string frame6l3="     xxxxx     ";
string frame6l4="     xxxxx     ";
string frame6l5="     xxxxx     ";

string frame6 [5]= {frame6l1, frame6l2, frame6l3,frame6l4, frame6l5};
  
string frame7l1="      xxx      ";
string frame7l2="      xxx      ";
string frame7l3="      xxx      ";
string frame7l4="      xxx      ";
string frame7l5="      xxx      ";

string frame7 [5]= {frame7l1, frame7l2, frame7l3,frame7l4, frame7l5};
  
string frame8l1="       x       ";
string frame8l2="       x       ";
string frame8l3="       x       ";
string frame8l4="       x       ";
string frame8l5="       x       ";
  
string frame8 [5]= {frame8l1, frame8l2, frame8l3,frame8l4, frame8l5};
  
string frames[15][5]={frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame7, frame6, frame5, frame4, frame3, frame2, frame1};




void gameScreen::animate(vector<char> highlightVector)
{
  attrset(COLOR_PAIR(5));
  int row= 1;
  int col= 5;
  //int frameNo=0;
  for (int m=0; m< 15; m++)
    {
      for (int p=0; p<(int)highlightVector.size(); p++)
	{
	  
	  switch(highlightVector[p])
	    {
	    case 'a':
	      {
		for (int k=0; k < 5; k++)
		  {
		    for (int i=0; i<(int)frames[m][k].length(); i++)
		      {
			if (frames[m][k][i]=='x')
			  {
			    mvaddch(row+k, col+i, ' '|A_REVERSE);

			  }

			else if (frames[m][k][i]!='x')
			  {
			    mvaddch(row+k, col+i, ' ');

			  }

		      }
		  }
		break;

	      }

	    case 'b':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k, col+i+20, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k, col+i+20, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'c':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k, col+i+40, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k, col+i+40, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'd':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+7, col+i, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+7, col+i, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'e':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+7, col+i+20, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+7, col+i+20, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'f':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+7, col+i+40, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+7, col+i+40, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'g':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+14, col+i, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+14, col+i, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'h':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+14, col+i+20, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+14, col+i+20, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'i':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+14, col+i+40, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+14, col+i+40, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'j':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+21, col+i, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+21, col+i, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'k':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+21, col+i+20, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+21, col+i+20, ' ');

                          }

                      }
                  }
                break;

              }

	    case 'l':
              {
                for (int k=0; k < 5; k++)
                  {
                    for (int i=0; i<(int)frames[m][k].length(); i++)
                      {
                        if (frames[m][k][i]=='x')
                          {
                            mvaddch(row+k+21, col+i+40, ' '|A_REVERSE);

                          }

                        else if (frames[m][k][i]!='x')
                          {
                            mvaddch(row+k+21, col+i+40, ' ');

                          }

                      }
                  }
                break;

              }


	    }
	}
      refresh();
      millisleep(50);
    }
}





#endif
