#include <iostream>
#include "Pawn.h"
using namespace std;
Pawn::Pawn()
{
	chessshape = 'O';
}
Pawn::~Pawn(){

}
void Pawn::setchessshape()         //human choose the shape
{
	do{
		char shape;
		cout << "please choose your shape X or O?:if not,O" << endl;
		cin >> shape;
		if (shape == 'X' || shape == 'O')
		{
			chessshape = shape;
			break;
		}
		else cout << "sorry not confirm to the rules";
	} while (1);
}
char Pawn::getchessshape()   //get the shape
{
	return chessshape;
}