#include <iostream>
#include <stdlib.h>
#include <conio.h> // getche()
#include <time.h>  // time();
#include "virtualKeyCodes.h" // Events()
#include "..\..\include\define_print.h"
#include "..\..\include\require.h"
#include "console.h"
#define _LG_MONITOR_    // 320 x 84
//#define _FULHD_MONITOR_ // 240 X 84
#define ver     "1.0"
#define prgdate "23/04/11"
#define author  "Written by claybom"

void clb::Console::displayInfo() {
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
clb::Console::Console() {
	hOut   = GetStdHandle(STD_OUTPUT_HANDLE);
	hIn    = GetStdHandle(STD_INPUT_HANDLE);
	hError = GetStdHandle(STD_ERROR_HANDLE);
	//setlocale(LC_ALL, ""); // habilita a acentuação para o português
	if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) 
		MyErrorExit("GetStdHandle: Console Error");

	// Windows10 Mouse input:
	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT);
	if (! SetConsoleMode(hIn, ENABLE_EXTENDED_FLAGS))
		MyErrorExit("SetConsoleMode");
	if (!SetConsoleMode(hIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
		MyErrorExit("SetConsoleMode");
}
//*****************************************************************************
clb::Console::Console(const int &_x, const int &_y, const char* _str) {
	hOut   = GetStdHandle(STD_OUTPUT_HANDLE);
	hIn    = GetStdHandle(STD_INPUT_HANDLE);
	hError = GetStdHandle(STD_ERROR_HANDLE);

	//setlocale(LC_ALL, ""); // habilita a acentuação para o português

	if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) 
		MyErrorExit("GetStdHandle: Console Error");

	// Windows10 Mouse input:
	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT);
	if (! SetConsoleMode(hIn, ENABLE_EXTENDED_FLAGS))
		MyErrorExit("SetConsoleMode");
	if (!SetConsoleMode(hIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
		MyErrorExit("SetConsoleMode");

	SetConsoleTitle(_str);
	setWindowSize(_x, _y);
}
//*****************************************************************************
void clb::Console::info() {
	// Teste vários tamanhos:
	//SetWindow(15,2);
	//SetBuffer(15,2, false);
	displayInfo();
	/*
	int dx=1,i=5,l=0;
	while(l<5) {
	i=i+dx;
	if( (i<1) || (i>16)) { dx=-dx; l++;}

	int x = 10*i;
	int y = 5*i;
	DisplayInfo();
	P(x)
	P(y)
	SetBuffer(x, y);
	//        SetWindow(x, y);
	getche();
	DisplayInfo();
	P(x)
	P(y)
	SetBuffer(x*100, y*100, false);		
	getche();
	}*/
}
//*****************************************************************************
void clb::Console::delay(const int &_mili) {
	clock_t t1;
	t1 = clock();
	while(clock()-t1 < _mili) {}
}
//*****************************************************************************
int clb::Console::setBuffer(int _x, int _y, bool windowResize) {
	using namespace std;
	// MIN and MAX buffer sizes:
	const int MinX    = 15;
	const int MinY    = 2;
	const int XYmax   = 32766;
	if(_x > XYmax) _x = XYmax;
	if(_y > XYmax) _y = XYmax;
	if(_x < 15)    _x = 15;
	if(_y <  2)    _y = 2;	
	// Get the actual size of the window:
	int xWnd = BSInfo.srWindow.Right;
	int yWnd = BSInfo.srWindow.Bottom;
	// Min buffer size (in buffer resize case only - windowResize = false):
	if(_x <= xWnd) xWnd = _x;
	if(_y <= yWnd) yWnd = _y;

	setWindow(0,0);
	COORD bufSz  = {_x, _y};
	//SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, &bufSz);
	if(!SetConsoleScreenBufferSize(hOut, bufSz)) {
		int error = GetLastError();
		cout << "Buffer resizin'...";
		prtColorReturn("FAILED: ", FRI);
		cout << error << endl;
		return error;
	} else {
		cout << "Buffer resizin'...";
		prtColorReturn("SUCCEED!\n", FGI);
	}
	if(windowResize)
		setWindow(_x, _y);
	else
		setWindow(xWnd, yWnd);
	// Teste:
#ifdef DEBUG_ON
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
int clb::Console::setWindow(int _x, int _y) { // Xmax = 320, Ymax = 84 (_LG_Monitor_ 2560x1080_)
	using namespace std;
	int xmax, ymax;
	xmax = 240;
	ymax = 84;
#ifdef _LG_MONITOR_
	xmax = 320;
#endif
	// MIN and MAX window sizes:
	if(_x > xmax) _x = xmax;
	if(_y > ymax) _y = ymax;
	if(_x < 2)    _x = 2;
	if(_y < 2)    _y = 2;

	SMALL_RECT window = {0, 0, _x-1, _y-1}; // (Left, Top, Right, Bottom). Zero based. 49 imput go through 0-49 and means 50.
	if(!SetConsoleWindowInfo(hOut, TRUE, &window)) {
		int error = GetLastError();
		cout << "Window resizin'...";
		prtColorReturn("FAILED: ", FRI);
		cout << error << endl;
		return error;
	} else {
		cout << "Window resizin'...";
		prtColorReturn("SUCCEED!\n", FGI);
	}
	return 0;
}
//*****************************************************************************
void clb::Console::prtColorReturn(char* _str, const WORD &_cor) {
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	WORD previousColour = BSInfo.wAttributes;
	PrintColour(_str, _cor);
	setColour(previousColour);
	//displayInfo();
}
//*****************************************************************************
void clb::Console::cls(bool _cb, char _ch, int _x, int _y, int _len) { // X=Columns, Y=Lines
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
}
//*****************************************************************************
void clb::Console::mouse() {
	using namespace std;
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
void clb::Console::gotoxy(const int &_x, const int &_y) {	// xColumns, yLines {
	// Cursor position (column/line):
	COORD point = {_x, _y};
	SetConsoleCursorPosition(hOut, point);
}
//*****************************************************************************
void clb::Console::cursor(const int &_sz, bool _show) {
	// Cursor info (visible/size):
	CONSOLE_CURSOR_INFO Cursor;
	Cursor.dwSize   = _sz;
	Cursor.bVisible = _show; // Turn cursor visibility on/off
	SetConsoleCursorInfo(hOut, &Cursor);
}
//*****************************************************************************
void clb::Console::scrolling() {
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
void clb::Console::events() {
	using namespace std;
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
void clb::Console::fillConsole(const WORD &_cor, const char &_ch, const int &_x, const int &_y, const int &_len) { // X=Colums, Y=Lines
	// Fill an 80-by-50-character screen buffer with the space character. 
	COORD startingP = {_x, _y}; // Starting Point to filling

	int lenght = _len;
	GetConsoleScreenBufferInfo(hOut, &BSInfo);
	if (_len == 0) // 0 means till the end of console. Jus'to implement the default arguments in the function prototype
		lenght = BSInfo.dwSize.X * BSInfo.dwSize.Y;

	//#define _DEBUG_ON_
#ifdef _DEBUG_ON_
	DisplayInfo();
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
void clb::Console::setColour(const WORD &_cor) {
	fSuccess = SetConsoleTextAttribute(hOut, _cor);
	if(!fSuccess) 
		MyErrorExit("SetConsoleTextAttribute FAILED!\n");
}
//*****************************************************************************
void clb::Console::printConsole(char* _str, int _x, int _y) { // X=Colums, Y=Lines
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
void clb::Console::write2Console(char* _str, const int &_x, const int &_y, const WORD &_cor) {
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
					text[i].Attributes = atrib|FWI; // Cor de fundo exixtente mais fonte branca.
				i++;
			}
		}
	}
	if(!WriteConsoleOutput(hOut, text, bufSize, startPos, &writeArea))
		std::cout << "WriteConsoleOutput failed\n";
	delete[] text;
}
//*****************************************************************************
void clb::Console::doubleBuffering(const char *_str, const WORD &_cor, const float &_time, bool _buffer, const signed int &_left, const signed int &_top, const signed int &_right, const signed int &_bottom) {
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
//*****************************************************************************
void clb::Console::canvas(char _fill, const WORD &_cor, const int &_left, const int &_top, const int &_right, const int &_bottom) {
	char ch[] = {_fill, 0};
	doubleBuffering(ch, _cor, 0, true, _left, _top, _right, _bottom);
}
//*****************************************************************************
void clb::Console::at(int _x, int _y, unsigned char _ch) {
	gotoxy(_x, _y);
	std::cout << _ch << std::flush;
}
//*****************************************************************************
void clb::Console::drawing() {	
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
void clb::Console::movingSize(int _minX, int _minY, int _msec) {
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