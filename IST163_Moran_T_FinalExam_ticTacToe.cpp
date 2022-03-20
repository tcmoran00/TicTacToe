/*******************************************
Author: Tucker Moran
Course: IST 163 - Programming Practicum
Date: 7/29/2016 - 7/31/2016
*******************************************
Files for Assignment: IST163_Moran_T_FinalExam_ticTacToe.cpp, ticTacToe.h, ticTacToe_Implementation.cpp
Purpose of File: Allow two players to play a tic-tac-toe game
Assistance Recieved: Notes from chapters 7-10
*******************************************/

#include<iostream>
#include<iomanip>
#include<string>
#include"ticTacToe.h"
using namespace std;

void showMenu();

ticTacToe game;

int main()
{
	// variables
	bool playersPlaying = true;
	char playAgain;
	bool playAgainMenu = false;
	int row;
	int col;

	// Start the game with large while loop, loops until players specify that they are done playing
	while (playersPlaying)
	{
		
		// Show menu
		showMenu();

		// Nested while loop for players moves, loop ends when the game is won or tied
		while (!game.endGameCheck)
		{
			// Player input variables
			bool playerXInputValid = true;
			bool playerOInputValid = true;

			// print board
			game.printBoard();
			cout << "To win the game, place three of your pieces ('X' or 'O') in a row \nbefore the other player. Good Luck!" << endl << endl;

			// Loop for player X input
			while (playerXInputValid == true)
			{
				// Player X input, checkMove, checkWinner if move is valid, and then allow Player O to select his move if game is not won
				cout << "Player X, select the position of your move by entering the row number and \ncolumn number, separated by a space. (i.e. '0 1'): ";
				cin >> row >> col;
				cout << endl << endl;

				if (game.checkMove(row, col, 'X'))
				{
					game.getMove(row, col, 'X');
					game.printBoard();
					cout << endl;
					playerXInputValid = false;
				}
				else
				{
					cout << "Invalid entry. Try again." << endl << endl;
					game.printBoard();
				}
			}

				// check game winner
			if (game.checkWinner())
				game.endGameCheck = true;

			else
			{
				// Loop for player O input
				while (playerOInputValid == true)
				{
					// Player O input, checkMove, checkWinner if move is valid, move goes back to player X
					cout << "Player O, select the position of your move by entering the row number and \ncolumn number, separated by a space. (i.e. '0 1'): ";
					cin >> row >> col;
					cout << endl << endl;

					if (game.checkMove(row, col, 'O'))
					{
						game.getMove(row, col, 'O');
						game.printBoard();
						cout << endl;
						playerOInputValid = false;
					}
					else
					{
						cout << "Invalid entry. Try again." << endl << endl;
						game.printBoard();
					}
					// check game winner
					if (game.checkWinner())
						game.endGameCheck = true;
				}
			}

						
		}
		
		// print board upon a win or tie and then clear it
		game.printBoard();
		game.clearBoard();
		cout << endl << endl;

		// call completedGames
		game.completedGames();
		cout << endl << endl;

		// Play again? if no: playersPlaying = false
		while (!playAgainMenu)
		{
			cout << "Would you like to play again? Enter 'Y' for yes or 'N' for no. " << endl;
			cin >> playAgain;

			if (playAgain == 'Y' || playAgain == 'y')
			{
				cout << "Playing again..." << endl << endl;
				playAgainMenu = true;
			}
			else if (playAgain == 'N' || playAgain == 'n')
			{
				cout << "Ending game..." << endl;
				playAgainMenu = true;
				playersPlaying = false;
			}
			else
			{
				cout << "Invalid input. Enter 'Y' or 'N'.";
				cout << endl << endl;
			}
		}

	}

	return 0;
}


/***************************
Function: showMenu
Precondition: no parameters
Postcondition: outputs a menu for the user. user can choose to play or quit game
Dates of Coding: 7/30/2016
Modifications:
***************************/
void showMenu()
{
	char menuOption;
	bool menu = false;

	while (!menu)
	{
		// program/game menu
		cout << endl;
		cout << "-------------------------TIC-TAC-TOE-------------------------" << endl;
		cout << "Options: " << endl;
		cout << "1. Enter '1' to play a game of tic-tac-toe." << endl;
		cout << "2. Enter '2' to exit the game" << endl << endl;
		cout << "Option: ";
		cin >> menuOption;
		cout << endl << endl;

		// check user input
		if (menuOption == '1')
			menu = true;
		else if (menuOption == '2')
		{
			game.endGameCheck = true;
			menu = true;
		}
		else
			cout << "Invalid response. Please enter a '1' or a '2'.";
		
		cout << endl << endl;
	}


}