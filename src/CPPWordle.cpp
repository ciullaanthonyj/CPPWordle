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
	Game mygame;
	Output newOut;

	//set output
	std::cout << std::fixed << std::setprecision(1) << std::showpoint << std::endl;

	newOut.DisplayHeader();

	bool continuePlaying = true;

	while (continuePlaying) {

		bool continuePlaying = false;
		bool gameControl = false;
		bool playerInput = true;

		//Ask if player wants to play
		//This is also where the loop will run to if they 
		//want to play again

		char userInputChar;

		std::cout << std::endl << "would you like to play? (y/n): ";
		std::cin >> userInputChar;
		std::cout << std::endl;

		//Do they want to play again? 
		//Force input char to upper and check it with switch

		char playAgain = toupper(userInputChar);

		//switch control
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

		//reset and initialize variables
		std::vector<char> gameWord;
		std::vector<char> playerWord;
		int maxRounds;
		int roundNumber;


		//They want to play
		while (gameControl == true) {

			//Reset Variables
			mygame.ResetVariables();

			//get max attempts allowed and verify it's a number
			std::cout << "\nHow many attempts allowed: ";
			std::cin >> maxRounds;

			//set the max rounds
			mygame.verifyNum(maxRounds);
			mygame.SetMaxRounds(maxRounds);
			std::cout << "\n" << std::endl;

			std::string tempGameWord;

			//get word to be guessed from player
			std::cout << "What word would you like the player to guess: ";
			tempGameWord = "";
			std::cin >> tempGameWord;
			std::cout << "\n" << std::endl;

			//verify / set word
			std::vector<char> gameWordVec;
			mygame.verifyLength(tempGameWord);
			mygame.ConvertToVec(tempGameWord, gameWordVec);
			mygame.SetGameWord(gameWordVec);
			//clear the game word
			gameWordVec.clear();

			// clear screen
			mygame.clearScreen();


			//get players word
			std::cout << "Enter a five character word: \n";

			//guess
			while (playerInput == true) {
				
				//Begin attempt
				mygame.IncRoundNumber();

				roundNumber = mygame.GetRoundNumber();
				maxRounds = mygame.GetMaxRounds();

				std::string tempPlayerWord;

				std::cout << "\nGUESS (" << roundNumber << "/" << maxRounds << "): ";

				//get and verify guess
				std::vector<char> playerWordVec;
				std::cin >> tempPlayerWord;
				mygame.verifyLength(tempPlayerWord);
				mygame.ConvertToVec(tempPlayerWord, playerWordVec);
				mygame.SetPlayerWord(playerWordVec);
				playerWordVec.clear();

				tempPlayerWord = "";

				//compare
				bool ansCheck = mygame.CompareWords();


				//works
				if (ansCheck == true) {
					//correct answer
					std::cout << "\nSuccess! It took you " << roundNumber << " tries!\n";
					//reset the while loops
					gameControl = false;
					continuePlaying = true;
					playerInput = false;
				}
				if (ansCheck != true) {
					//wrong answer, keep the loop going for the Nth try
					playerInput = true;
				}

				if (roundNumber == maxRounds && ansCheck != true) {
					//reset loops, player lost via max attempts
					playerInput = false;
					continuePlaying = true;
					gameControl = false;

					std::cout << "\nFailure. The correct word was: " << tempGameWord << "\n";

					tempGameWord.clear();
				}
			}
		}
	}
	return 0;
}
