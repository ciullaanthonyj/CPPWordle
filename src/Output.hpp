/*
 *  File: Output.hpp
 *  Desc: main header file for output
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

#ifndef OUTPUT_H

#define OUTPUT_H

#include "Game.hpp"


enum class COLORS : int
{
	GREY = 0,
	GREEN = 1,
	BLUE = 2,
	RED = 3,
	YELLOW = 4,
	WHITE = 5,
};

class Output {
	public:
		const double VERSION = 2.0;

		void DisplayHeader();

		void changeColor(COLORS newColor);
};

#endif
