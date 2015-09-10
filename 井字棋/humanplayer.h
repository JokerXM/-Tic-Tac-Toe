#ifndef HUMANPLAYER_H_INCLUDED
#define HUMANPLAYER_H_INCLUDED
#include "player.h"
#include "table.h"
#include <string>
class HumanPlayer:public Player{
public:
	HumanPlayer();
	~HumanPlayer();
	int chooserow();
	int choosecol();
	void coutname();
	int setname();
	int getturn();
	std::string getname();
	void whoseturn(int);
	int getwinnumber();

private:
	std::string name;
	int turn;
	int winnumber;
	int raw;
	int col;
};


#endif // HUMANPLAYER_H_INCLUDED