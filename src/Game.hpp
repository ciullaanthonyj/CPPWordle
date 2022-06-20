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

//CPPWordle header
#include "Output.hpp"

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

		void clearScreen();

		void verifyLength(std::string& word);

		void verifyNum(int& num);
};


#endif