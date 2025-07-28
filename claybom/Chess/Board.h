#pragma once
#include <windows.h>
#include <iostream>

class Board {
	HANDLE hOut;
	int  board[8][8];
	void fillGrid();	
	void lineThick8(bool whiteGap, int line);
	void Paint();
public:
	Board();
	~Board();
	void DrawCell(int line=0, int column=0, int x=0, int y=0);
	void showGrid();
};