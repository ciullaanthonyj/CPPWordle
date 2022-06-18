/*
 *  File: Game.cc
 *  Desc: functions for game
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

Game g;


bool Game::compareChar(std::vector<char>& i, std::vector<char>& j)
{ 
	//initialize a temp vector to hold the correct characters,
	//so that we can test against them. This is for the common
	//case of the word being 'hyper' and the guess being
	//'reset'

	std::vector<char> correct;

	if (i == j) {
		g.changeColor(10); //green
		
		for (auto& num : i) {
			std::cout << num;
		}
		g.changeColor(15);
		return true;
	}
	else {
		for (int k = 0; k < 5; k++) {
			if (i[k] == j[k]) {
				correct.push_back(i[k]);
			}
		}

		for (int k = 0; k < 5; k++) {
			if (i[k] == j[k]) {
				g.changeColor(10); //green
				std::cout << i[k];
				g.changeColor(15); //white
			}
			else if (find(j.begin(), j.end(), i[k]) != j.end()) {
				if (find(correct.begin(), correct.end(), i[k]) == correct.end()) {
					g.changeColor(14); //yellow
					std::cout << i[k];
					g.changeColor(15); //white
				}
				else {
					g.changeColor(8); //gray
					std::cout << i[k];
					g.changeColor(15); //white
				}
			}
			else {
				g.changeColor(8); //gray
				std::cout << i[k];
				g.changeColor(15); //white
			}
		}
		return false;
	}
}

void Game::includesChar(char i, std::vector<char> gameWordVector)
{
	if (find(gameWordVector.begin(), gameWordVector.end(), i) != gameWordVector.end()) {
		//character exists in vector
	}
}

void Game::clearScreen()
{
	for (int i = 0; i < 50; i++) {
		std::cout << "\n" << std::endl;
	}
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

void Game::verifyLength(std::string& word)
{
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

void Game::convertToVec(std::string oldString, std::vector<char>& newVector)
{
	for (auto& num : oldString) {
		newVector.push_back(toupper(num));
	}
}

void Game::displayHeader() {
	changeColor(11);
	std::cout
		<< "################################################################################\n"
		<< "#        CPPWordle                Version 1.1              Anthony Ciulla      #\n"
		<< "################################################################################\n"
		<<
		std::endl;
	changeColor(15);
	//Program Description
	std::cout << std::endl;
	std::cout
		<< "Description:\n"
		<< "To play Wordle, you first will be asked to enter a number reflecting\n"
		<< "the number of attempts the player will have to guess the obejctive word\n"
		<< "then, you will then be asked to submit a five character word to try to guess.\n"
		<< "\nLegend:\n"
		<< "After you guess a word, you will have it redisplayed to you with the colors\n"
		<< "indicating if it was correct or wrong.\n"
		<<
		std::endl;
	changeColor(10);
	std::cout
		<< "This color indicates the letter is in the correct place and spot in the word"
		<<
		std::endl;
	changeColor(14);
	std::cout
		<< "This color indicates the letter appears in the word but not in the current spot"
		<<
		std::endl;
	changeColor(8);
	std::cout
		<< "This color indicates the letter does not appear in the word\n"
		<<
		std::endl;
	changeColor(15);
}