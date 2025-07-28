#include <iostream>
#include <stdlib.h>
#include <conio.h> // getche()
#include <time.h>  // time();
#include "virtualKeyCodes.h" // Events()
#include "defines.h"
#include "..\Utilidades\_require.h"
#include "console.h"
#define _LG_MONITOR_    // 320 x 84
//#define _FULHD_MONITOR_ // 240 X 84
using namespace std;

void utils::Console::displayInfo() {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	P_(BSInfo.dwSize.X)		 
	P_(BSInfo.dwSize.Y)		 
	P_(BSInfo.dwMaximumWindowSize.X)
	P_(BSInfo.dwMaximumWindowSize.Y)
	P_(BSInfo.srWindow.Bottom) 
	P_(BSInfo.srWindow.Left) 
	P_(BSInfo.srWindow.Right)		 
	P_(BSInfo.srWindow.Top)
	P_(BSInfo.dwCursorPosition.X)
	P_(BSInfo.dwCursorPosition.Y)
	P_(BSInfo.wAttributes)
}
//*****************************************************************************
void utils::Console::chores() {
	hOut   = GetStdHandle(STD_OUTPUT_HANDLE);
	hIn    = GetStdHandle(STD_INPUT_HANDLE);
	hError = GetStdHandle(STD_ERROR_HANDLE);
	setlocale(LC_ALL, ""); // habilita a acentuação para o português
	//text2 = new CHAR_INFO[220*84];//matrix];
	swap = false;

	if(hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) 
		MyErrorExit("GetStdHandle: Invalid Handle Error");
	// Windows10 Mouse input:
	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT);
	if(! SetConsoleMode(hIn, ENABLE_EXTENDED_FLAGS))
		MyErrorExit("SetConsoleMode error");
	if(!SetConsoleMode(hIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
		MyErrorExit("SetConsoleMode error");
}
//*****************************************************************************
utils::Console::Console() {
	chores();
	DS_("Console()...")
}
//*****************************************************************************
utils::Console::Console(const int &_x, const int &_y, const char* _str) {
	chores();
	SetConsoleTitle(_str);
	setWindowSize(_x, _y);
	DS_("Console(int, int, char)...")
}
//*****************************************************************************
void utils::Console::delay(const int &_mili) {
	clock_t t1;
	t1 = clock();
	while(clock()-t1 < _mili) {}
}
//*****************************************************************************
void utils::Console::boundaries(int &_x, int &_y) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	_x = BSInfo.srWindow.Right;
	_y = BSInfo.srWindow.Bottom;
}
//*****************************************************************************
void utils::Console::setMinMax(int &_x, int &_y, const int &_mode) {
	int MinX, MinY, MaxX, MaxY;
	if(_mode == buffer) {
		MinX = 15;
		MinY = 2;
		MaxX = 32766;
		MaxY = 32766;
	} else if(_mode == window) {
		MinX = 2;
		MinY = 2;
		MaxX = 240;
		MaxY = 84;
	#ifdef _LG_MONITOR_
		MaxX = 320;
	#endif
	}
	if(_x > MaxX) _x = MaxX;
	if(_y > MaxY) _y = MaxY;
	if(_x < MinX) _x = MinX;
	if(_y < MinY) _y = MinY;	
} 
//*****************************************************************************
int utils::Console::setBuffer(int _x, int _y, bool windowResize) {
	// MIN and MAX buffer sizes:
	setMinMax(_x, _y, buffer);
	// Get the actual size of the window:
	int xWnd, yWnd;
	boundaries(xWnd, yWnd);
	// Min buffer size (in buffer resize case only - windowResize = false):
	if(_x <= xWnd) xWnd = _x;
	if(_y <= yWnd) yWnd = _y;

	setWindow(0,0);
	COORD bufSz  = {_x, _y};
	//SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, &bufSz);
	if(!SetConsoleScreenBufferSize(hOut, bufSz)) {
		int error = GetLastError();
		DS("Buffer resizin'...")
#ifdef DEBUG
		prtColorReturn("FAILED: ", FRI);
#endif
		cout << error << endl;
		return error;
	} else {
		DS("Buffer resizin'...")
#ifdef DEBUG
		prtColorReturn("SUCCEED!\n", FGI);
#endif
	}
	if(windowResize)
		setWindow(_x, _y);
	else
		setWindow(xWnd, yWnd);
	// Teste:
//#define DEBUG_ON
#ifdef DEBUG
	cls();
	for(signed int count=-1; count<=_y;)
		P_(count++)
	cout << "<";
	for(signed int count=0; count<_x-2; count++)
		cout << "=";
	cout << ">";
	_getche();
#endif
	return 0;
}
//*****************************************************************************
// Window size is related with font size of the console, monitor size and maybe operacional system
int utils::Console::setWindow(int _x, int _y) { // Xmax = 320, Ymax = 84 (_LG_Monitor_ 2560x1080_)
	// MIN and MAX window sizes:
	setMinMax(_x, _y, window);

	SMALL_RECT window = {0, 0, _x-1, _y-1}; // (Left, Top, Right, Bottom). Zero based. 49 imput go through 0-49 and means 50.
	if(!SetConsoleWindowInfo(hOut, TRUE, &window)) {
		int error = GetLastError();
		DS("Window resizin'...")
#ifdef DEBUG
		prtColorReturn("FAILED: ", FRI);
#endif
		cout << error << endl;
		return error;
	} else {
		DS("Window resizin'...")
#ifdef DEBUG
		prtColorReturn("SUCCEED!\n", FGI);
#endif
	}
	return 0;
}
//*****************************************************************************
void utils::Console::prtColorReturn(char* _str, const WORD &_cor) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	WORD previousColour = BSInfo.wAttributes;
	utils::PrintColour(_str, _cor);
	setColour(previousColour);
	//displayInfo();
}
//*****************************************************************************
void utils::Console::mouse() {
	bool Continue    = TRUE;
	int  KeyEvents   = 0;
	int  MouseEvents = 0;
	INPUT_RECORD InRec;
	DWORD        NumRead;

	cursor(0,0);
	cout << "Key Events   : \n";
	cout << "Mouse Events : " << flush;

	while(Continue) {
		ReadConsoleInput(hIn, &InRec, 1, &NumRead);

		switch(InRec.EventType) {
		case KEY_EVENT:
			++KeyEvents;
			cursor(15,0);
			cout << KeyEvents << " ScanCode : ";
			cout << InRec.Event.KeyEvent.wVirtualScanCode << flush;
			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x') {
				gotoxy(0,3);
				cout << "Exiting...\n";
				Continue = FALSE;
			}
			break;
		case MOUSE_EVENT:
			++MouseEvents;
			cursor(15,1);
			cout << MouseEvents << flush;
			break;
		}
	}
}
//*****************************************************************************
void utils::Console::setColour(const WORD &_cor) {
	fSuccess = SetConsoleTextAttribute(hOut, _cor);
	if(!fSuccess) 
		MyErrorExit("SetConsoleTextAttribute FAILED!\n");
}
//*****************************************************************************
void utils::Console::gotoxy(const int &_x, const int &_y) {	// xColumns, yLines {
	// Cursor position (column/line):
	COORD point = {_x, _y};
	SetConsoleCursorPosition(hOut, point);
}
//*****************************************************************************
void utils::Console::cursor(const int &_sz, bool _show) {
	// Cursor info (visible/size):
	CONSOLE_CURSOR_INFO Cursor;
	Cursor.dwSize   = _sz;
	Cursor.bVisible = _show; // Turn cursor visibility on/off
	SetConsoleCursorInfo(hOut, &Cursor);
}
//*****************************************************************************
void utils::Console::scrolling() {
	SMALL_RECT DisplayArea = { 5, 5, 0, 0};
	SMALL_RECT ScrollRight = {-1, 0,-1, 0};
	SMALL_RECT ScrollDown  = { 0,-1, 0,-1};
	SMALL_RECT ScrollLeft  = { 1, 0, 1, 0};
	SMALL_RECT ScrollUp    = { 0, 1, 0, 1};

	GetConsoleScreenBufferInfo(hOut, &BSInfo);

	DisplayArea.Bottom = BSInfo.srWindow.Bottom -5;
	DisplayArea.Right  = BSInfo.srWindow.Right  -5;
	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

	srand((unsigned)time(NULL));
	/*	for (Lines = 0; Lines < (BSInfo.srWindow.Bottom - 1); Lines++) {
	for(Characters = 0; Characters < 80; Characters++) {
	Random = ( rand() % 32);
	if (Random > 25) {
	std::cout << " " << std::flush;
	} else {
	std::cout << (char)('a' + Random) << std::flush;
	}
	}
	}*/
	Sleep(250);
	for(int i=0; i<5; i++) {
		SetConsoleWindowInfo(hOut, FALSE, &ScrollRight);
		Sleep(100);
	}
	Sleep(250);

	for(int i=0; i<5; i++) {
		SetConsoleWindowInfo(hOut, FALSE, &ScrollDown);
		Sleep(100);
	}
	Sleep(250);

	for(int i=0; i<5; i++) {
		SetConsoleWindowInfo(hOut, FALSE, &ScrollLeft);
		Sleep(100);
	}
	Sleep(250);

	for(int i=0; i<5; i++) {
		SetConsoleWindowInfo(hOut, FALSE, &ScrollUp);
		Sleep(100);
	}
	Sleep(250);

	for(int i=0; i<5; i++) {
		SetConsoleWindowInfo(hOut, FALSE, &ScrollRight);
		SetConsoleWindowInfo(hOut, FALSE, &ScrollDown);
		Sleep(100);
	}
	Sleep(250);

	DisplayArea.Top    = 0;
	DisplayArea.Left   = 0;
	DisplayArea.Bottom = BSInfo.srWindow.Bottom;
	DisplayArea.Right  = BSInfo.srWindow.Right;

	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}
