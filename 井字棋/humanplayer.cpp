#include "HumanPlayer.h"
#include <iostream>
#include <string>
using namespace std;
HumanPlayer::HumanPlayer(){  //constructor
	turn = 0;
	name = "Pig";
	winnumber = 0;
}
HumanPlayer::~HumanPlayer(){  //disconstructor

}

int HumanPlayer::chooserow()   //human choose raw to put
{
	int row;
	while(1){
		cout << "where do you add the pawn ?"<<endl<<"row:" << endl;
		cin >> row;
		if (row > 0 && row<=3)
		{
			return row;
			break;
		}
		else cout << " it is not exit,more time!";
	} 
}
int HumanPlayer::choosecol()  //human choose col to put
{
	int col;
	while(1){
		cout << "col:" << endl;
		cin >> col;
		if (col > 0 && col<=3 )
		{
			return col;
		}
		else cout << "it is not exit,more time!";
	};
}

int HumanPlayer::setname()   //set the name
{
	std::string yourname;
	cout << "^_^ please input your name:  " << endl;
	cin >> yourname;
	name = yourname;
	return 0;
}
void HumanPlayer::coutname()  //print the name
{
	cout << "hi," << name << endl;
}
std::string HumanPlayer::getname()  //get the name
{
	return name;
}
int HumanPlayer::getturn()   //get the turn
{
	return turn;
}
void HumanPlayer::whoseturn(int whoseturn) // use this to define who is first and how many games they win

{
	winnumber += whoseturn;
	turn = whoseturn;
}
int HumanPlayer::getwinnumber()    //get the win number
{
	return winnumber;
}