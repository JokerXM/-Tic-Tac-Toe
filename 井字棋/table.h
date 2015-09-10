#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
class Pawn;
class ComputerPlayer;
class HumanPlayer;
class Table
{
public:
	Table();
	~Table();
	void begining();
	void show_chessboard(HumanPlayer &human, ComputerPlayer &computer);
	char* getchessboard();
	void humanchange(HumanPlayer &human, Pawn &shape);
	void computerchange(ComputerPlayer &computer, Pawn &shape);
	int check(Pawn &shape);
private:
	char chessboard[3][3];
	int humanchangerow;
	int humanchangecol;
	int computerchangerow;
	int computerchangecol;
	char* board;


};


#endif  TABLE_H_INCLUDED