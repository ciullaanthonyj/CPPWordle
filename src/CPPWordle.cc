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
	bool gameControl = true;
	bool ansCheck = false;
	bool continuePlaying = true;
	bool playerInput = true;
	string userInputString;
	char userInputChar;
	vector<char> unsafeGameWord;
	vector<char> unsafePlayerWord;

	//Header
	w.displayHeader();

	while (continuePlaying) {
		g.resetAttemptNumber();
		g.resetGameWord();
		g.resetPlayerWord();
		continuePlaying = false;
		gameControl = false;
		playerInput = true;

		std::cout << std::endl << "would you like to play? (y/n): ";
		std::cin >> userInputChar;
		std::cout << std::endl;

		char playAgain = toupper(userInputChar); //force decision to upper
		switch (playAgain) {
		case 'Y':
			gameControl = true;
			continuePlaying = false;
			break;
		case 'N':
			std::cout << "Play again later!" << std::endl;
			return 0;
			break;
		default:
			return 1;
			break;
		}

		while (gameControl == true) {
			//get max attempts allowed
			cout << "\nHow many attempts allowed: ";
			cin >> userInputInt;
			w.verifyNum(userInputInt);
			g.setMaxAttempts(userInputInt);
			cout << "\n" << endl;

			//get word to be guessed from player
			cout << "What word would you like the player to guess: ";
			cin >> userInputString;
			cout << "\n" << endl;

			//verify / set word
			w.verifyLength(userInputString);
			g.setGameWord(userInputString);

			// clear screen
			g.clearScreen();

			//get players word
			cout << "Enter a five character word: \n";

			//guess
			while (playerInput == true) {
				g.setAttemptNumber(1);

				//set attempt num local and max attempt num local
				int unsafeGameAttemptNum = g.getAttemptNumber();
				int unsafeMaxAttemptNum = g.getMaxAttempts();

				cout << "\nGUESS (" << unsafeGameAttemptNum << "/" << unsafeMaxAttemptNum << "): ";

				//get and verify guess
				cin >> userInputString;
				w.verifyLength(userInputString);
				g.setPlayerWord(userInputString);

				//localize gameWord and playerWord vector
				unsafePlayerWord = g.getPlayerWordVector();
				unsafeGameWord = g.getGameWordVector();

				//compare
				ansCheck = g.compareChar(unsafePlayerWord, unsafeGameWord);


				//works
				if (ansCheck == true) {
					//correct answer
					cout << "\nSuccess! It took you " << unsafeGameAttemptNum << " tries!\n";
					gameControl = false;
					continuePlaying = true;
					playerInput = false;
				}
				if (ansCheck != true) {
					playerInput = true;
				}

				if (unsafeGameAttemptNum == unsafeMaxAttemptNum && ansCheck != true) {
					playerInput = false;
					continuePlaying = true;
					gameControl = false;

					cout << "\nFailure. The correct word was: ";
					g.getGameWord();
					cout << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
