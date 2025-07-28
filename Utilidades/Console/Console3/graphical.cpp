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
#include "..\..\include\define_print.h"

#define ver     "1.0"
#define prgdate "29/08/19"
#define author  "Written by claybom"
using namespace std;
int keyCode, key;

//*****************************************************************************
void clb::Graphical::box(const unsigned int &_x, const unsigned int &_y, const unsigned int &_x2, const unsigned int &_y2, char* _label) {
	//SMALL_RECT ScrollUp = {0, -1, 0, -1};
	//SetConsoleWindowInfo(hOut, TRUE, &ScrollUp);

	at(_x, _y,  'É'); // Top left corner of box
	at(_x2,_y,  '»'); // Top right corner of box
	at(_x, _y2, 'È'); // Bottom left corner of box
	at(_x2,_y2, '¼'); // Bottom right corner of box

	using std::cout;
	unsigned j, m;
	
	for(unsigned int i=_x+1; i<_x2; i++) {
		at(i,_y,  'Í'); // Top horizontol line
		at(i,_y2, 'Í'); // Bottom Horizontal line
		delay(10);
	}
	for(unsigned int i=_y+1; i<_y2; i++) {
		at(_x, i, 'º'); // Left Vertical line
		at(_x2,i, 'º'); // Right Vertical Line
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
void clb::Graphical::colourSamples() {
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
	PrintColour("Intense Cyan on yellow background.\n", BYI|FBI);
	// bg colour must be set in every call otherwise it turns back to default blk.
	PrintColour("Intense Cyan on black background.\n", FBI);
}
//*****************************************************************************
void clb::Graphical::samples(char* _str, WORD _cor1, WORD _cor2) {
	PrintColour(_str, _cor1);
	PrintColour_(_str, _cor2);
}
//*****************************************************************************
void clb::Graphical::canvas(char _fill, const WORD &_cor, const int &_left, const int &_top, const int &_right, const int &_bottom) {
	char ch[] = {_fill, 0};
	doubleBuffering(ch, _cor, 0, true, _left, _top, _right, _bottom);
}
// ***************** <<_USAGE_>> *****************
void clb::_graphical() {
	Graphical gr(90,50, "Graphical Console");

	gr.colourSamples();
	gr.setColour(FRI|BBI);
	gr.canvas(' ', BYI, 1, 1, 88, 47);
	gr.canvas(' ', BWI, 11, 17, 34, 29);
	gr.canvas(' ', BWI, 67, 17, 76, 17);
	gr.box(10,16,35,30,"Clailton F Silva");
	gr.box(66,16,77,18,"bbb");
	gr.box(0, 0, 89, 48, "The Entire Canvas");

	//gr.box(1, 1, 88, 48, "The Entire Canvas");
}
