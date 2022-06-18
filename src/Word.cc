/*
 *  File: Word.cc
 *  Desc: functions for words
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

void Word::changeColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Word::verifyLength(string& word)
{
	cin.clear();
	cin.ignore();
	if (word.size() != 5) {
		changeColor(12);
		cout << "Invalid input. Try again:";
		changeColor(15);
		cout << " ";
		cin >> word;
		verifyLength(word);
	}
}

void Word::verifyNum(int& num)
{
	if (num <= 0) {
		//number is negative invalid
		cin.clear();
		cin.ignore();
		changeColor(12);
		cout << "Invalid input. Try again:";
		changeColor(15);
		cout << " ";
		cin >> num;
		verifyNum(num);
	}
}

void Word::convertToVec(std::string oldString, std::vector<char>& newVector)
{
	for (int i = 0; i < oldString.size(); i++) {
		char currentChar = toupper(oldString[i]);
		newVector.begin();
		newVector.push_back(currentChar);
	}
}

void Word::displayHeader() {
	changeColor(11);
	cout
		<< "################################################################################\n"
		<< "#        CPPWordle                Version 1                Anthony Ciulla      #\n"
		<< "################################################################################\n"
		<<
		endl;
	changeColor(15);
	//Program Description
	cout << endl;
	cout
		<< "Description:\n"
		<< "To play Wordle, you first will be asked to enter a number reflecting\n"
		<< "the number of attempts the player will have to guess the obejctive word\n"
		<< "then, you will then be asked to submit a five character word to try to guess.\n"
		<< "\nLegend:\n"
		<< "After you guess a word, you will have it redisplayed to you with the colors\n"
		<< "indicating if it was correct or wrong.\n"
		<<
		endl;
	changeColor(10);
	cout
		<< "This color indicates the letter is in the correct place and spot in the word"
		<<
		endl;
	changeColor(14);
	cout
		<< "This color indicates the letter appears in the word but not in the current spot"
		<<
		endl;
	changeColor(8);
	cout
		<< "This color indicates the letter does not appear in the word\n"
		<<
		endl;
	changeColor(15);
}


