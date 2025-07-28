#ifndef _CONSOLE_
#define _CONSOLE_
#include <windows.h>
#include <locale.h>  // setLocale();
#include "define_print.h"
#include "colour.h"
#include "ShortColours.h"

namespace clb {

	class Console {

	protected:
		CONSOLE_SCREEN_BUFFER_INFO BSInfo;
		HANDLE hOut;
		HANDLE hIn;
		HANDLE hError;
		BOOL   fSuccess;
		DWORD  dWritten;

		int  setBuffer(int Columns, int Lines, bool windowResize = true);
		int  setWindow(int Columns, int Lines);
		void at(int _x, int _y, unsigned char _ch);
		void displayInfo();

		void MyErrorExit(LPTSTR _msg) {
			fprintf(stderr, "%s\n", _msg);
			// Exit peacefully...
			ExitProcess(0);
		}
	public:
		// Default Constructor:
		Console();
		Console(const int &Columns, const int &Lines, const char* _Title = "Default Command Line Prompt");
		~Console(){}
		void title(const char* Phrase) {
			SetConsoleTitle(Phrase);
		}
		//*****************************************************************************
		HANDLE GetHandleIn()  { return hIn;  };
		HANDLE GetHandleOut() { return hOut; };
		// Cleans only foreground attributes:
		void cls(bool CleanBehind = true, char Filling = ' ', int StartColumn=0, int StartLine=0, int Lenght=0/*end of canvas*/);
		// Fills Foreground and backgrounds to the following default arguments attributes:
		void fillConsole(const WORD &Colour=FWI, const char &Filling = ' ', const int &StartColumn=0, const int &StartLine=0, const int &Lenght=0); // X=Colums, Y=Lines; Lenght 0=T?he entire console
		void printConsole(char* Str, int StartColumn=0, int StartLine=0);
		void write2Console(char* Str, const int &StartColumn=0, const int &StartLine=0, const WORD &Colour = FWI);
		void prtColorReturn(char* Str, const WORD &Cor);
		void setWindowSize(const int &x, const int &y) { setBuffer(x, y);        }; // Changes window and buffer accordingly
		void setBufferSize(const int &x, const int &y) { setBuffer(x, y, false); }; // false = Changes only buffer. Buffer could only grows up!
		void gotoxy(const int &Columns=0, const int &Lines=0); // xColumns, yLines {
		void cursor(const int &Size=50, bool Show = true);
		void setColour(const WORD &Colour);	
		void delay(const int &Milliseconds=10); // same as sleep
		//*****************************************************************************
		void doubleBuffering(const char *Str = " ", const WORD &Colour = FGI, const float &_time = 10.0, bool _buffer = true, const signed int &X1=0, const signed int &Y1=0, const signed int &X2=0, const signed int &Y2=0);
		void canvas(char _fill, const WORD &_cor, const int &Left, const int &Top, const int &Right=0, const int &Bottom=0);
		void movingSize(int _minX, int _minY, int _msec);
		//void _readConsole();
		void scrolling();
		void drawing();
		void events();
		void mouse();	
		void info();
	};
}

#endif // _CONSOLE_