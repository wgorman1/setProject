//charles eswine


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
#include <deque>
using namespace std;



int  main(int argc, char* argv[])
{
  deque<int> deck;
  deck.push_back(0);
  deck.push_back(1);
  deck.push_back(2);
  deck.push_back(3);
  deck.push_back(4);
  deck.push_back(5);
  deck.push_back(6);
  deck.push_back(7);
  deck.push_back(8);
  deck.push_back(9);
  deck.push_back(10);
  deck.push_back(11);
  deck.push_back(12);
  deck.push_back(13);
  deck.push_back(14);
  deck.push_back(15);
  deck.push_back(16);
  deck.push_back(17);
  deck.push_back(18);
  deck.push_back(19);

  cout<<"before shuffle"<<endl;

  for (unsigned int i=0; i<deck.size(); i++)
    {
      cout<<deck[i]<<endl;

    }
  srand(time(0));
  random_shuffle(deck.begin(), deck.end());

  cout<<"after shuffle"<<endl;

  for (unsigned int i=0; i<deck.size(); i++)
    {
      cout<<deck[i]<<endl;

    }

  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();
  deck.pop_front();

  cout<< "after pop"<<endl;

  for (unsigned int i=0; i<deck.size(); i++)
    {
      cout<<deck[i]<<endl;

    }


  deck.push_back(0);
  deck.push_back(1);
  deck.push_back(2);
  deck.push_back(3);
  deck.push_back(4);
  deck.push_back(5);
  deck.push_back(6);
  deck.push_back(7);
  deck.push_back(8);
  deck.push_back(9);
 
  cout<<"after push"<<endl;

  for (unsigned int i=0; i<deck.size(); i++)
    {
      cout<<deck[i]<<endl;

    }

  cout<<"after 2nd shuffle"<<endl;

  srand(time(0));
  random_shuffle(deck.begin(), deck.end());

  for (unsigned int i=0; i<deck.size(); i++)
    {
      cout<<deck[i]<<endl;

    }


}
