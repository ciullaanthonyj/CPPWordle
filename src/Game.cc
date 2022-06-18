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

#include "Game.h"

Game g;
Word w;

void Game::setGameWord(string gameWord) {
	g.gameWord = gameWord;
	setGameWordVector(gameWord, g.gameWordVector);
}

void Game::setMaxAttempts(int maxAttempts) {
	g.maxNumberAttempts = maxAttempts;
}

void Game::setPlayerWord(string playerWord)
{
	g.playerWord = playerWord;
	setPlayerWordVector(playerWord, g.playerWordVector);
}

void Game::setGameWordVector(string gameWord, std::vector<char>& gameWordVector)
{
	w.convertToVec(gameWord, gameWordVector);
}

void Game::setPlayerWordVector(string playerWord, std::vector<char>& playerWordVector)
{
	playerWordVector.clear();
	w.convertToVec(playerWord, playerWordVector);
}

vector<char> Game::getGameWordVector()
{
	//cout << g.gameWordVector[iterator];
	return g.gameWordVector;
}

vector<char> Game::getPlayerWordVector()
{
	//cout << g.playerWordVector[iterator];
	return g.playerWordVector;
}

int Game::getMaxAttempts()
{
	return g.maxNumberAttempts;
}

bool Game::compareChar(vector<char>& i, vector<char>& j)
{ //player == i game == j

	vector<char> correct;
	//compare the two vectors
	//correct
	char dups[5];

	if (i == j) {
		w.changeColor(10); //green
		for (int k = 0; k < 5; k++) {
			cout << i[k];
		}
		w.changeColor(15);
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
				w.changeColor(10); //green
				cout << i[k];
				w.changeColor(15); //white
			}
			else if (find(j.begin(), j.end(), i[k]) != j.end()) {
				if (find(correct.begin(), correct.end(), i[k]) == correct.end()) {
					w.changeColor(14); //yellow
					cout << i[k];
					w.changeColor(15); //white
				}
				else {
					w.changeColor(8); //gray
					cout << i[k];
					w.changeColor(15); //white
				}
			}
			else {
				w.changeColor(8); //gray
				cout << i[k];
				w.changeColor(15); //white
			}
		}
		return false;
	}
}

void Game::includesChar(char i, vector<char> gameWordVector)
{
	if (find(gameWordVector.begin(), gameWordVector.end(), i) != gameWordVector.end()) {
		//character exists in vector
	}
}

void Game::clearScreen()
{
	for (int i = 0; i < 50; i++) {
		cout << "\n" << endl;
	}
}

void Game::setAttemptNumber(int attemptNumber)
{
	g.attemptNumber = g.attemptNumber + attemptNumber;
}

int Game::getAttemptNumber()
{
	return g.attemptNumber;
}

void Game::getGameWord()
{
	cout << g.gameWord;
}

void Game::resetAttemptNumber()
{
	g.attemptNumber = 0;
}

void Game::resetGameWord()
{
	g.gameWordVector.clear();
	g.gameWord = "";
}

void Game::resetPlayerWord()
{
	g.playerWordVector.clear();
	g.playerWord = "";
}
