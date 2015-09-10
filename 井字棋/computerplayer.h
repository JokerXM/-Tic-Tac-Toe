#ifndef COMPUTERPLAYER_H_INCLUDED
#define COMPUTERPLAYER_H_INCLUDED
#include <iostream>
using namespace std;
#include "string"
#include "Player.h"
#include "Pawn.h"

class Table;
class ComputerPlayer :public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
	void computerchoose(Table &t,Pawn &shape);
	int chooserow();
	int choosecol();
	int getturn();
	void whoseturn(int);
	int getwinnumber();



private:
	int turn;
	int row;
	int col;
	int winnumber;
};


#endif // COMPUTERPLAYER_H_INCLUDED