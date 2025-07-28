#pragma once
#include <windows.h>
#include <iostream>
#include "console.h"

static void _readConsole() {
	using namespace std;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char   buf[7];
    COORD  pos;
    DWORD  read, written;
	WORD   attribute;

	cout << "A line of little consequence." << endl;
// Reading from console:
	pos.X = 0;
	pos.Y = 0;
    ReadConsoleOutputCharacter(hOut,	// Handle to output buffer.
                               buf,		// Ptr to char storing place.
                               5,		// Number o'chars to read.
                               pos,		// Starting point.
                               &read);	// Actually read.
	buf[6] = 0; // Zero terminated string.
	cout << "Char at (0,0) is " << buf << endl;

    pos.X = 10;
    ReadConsoleOutputCharacter(hOut, buf, 6, pos, &read);

	buf[6] = 0; // Zero terminated string.
	cout << "6 chars starting from (10,0):" << buf << endl;

// Reading attibutes:
    SetConsoleTextAttribute(hOut, FY);
    cout << "This text is yellow." << endl;

    pos.X = 4;
    pos.Y = 3;
    ReadConsoleOutputAttribute(hOut,		// Standard handle.
                               &attribute,	// Atribute code (WORD type masking bits).
                               1,			// lenght
                               pos,			// position (4,0)
                               &read);		// Number of attributes read.

	cout << "Attribute is " << attribute << endl;

// Writing to console:
	pos.X = pos.Y = 10;

	SetConsoleCursorPosition(hOut, pos);
    FillConsoleOutputCharacter(hOut,		// Handle to output buffer.
                               'X',			// Char to be written.
                               15,			// 15 x 'X' = XXXXXXXXXXXXXXX
                               pos,			// Starting position.
                               &written);	// Actually written.
}