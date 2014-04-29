//Team Lavender
//Charles Eswine

#define PLAYER
using namespace std;
#include <curses.h>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

int playerNumber=0;


class Player
{
 public:
  string name;
  int score;
  Player();
  Player(string name);


};

Player::Player()
{
  name="Player"+playerNumber;
  score=0;
}

Player::Player(string namei)
{
  name=namei;
  score=0;

}
