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

INPUT_RECORD input_record;

//*****************************************************************************
void clb::Graphical::box(const unsigned int &_x, const unsigned int &_y, const unsigned int &_x2, const unsigned int &_y2, char* _label) {
	using std::cout;
	unsigned j, m;
	m=(_x2-_x);		  // differential
	j=m/8;			  // adjust
	j=j-1;			  // more adjustment
	at(_x, _y,  'É'); // Top left corner of box
	at(_x2,_y,  '»'); // Top right corner of box
	at(_x, _y2, 'È'); // Bottom left corner of box
	at(_x2,_y2, '¼'); // Bottom right corner of box

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
void clb::Graphical::teste() {
	//setColour(FRI|BBI);
	//box(10,16,35,30,"Clailton F Silva");
	//box(66,16,77,18,"bbb");
}
