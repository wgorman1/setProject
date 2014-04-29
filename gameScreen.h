//Team Lavender
//Charles Eswine

#ifndef GAMESCREEN
#define GAMESCREEN
using namespace std;
#include <curses.h>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include "global.h"
//#include "game.cpp"

int xSpace=3;
int ySpace=2;

class gameScreen
{
 public:
  void initializeScreen();
  void replaceCard(char letter, Card card);
  void highlightCard(char letter);
  void unhighlightCard(char letter);
  void onOffHighlight(char letter);
  void clearCard(char letter);
  map<char, Card> screenMap;
  vector<char> getHighlights();
  gameScreen();
  vector <char> highlightVector;
  void updateDeckSize(Deck deck);
  void deal(Deck deck);
  //map<char, Card> getScreenMap();
};

void gameScreen::deal(Deck deck)
{
  replaceCard('a',deck.nextCard());
  replaceCard('b',deck.nextCard());
  replaceCard('c',deck.nextCard());
  replaceCard('d',deck.nextCard());
  replaceCard('e',deck.nextCard());
  replaceCard('f',deck.nextCard());
  replaceCard('g',deck.nextCard());
  replaceCard('h',deck.nextCard());
  replaceCard('i',deck.nextCard());
  replaceCard('j',deck.nextCard());
  replaceCard('k',deck.nextCard());
  replaceCard('l',deck.nextCard());

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
  addstr(cardNo.c_str());
}


void gameScreen::onOffHighlight(char letter)
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

  refresh();
  //sleep(2);


}

#endif
