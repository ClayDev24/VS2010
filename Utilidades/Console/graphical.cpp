#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include "console.h"
#include "graphical.h"
#include "defines.h"

#define ver     "1.0"
#define prgdate "29/08/19"
#define author  "Written by claybom"
using namespace std;
int keyCode, key;

//*****************************************************************************
void utils::Graphical::box(char* _label, int _x, int _y, int _x2, int _y2) {
	//SMALL_RECT ScrollUp = {0, -1, 0, -1};
	//SetConsoleWindowInfo(hOut, TRUE, &ScrollUp);
	setlocale(LC_ALL, ""); // habilita a acentuação para o português
	if(!_y2) { // entire canvas
		GetConsoleScreenBufferInfo(hOut, &BSInfo);
		_y2 = BSInfo.srWindow.Bottom-1; 
		_x  = BSInfo.srWindow.Left;
		_x2 = BSInfo.srWindow.Right;		 
		_y  = BSInfo.srWindow.Top;
	}

	at(_x, _y,  '<'); // Top left corner of box
	at(_x2,_y,  '>'); // Top right corner of box
	at(_x, _y2, '<'); // Bottom left corner of box
	at(_x2,_y2, '>'); // Bottom right corner of box

	using std::cout;
	unsigned j, m;
	
	for(unsigned int i=_x+1; i<_x2; i++) {
		at(i,_y,  '='); // Top horizontol line
		at(i,_y2, '='); // Bottom Horizontal line
		delay(10);
	}
	for(unsigned int i=_y+1; i<_y2; i++) {
		at(_x, i, '|'); // Left Vertical line
		at(_x2,i, '|'); // Right Vertical Line
		delay(10);
	}

	m = (_x2-_x);		  // differential
	j = m/8;			  // adjust
	j = j-1;			  // more adjustment
	gotoxy(_x+j,_y);
	cout << _label;
	//gotoxy(1,26);
}
//*****************************************************************************
void utils::Graphical::colourSamples() {
	// Foreground colours:
	samples("Red     ", FR, FRI);
	samples("Green   ", FG, FGI);
	samples("Blue    ", FB, FBI);
	samples("Yellow  ", FY, FYI);
	samples("Cyan    ", FC, FCI);
	samples("Magenta ", FM, FMI);
	samples("White   ", FW, FWI);
	// Background colours:
	samples("Red     ", BR, BRI);
	samples("Green   ", BG, BGI);
	samples("Blue    ", BB, BBI);
	samples("Yellow  ", BY, BYI);
	samples("Cyan    ", BC, BCI);
	samples("Magenta ", BM, BMI);
	samples("White   ", BW, BWI);
	// Foreground & background at the same time:
	utils::PrintColour("Intense Cyan on yellow background.\n", BYI|FBI);
	// bg colour must be set in every call otherwise it turns back to default blk.
	utils::PrintColour("Intense Cyan on black background.\n", FBI);
}
//*****************************************************************************
void utils::Graphical::samples(char* _str, WORD _cor1, WORD _cor2) {
	utils::PrintColour(_str, _cor1);
	utils::PrintColour_(_str, _cor2);
}
//*****************************************************************************
void utils::Graphical::canvas(char _fill, const WORD &_cor, int _left, int _top, int _right, int _bottom) {
	char ch[] = {_fill, 0};
	if(!_bottom) { // entire canvas
		GetConsoleScreenBufferInfo(hOut, &BSInfo);
		_bottom = BSInfo.srWindow.Bottom-2; 
		_left   = BSInfo.srWindow.Left+1;
		_right  = BSInfo.srWindow.Right-1;		 
		_top    = BSInfo.srWindow.Top+1;
	}
	//P_(_bottom)
	//P_(_left)
	//P_(_right)
	//P_(_top)
	//system("pause");
	doubleBuffering(ch, _cor, 0, true, _left, _top, _right, _bottom);
}
// ***************** <<_USAGE_>> *****************
void utils::_graphicalUsage() {
	Graphical gr(90, 50, "Graphical Console");

	gr.colourSamples();
	gr.setColour(FRI|BBI);
	//gr.canvas(' ', BB, 1, 1, 88, 47);
	gr.canvas(' ', BB);
	gr.canvas(' ', BWI, 11, 17, 34, 29);
	gr.canvas(' ', BWI, 67, 17, 76, 17);
	gr.box("Clailton F Silva", 10,16,35,30);
	gr.box("bbb", 66,16,77,18);
	gr.box("The Entire Canvas");
}
