//Lavender Team
//Charles Eswine


#ifndef CARD
#define CARD
//#include "global.h"
using namespace std;

//extern Card cardArray[80];

int idn=1;

class Card
{
 public:
  int id,shape,color,number,symbol;
  int properties[4];
  //string l1,l2,l3,l4,l5;
  string lines[5];
  Card(int idi, string linesi[], int shapei, int colori, int numberi, int symboli);
  Card();
  string getLine(Card card, int line);
  //int  getProperties(Card card);
  friend ostream & operator<<(ostream & out, Card & card);
  //bool operator<(const Card & rightOperand) const;
};


inline ostream & operator<< (ostream & out, Card & card)
{
  out<<card.id;
  return out;
}



/*
int Card::getProperties(Card card)
{
  return card.properties;
}
*/

string Card::getLine(Card card, int line)
{
  return card.lines[line];

}

Card::Card()
{
  lines[0]="xxxxxxxxxxxxxxx";
  lines[1]="xxxxxxxxxxxxxxx";
  lines[2]="xxxxxxxxxxxxxxx";
  lines[3]="xxxxxxxxxxxxxxx";
  lines[4]="xxxxxxxxxxxxxxx";

  //l1="               ";
  //l2="               ";
  //l3="               ";
  //l4="               ";
  //l5="               ";

  id=99;
  shape=0;
  properties[0]=0;
  color=6;
  properties[1]=6;
  number=0;
  properties[2]=0;
  symbol=0;
  properties[3]=0;
}

Card::Card(int idi, string linesi[], int shapei, int colori, int numberi, int symboli)
{

  for (int i=0; i<5; i++)
    {
      lines[i]=linesi[i];
    }

  id=idi;
  //idn=idn+1;
  shape=shapei;
  properties[0]=shape;
  color=colori;
  properties[1]=color;
  number=numberi;
  properties[2]=number;
  symbol=symboli;
  properties[3]=symbol;
}


