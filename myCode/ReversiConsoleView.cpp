/*
 * ReversiConsoleView.cpp
 *
 *  Created on: Nov 4, 2024
 *      Author: ngocnhat
 */
#include <iostream>
#include "ReversiConsoleView.h"
#include "ReversiBoard.h"



void ReversiConsoleView::print()
{
	std::cout<<"  ";
	for (int border=0; border< pBoard->getSize();border++){
		std::cout<<" "<< border+1 << " ";
	}
	std::cout<<std::endl;

	for (int rowIndex=0;rowIndex<pBoard->getSize();rowIndex++){

		std::cout<<rowIndex+1<<" ";
		for (int colIndex=0;colIndex< pBoard->getSize();colIndex++){
			fieldStatus piece = pBoard->checkFieldStatus(rowIndex,colIndex);
			if (piece == E){
				std::cout<<" "<<"."<<" ";
			}
			else if (piece == X){
				std::cout<<" "<<"X"<<" ";
			}
			else if (piece == O){
				std::cout<<" "<<"O"<<" ";
			}
			else if (piece == P){
				std::cout<<" "<<"="<<" ";
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<"The number of player 1's pieces: "<<
			pBoard->pieceOfPlayer(X)<<std::endl;
	std::cout<<"The number of player 2's pieces: "<<
			pBoard->pieceOfPlayer(O)<<std::endl;
}

ReversiConsoleView::ReversiConsoleView(ReversiBoard* pBoard)
{
	this->pBoard=pBoard;
}

void ReversiConsoleView::declareWinner()
{
	int playerPiece = pBoard->pieceOfPlayer(X);
	int opponentPiece = pBoard->pieceOfPlayer(O);
	if (playerPiece>opponentPiece){
		std::cout<<"Player 1 wins the game with "<<playerPiece<<
				" pieces"<<std::endl;
	}
	else if (playerPiece<opponentPiece){
		std::cout<<"Player 2 wins the game with "<<opponentPiece<<
				" pieces"<<std::endl;
	}
	else {
		std::cout<<"It's a tie! Both players have "<<playerPiece<<
				" pieces"<<std::endl;
	}

}
