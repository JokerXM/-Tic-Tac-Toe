#include "ComputerPlayer.h"
#include <iostream>
#include "table.h"
#include "Pawn.h"

using namespace std;
ComputerPlayer::ComputerPlayer(){      //constructor
	turn = 1;
	row = 4;
	col = 4;
	winnumber = 0;
}
ComputerPlayer::~ComputerPlayer()     //disconstuctor
{

}
void ComputerPlayer::computerchoose(Table &t, Pawn &shape)   //computer choose a pawn
{
	char*p = t.getchessboard();                               //get the chessboard first address
	int i;
	int b[9];
	int a[3], c[3], e, f;
	row = 4;
	col = 4;

	for (i = 0; i < 9; i++)
	{
		if (*(p + i) == '*')
		{
			b[i] = 0;
		}
		else if (*(p + i) == shape.getchessshape())                 //replace the char use int esay to check
		{
			b[i] = -1;
		}
		else
			b[i] = 10;

	}
	a[0] = b[0] + b[1] + b[2];
	a[1] = b[3] + b[4] + b[5];
	a[2] = b[6] + b[7] + b[8];
	c[0] = b[0] + b[3] + b[6];
	c[1] = b[1] + b[4] + b[7];
	c[2] = b[2] + b[5] + b[8];
	e = b[0] + b[4] + b[8];
	f = b[2] + b[4] + b[6];
	for (int i = 0; i < 3; i++)                                     //if computer or human have two pawn in one line then put in this line
	{
		if (a[i] == 20)
		{			
			for (int j = 0; j < 3; j++)
			{
				if (b[3*i + j] == 0) {
					row = i + 1;
					col = j + 1;
					break;
				}
			}
			break;
		}
		else if (a[i] == -2)
		{
			for (int j = 0; j < 3; j++)
			if (b[i+j] == 0) {
				row = j / 3 + 1;
				col = j % 3 + 1;
				break;

			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (c[i] == 20)
		{
			for (int j = 0; j < 3; j++)
			if (b[i + 3 * j] == 0) {
				row = (i + 3 * j) / 3 + 1;
				col = (i + 3 * j) % 3 + 1;
				break;
			}
			break;
		}
		else if (c[i] == -2)
		{
			for (int j = 0; j < 3; j++)
			if (b[i + 3 * j] == 0) {
				row = (i + 3 * j) / 3 + 1;
				col = (i + 3 * j) % 3 + 1;
				break;

			}

		}
	}
	if (e == -2 || e == 20)
	{
		for (int j = 0; j < 9; j += 4)
		if (b[j] == 0) {
			row = j / 3 + 1;
			col = j % 3 + 1;
			break;

		}
	}
	if (f == -2 || f == 20)
		{
			for (int j = 2; j < 7; j += 2)
			if (b[j] == 0) {
				row = (j) / 3 + 1;
				col = (j) % 3 + 1;
				break;

			}
		}

	if (row == 4 && col == 4)
	{                                                          //if there is no two pawn in one line,random put
		if (*(p + 4) == '*') { row = 2; col = 2; }
		else
		{
			while (1)
			{
				int j = rand() % 9;
				if (*(p + j) == '*')
				{
					row = (j / 3) + 1;
					col = (j % 3) + 1;

					break;
				}
			}
		}
	}
	
}

int ComputerPlayer::chooserow()       //get raw
{
	return row;
}
int ComputerPlayer::choosecol()       //get col
{
	return col;
}
int ComputerPlayer::getturn()        //get turn
{
	return turn;
}
void ComputerPlayer::whoseturn(int whoseturn)     //use this to define who is first and how many games they win

{
	winnumber += whoseturn;
	turn = whoseturn;
}
int ComputerPlayer::getwinnumber()                 //get win number
{
	return winnumber;
}