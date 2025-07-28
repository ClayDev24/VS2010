#include <conio.h> // getche()
#include <cstdlib>
#include "console.h"
#include "require.h"
using namespace std;
//*****************************************************************************
clb::Console::Console(int _x, int _y, char* _t) { // X=Columns, Y=Lines
	SetConsoleTitle(_t);
    hIn  = GetStdHandle(STD_INPUT_HANDLE);
    hOut  = GetStdHandle(STD_OUTPUT_HANDLE);
    hError = GetStdHandle(STD_ERROR_HANDLE);

	size(_x, _y); // column, line
	swapBuf = NULL;
}
//*****************************************************************************
clb::Console::~Console() {
	delete []swapBuf;
}
//*****************************************************************************
void clb::Console::title(char* _title) {
    SetConsoleTitle(_title);
}
void clb::Console::DisplayInfo() {
    GetConsoleScreenBufferInfo(hOut, &BSInfo);
	P_(BSInfo.dwSize.X)		 
	P_(BSInfo.dwSize.Y)		 
	P_(BSInfo.dwMaximumWindowSize.X)
	P_(BSInfo.dwMaximumWindowSize.Y)
	P_(BSInfo.srWindow.Bottom) 
	P_(BSInfo.srWindow.Left) 
	P_(BSInfo.srWindow.Right)		 
	P_(BSInfo.srWindow.Top)	 
}
//*****************************************************************************
void clb::Console::Info() {
	//DisplayInfo();
// Teste vários tamanhos:
	//SetWindow(15,2);
	//SetBuffer(15,2, false);
	DisplayInfo();
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
void clb::Console::size(int _x, int _y, int _left, int _top) { // X-Right(Columns), Y-Bottom(Lines)
	require(_x >=14 && _y >= 10, "console sizes outta bounds...");
	bufSz.X       = _x;    // column
	bufSz.Y       = _y;   // line

	SMALL_RECT windowRect = {_left, _top, _x-1, _y-1}; // => {Left, Top, Right, Bottom}

	if(swapBuf)
		;//delete swapBuf;

    swapBuf = new(nothrow) CHAR_INFO[_x * _y];

	if(!swapBuf) {
		cout << "ERROR!: Memory could not be allocated";
		exit(0);
	}	
    SetConsoleWindowInfo(hOut, TRUE, &windowRect); // Change the console  window size:
    SetConsoleScreenBufferSize(hOut, bufSz);	   // Change the internal buffer size:    
	DisplayInfo();
}
//*****************************************************************************
void clb::Console::gotoxy(const int &_x, const int &_y) {
	require((((_x >= 0) && (_y >= 0)) && ((_x <= window.Right) && (_y <= window.Bottom))), "Canvas Outta bounds...");
	Pos.X = _x; // column
	Pos.Y = _y; // line
	SetConsoleCursorPosition(hOut, Pos);
}
//*****************************************************************************
void clb::Console::colour(WORD _cor) {
	SetConsoleTextAttribute(hOut, _cor);
}
//*****************************************************************************
void clb::Console::cursor(int _size, bool _visible) {
    Cursor.dwSize   = _size;
    Cursor.bVisible = _visible; // Turn cursor visibility on/off

    SetConsoleCursorInfo(hOut, &Cursor);
}
//*****************************************************************************
void clb::Console::paint(WORD _cor, char _fill, bool _random) {
	Pos.X = Pos.Y = 0;
	for (int x = 0; x <= window.Bottom; ++x)
		for (int y = 0; y <= (window.Right); ++y) {                    
			if(_random) {
				_fill = rand() % 256;
				_cor  = rand() % 256;
			}
            swapBuf[(window.Right+1)*x + y].Char.AsciiChar = _fill;
			swapBuf[(window.Right+1)*x + y].Attributes     = _cor;
        }
    WriteConsoleOutputA(hOut, swapBuf, bufSz, Pos, &window); // Buffer SWAP
}
//*****************************************************************************
void clb::Console::cls(int _x, int _y, char _fill) {
	canvas(0,0,window.Right,window.Bottom,FNULL|BNULL,_fill);
}
//*****************************************************************************
void clb::Console::canvas(int _left, int _top, int _right, int _bottom, WORD _cor, char _fill) {
    GetConsoleScreenBufferInfo(hOut, &BSInfo);
	require((((_left >= 0) && (_top >= 0)) && ((_right <= window.Right) && (_bottom <= window.Bottom))), "Canvas Outta bounds...");
	Pos.X = Pos.Y = 0;
	for    (int yLines  =_top;  yLines  <=_bottom; yLines++)
		for(int xColumns=_left; xColumns<=_right;  xColumns++) {
            swapBuf[(window.Right+1)*yLines + xColumns].Char.AsciiChar = 'x';//_fill;
			swapBuf[(window.Right+1)*yLines + xColumns].Attributes     = FWI;//_cor;
        }
    WriteConsoleOutputA(hOut, swapBuf, bufSz, Pos, &window); // Buffer SWAP
}
//*****************************************************************************
void clb::Console::printBuf(int _xColumns, int _yLines, char* _text, WORD _cor) {
    GetConsoleScreenBufferInfo(hOut, &BSInfo);
	require((((_xColumns >= 0) && (_yLines >= 0)) && ((_xColumns <= window.Right) && (_yLines <= window.Bottom))), "printBuf Outta bounds...");
	Pos.X = Pos.Y = 0;
	int i=0;
	while(_text[i] && _xColumns <= window.Right) {
            swapBuf[(window.Right+1)*_yLines + _xColumns].Char.AsciiChar = _text[i++];
			swapBuf[(window.Right+1)*_yLines + _xColumns].Attributes     = _cor;
			_xColumns++;
        }
    WriteConsoleOutputA(hOut, swapBuf, bufSz, Pos, &window); // Buffer SWAP
}
//*****************************************************************************
void clb::Console::outline(int _left, int _top, int _right, int _bottom, char* _text) {
	require((((_left >= 0) && (_top >= 0)) && ((_right <= window.Right) && (_bottom <= window.Bottom))), "outline Outta bounds...");
	unsigned j, m;
	m=(_right - _left);						//differential
	j=m/8-1;								//adjust
	gotoxy(_left,  _top);    cout << 'É';	//Top left corner of box
	gotoxy(_right, _top);    cout << '»';	//Top right corner of box
	gotoxy(_left,  _bottom); cout << 'È';	//Bottom left corner of box
	gotoxy(_right, _bottom); cout << '¼';	//Bottom right corner of box

	for(int i=_left+1; i<_right; i++) {
		gotoxy(i,_top);      cout << 'Í';	// Top horizontol line
		gotoxy(i,_bottom);   cout << 'Í';	// Bottom Horizontal line
	}
	for(int i=_top+1; i<_bottom; i++) {
		gotoxy(_left, i);	 cout << 'º';	//Left Vertical line
		gotoxy(_right,i);	 cout << 'º';	//Right Vertical Line
	}
	gotoxy(_left+j, _top); cout << _text;
	gotoxy(1,24);
}
//*****************************************************************************
void clb::Console::outlineBuf(int _left, int _top, int _right, int _bottom, char* _text, WORD _cor) {
	require((((_left >= 0) && (_top >= 0)) && ((_right <= window.Right) && (_bottom <= window.Bottom))), "outline Outta bounds...");
	unsigned j, m;
	m=(_right - _left);						//differential
	j=m/8-1;								//adjust
	printBuf(_left,  _top,    "É", _cor);	//Top left corner of box
	printBuf(_right, _top,    "»", _cor);	//Top right corner of box
	printBuf(_left,  _bottom, "È", _cor);	//Bottom left corner of box
	printBuf(_right, _bottom, "¼", _cor);	//Bottom right corner of box

	for(int i=_left+1; i<_right; i++) {
		printBuf(i, _top,     "Í", _cor);	// Top horizontol line
		printBuf(i, _bottom,  "Í", _cor);	// Bottom Horizontal line
	}
	for(int i=_top+1; i<_bottom; i++) {
		printBuf(_left, i,    "º", _cor);	//Left Vertical line
		printBuf(_right, i,   "º", _cor);	//Right Vertical Line
	}
	printBuf(_left+j, _top, _text, _cor);
	//gotoxy(1,24);
}
//*****************************************************************************
void clb::Console::button(int _left, int _top, int _right, int _bottom, WORD _cor) {
	canvas (_left, _top, _right, _bottom, _cor);
	outline(_left, _top, _right, _bottom, "example");
}