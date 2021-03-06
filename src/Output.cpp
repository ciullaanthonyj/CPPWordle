/*
 *  File: Output.cpp
 *  Desc: cpp file dealing with output class functions
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

#include "Output.hpp"

Game mygame;

void Output::DisplayHeader()
{
	changeColor(COLORS::BLUE);
	std::cout
		<< "################################################################################\n"
		<< "#        CPPWordle                Version " << Output::VERSION << "              Anthony Ciulla      #\n"
		<< "################################################################################\n"
		<<
		std::endl;
	changeColor(COLORS::WHITE);
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
	changeColor(COLORS::GREEN);
	std::cout
		<< "This color indicates the letter is in the correct place and spot in the word"
		<<
		std::endl;
	changeColor(COLORS::YELLOW);
	std::cout
		<< "This color indicates the letter appears in the word but not in the current spot"
		<<
		std::endl;
	changeColor(COLORS::GREY);
	std::cout
		<< "This color indicates the letter does not appear in the word\n"
		<<
		std::endl;
	changeColor(COLORS::WHITE);
}

void Output::changeColor(COLORS newColor)
{
	switch (newColor)
	{
	case COLORS::GREY:
		std::cout << ESC << "[38;2;192;192;192m";
		break;
	case COLORS::GREEN:
		std::cout << ESC << "[38;2;0;255;0m";
		break;
	case COLORS::BLUE:
		std::cout << ESC << "[38;2;0;204;204m";
		break;
	case COLORS::RED:
		std::cout << ESC << "[38;2;255;0;0m";
		break;
	case COLORS::YELLOW:
		std::cout << ESC << "[38;2;255;255;0m";
		break;
	case COLORS::WHITE:
		std::cout << ESC << "[38;2;255;255;255m";
		break;
	}
}

