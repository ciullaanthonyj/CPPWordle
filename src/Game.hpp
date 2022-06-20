/*
 *  File: Game.hpp
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
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//Const
const std::string ESC = "\033";

//Classes

enum class COLORS : int
{
	BLACK = 0,
	DARKBLUE = 1,
	DARKGREEN = 2,
	DARKCYAN = 3,
	DARKRED = 4,
	DARKMAGENTA = 5,
	DARKYELLOW = 6,
	WHITE = 7,
	GREY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	MAGENTA = 13,
	YELLOW = 14,
	LIGHTGREY = 15,
};

class Game {
	private:

		std::vector<char> SafeGameWord;

		std::vector<char> SafePlayerWord;

		int SafeMaxRounds = 0;

		int SafeRoundNumber = 0;

	public:

		void ConvertToVec(std::string OldWord, std::vector<char>& NewVector);

		void SetGameWord(std::vector<char> GameWord);

		void SetPlayerWord(std::vector<char> PlayerWord);

		void SetMaxRounds(int MaxRounds);

		void IncRoundNumber();

		bool CompareWords();

		void ResetVariables();

		int GetMaxRounds();

		int GetRoundNumber();

		std::string GetGameWord();

		void changeColor(COLORS newColor);

		void clearScreen();

		void verifyLength(std::string& word);

		void verifyNum(int& num);
};


#endif