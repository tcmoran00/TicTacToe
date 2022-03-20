/*******************************************
Author: Tucker Moran
Course: IST 163 - Programming Practicum
Date: 7/29/2016 - 7/31/2016
*******************************************
Files for Assignment: IST163_Moran_T_FinalExam_ticTacToe.cpp, ticTacToe.h, ticTacToe_Implementation.cpp
Purpose of File: Header file for class ticTacToe
Assistance Recieved: Notes from chapter 10
*******************************************/

class ticTacToe
{
public:
	void printBoard();
	void getMove(int, int, char);
	bool checkMove(int, int, char);
	bool checkWinner();
	bool checkCat();
	void completedGames();
	void clearBoard();
	ticTacToe();

	bool endGameCheck;

private:
	char board[3][3];
	int playerXWins;
	int playerOWins;
	int cats;
};
