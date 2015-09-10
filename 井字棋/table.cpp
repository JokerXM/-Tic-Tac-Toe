#include <iostream>
#include "table.h"
#include "humanplayer.h"
#include "computerplayer.h"
#include "pawn.h"
using namespace std;
Table::Table(){                  //constructor
	humanchangerow = 0;
	humanchangecol = 0;
	char beginning = '*';
	int i, j;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
			chessboard[i][j] = beginning;
	}
	board = &chessboard[0][0];
}
Table::~Table(){                 //disconstructor

}

void Table::humanchange(HumanPlayer &human, Pawn &shape)       //human change the pawn
{
	while (1){

		humanchangerow = human.chooserow();
		humanchangecol = human.choosecol();
		if (*(board + (humanchangerow - 1) * 3 + (humanchangecol - 1)) == '*')
		{

			*(board + (humanchangerow - 1) * 3 + (humanchangecol - 1)) = shape.getchessshape();
			break;
		}
		else cout << "there is already a pawn ,choose another position "<<endl;
	}

}
void Table::computerchange(ComputerPlayer &computer, Pawn &shape)   //computer change the pawn
{
	char computershape;
	char t = shape.getchessshape();
	if ( t =='X') computershape='O';
	if ( t == 'O') computershape = 'X';
	computerchangerow = computer.chooserow();
	computerchangecol = computer.choosecol();
	*(board + (computerchangerow - 1) * 3 + (computerchangecol - 1)) = computershape;
}

void Table::show_chessboard(HumanPlayer& human,ComputerPlayer& computer)  //show the chessboard and win number
{
	int i = 0;
	cout << endl;
	for (i = 0; i < 9; i++)
	{
		cout << *(board + i)<<" ";
		if ((i + 1) % 3 == 0) cout << endl;
	}
	cout <<human.getname()<<": "<< human.getwinnumber() << endl;
	cout << "computer" << ": " << computer.getwinnumber() << endl;
}

char* Table::getchessboard()    //get the array first address
{
	return &chessboard[0][0];
}

int Table::check(Pawn& shape){   //check if win
	int a[8];
	int b[3][3];
	int i, j;
	int win;
	int c;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (chessboard[i][j] == '*') b[i][j] = 0;
			else if (chessboard[i][j] == shape.getchessshape()) b[i][j] = -1;
			else  b[i][j] = 1;
		
		}
	}

	a[0] = b[0][0] + b[0][1] + b[0][2];
	a[1] = b[1][0] + b[1][1] + b[1][2];
	a[2] = b[2][0] + b[2][1] + b[2][2];
	a[3] = b[0][0] + b[1][0] + b[2][0];
	a[4] = b[0][1] + b[1][1] + b[2][1];
	a[5] = b[0][2] + b[1][2] + b[2][2];
	a[6] = b[0][0] + b[1][1] + b[2][2];
	a[7] = b[0][2] + b[1][1] + b[2][0];
	for ( c=0; c < 8; c++)
	{
		if (a[c] == -3)
		{
			win = -10; break;
		}
		else if (a[c] == 3)
		{
			win = 10; break;
		}
		else
		{
			win = 1;
		}
	}

	return win;
}
