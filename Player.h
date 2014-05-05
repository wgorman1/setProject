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
  void giveScore(Player player, int scorei);
  //void giveScore(int scorei);
  bool operator<(const Player & rightOperand) const;
  bool operator>(const Player & rightOperand) const;
  bool operator==(const Player & rightOperand) const;
};

bool Player::operator<(const Player & rightOperand) const
{
  return score<rightOperand.score;

}

bool Player::operator>(const Player & rightOperand) const
{
  return score>rightOperand.score;

}


bool Player::operator==(const Player & rightOperand) const
{
  return score==rightOperand.score;


}


void Player::giveScore(Player player, int scorei)
//void Player::giveScore(int scorei)
{
  //score= score + scorei + ;
  if (scorei<0)
    {
      streak=0;
      score= score + scorei;
    }

  else if (scorei>0 && streak>0)
    {
      streak=streak+1;
      score= score + scorei + (2 * streak);
      //player.streak+=1;
    }

  else if (scorei>0 && streak==0)
    {
      //reset all other players streaks
      /*
      for (int i=0; i< playerVector.size(); i++)
	{
	  playerVector[i].streak=0;
	}
      player.streak+=1;
      */
      score= score + scorei;
      streak=1;
    }

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
