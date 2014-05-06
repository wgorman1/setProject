#ifndef GAME_H
#define GAME_H

int millisleep(unsigned msecs);
void animate();
void finishGame();
void endGameCheck();
bool isMatch(vector<char> selectedCards, gameScreen screen);
bool noSet();
void printMap(Deck deck);
void giveScore(Player &player, int scorei);
int mainGame();
//int main(int argc, char* argv[]);


#endif
