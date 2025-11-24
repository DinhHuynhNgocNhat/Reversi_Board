// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here

// Main program
int main ()
{
    // TODO: Add your program code here
	ReversiBoard board;
	ReversiConsoleView  view(&board);
	cout << "Reversi Board by Nhat Dinh Huynh Ngoc " << endl;
	int skip=0;
	int turn=1;
	fieldStatus player=X;

	while (true){
		fieldStatus opponent=(player==X)?O:X;
		cout<<endl;
		cout<<"Turn "<<turn<<endl;
		board.clearPrediction();
		for (int x=0;x<board.getSize();x++){
			for (int y=0;y<board.getSize();y++){
				board.predictField(x,y,player);
			}
		}
		view.print();
		if(board.pieceOfPlayer(P)==0){
			if (skip!=2&& board.pieceOfPlayer(E)!=0){
				cout<<"Player "<<player<<" has no move"<<endl;
				cout<<"Skip to player "<<opponent<<"'s turn"<<endl;
				skip++;
				turn++;
				player = (player==X)?O:X;
			}
			else if (skip==2 || board.pieceOfPlayer(E)==0){
				view.declareWinner();
				cout << "End of the game!!!";
				break;
			}
		}

		else {
			skip=0;
			cout<<"Player "<<player<<" enter your move: "<<endl;
			int inRow,inCol;
			cout << "Enter row: ";
			cin >> inRow;
			cout << "Enter column: ";
			cin >> inCol;

			if (board.isFieldValid(inRow-1,inCol-1)==false){
				cout<<"Invalid move!!!"<<endl;
				cout<<"Player "<< player << " enter again your move (row and"
						" column) or enter 'pass' to skip your turn: ";
				continue;
			}
			else {
				board.insertField(inRow-1,inCol-1,player);
				if(board.checkFieldStatus(inRow-1,inCol-1)==player){
					player = (player==X)?O:X;
					turn++;
				}
				else {
					continue;
				}
			}
		}
	}
	return 0;
}
