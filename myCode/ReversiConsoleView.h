/**
 * @file ReversiConsoleView.h
 * @brief  Defines the console-based view for displaying the board.
 *
 * This file contains the definition of the ReversiConsoleView class, which
 * provides methods for displaying the current status of the Reversi board to
 * the console.
 *
 *  Created on: Nov 4, 2024
 *      Author: ngocnhat
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_
#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Displays the Reversi board in a console view.
 *
 * This class is responsible for presenting the current state of the game to the
 * console, allowing players to see the board and understand the game state.
 */
class ReversiConsoleView
{
private:
	ReversiBoard* pBoard; /**< Pointer to the Reversi board*/

public:
	/**
	 * @brief Constructs a ReversiConsoleView with a pointer to the game board.
	 */
	ReversiConsoleView(ReversiBoard* pBoard);

	/**
	 * @brief Prints the current state of the board to the console
	 *
	 * @This function output the board layout, showing the position of players's
	 * piece as well as empty fields
	 */
	void print();

	/**
	 * @brief Declare the winner of the game.
	 *
	 * @This function declare the winner.
	 */
	void declareWinner();
};

#endif /* REVERSICONSOLEVIEW_H_ */
