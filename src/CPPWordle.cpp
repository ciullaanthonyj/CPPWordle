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

#include "Game.hpp"

int main()
{
	//Class Declaration
	Game g;

	//Variable Declaration

	bool ansCheck = false;
	bool continuePlaying = true;
	bool gameControl = true;
	bool playerInput = true;
	char userInputChar;
	int maxNumberAttempts;
	int attemptNumber;
	std::string gameWord;
	std::string playerWord;
	std::vector<char> gameWordVector;
	std::vector<char> playerWordVector;


	//Header
	g.displayHeader();

	while (continuePlaying) {

		//Reset Variables

		attemptNumber = 0;
		gameWord = "";
		gameWordVector.clear();
		playerWord = "";
		playerWordVector.clear();
		continuePlaying = false;
		gameControl = false;
		playerInput = true;

		//Ask if player wants to play
		//This is also where the loop will run to if they 
		//want to play again

		std::cout << std::endl << "would you like to play? (y/n): ";
		std::cin >> userInputChar;
		std::cout << std::endl;

		//Do they want to play again? 
		//Force input char to upper and check it with switch

		char playAgain = toupper(userInputChar);
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

		//They want to play
		while (gameControl == true) {

			//get max attempts allowed and verify it's a number
			std::cout << "\nHow many attempts allowed: ";
			std::cin >> maxNumberAttempts;
			g.verifyNum(maxNumberAttempts);
			std::cout << "\n" << std::endl;

			//get word to be guessed from player
			std::cout << "What word would you like the player to guess: ";
			std::cin >> gameWord;
			std::cout << "\n" << std::endl;

			//verify / set word
			g.verifyLength(gameWord);
			g.convertToVec(gameWord, gameWordVector);
	

			// clear screen
			g.clearScreen();

			//get players word
			std::cout << "Enter a five character word: \n";

			//guess
			while (playerInput == true) {
				
				//Begin attempt
				attemptNumber += 1;

				//reset playerWord
				playerWord = "";
				playerWordVector.clear();

				std::cout << "\nGUESS (" << attemptNumber << "/" << maxNumberAttempts << "): ";

				//get and verify guess
				std::cin >> playerWord;
				g.verifyLength(playerWord);
				g.convertToVec(playerWord, playerWordVector);


				//compare
				ansCheck = g.compareChar(playerWordVector, gameWordVector);


				//works
				if (ansCheck == true) {
					//correct answer
					std::cout << "\nSuccess! It took you " << attemptNumber << " tries!\n";
					//reset the while loops
					gameControl = false;
					continuePlaying = true;
					playerInput = false;
				}
				if (ansCheck != true) {
					//wrong answer, keep the loop going for the Nth try
					playerInput = true;
				}

				if (attemptNumber == maxNumberAttempts && ansCheck != true) {
					//reset loops, player lost via max attempts
					playerInput = false;
					continuePlaying = true;
					gameControl = false;

					std::cout << "\nFailure. The correct word was: " << gameWord << "\n";
				}
			}
		}
	}
	return 0;
}
