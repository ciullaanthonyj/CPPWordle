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
#include <iostream>
#include <map>
#include <string>
#include <vector>

#endif



class Game {
	public:

		bool compareChar(std::vector<char>& i, std::vector<char>& j);
		
		void includesChar(char i, std::vector<char> gameWordVector);

		void clearScreen();

		void changeColor(int color);

		void verifyLength(std::string& word);

		void verifyNum(int& num);

		void convertToVec(std::string oldString, std::vector<char>& newVector);

		void displayHeader();

};

