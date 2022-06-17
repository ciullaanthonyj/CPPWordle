/*
 *  File: CPPWordle.cpp
 *  Desc: main program entry point
 *  Author: Anthony Ciulla
 *
 *  This file is part of cWordle.
 *	cWordle is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Foundation, either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  cWordle is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with cWordle.
 *  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Game.h"

int main()
{
	//Class Declaration
	Word w;
	Game g;

	//Variable Declaration
	int userInputInt;
	string userInputString;
	char userInputChar;
	int gameControl = 1;
	int gameStatus; //1 = win, 2 = retry, 3 = loss 
	vector<char> unsafeGameWord;
	vector<char> unsafePlayerWord;

	//Header
	w.displayHeader();
	while (gameControl == 1) {
	// Begin Program
	
	//get attempts allowed from player
		cout << "How many attempts allowed: ";
		cin >> userInputInt;
		w.verifyNum(userInputInt);
		//setword
		g.setMaxAttempts(userInputInt);
		cout << "\n" << endl;
		//get word to be guessed from player
		cout << "What word would you like the player to guess: ";
		cin >> userInputString;
		cout << "\n" << endl;
		//verify word
		w.verifyLength(userInputString);
		//set word
		g.setGameWord(userInputString);
		// clear screen
		g.clearScreen();
			
		//add 1 to attempt before getting users guess word
		g.setAttemptNumber(1);
		//get players word
		cout << "Enter a five character word: \n";
		//displays attempt number by the players guess
		int unsafeGameAttemptNum = g.getAttemptNumber();
		int unsafeMaxAttemptNum = g.getMaxAttempts();
		cout << "\n(" << unsafeGameAttemptNum << "/" << unsafeMaxAttemptNum << "): ";

		cin >> userInputString;
		w.verifyLength(userInputString); //verify length
		g.setPlayerWord(userInputString); //convert word to protected vector

		unsafePlayerWord = g.getPlayerWordVector();
		unsafeGameWord = g.getGameWordVector();
		//compare


		//NEED TO WRITE LOGIC FOR LOOPS
		if (g.compareChar(unsafePlayerWord, unsafeGameWord) == true) {
			//win

		}
		else {
			//not correct
			if (unsafeGameAttemptNum < unsafeMaxAttemptNum) {
				//still has attempts left
			}
			else {
				//no attempts left
			}
		}
	}
	return 0;
}