//void createCards()

  string cardPlusBlock1l1="              ";
  string cardPlusBlock1l2="       x       ";
  string cardPlusBlock1l3="      xxx      ";
  string cardPlusBlock1l4="       x       ";
  string cardPlusBlock1l5="               ";

  string cardPlusBlock1 [5]= {cardPlusBlock1l1,cardPlusBlock1l2,cardPlusBlock1l3,cardPlusBlock1l4,cardPlusBlock1l5};

  string cardPlusBlock2l1="              ";
  string cardPlusBlock2l2="     x   x     ";
  string cardPlusBlock2l3="    xxx xxx    ";
  string cardPlusBlock2l4="     x   x     ";
  string cardPlusBlock2l5="               ";

  string cardPlusBlock2 [5]= {cardPlusBlock2l1,cardPlusBlock2l2,cardPlusBlock2l3,cardPlusBlock2l4,cardPlusBlock2l5};

  string cardPlusBlock3l1="              ";
  string cardPlusBlock3l2="   x   x   x   ";
  string cardPlusBlock3l3="  xxx xxx xxx  ";
  string cardPlusBlock3l4="   x   x   x   ";
  string cardPlusBlock3l5="               ";

  string cardPlusBlock3 [5]= {cardPlusBlock3l1,cardPlusBlock3l2,cardPlusBlock3l3,cardPlusBlock3l4,cardPlusBlock3l5};


  string cardPluso1l1="              ";
  string cardPluso1l2="       o       ";
  string cardPluso1l3="      ooo      ";
  string cardPluso1l4="       o       ";
  string cardPluso1l5="               ";

  string cardPluso1 [5]= {cardPluso1l1, cardPluso1l2, cardPluso1l3, cardPluso1l4, cardPluso1l5};

  string cardPluso2l1="              ";
  string cardPluso2l2="     o   o     ";
  string cardPluso2l3="    ooo ooo    ";
  string cardPluso2l4="     o   o     ";
  string cardPluso2l5="               ";

  string cardPluso2 [5]= {cardPluso2l1, cardPluso2l2, cardPluso2l3, cardPluso2l4, cardPluso2l5};

  string cardPluso3l1="              ";
  string cardPluso3l2="   o   o   o   ";
  string cardPluso3l3="  ooo ooo ooo  ";
  string cardPluso3l4="   o   o   o   ";
  string cardPluso3l5="               ";

  string cardPluso3 [5]= {cardPluso3l1, cardPluso3l2, cardPluso3l3, cardPluso3l4, cardPluso3l5};

  string cardPlusAmp1l1="              ";
  string cardPlusAmp1l2="       @       ";
  string cardPlusAmp1l3="      @@@      ";
  string cardPlusAmp1l4="       @       ";
  string cardPlusAmp1l5="               ";

  string cardPlusAmp1 [5]= {cardPlusAmp1l1, cardPlusAmp1l2, cardPlusAmp1l3, cardPlusAmp1l4, cardPlusAmp1l5};

  string cardPlusAmp2l1="              ";
  string cardPlusAmp2l2="     @   @     ";
  string cardPlusAmp2l3="    @@@ @@@    ";
  string cardPlusAmp2l4="     @   @     ";
  string cardPlusAmp2l5="               ";

  string cardPlusAmp2 [5]= {cardPlusAmp2l1, cardPlusAmp2l2, cardPlusAmp2l3, cardPlusAmp2l4, cardPlusAmp2l5};

  string cardPlusAmp3l1="              ";
  string cardPlusAmp3l2="   @   @   @   ";
  string cardPlusAmp3l3="  @@@ @@@ @@@  ";
  string cardPlusAmp3l4="   @   @   @   ";
  string cardPlusAmp3l5="               ";

  string cardPlusAmp3 [5]= {cardPlusAmp3l1, cardPlusAmp3l2, cardPlusAmp3l3, cardPlusAmp3l4, cardPlusAmp3l5};

  string cardSquareAmp1l1="              ";
  string cardSquareAmp1l2="      @@@      ";
  string cardSquareAmp1l3="      @ @      ";
  string cardSquareAmp1l4="      @@@      ";
  string cardSquareAmp1l5="               ";

  string cardSquareAmp1 [5]= {cardSquareAmp1l1, cardSquareAmp1l2, cardSquareAmp1l3, cardSquareAmp1l4, cardSquareAmp1l5};

  string cardSquareAmp2l1="              ";
  string cardSquareAmp2l2="    @@@ @@@    ";
  string cardSquareAmp2l3="    @ @ @ @    ";
  string cardSquareAmp2l4="    @@@ @@@    ";
  string cardSquareAmp2l5="               ";

  string cardSquareAmp2 [5]= {cardSquareAmp2l1, cardSquareAmp2l2, cardSquareAmp2l3, cardSquareAmp2l4, cardSquareAmp2l5};

  string cardSquareAmp3l1="              ";
  string cardSquareAmp3l2="  @@@ @@@ @@@  ";
  string cardSquareAmp3l3="  @ @ @ @ @ @  ";
  string cardSquareAmp3l4="  @@@ @@@ @@@  ";
  string cardSquareAmp3l5="               ";

  string cardSquareAmp3 [5]= {cardSquareAmp3l1, cardSquareAmp3l2, cardSquareAmp3l3, cardSquareAmp3l4, cardSquareAmp3l5};

  string cardSquareo1l1="              ";
  string cardSquareo1l2="      ooo      ";
  string cardSquareo1l3="      o o      ";
  string cardSquareo1l4="      ooo      ";
  string cardSquareo1l5="               ";

  string cardSquareo1 [5]= {cardSquareo1l1, cardSquareo1l2, cardSquareo1l3, cardSquareo1l4, cardSquareo1l5};

  string cardSquareo2l1="              ";
  string cardSquareo2l2="    ooo ooo    ";
  string cardSquareo2l3="    o o o o    ";
  string cardSquareo2l4="    ooo ooo    ";
  string cardSquareo2l5="               ";

  string cardSquareo2 [5]= {cardSquareo2l1, cardSquareo2l2, cardSquareo2l3, cardSquareo2l4, cardSquareo2l5};

  string cardSquareo3l1="              ";
  string cardSquareo3l2="  ooo ooo ooo  ";
  string cardSquareo3l3="  o o o o o o  ";
  string cardSquareo3l4="  ooo ooo ooo  ";
  string cardSquareo3l5="               ";

  string cardSquareo3 [5]= {cardSquareo3l1, cardSquareo3l2, cardSquareo3l3, cardSquareo3l4, cardSquareo3l5};

  string cardSquareBlock1l1="              ";
  string cardSquareBlock1l2="      xxx      ";
  string cardSquareBlock1l3="      x x      ";
  string cardSquareBlock1l4="      xxx      ";
  string cardSquareBlock1l5="               ";

  string cardSquareBlock1 [5]= {cardSquareBlock1l1, cardSquareBlock1l2, cardSquareBlock1l3, cardSquareBlock1l4, cardSquareBlock1l5};

  string cardSquareBlock2l1="              ";
  string cardSquareBlock2l2="    xxx xxx    ";
  string cardSquareBlock2l3="    x x x x    ";
  string cardSquareBlock2l4="    xxx xxx    ";
  string cardSquareBlock2l5="               ";

  string cardSquareBlock2 [5]= {cardSquareBlock2l1, cardSquareBlock2l2, cardSquareBlock2l3, cardSquareBlock2l4, cardSquareBlock2l5};

  string cardSquareBlock3l1="              ";
  string cardSquareBlock3l2="  xxx xxx xxx  ";
  string cardSquareBlock3l3="  x x x x x x  ";
  string cardSquareBlock3l4="  xxx xxx xxx  ";
  string cardSquareBlock3l5="               ";

  string cardSquareBlock3 [5]= {cardSquareBlock3l1, cardSquareBlock3l2, cardSquareBlock3l3, cardSquareBlock3l4, cardSquareBlock3l5};

  string cardSlashBlock1l1="              ";
  string cardSlashBlock1l2="        x      ";
  string cardSlashBlock1l3="       x       ";
  string cardSlashBlock1l4="      x        ";
  string cardSlashBlock1l5="               ";

  string cardSlashBlock1 [5]= {cardSlashBlock1l1, cardSlashBlock1l2, cardSlashBlock1l3, cardSlashBlock1l4, cardSlashBlock1l5};

  string cardSlashBlock2l1="              ";
  string cardSlashBlock2l2="      x   x    ";
  string cardSlashBlock2l3="     x   x     ";
  string cardSlashBlock2l4="    x   x      ";
  string cardSlashBlock2l5="               ";

  string cardSlashBlock2 [5]= {cardSlashBlock2l1, cardSlashBlock2l2, cardSlashBlock2l3, cardSlashBlock2l4, cardSlashBlock2l5};

  string cardSlashBlock3l1="              ";
  string cardSlashBlock3l2="    x   x   x  ";
  string cardSlashBlock3l3="   x   x   x   ";
  string cardSlashBlock3l4="  x   x   x    ";
  string cardSlashBlock3l5="               ";

  string cardSlashBlock3 [5]= {cardSlashBlock3l1, cardSlashBlock3l2, cardSlashBlock3l3, cardSlashBlock3l4, cardSlashBlock3l5};

  string cardSlasho1l1="              ";
  string cardSlasho1l2="        o      ";
  string cardSlasho1l3="       o       ";
  string cardSlasho1l4="      o        ";
  string cardSlasho1l5="               ";

  string cardSlasho1 [5]= {cardSlasho1l1, cardSlasho1l2, cardSlasho1l3, cardSlasho1l4, cardSlasho1l5};

  string cardSlasho2l1="              ";
  string cardSlasho2l2="      o   o    ";
  string cardSlasho2l3="     o   o     ";
  string cardSlasho2l4="    o   o      ";
  string cardSlasho2l5="               ";

  string cardSlasho2 [5]= {cardSlasho2l1, cardSlasho2l2, cardSlasho2l3, cardSlasho2l4, cardSlasho2l5};

  string cardSlasho3l1="              ";
  string cardSlasho3l2="    o   o   o  ";
  string cardSlasho3l3="   o   o   o   ";
  string cardSlasho3l4="  o   o   o    ";
  string cardSlasho3l5="               ";

  string cardSlasho3 [5]= {cardSlasho3l1, cardSlasho3l2, cardSlasho3l3, cardSlasho3l4, cardSlasho3l5};

  string cardSlashAmp1l1="              ";
  string cardSlashAmp1l2="        @      ";
  string cardSlashAmp1l3="       @       ";
  string cardSlashAmp1l4="      @        ";
  string cardSlashAmp1l5="               ";

  string cardSlashAmp1 [5]= {cardSlashAmp1l1, cardSlashAmp1l2, cardSlashAmp1l3,cardSlashAmp1l4, cardSlashAmp1l5};

  string cardSlashAmp2l1="              ";
  string cardSlashAmp2l2="      @   @    ";
  string cardSlashAmp2l3="     @   @     ";
  string cardSlashAmp2l4="    @   @      ";
  string cardSlashAmp2l5="               ";

  string cardSlashAmp2 [5]= {cardSlashAmp2l1, cardSlashAmp2l2, cardSlashAmp2l3,cardSlashAmp2l4, cardSlashAmp2l5};

  string cardSlashAmp3l1="              ";
  string cardSlashAmp3l2="    @   @   @  ";
  string cardSlashAmp3l3="   @   @   @   ";
  string cardSlashAmp3l4="  @   @   @    ";
  string cardSlashAmp3l5="               ";

  string cardSlashAmp3 [5]= {cardSlashAmp3l1, cardSlashAmp3l2, cardSlashAmp3l3,cardSlashAmp3l4, cardSlashAmp3l5};

