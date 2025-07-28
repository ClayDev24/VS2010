#pragma once
#include <windows.h>
#include <locale.h>  // setLocale();
#include "_colour.h"

namespace utils {
	//static HANDLE hOut;
	//static HANDLE hIn;
	class Console {
	protected:
		enum { buffer = 1, window } MODE; // Untagged enum
		CONSOLE_SCREEN_BUFFER_INFO BSInfo;
		HANDLE hOut;
		HANDLE hIn;
		HANDLE hError;
		BOOL   fSuccess;
		DWORD  dWritten;
		bool   swap;

		void at(int _x, int _y, unsigned char _ch);
		int  setBuffer(int Columns, int Lines, bool windowResize = true);
		int  setWindow(int Columns, int Lines);
		void setMinMax(int &Right,  int &Bottom, const int &Mode);
		
		void displayInfo();
		void chores();
	
		void MyErrorExit(LPTSTR _msg) {
			fprintf(stderr, "%s\n", _msg);
			// Exit peacefully...
			ExitProcess(0);
		}
	public:
		// Default Constructor:
		Console();
		Console(const int &Columns, const int &Lines, const char* _Title = "Default Command Line Prompt");
		~Console() { std::cout << "~Console()..." << std::endl; }
		void title(const char* Phrase) {
			//SetConsoleTitle(Phrase);
		}
		//*****************************************************************************
		HANDLE GetHandleIn()  { return hIn;  };
		HANDLE GetHandleOut() { return hOut; };
		void boundaries(int &Right, int &Bottom);
		// Cleans only foreground attributes:
		void cls(bool CleanBehind = true, char Filling = ' ', int StartColumn=0, int StartLine=0, int Lenght=0/*end of canvas*/);
		// Fills Foreground and backgrounds to the following default arguments attributes:
		void fillConsole(const WORD &Colour=FWI, const char &Filling = ' ', const int &StartColumn=0, const int &StartLine=0, const int &Lenght=0); // X=Colums, Y=Lines; Lenght 0=T?he entire console
		void printConsole(char* Str, int StartColumn=0, int StartLine=0);
		void write2Console(char* Str, const int &StartColumn=0, const int &StartLine=0, const WORD &Colour = FWI);
		void prtColorReturn(char* Str, const WORD &Cor);
		inline void setWindowSize(const int &x, const int &y) { setBuffer(x, y);        }; // Changes window and buffer accordingly
		inline void setBufferSize(const int &x, const int &y) { setBuffer(x, y, false); }; // false = Changes only buffer. Buffer could only grows up!
		inline void setSwap() { swap = true; }
		void gotoxy(const int &Columns=0, const int &Lines=0); // xColumns, yLines {
		void cursor(const int &Size=50, bool Show = true);
		void setColour(const WORD &Colour);	
		void delay(const int &Milliseconds=10); // same as sleep
		//*****************************************************************************
		void doubleBuffering(const char *Str = " ", const WORD &Colour = FGI, const float &_time = 10.0, bool _buffer = true, const signed int &X1=0, const signed int &Y1=0, const signed int &X2=0, const signed int &Y2=0);
//		void doubleBuffering2(const char *Str = " ", const WORD &Colour = FGI, const float &_time = 10.0, bool _buffer = true, const signed int &X1=0, const signed int &Y1=0, const signed int &X2=0, const signed int &Y2=0);
		void movingSize(int _minX, int _minY, int _msec);
		//void _readConsole();
		void scrolling();
		void drawing();
		void events();
		void mouse();
		// For debug purposes usage:
		void testeSize();
	};
	// **************<<_USAGE_>>****************
	void _consoleUsage();

} // utils