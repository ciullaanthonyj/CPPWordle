/*
 *  File: Game.cpp
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

//Converts string to vector
void Game::ConvertToVec(std::string OldWord, std::vector<char>& NewVector) {
	for (int i = 0; i < 5; i++) {
		NewVector.push_back(toupper(OldWord[i]));
	}
}

//set private class properties:
void Game::SetGameWord(std::vector<char> GameWord)
{
	SafeGameWord = GameWord;
}

void Game::SetPlayerWord(std::vector<char> PlayerWord)
{
	SafePlayerWord = PlayerWord;
}

void Game::SetMaxRounds(int MaxRounds)
{
	SafeMaxRounds = MaxRounds;
}

void Game::SetRoundNumber()
{
	SafeRoundNumber++;
}

//BIG BOY ALGORITHM lol
bool Game::CompareWords()
{
	//initialize a temp vector to hold the correct characters,
	//so that we can test against them. This is for the common
	//case of the word being 'hyper' and the guess being
	//'reset'
	std::vector<char> correct;

	//Exact Match
	if (SafePlayerWord == SafeGameWord) {
		changeColor("green"); //green

		for (auto& num : SafePlayerWord) {
			std::cout << num;
		}
		changeColor("white");
		return true;
	}

	//Lets test for maybes and nos
	else {
		//First we will check if any are correct and push them into the correct vector for later
		for (int i = 0; i < 5; i++) {
			if (SafePlayerWord[i] == SafeGameWord[i]) {
				correct.push_back(SafePlayerWord[i]);
			}
		}
		//Check for correct char
		for (int i = 0; i < 5; i++) {
			if (SafePlayerWord[i] == SafeGameWord[i]) {
				changeColor("green"); //green
				std::cout << SafePlayerWord[i];
				changeColor("white"); //white
			}
			//Check for correct char wrong place
			else if (find(SafeGameWord.begin(), SafeGameWord.end(), SafePlayerWord[i]) != SafeGameWord.end()) {
				//Make sure that the char isn't correct somewhere in the word
				if (find(correct.begin(), correct.end(), SafePlayerWord[i]) == correct.end()) {
					changeColor("yellow"); //yellow
					std::cout << SafePlayerWord[i];
					changeColor("white"); //white
				}
				//if it is print it gray
				else {
					changeColor("gray"); //gray
					std::cout << SafePlayerWord[i];
					changeColor("white"); //white
				}
			}
			//lastly wrong char doesn't belong in word.
			else {
				changeColor("gray"); //gray
				std::cout << SafePlayerWord[i];
				changeColor("white"); //white
			}
		}
		return false;
	}
}

void Game::ResetVariables()
{
	SafeRoundNumber = 0;
	SafeMaxRounds = 0;
	SafePlayerWord.clear();
	SafeGameWord.clear();
}

int Game::GetMaxRounds()
{
	return SafeMaxRounds;
}

int Game::GetRoundNumber()
{
	return SafeRoundNumber;
}

//Returns game word
std::string Game::GetGameWord()
{
	std::string TempGameWordString;
	for (auto num : SafeGameWord) {
		TempGameWordString.push_back(toupper(SafeGameWord[num]));
	}
	return TempGameWordString;
}

//Change the color of the console text via ansi. Haven't gotten functional 100% on CMake build from github copy outside of vs
void Game::changeColor(std::string newColor)
{
	//Couldn't figure out the enum type or how to properly match it so this will have to do for now
	if (newColor == "gray") {
		std::cout << "\033[38;2;192;192;192m";
	}
	if (newColor == "green") {
		std::cout << "\033[38;2;0;255;0m";
	}
	if (newColor == "blue") {
		std::cout << "\033[38;2;0;204;204m";
	}
	if (newColor == "red") {
		std::cout << "\033[38;2;255;0;0m";
	}
	if (newColor == "yellow") {
		std::cout << "\033[38;2;255;255;0m";
	}
	if (newColor == "white") {
		std::cout << "\033[38;2;255;255;255m";
	}
}

//Clears screen for gameplay
void Game::clearScreen()
{
	for (int i = 0; i < 50; i++) {
		std::cout << "\n" << std::endl;
	}
}

//Checks to verify the length of the string and ensure it's 5, if not it can ask for the variable and change it via the reference
void Game::verifyLength(std::string& word)
{
	//reset input
	std::cin.clear();
	std::cin.ignore();

	if (word.size() != 5) {
		changeColor("red");
		std::cout << "Invalid input. Try again:";
		changeColor("white");
		std::cout << " ";
		std::cin >> word;
		verifyLength(word);
	}
}

//Checks to verify the length of the number or that it's a real num. Can ask for a new number and change it via reference variable
void Game::verifyNum(int& num)
{
	//clear input to surpress that whole loop screaming invalid input lol
	std::cin.clear();
	std::cin.ignore();

	if (num <= 0) {
		//number is negative invalid
		changeColor("red");
		std::cout << "Invalid input. Try again:";
		changeColor("white");
		std::cout << " ";
		std::cin >> num;
		verifyNum(num);
	}
}