/*
string highlightl1="xxxxxxxxxxxxxxxxx";
string highlightl2="x               x";
string highlightl3="x               x";
string highlightl4="x               x";
string highlightl5="x               x";
string highlightl6="x               x";
string highlightl7="xxxxxxxxxxxxxxxxx";

string highlight [7]= {highlightl1, highlightl2, highlightl3, highlightl4, highlightl5, highlightl6, highlightl7};
*/
Card c1(1,cardPlusBlock1, 0, 1, 1, 0);
Card c2(2,cardPlusBlock2, 0, 1, 2, 0);
Card c3(3,cardPlusBlock3, 0, 1, 3, 0);
Card c4(4,cardPluso1, 0, 1, 1, 1);
Card c5(5,cardPluso2, 0, 1, 2, 1);
Card c6(6,cardPluso3, 0, 1, 3, 1);
Card c7(7,cardPlusAmp1, 0, 1, 1, 2);
Card c8(8,cardPlusAmp2, 0, 1, 2, 2);
Card c9(9,cardPlusAmp3, 0, 1, 3, 2);

Card c10(10,cardPlusBlock1, 0, 2, 1, 0);
Card c11(11,cardPlusBlock2, 0, 2, 2, 0);
Card c12(12,cardPlusBlock3, 0, 2, 3, 0);
Card c13(13,cardPluso1, 0, 2, 1, 1);
Card c14(14,cardPluso2, 0, 2, 2, 1);
Card c15(15,cardPluso3, 0, 2, 3, 1);
Card c16(16,cardPlusAmp1, 0, 2, 1, 2);
Card c17(17,cardPlusAmp2, 0, 2, 2, 2);
Card c18(18,cardPlusAmp3, 0, 2, 3, 2);

