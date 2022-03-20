/*******************************************
Author: Tucker Moran
Course: IST 163 - Programming Practicum
Date: 7/29/2016 - 7/31/2016
*******************************************
Files for Assignment: IST163_Moran_T_FinalExam_ticTacToe.cpp, ticTacToe.h, ticTacToe_Implementation.cpp
Purpose of File: Implementation file for class ticTacToe
Assistance Recieved: Notes from chapter 10
*******************************************/

#include<iostream>
#include<iomanip>
#include<string>
#include"ticTacToe.h"
using namespace std;


/***************************
Function: ticTacToe
Precondition: constructor function
Postcondition: sets member variables to starting values
Dates of Coding: 7/30/2016
Modifications:
***************************/
ticTacToe::ticTacToe()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
			board[x][y] = '-';
	}

	endGameCheck = false;
	playerXWins = 0;
	playerOWins = 0;
	cats = 0;
}


/***************************
Function: clearBoard
Precondition: requires the board array to be declared
Postcondition: clears the board array
Dates of Coding: 7/30/2016
Modifications:
***************************/
void ticTacToe::clearBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
			board[x][y] = '-';   // Sets the board back to the starting '-' character
	}

	endGameCheck = false;
}


/***************************
Function: printBoard
Precondition: requires the board array be initialized
Postcondition: prints the current gameboard
Dates of Coding: 7/30/2016
Modifications: 
***************************/
void ticTacToe::printBoard()
{
	cout << "  " << "0" << " " << "1" << " " << "2" << endl;
	cout << "0" << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
	cout << "1" << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
	cout << "2" << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
	cout << endl << endl;
}


/***************************
Function: checkMove
Precondition: uses 2 int and a char parameter: row, column, and player
row - int
col - int
player - char
Postcondition: checks to make sure there isn't already a game "piece" in that spot
Dates of Coding: 7/30/2016
Modifications: 
***************************/
bool ticTacToe::checkMove(int row, int col, char player)
{
	// Checks to make sure that move is within range and that there isnt an X or O there
	if (row <= 2 && col <= 2 && board[row][col] != 'X' && board[row][col] != 'O')
		return true;
	else
		return false;
}


/***************************
Function: getMove
Precondition:  uses 2 int and a char parameter: row, column, and player
row - int
col - int
player - char
Postcondition: places the player character in the user-specified position on the board
Dates of Coding: 7/30/2016
Modifications: 
***************************/
void ticTacToe::getMove(int row, int col, char player)
{
	board[row][col] = player;
}


/***************************
Function: checkWinner
Precondition: requires board array to be intialized
Postcondition: checks the board to see if there is a winner or a CAT
Dates of Coding: 7/31/2016
Modifications:
***************************/
bool ticTacToe::checkWinner() // check for winner or cat and then add to winner or cat variable
{
	bool winner = false;  // will use this to check for cat
		
		for (int x = 0; x < 3; x++)
		{
			if (board[0][x] == board[1][x] && board[1][x] == board[2][x])   // Checks for vertical win
			{
				if (board[0][x] != '-' && board[1][x] != '-' && board[2][x] != '-')
				{
					// Check to see who won
					if (board[0][x] == 'X')
					{
						ticTacToe::playerXWins++;
						cout << "Player X Wins!" << endl << endl << endl;
					}
					else
					{
						ticTacToe::playerOWins++;
						cout << "Player O Wins!" << endl << endl << endl;
					}

					winner = true;
					return true;
				}
			}

			else if (board[x][0] == board[x][1] && board[x][1] == board[x][2])   // Checks for horizontal win
			{
				if (board[x][0] != '-' && board[x][1] != '-' && board[x][2] != '-')
				{
					// Check to see who won
					if (board[x][0] == 'X')
					{
						ticTacToe::playerXWins++;
						cout << "Player X Wins!" << endl << endl << endl;
					}
					else
					{
						ticTacToe::playerOWins++;
						cout << "Player O Wins!" << endl << endl << endl;
					}

					winner = true;
					return true;
				}
			}
		}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])   // Checks for first possible diagonal win
		{
			if (board[0][0] != '-' && board[1][1] != '-' && board[2][2] != '-')
			{
				// Check to see who won
				if (board[0][0] == 'X')
				{
					ticTacToe::playerXWins++;
					cout << "Player X Wins!" << endl << endl << endl;
				}
				else
				{
					ticTacToe::playerOWins++;
					cout << "Player O Wins!" << endl << endl << endl;
				}

				winner = true;
				return true;
			}
		}

		else if (board[2][0] == board[1][1] && board[1][1] == board[0][2])   // Checks for other possible diagonal win
		{
			if (board[2][0] != '-' && board[1][1] != '-' && board[0][2] != '-')
			{
				// Check to see who won
				if (board[2][0] == 'X')
				{
					ticTacToe::playerXWins++;
					cout << "Player X Wins!" << endl << endl << endl;
				}
				else
				{
					ticTacToe::playerOWins++;
					cout << "Player O Wins!" << endl << endl << endl;
				}

				winner = true;
				return true;
			}
		}

	// Check for CAT
	if (winner == false && ticTacToe::checkCat())
	{
		ticTacToe::cats++;
		cout << "CAT!" << endl << endl << endl;
		return true;
	}
	
	else
		return false;
}


/***************************
Function: checkCat
Precondition: requires that winner == false in the checkWinner function
Postcondition: checks the board to see if all of the spots are filled
Dates of Coding: 7/31/2016
Modifications:
***************************/
bool ticTacToe::checkCat()
{
	int cat = 0;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (board[x][y] == 'X' || board[x][y] == 'O')
				cat++;
		}
	}

	if (cat == 9)
		return true;
	else
		return false;
}


/***************************
Function: completedGames
Precondition: requires at least one game have been completed
Postcondition: outputs the number of wins by each player and the number of ties
Dates of Coding: 7/30/2016
Modifications:
***************************/
void ticTacToe::completedGames()
{
	cout << "--------------------WINS & CATS--------------------" << endl;
	cout << setw(16) << "Player X Wins: " << setw(4) << ticTacToe::playerXWins << endl;
	cout << setw(16) << "Player O Wins: " << setw(4) << ticTacToe::playerOWins << endl;
	cout << setw(16) << "Cats: " << setw(4) << ticTacToe::cats << endl;
}