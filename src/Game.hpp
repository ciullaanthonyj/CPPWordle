/*
 *  File: game.h
 *  Desc: main header file for game
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

#pragma once

#ifndef GAME_H

#define GAME_H

//library headers
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#endif


//Functions 

//Change color of output. Need to do this with an enum or something
void changeColor(int color){
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

//Takes a string and iterates over it converting it to a vector
void convertToVec(std::string oldString, std::vector<char>& newVector){
	for (auto& num : oldString) {
		newVector.push_back(toupper(num));
	}
}

//Header file for game
void displayHeader() {
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

bool compareChar(std::vector<char>& playerWord, std::vector<char>& GameWord){
	
	//initialize a temp vector to hold the correct characters,
	//so that we can test against them. This is for the common
	//case of the word being 'hyper' and the guess being
	//'reset'
	std::vector<char> correct;

	//Exact Match
	if (playerWord == GameWord) {
		changeColor(10); //green

		for (auto& num : playerWord) {
			std::cout << num;
		}
		changeColor(15);
		return true;
	}
	
	//Lets test for maybes and nos
	else {
		//First we will check if any are correct and push them into the correct vector for later
		for (int i = 0; i < 5; i++) {
			if (playerWord[i] == GameWord[i]) {
				correct.push_back(playerWord[i]);
			}
		}
		//Check for correct char
		for (int i = 0; i < 5; i++) {
			if (playerWord[i] == GameWord[i]) {
				changeColor(10); //green
				std::cout << playerWord[i];
				changeColor(15); //white
			}
			//Check for correct char wrong place
			else if (find(GameWord.begin(), GameWord.end(), playerWord[i]) != GameWord.end()) {
				//Make sure that the char isn't correct somewhere in the word
				if (find(correct.begin(), correct.end(), playerWord[i]) == correct.end()) {
					changeColor(14); //yellow
					std::cout << playerWord[i];
					changeColor(15); //white
				}
				//if it is print it gray
				else {
					changeColor(8); //gray
					std::cout << playerWord[i];
					changeColor(15); //white
				}
			}
			//lastly wrong char doesn't belong in word.
			else {
				changeColor(8); //gray
				std::cout << playerWord[i];
				changeColor(15); //white
			}
		}
		return false;
	}
}

//lazy function to clear the screen
void clearScreen(){
	for (int i = 0; i < 50; i++) {
		std::cout << "\n" << std::endl;
	}
}

//Verify's the length of the word
void verifyLength(std::string& word){
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

//!!Verifys the input is a number
void verifyNum(int& num){
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