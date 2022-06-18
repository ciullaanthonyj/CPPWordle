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

void Game::ConvertToVec(std::string OldWord, std::vector<char>& NewVector) {
	for (int i = 0; i < 5; i++) {
		NewVector.push_back(toupper(OldWord[i]));
	}
}

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

bool Game::CompareWords()
{
	//initialize a temp vector to hold the correct characters,
	//so that we can test against them. This is for the common
	//case of the word being 'hyper' and the guess being
	//'reset'
	std::vector<char> correct;

	//Exact Match
	if (SafePlayerWord == SafeGameWord) {
		changeColor(10); //green

		for (auto& num : SafePlayerWord) {
			std::cout << num;
		}
		changeColor(15);
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
				changeColor(10); //green
				std::cout << SafePlayerWord[i];
				changeColor(15); //white
			}
			//Check for correct char wrong place
			else if (find(SafeGameWord.begin(), SafeGameWord.end(), SafePlayerWord[i]) != SafeGameWord.end()) {
				//Make sure that the char isn't correct somewhere in the word
				if (find(correct.begin(), correct.end(), SafePlayerWord[i]) == correct.end()) {
					changeColor(14); //yellow
					std::cout << SafePlayerWord[i];
					changeColor(15); //white
				}
				//if it is print it gray
				else {
					changeColor(8); //gray
					std::cout << SafePlayerWord[i];
					changeColor(15); //white
				}
			}
			//lastly wrong char doesn't belong in word.
			else {
				changeColor(8); //gray
				std::cout << SafePlayerWord[i];
				changeColor(15); //white
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

std::string Game::GetGameWord()
{
	std::string TempGameWordString;
	for (auto num : SafeGameWord) {
		TempGameWordString.push_back(toupper(SafeGameWord[num]));
	}
	return TempGameWordString;
}

void Game::changeColor(int color)
{
	switch (color) {
		//11 15 10 14 8
	case 8: //gray
		std::cout << "\033[38;2;192;192;192m";
		break;
	case 10: //green
		std::cout << "\033[38;2;0;255;0m";
		break;
	case 11: //header color
		std::cout << "\033[38;2;0;204;204m";
		break;
	case 12: //red
		std::cout << "\033[38;2;255;0;0m";
		break;
	case 14: //yellow
		std::cout << "\033[38;2;255;255;0m";
		break;
	case 15: //bright white
		std::cout << "\033[38;2;255;255;255m";
		break;
	default:
		std::cout << "\033[38;2;255;255;255m";
		break;
	}
}

void Game::clearScreen()
{
	for (int i = 0; i < 50; i++) {
		std::cout << "\n" << std::endl;
	}
}

void Game::verifyLength(std::string& word)
{
	//reset input
	std::cin.clear();
	std::cin.ignore();

	if (word.size() != 5) {
		changeColor(12);
		std::cout << "Invalid input. Try again:";
		changeColor(15);
		std::cout << " ";
		std::cin >> word;
		verifyLength(word);
	}
}

void Game::verifyNum(int& num)
{
	//clear input to surpress that whole loop screaming invalid input lol
	std::cin.clear();
	std::cin.ignore();

	if (num <= 0) {
		//number is negative invalid
		changeColor(12);
		std::cout << "Invalid input. Try again:";
		changeColor(15);
		std::cout << " ";
		std::cin >> num;
		verifyNum(num);
	}
}