Card c19(19,cardPlusBlock1, 0, 3, 1, 0);
Card c20(20,cardPlusBlock2, 0, 3, 2, 0);
Card c21(21,cardPlusBlock3, 0, 3, 3, 0);
Card c22(22,cardPluso1, 0, 3, 1, 1);
Card c23(23,cardPluso2, 0, 3, 2, 1);
Card c24(24,cardPluso3, 0, 3, 3, 1);
Card c25(25,cardPlusAmp1, 0, 3, 1, 2);
Card c26(26,cardPlusAmp2, 0, 3, 2, 2);
Card c27(27,cardPlusAmp3, 0, 3, 3, 2);




Card c28(28,cardSquareBlock1, 1, 1, 1, 0);
Card c29(29,cardSquareBlock2, 1, 1, 2, 0);
Card c30(30,cardSquareBlock3, 1, 1, 3, 0);
Card c31(31,cardSquareo1, 1, 1, 1, 1);
Card c32(32,cardSquareo2, 1, 1, 2, 1);
Card c33(33,cardSquareo3, 1, 1, 3, 1);
Card c34(34,cardSquareAmp1, 1, 1, 1, 2);
Card c35(35,cardSquareAmp2, 1, 1, 2, 2);
Card c36(36,cardSquareAmp3, 1, 1, 3, 2);

