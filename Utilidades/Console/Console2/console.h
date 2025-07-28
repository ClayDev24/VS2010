#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "colour.h"
#include "define_print.h"

namespace clb {
	class Console {
		HANDLE hIn;
		HANDLE hOut;
		HANDLE hError;	
		COORD  Pos;			// Position COORD struct to use sparingly
		COORD  bufSz;		// SCREEN Buffer size: Column x line
		CHAR_INFO*  swapBuf;
		SMALL_RECT  window;	// Window parameters: left, top, right, bottom (ZERO-based)
		CONSOLE_CURSOR_INFO        Cursor;
	    CONSOLE_SCREEN_BUFFER_INFO BSInfo;

	public:
		Console(int Columns = 110, int Lines = 60, char* Title = "Default Command Line Prompt");
		~Console();
		void title     (char* Title);
		bool bounds    (int   _right, int  _bottom, int _left=0, int _top=0);
		void size      (int   _right, int  _bottom, int _left=0, int _top=0);		
		void cls       (int   _x=0,   int  _y=0,    char _fill=' ');
		void gotoxy    (const int &X=0,const int &Y=0);	// xColumns, yLines
		void printBuf  (int   _x,     int  _y,   char* _text, WORD _cor);
		void cursor    (int   _size =10, bool _visible=true);	
		void outline   (int   _left,  int  _top, int _right, int _bottom, char* _text);
		void outlineBuf(int   _left,  int  _top, int _right, int _bottom, char* _text, WORD _cor);
		void canvas    (int   _left,  int  _top, int _right, int _bottom, WORD  _cor, char _fill=' ');
		void button    (int   _left,  int  _top, int _right, int _bottom, WORD  _cor);
		void colour    (WORD _cor = FGI|BNULL);
		void paint     (WORD _cor = BNULL|FNULL, char _fill=' ', bool _random=false);
		COORD GetBufSz() { return bufSz; };
		CHAR_INFO* GetSwapBuf() { return swapBuf; };
		void Info();
		void DisplayInfo();
	};
};

#endif // __CONSOLE_H__
