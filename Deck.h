//Lavender Team
//Charles Eswine

#define DECK
#include <vector>
#include <algorithm>
#include "global.h"
#include <deque>
#include "global.h"
//#include "gameScreen.h"
using namespace std;


class Deck
{
 public:
  //vector<Card> deck;
  int cardNo;
  deque<Card> deck;

  Deck();
  Deck(Card cardArray[]);
  void shuffle();
  Card nextCard();
  int deckSize();
  void clearAndReshuffle();
  void putBack(Card card);
};

void Deck::putBack(Card card)
{
  deck.push_back(card);
  //deck.shrink_to_fit();
}



void Deck::clearAndReshuffle()
{
  //map<char, Card> imap= screen.screenMap;
  //deck.shrink_to_fit();
  
  
  deck.push_back(screenMap['a']);
  deck.push_back(screenMap['b']);
  deck.push_back(screenMap['c']);
  deck.push_back(screenMap['d']);
  deck.push_back(screenMap['e']);
  deck.push_back(screenMap['f']);
  deck.push_back(screenMap['g']);
  deck.push_back(screenMap['h']);
  deck.push_back(screenMap['i']);
  deck.push_back(screenMap['j']);
  deck.push_back(screenMap['k']);
  deck.push_back(screenMap['l']);
  
  /*
  putBack(screenMap['a']);
  putBack(screenMap['b']);
  putBack(screenMap['c']);
  putBack(screenMap['d']);
  putBack(screenMap['e']);
  putBack(screenMap['f']);
  putBack(screenMap['g']);
  putBack(screenMap['h']);
  putBack(screenMap['i']);
  putBack(screenMap['j']);
  putBack(screenMap['k']);
  putBack(screenMap['l']);
  */
  //deck.shrink_to_fit();
  shuffle();
  /*
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
  */

}


int Deck::deckSize()
{
  return deck.size();
}

Card Deck::nextCard()
{
  //cardNo+=1;
  Card c=deck[0];
  deck.pop_front();
  //deck.erase(deck.begin());
  //deck.shrink_to_fit();
  return c;  
}

Deck::Deck()
{
  cardNo=0;
  Card c;
  for (int i=0; i<=80; i++)
    {
      deck.push_back(c);
    }
}


Deck::Deck(Card cardArray[])
{
  cardNo=0;
  for (int i=0; i<=80; i++)
    {
      deck.push_back(cardArray[i]);
    }

}

void Deck::shuffle()
{
  srand(time(0));
  random_shuffle(deck.begin(), deck.end());
}

