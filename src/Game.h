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

#include <iostream>
#include <vector>
#include <string>
#include "Word.h"
#include <map>

using namespace std;

class Game {
	protected:

		string gameWord;
		string playerWord;
		int maxNumberAttempts;
		int attemptNumber;
		vector<char> gameWordVector;
		vector<char> playerWordVector;

	public:

		void setGameWord(string gameWord);

		void setMaxAttempts(int maxAttempts);

		void setPlayerWord(string playerWord);

		void setGameWordVector(string gameWord, vector<char>& gameWordVector);

		void setPlayerWordVector(string playerWord, vector<char>& playerWordVector);

		vector<char> getGameWordVector();

		vector<char> getPlayerWordVector();

		int getMaxAttempts();

		bool compareChar(vector<char>& i, vector<char>& j);
		
		void includesChar(char i, vector<char> gameWordVector);

		void clearScreen();

		void setAttemptNumber(int attemptNumber);

		int getAttemptNumber();

		void getGameWord();

		void resetAttemptNumber();

		void resetGameWord();

		void resetPlayerWord();

};