//*****************************************************************************
void utils::Console::events() {
	DWORD events = 0;
	DWORD read   = 0;
	bool  run	 = true;
	while(run) {
		GetNumberOfConsoleInputEvents(hIn, &events);
		if(events) {
			INPUT_RECORD *evt = new INPUT_RECORD[events];
			ReadConsoleInput(hIn, evt, events, &read);

			for(DWORD i = 0; i < read; i++) {
				if(evt[i].EventType == KEY_EVENT) {
					cout << "char pressed: " << evt[i].Event.KeyEvent.uChar.AsciiChar << endl;
					if(evt[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						run = false;
					}
					for(int h = 0; h < (sizeof(keyCodes)/sizeof(WORD)); h++) {
						if(evt[i].Event.KeyEvent.wVirtualKeyCode == (WORD)keyCodes[h]) {
							cout << "key: " << keyStrs[h] << endl;
						}
					}
					for(int h = 0; h < (sizeof(keyStates)/sizeof(WORD)); h++) {
						if(evt[i].Event.KeyEvent.dwControlKeyState & (WORD)keyStates[h]) {
							cout << "state: " << keyStatesStrs[h] << endl;
						}
					}
				} else if(evt[i].EventType == MOUSE_EVENT) {
					cout << "mouse event...\n";
					COORD pos = evt[i].Event.MouseEvent.dwMousePosition;
					cout << "position.X: " << pos.X << endl;
					cout << "position.Y: " << pos.Y << endl;

					for(int h = 0; h < (sizeof(mouseButtons)/sizeof(WORD)); h++) {
						if(evt[i].Event.MouseEvent.dwButtonState & mouseButtons[h]) {
							cout << mouseButtonStrs[h] << endl;
						}
					}

					if(evt[i].Event.MouseEvent.dwEventFlags & DOUBLE_CLICK) { // MOUSE_MOVED & MOUSE WHEELED
						cout << "DOUBLE_CLICK" << endl;
					}

				} else if(evt[i].EventType == WINDOW_BUFFER_SIZE_EVENT) {
					cout << "window buffer size event...\n";
				} else if(evt[i].EventType == MENU_EVENT) {
					cout << "menu event...\n";
				} else if(evt[i].EventType == FOCUS_EVENT) {
					cout << "focus event...\n";
				}
			}
			delete[] evt;
		}
	}
}
//*****************************************************************************
void utils::Console::cls(bool _cb, char _ch, int _x, int _y, int _len) { // X=Columns, Y=Lines
	// Starting point to clean
	COORD pos = {_x, _y};

	int lenght = _len;
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	if(_len==0) // 0 means till the end of console. Jus'to implement the default arguments in the function prototype
		lenght = BSInfo.dwSize.X * BSInfo.dwSize.Y;
	//DisplayInfo();
	if(_cb)
		FillConsoleOutputAttribute(hOut, (WORD)0, lenght, pos, &dWritten);
	FillConsoleOutputCharacter(hOut, _ch, lenght, pos, &dWritten);
	SetConsoleCursorPosition  (hOut, pos);

	//fillConsole(
}
//*****************************************************************************
void utils::Console::fillConsole(const WORD &_cor, const char &_ch, const int &_x, const int &_y, const int &_len) { // X=Colums, Y=Lines
	// Fill an 80-by-50-character screen buffer with the space character. 
	COORD startingP = {_x, _y}; // Starting Point to filling
	int lenght = _len;
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	if (_len == 0) // 0 means till the end of console. Jus'to implement the default arguments in the function prototype
		lenght = BSInfo.dwSize.X * BSInfo.dwSize.Y;

	//#define _DEBUG_ON_
#ifdef DEBUG
	;//DisplayInfo();
#endif

	fSuccess = FillConsoleOutputCharacter( 
		hOut,           // screen buffer handle 
		_ch,           // fill with spaces 
		lenght,       // number of cells to fill (Columns x Lines)
		startingP,   // first cell to write to 
		&dWritten); // actual number written 
	if (!fSuccess) 
		MyErrorExit("FillConsoleOutputCharacter FAILED!\n"); 

	// Set 80-by-50-character screen buffer colors to white text on red.    
	fSuccess = FillConsoleOutputAttribute( 
		hOut,           // screen buffer handle
		_cor,          // color to fill with 
		lenght,       // number of cells to fill (Columns x Lines)
		startingP,   // first cell to write to 
		&dWritten); // actual number written 
	if(!fSuccess) 
		MyErrorExit("FillConsoleOutputAttribute FAILED!\n");
}
//*****************************************************************************
void utils::Console::printConsole(char* _str, int _x, int _y) { // X=Colums, Y=Lines
	LPTSTR lpszStr = _str;
	int    lenght  = lstrlen(lpszStr);
	WORD   wColors[3];
	// Write a string of characters to a screen buffer. 
	COORD point = {_x, _y}; // start at first cell x, of first row y  

	fSuccess = WriteConsoleOutputCharacter( 
		hOut,           // screen buffer handle 
		lpszStr,       // pointer to source string 
		lenght,       // length of string 
		point,       // first cell to write to 
		&dWritten); // actual number written 
	if (! fSuccess) 
		MyErrorExit("WriteConsoleOutputCharacter FAILED!\n"); 

	// Write a string of colors to a screen buffer. 
	wColors[0] = BR | FWI; 
	wColors[1] = BR | BGI | BBI;     // white background  
	wColors[2] = BBI; 

	for (;fSuccess && point.X < (lenght+_x); point.X += 1) {
		fSuccess = WriteConsoleOutputAttribute( 
			hOut,           // screen buffer handle 
			wColors,       // pointer to source string 
			1,            // length of string 
			point,       // first cell to write to 
			&dWritten); // actual number written 
	}
	if (!fSuccess) 
		MyErrorExit("WriteConsoleOutputAttribute FAILED!\n");
}
//*****************************************************************************
void utils::Console::write2Console(char* _str, const int &_x, const int &_y, const WORD &_cor) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	bool _buffer = true;
	int right, bottom;
	if(_buffer) {
		right  = BSInfo.dwSize.X;
		bottom = BSInfo.dwSize.Y;
	} else {
		right  = BSInfo.srWindow.Right;
		bottom = BSInfo.srWindow.Bottom;
	}

	int lenght = strlen(_str);
	CHAR_INFO *text = new CHAR_INFO[lenght];
	COORD bufSize   = {lenght, 1};
	COORD startPos  = {0,0};//_x-5, _y-1}; // X=Columns, Y=Lines COORD startPos  = {0,0};
	//SMALL_RECT writeArea = {_x-25, _y-1, _x-1, _y-1}; // The position (offset) the canvas will roll in/out:
	SMALL_RECT writeArea = {_x, _y, _x+lenght, _y+1};

	DWORD read;
	WORD atrib;
	COORD pos = {_x, _y};
	int i=0;
	//for(int i=0; i<lenght; i++) {
	for(int y=_y; y<=bottom; ++y) {
		for(int x=_x; x<=right; ++x) {
			pos.X = x;
			pos.Y = y;
			ReadConsoleOutputAttribute(hOut, &atrib, 1, pos, &read);
			if(i<lenght) {
				text[i].Char.AsciiChar = _str[i];
				if(_cor)
					text[i].Attributes = _cor;
				else
					text[i].Attributes = atrib|FWI; // Cor de fundo existente mais fonte branca.
				i++;
			}
		}
	}
	if(!WriteConsoleOutput(hOut, text, bufSize, startPos, &writeArea))
		std::cout << "WriteConsoleOutput failed\n";
	delete[] text;
}
//*****************************************************************************
void utils::Console::doubleBuffering(const char *_str, const WORD &_cor, const float &_time, bool _buffer, const signed int &_left, const signed int &_top, const signed int &_right, const signed int &_bottom) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	REQUIRE((_left >= 0)&&(_top >= 0)&&(_right <= BSInfo.dwSize.X)&&(_bottom <= BSInfo.dwSize.Y))
	int lenght = strlen(_str);
	int right, bottom;
	int matrix;
	if(_buffer) {
		right  = BSInfo.dwSize.X-1;
		bottom = BSInfo.dwSize.Y-1;
	} else {
		right  = BSInfo.srWindow.Right;
		bottom = BSInfo.srWindow.Bottom;
	}
	matrix = (right+1)*(bottom+1);
	if((_right!=0)||(_bottom!=0)) {
		right  = _right;
		bottom = _bottom;
	}
	matrix = (right+1)*(bottom+1);
	//P_(right)
	//P_(bottom)
	// Set up the positions:
	COORD wndSize  = {right+1, bottom+1}; // Window size
	COORD startPos = {0, 0}; // X=Columns, Y=Lines
	// Margins (zero-indexed) {Left/Top/Right/Bottom}
	SMALL_RECT writeArea = {0, 0, right, bottom}; // The entire canvas console:

	CHAR_INFO *text= new CHAR_INFO[matrix];
	memset(text, 0, (matrix)*sizeof(CHAR_INFO));

	// Reading previous matrix:
	DWORD read;
	WORD atrib;
	char *buf = new char[matrix];
	COORD pos = {0,0};
	int i=0;
	for(int y=0; y<=bottom; ++y) {
		for(int x=0; x<=right; ++x) {
			int index = (right+1)*y+x;
			pos.X = x;
			pos.Y = y;
			ReadConsoleOutputAttribute(hOut, &atrib, 1, pos, &read);
			ReadConsoleOutputCharacter(hOut, buf,    1, pos, &read);
			text[index].Attributes     = atrib;
			text[index].Char.AsciiChar = buf[0];
			if(!_time) {
				if(((y>=_top) && (y<=bottom)) && ((x>=_left) && (x<=right))) {
					if(lenght==1) { // character
						text[index].Char.AsciiChar = _str[0];
						if(_cor)
							text[index].Attributes = _cor;
						else
							text[index].Attributes = atrib|FWI;
						Sleep(static_cast<DWORD>(_time));
					} else { // string characters
						if(i<lenght) {
							text[index].Char.AsciiChar = _str[i++]; // rand() % 256;	// ANSI char = 0-255. % to keep in this range.
							if(_cor)
								text[index].Attributes = _cor;
							else
								text[index].Attributes = atrib|FWI; // Cor de fundo exixtente mais fonte branca.
							Sleep(static_cast<DWORD>(_time));
						}
					}
				}
			}
		}
	}
	//******
	if(_time) {
		for(int y=_top; y<=bottom; ++y)
			for(int x=_left; x<=right; ++x) {
				int index = (right+1)*y+x;
				pos.X = x;
				pos.Y = y;
				ReadConsoleOutputAttribute(hOut, &atrib, 1, pos, &read);
				if(lenght==1) {
					text[index].Char.AsciiChar = _str[0];
					if(_cor)
						text[index].Attributes = _cor;
					else
						text[index].Attributes = atrib|FWI;
					Sleep(static_cast<DWORD>(_time));
				} else {
					if(i<lenght) {
						text[index].Char.AsciiChar = _str[i++]; // rand() % 256;	// ANSI char = 0-255. % to keep in this range.
						if(_cor)
							text[index].Attributes = _cor;
						else
							text[index].Attributes = atrib|FWI; // Cor de fundo exixtente mais fonte branca.
						Sleep(static_cast<DWORD>(_time));
					}
				}
				//SWAP the buffer
				if(!WriteConsoleOutput(hOut, text, wndSize, startPos, &writeArea))
					std::cout << "WriteConsoleOutput failed\n";
			}
	}
	//SWAP the buffer
	if(!WriteConsoleOutput(hOut, text, wndSize, startPos, &writeArea))
	std::cout << "WriteConsoleOutput failed\n";
	delete[] buf;
	delete[] text;
}
/*
void utils::Console::doubleBuffering2(const char *_str, const WORD &_cor, const float &_time, bool _buffer, const signed int &_left, const signed int &_top, const signed int &_right, const signed int &_bottom) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	REQUIRE((_left >= 0)&&(_top >= 0)&&(_right <= BSInfo.dwSize.X)&&(_bottom <= BSInfo.dwSize.Y))
	int lenght = strlen(_str);
	int right, bottom;
	int matrix;
	if(_buffer) {
		right  = BSInfo.dwSize.X-1;
		bottom = BSInfo.dwSize.Y-1;
	} else {
		right  = BSInfo.srWindow.Right;
		bottom = BSInfo.srWindow.Bottom;
	}
	matrix = (right+1)*(bottom+1);
	if((_right!=0)||(_bottom!=0)) {
		right  = _right;
		bottom = _bottom;
	}
	matrix = (right+1)*(bottom+1);
	//P_(right)
	//P_(bottom)
	// Set up the positions:
	COORD wndSize  = {right+1, bottom+1}; // Window size
	COORD startPos = {0, 0}; // X=Columns, Y=Lines
	// Margins (zero-indexed) {Left/Top/Right/Bottom}
	SMALL_RECT writeArea = {0, 0, right, bottom}; // The entire canvas console:

	char *buf = new char[matrix];
	static int aaa = 0;
	static CHAR_INFO *text2;// = new CHAR_INFO[matrix];
	if(aaa++==0)
		text2= new CHAR_INFO[matrix];
	if(swap) {
		//SWAP the buffer
		if(!WriteConsoleOutput(hOut, text2, wndSize, startPos, &writeArea))
			std::cout << "WriteConsoleOutput failed\n";

		//delete[] buf;
		//delete[] text2;
		//text2= new CHAR_INFO[matrix];
		//memset(text2, 0, (matrix)*sizeof(CHAR_INFO));
		//swap = false;
		return;
	}

	// Reading previous matrix:
	DWORD read;
	WORD atrib;
	COORD pos = {0,0};
	int i=0;
	for(int y=0; y<=bottom; ++y) {
		for(int x=0; x<=right; ++x) {
			int index = (right+1)*y+x;
			pos.X = x;
			pos.Y = y;
			//ReadConsoleOutputAttribute(hOut, &atrib, 1, pos, &read);
			//ReadConsoleOutputCharacter(hOut, buf,    1, pos, &read);
			//text2[index].Attributes     = atrib;
			//text2[index].Char.AsciiChar = buf[0];
			if(((y>=_top) && (y<=bottom)) && ((x>=_left) && (x<=right))) {
				if(lenght==1) { // character
					text2[index].Char.AsciiChar = _str[0];
					if(_cor)
						text2[index].Attributes = _cor;
					else
						text2[index].Attributes = atrib|FWI;
					//Sleep(_time);
				} else { // string characters
					if(i<lenght) {
						text2[index].Char.AsciiChar = _str[i++]; // rand() % 256;	// ANSI char = 0-255. % to keep in this range.
						if(_cor)
							text2[index].Attributes = _cor;
						else
							text2[index].Attributes = atrib|FWI; // Cor de fundo exixtente mais fonte branca.
						//Sleep(_time);
					}
				}
			}
		}
	}
}*/
//*****************************************************************************
void utils::Console::at(int _x, int _y, unsigned char _ch) {
	gotoxy(_x, _y);
	std::cout << _ch << std::flush;
}
//*****************************************************************************
void utils::Console::drawing() {	
	at(9,  0, (unsigned char) 218);
	at(10, 0, (unsigned char) 196);
	at(11, 0, (unsigned char) 191);
	at(9,  1, (unsigned char) 179);
	at(10, 1, (unsigned char) 32);
	at(11, 1, (unsigned char) 179);
	at(9,  2, (unsigned char) 192);
	at(10, 2, (unsigned char) 196);
	at(11, 2, (unsigned char) 217);
}
//*****************************************************************************
void utils::Console::movingSize(int _minX, int _minY, int _msec) {
	SMALL_RECT window = {0, 0, 0, 0};
	GetConsoleScreenBufferInfo(hOut, &BSInfo);

	int x, y, x2, y2;
	x = x2 = BSInfo.srWindow.Right;
	y = y2 = BSInfo.srWindow.Bottom;

	window.Bottom = y;
	while(x-- > _minX){//(x2 / 2)) {
		window.Right = x;
		SetConsoleWindowInfo(hOut, TRUE, &window);
		Sleep(_msec);
	}
	while(y-- > _minY) {
		window.Bottom = y;
		SetConsoleWindowInfo(hOut, TRUE, &window);
		Sleep(_msec);
	}
	while(x++ < x2) {
		window.Right = x;
		SetConsoleWindowInfo(hOut, TRUE, &window);
		Sleep(_msec);
	}
	while (y++ < y2) {
		window.Bottom = y;
		SetConsoleWindowInfo(hOut, TRUE, &window);
		Sleep(_msec);
	}
}
//*****************************************************************************
void utils::Console::testeSize() {
	// Teste vários tamanhos:
	int dx=1,i=5,l=0;
	while(l<5) {
		i = i+dx;
		if((i<1) || (i>16)) { dx=-dx; l++;}

		int x = 10*i;
		int y = 5*i;
		displayInfo();
		D(x)
		D(y)
		//setBuffer(x, y); // resizeWindowns defaults true
		setWindow(x, y);
		delay(1000);
		displayInfo();
		D(x)
		D(y)
		setBuffer(x*100, y*100, false);		
	}
}
// ***************** <<_USAGE_>> *****************
static void usage1(); // setBufferSize()
static void usage2(); // doubleBuffering()
static void usage3();
static void usage4();
static void usage5();
static void usage6();
static void usage7();
static void usage8();
static void usage9();

