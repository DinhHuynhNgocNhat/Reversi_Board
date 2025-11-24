/**
 * @file ReversiBoard.h
 * @brief  Defines the Reversi board and its operations.
 *
 * This file contains the definition of the ReversiBoard class, which manages
 * the state of the Reversi game board and provides methods for making moves,
 * checking the valid of moves, and retrieving the status of board fields.
 *
 *  Created on: Nov 3, 2024
 *      Author: ngocnhat
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @enum fieldStatus
 * @brief Represents the status of a field on the board.
 */
enum fieldStatus {
	E, /**< Empty field. */
	X, /**< Field occupied by player X (One). */
	O,  /**< Field occupied by player O (Two). */
	P  /**< Field predicted as a valid move for the player. */
};

/**
 * @class ReversiBoard
 * @brief Manage the game board for a game.
 *
 * This class provides functionality to initialize the board, validate moves,
 * retrieve field statuses, place pieces, clear predictions, and determine the
 * number of pieces for each player.
 */
class ReversiBoard
{
private:
	static const int boardSize=8;
	fieldStatus board[boardSize][boardSize];

public:
	/**
	 * @brief Construct a new board with the initial setup.
	 */
	ReversiBoard();

	/**
	 * @brief Checks if a move to a given fields is valid.
	 *
	 * @param row The row index of the field.
	 * @param col The column index of the field.
	 * @return true if the move is valid, false otherwise.
	 */
	bool isFieldValid(int row, int col);

	/**
	 * @brief Return the status of the specified field.
	 *
	 * @param row The row index of the field.
	 * @param col The column index of the field.
	 * @return The status of the field (E, X, O, P).
	 */
	fieldStatus checkFieldStatus(int row, int col);

	/**
	 * @brief Places a piece on the board and flips the opponent's pieces
	 * accordingly.
	 *
	 * @param row The row index of the field.
	 * @param col The column index of the field.
	 * @param setPiece the piece to place (X or O).
	 */
	void insertField(int row, int col, enum fieldStatus setPiece);

    /**
     * @brief Predicts valid moves for a player by marking fields as P.
     *
     * This method identifies potential moves where the player can flip
     * opponent pieces and marks them on the board.
     *
     * @param row The row index to check for predictions.
     * @param col The column index to check for predictions.
     * @param player The player making the move (X or O).
     */
	void predictField(int row, int col, enum fieldStatus player);

    /**
     * @brief Clears all predicted moves from the board.
     *
     * Fields marked as P are reset to E (empty).
     */
	void clearPrediction();
	/**
	 * @brief return the size of board.
	 *
	 * @return The size of board.
	 */
	int getSize();

	/**
	 * @brief return the number of player's pieces.
	 * @param player The player (X or O).
	 * @return The number of player's pieces.
	 */
	int pieceOfPlayer(enum fieldStatus player);
};

#endif /* REVERSIBOARD_H_ */
