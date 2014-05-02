//Team Lavender
//Charles Eswine

#define PLAYER
using namespace std;
#include <curses.h>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
//#include "global.h"

int playerNumber=0;


class Player
{
 public:
  string name;
  int score, streak;
  Player(string name);
  Player();
  //Player(string name);
  void giveScore(Player player, int score);

};

void Player::giveScore(Player player, int score)
{
  score= score + score;

}

Player::Player()
{
  name="Player"+playerNumber;
  playerNumber+=1;
  score=0;
  streak=0;
 
}

Player::Player(string namei)
{
  name=namei;
  score=0;
  streak=0;
}