void utils::_consoleUsage() {

	Console cmd(125, 34, "<<_CONSOLE USAGE_>>");
	cmd.setBufferSize(125, 200);

	cmd.setColour(FGI);
	cmd.prtColorReturn("\n******<<_CONSOLE USAGE_>>******\n", FRI);
	system("pause");

//	Console cmd(80, 24, "Console Usage");
	//usage1(); // setBufferSize()
	usage2(); // doubleBuffering()
	//cmd.events();
	system("pause");

//	cmd.printConsole("Teclado habilitado para o porguguês!", 10, 10);
	cmd.write2Console("Maria Ap. da Silva", 1, 1, FY);
	cmd.write2Console("Maria Ap. da Silva", 2, 2, 0);
	cmd.write2Console("Hey I'm here! haha", 3, 3);
	_getche();
	cmd.fillConsole(BGI,'_', 0, 0, 0);
	_getche();

	cmd.cursor();
	_getche();
	cmd.cursor(100);
	cmd.title(TEXT("<<_Title Test_>>"));
	// Cleans only the foreground stuff:
	cmd.cls(true, '*', 10, 10, 1800);
	
	utils::PrintColour("Hello World!", FRI);
	cmd.gotoxy(0,0);
	_getche();
	cmd.cls();
	_getche();
	//cmd.events();
	//cmd.mouse();
	cmd.drawing();
	//cmd.scrolling();
	cmd.movingSize(5, 5, 5);
}
void usage1() {
	utils::Console cmd(80, 24, "setWindownSize");
	cmd.testeSize();
	//cmd.setWindow(15,2);
	//cmd.setBuffer(15,2, false); // resizeWindowns defaults true
	//cmd.displayInfo();
	//cmd.setWindowSize(40, 40);
	//cmd.setBufferSize(220, 84);
}
void usage2() {
	utils::Console cmd(90, 40, "doubleBuffering");
	cmd.doubleBuffering("=", BB |FRI, 0, true, 15, 15, 39, 39);
	cmd.doubleBuffering("=", BB |FRI, 0, true, 0,  0,  14, 14);
	cmd.doubleBuffering("=", BRI|FYI, 0, true, 7,  7);
	cmd.doubleBuffering(" ",       0, 0, true, 12, 12, 17, 17);
	_getche();
	cmd.doubleBuffering(" claybom",  0,  0, false, 0, 0, 14, 14);
	cmd.doubleBuffering(" claybom2", 0,  0, false, 15, 15);
	cmd.doubleBuffering(" hahaha",   0,  0, false, 7, 7, 22, 22);
	cmd.doubleBuffering(" Mary Loou", 0, 0, false, 5, 12, 17, 17);
	_getche();
	cmd.doubleBuffering(" ", BGI, 0, false, 12, 12);
	cmd.cls();
}