Card c37(37,cardSquareBlock1, 1, 2, 1, 0);
Card c38(38,cardSquareBlock2, 1, 2, 2, 0);
Card c39(39,cardSquareBlock3, 1, 2, 3, 0);
Card c40(40,cardSquareo1, 1, 2, 1, 1);
Card c41(41,cardSquareo2, 1, 2, 2, 1);
Card c42(42,cardSquareo3, 1, 2, 3, 1);
Card c43(43,cardSquareAmp1, 1, 2, 1, 2);
Card c44(44,cardSquareAmp2, 1, 2, 2, 2);
Card c45(45,cardSquareAmp3, 1, 2, 3, 2);

Card c46(46,cardSquareBlock1, 1, 3, 1, 0);
Card c47(47,cardSquareBlock2, 1, 3, 2, 0);
Card c48(48,cardSquareBlock3, 1, 3, 3, 0);
Card c49(49,cardSquareo1, 1, 3, 1, 1);
Card c50(50,cardSquareo2, 1, 3, 2, 1);
Card c51(51,cardSquareo3, 1, 3, 3, 1);
Card c52(52,cardSquareAmp1, 1, 3, 1, 2);
Card c53(53,cardSquareAmp2, 1, 3, 2, 2);
Card c54(54,cardSquareAmp3, 1, 3, 3, 2);




Card c55(55,cardSlashBlock1, 2, 1, 1, 0);
Card c56(56,cardSlashBlock2, 2, 1, 2, 0);
Card c57(57,cardSlashBlock3, 2, 1, 3, 0);
Card c58(58,cardSlasho1, 2, 1, 1, 1);
Card c59(59,cardSlasho2, 2, 1, 2, 1);
Card c60(60,cardSlasho3, 2, 1, 3, 1);
Card c61(61,cardSlashAmp1, 2, 1, 1, 2);
Card c62(62,cardSlashAmp2, 2, 1, 2, 2);
Card c63(63,cardSlashAmp3, 2, 1, 3, 2);

Card c64(64,cardSlashBlock1, 2, 2, 1, 0);
Card c65(65,cardSlashBlock2, 2, 2, 2, 0);
Card c66(66,cardSlashBlock3, 2, 2, 3, 0);
Card c67(67,cardSlasho1, 2, 2, 1, 1);
Card c68(68,cardSlasho2, 2, 2, 2, 1);
Card c69(69,cardSlasho3, 2, 2, 3, 1);
Card c70(70,cardSlashAmp1, 2, 2, 1, 2);
Card c71(71,cardSlashAmp2, 2, 2, 2, 2);
Card c72(72,cardSlashAmp3, 2, 2, 3, 2);

Card c73(73,cardSlashBlock1, 2, 3, 1, 0);
Card c74(74,cardSlashBlock2, 2, 3, 2, 0);
Card c75(75,cardSlashBlock3, 2, 3, 3, 0);
Card c76(76,cardSlasho1, 2, 3, 1, 1);
Card c77(77,cardSlasho2, 2, 3, 2, 1);
Card c78(78,cardSlasho3, 2, 3, 3, 1);
Card c79(79,cardSlashAmp1, 2, 3, 1, 2);
Card c80(80,cardSlashAmp2, 2, 3, 2, 2);
Card c81(81,cardSlashAmp3, 2, 3, 3, 2);

//Card cardArray []= {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20,c21,c22,c23,c24,c25,c26,c27,c28,c29,c30,c31,c32,c33,c34,c35,c36,c37,c38,c39,c40,c41,c42,c43,c44,c45,c46,c47,c48,c49,c50,c51,c52,c53,c54,c55,c56,c57,c58,c59,c60,c61,c62,c63,c64,c65,c66,c67,c68,c69,c70,c71,c72,c73,c74,c75,c76,c77,c78,c79,c80,c81};

//vector<Card> cardArray= {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20,c21,c22,c23,c24,c25,c26,c27,c28,c29,c30,c31,c32,c33,c34,c35,c36,c37,c38,c39,c40,c41,c42,c43,c44,c45,c46,c47,c48,c49,c50,c51,c52,c53,c54,c55,c56,c57,c58,c59,c60,c61,c62,c63,c64,c65,c66,c67,c68,c69,c70,c71,c72,c73,c74,c75,c76,c77,c78,c79,c80,c81};

vector<Card> cardArray = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12};

//vector<Card> cardArray = {c1,c5,c8};

#endif
