#include "Board.h"
#include "_colour.h"
using namespace std;

void Board::fillGrid() {
	for(int i = 0; i < 8; i++)
		for(int i2 = 0; i2 < 8; i2++)
			grid[i][i2] = i;
}
void Board::lineThick8(bool whiteGap, int line) {
	SetConsoleTextAttribute(hOut, FWI);

	unsigned char blk = 219;
	char blkPiece = 'x';
	char whtPiece = '.';
	char current = whtPiece;
	for(int gap = 0; gap < 8; gap++) {
		//cells++;
		for(int pix = 0; pix < 7; pix++) {
			if(whiteGap) 
				cout << " ";
			else {
				if(line == 1) {
					if(pix == 0)	  cout << current;
					else if(pix == 1) cout << current;
					else if(pix == 2) cout << current;
					else if(pix == 3) cout << current;
					else if(pix == 4) cout << current;
					else if(pix == 5) cout << current;
					else if(pix == 6) cout << current;
				} else
					std::cout << blk;
			}
		}
		whiteGap =! whiteGap;
	}
}
void Board::Paint() {
	bool whiteGap = false;
	int cells = 0;
	for(int line = 0; line < 8; line++) {
		whiteGap = !whiteGap; // chessboard
		for(int lineThick = 0; lineThick < 5; lineThick++) {
			lineThick8(whiteGap, lineThick);
			cout << endl;
		}
	}
	cout << "cells = " << cells << endl;
}

void Board::DrawSquare(int line, int column, int x, int y) {
    COORD Pos; // COORD is a simple WINDOWS structure containing x and y SHORT types*.
	Pos.X = x;
	Pos.Y = y;

    SetConsoleCursorPosition(hOut, Pos);

	unsigned char blk = 219;
	int cells = 0;
	for(int i=0; i<line; i++) {
		for(int i2=0; i2<column; i2++) {
			cout << blk;
			cells++;
		}
		cout << endl;
	}
	cout << "cells = " << cells << endl;
}

Board::Board() {
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	memset(grid, 0, 256);
	fillGrid();
	DrawSquare(5, 8, 20); // line x column, x, y
//	Paint();
}