#include <iostream>
#include "game.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Pawn.h"
#include "stdlib.h"
#include "Player.h"
#include "Table.h"
using namespace std;
Game::Game(){
	gameloop = 0;
}
Game::~Game(){

}
void Game::run(){
	system("color 5E");                      //the screen colour 
	cout << "                      Tic-Tac-Toe                       " << endl;
	cout << "   -------------------------------------------------------" << endl;
	cout << "   |   >_<   new game begin now,try your best   >_<      |" << endl;
	cout << "   -------------------------------------------------------" << endl;
	HumanPlayer newplayer;
	HumanPlayer &human = newplayer;           //another name of it
	ComputerPlayer CP;
	ComputerPlayer &computer = CP;
	Pawn choosepawn;
	Pawn &shape = choosepawn;
	human.setname();                        //input the player name 
	human.coutname();
	shape.setchessshape();                  //choose the shape 
	for (gameloop = 0; gameloop < 5; gameloop++)            // gameloop five round
	{
		cout << "    -----------------------------------------------------" << endl;
		cout << "    |  >_<   new game begin now,try your best   >_<      |" << endl;
		cout << "    -----------------------------------------------------" << endl;

		Table T;
		Table &t = T;
		t.show_chessboard(human,computer);                   //show the chessboard,transfer their another name 
		int loop = 0;                                        //loop is to check the pawn is full but no win
		if (human.getturn()==0)                              //human first begin
		{
			while (1)
			{

				t.humanchange(human, shape);                    //human choose to add a pawn
				t.show_chessboard(human, computer);             //show the chessboard
				int win = t.check(shape);                       //check if win
				if (win == -10)
				{ 
					cout << "you win"<<endl; 
					human.whoseturn(1);
					computer.whoseturn(0);
					break; 
				}
				loop++;                                         //check if pawn is full and no win
				if (loop >= 9)
				{
					cout << "no win no lose" << endl;
					break;
				}
				computer.computerchoose(t,shape);               //computer choose
				t.computerchange(computer, shape);              
				t.show_chessboard(human, computer);             //show the chessboard
				win = t.check(shape);
				if (win == 10)                                  //check if computer win
				{ 
					cout << "you lose"<<endl; 
					human.whoseturn(0);
					computer.whoseturn(1);
					break; 
				}
				loop++;                                         //check if no win no lose
				if (loop >= 9)
				{
					cout << "no win no lose" << endl;
					break;
				}
			}
			continue;
		}
	
		if (computer.getturn() == 0)                                       // same as before just for when the computer first begain
		{
			while (1)
			{
				computer.computerchoose(t,shape);
				t.computerchange(computer, shape);
				t.show_chessboard(human, computer);
				int win = t.check(shape);
				if (win == 10)
				{
					cout << human.getname()<< "you lose"<<endl; 
					human.whoseturn(0);
					computer.whoseturn(1);
					break; 
				}
				loop++;
				if (loop >= 9)
				{
					cout << "no win no lose" << endl;
					break;
				}
				t.humanchange(human, shape);
				t.show_chessboard(human, computer);
				win = t.check(shape);
				if (win == -10)
				{ 
					cout <<human.getname()<< "you win"<<endl;
					human.whoseturn(1);
					computer.whoseturn(0);
					break; 
				}
				loop++;
				if (loop >= 9)
				{
					cout << " no win no lose " << endl;
					break;
				}
			}
		}
	}
	if (human.getwinnumber() > computer.getwinnumber()) cout << "hey,   "<<human.getname()<<"   you win ^_^";           //after the five round print the winner
	if (human.getwinnumber() < computer.getwinnumber()) cout << "hey, computer   " << human.getname() << " you win ^_^";
	if (human.getwinnumber() == computer.getwinnumber()) cout << "hey,   " << human.getname() << "   you are the same";
}
