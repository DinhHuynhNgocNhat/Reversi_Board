/*
 * ReversiBoard.cpp
 *
 *  Created on: Nov 3, 2024
 *      Author: ngocnhat
 */
#include <iostream>
#include "ReversiBoard.h"

ReversiBoard::ReversiBoard()
{
	for(int rowIndex = 0; rowIndex < boardSize; rowIndex++){
		for (int colIndex = 0; colIndex < boardSize; colIndex++){
			board[rowIndex][colIndex] = E;
		}
	}

	board[boardSize/2-1][boardSize/2-1] = O;
	board[boardSize/2][boardSize/2] = O;
	board[boardSize/2-1][boardSize/2] = X;
	board[boardSize/2][boardSize/2-1] = X;
}

bool ReversiBoard::isFieldValid(int row, int col)
{
	if ( row<0 || row>(boardSize-1) || col<0 || col>(boardSize-1)){
		return false;
	}
	else if (board[row][col] == X || board[row][col] == O){
		return false;
	}
	else
		return true;
}

fieldStatus ReversiBoard::checkFieldStatus(int row, int col)
{
	return board[row][col];
}

void ReversiBoard::insertField(int row, int col, enum fieldStatus setPiece)
{
	if (isFieldValid(row,col)==true){
		int dxRow[] = {-1,-1,-1,0,0,1,1,1};
		int dyCol[] = {-1,0,1,-1,1,-1,0,1};

		fieldStatus opponent = (setPiece==X)?O:X;
		int checkDirection=0;

		for (int direct=0; direct<8; direct++){
			int x = row + dxRow[direct];
			int y = col + dyCol[direct];
			bool findOpponent=false;
			int count=0;
			int turnOver[8][2];

			while (x>=0 && x<boardSize && y>=0 && y<boardSize){
				if(board[x][y]==opponent){
					turnOver[count][0]=x;
					turnOver[count][1]=y;
					findOpponent = true;
					count++;
				}
				else if (board[x][y]==setPiece && findOpponent){
					board[row][col]=setPiece;
					for(int countPiece=0; countPiece<count; countPiece++){
						board[turnOver[countPiece][0]][turnOver[countPiece][1]]
													   =setPiece;
					}
					break;
				}
				else {
					checkDirection++;
					break;
				}
				x+=dxRow[direct];
				y+=dyCol[direct];
			}
		}
		if(checkDirection==8){
			std::cout<<"Invalid move!!!"<<std::endl;
		}
	}
	else {
		std::cout<<"Invalid move!!!"<<std::endl;
	}
}

void ReversiBoard::predictField(int row, int col, enum fieldStatus player)
{
	if (isFieldValid(row,col)==true){
		int dxRow[] = {-1,-1,-1,0,0,1,1,1};
		int dyCol[] = {-1,0,1,-1,1,-1,0,1};

		fieldStatus opponent = (player==X)?O:X;
		bool isValidMove = false;

		for (int direct=0; direct<8; direct++){
			int x = row + dxRow[direct];
			int y = col + dyCol[direct];
			bool findOpponent=false;

			while (x>=0 && x<boardSize && y>=0 && y<boardSize){
				if(board[x][y]==opponent){
					findOpponent = true;
				}
				else if (board[x][y]==player && findOpponent){
					isValidMove = true;
					break;
				}
				else {
					break;
				}
				x+=dxRow[direct];
				y+=dyCol[direct];
			}
	        if (isValidMove) {
	            board[row][col] = P;
	            break;
	        }
		}
	}
}

void ReversiBoard::clearPrediction()
{
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            if (board[row][col] == P) {
                board[row][col] = E;
            }
        }
    }
}

int ReversiBoard::getSize()
{
	return boardSize;
}

int ReversiBoard::pieceOfPlayer(enum fieldStatus player)
{
	int piece=0;
	for (int rowIndex=0;rowIndex<boardSize;rowIndex++){
		for (int colIndex=0;colIndex<boardSize;colIndex++){
			if (board[rowIndex][colIndex]==player){
				piece++;
			}
		}
	}
	return piece;
}
