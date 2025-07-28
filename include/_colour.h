#pragma once
#include <iostream>
#include <windows.h>

//RED:
#define FR  FOREGROUND_RED
#define FRI FOREGROUND_RED |\
            FOREGROUND_INTENSITY
//GREEN:
#define FG  FOREGROUND_GREEN
#define FGI FOREGROUND_GREEN |\
            FOREGROUND_INTENSITY
//BLUE:
#define FB  FOREGROUND_BLUE
#define FBI FOREGROUND_BLUE |\
            FOREGROUND_INTENSITY
//YELLOW:
#define FY  FOREGROUND_RED |\
			FOREGROUND_GREEN
#define FYI FOREGROUND_RED |\
			FOREGROUND_GREEN |\
			FOREGROUND_INTENSITY
//CYAN:
#define FC  FOREGROUND_BLUE |\
			FOREGROUND_GREEN
#define FCI FOREGROUND_BLUE |\
			FOREGROUND_GREEN |\
            FOREGROUND_INTENSITY
//MAGENTA:
#define FM  FOREGROUND_RED |\
			FOREGROUND_BLUE
#define FMI FOREGROUND_RED |\
			FOREGROUND_BLUE |\
            FOREGROUND_INTENSITY
//WHITE:
#define FW  FOREGROUND_RED |\
			FOREGROUND_BLUE |\
			FOREGROUND_GREEN
#define FWI FOREGROUND_RED |\
			FOREGROUND_BLUE |\
			FOREGROUND_GREEN |\
            FOREGROUND_INTENSITY
#define FNULL 0

// BACKGROUND:
//RED:
#define BR  BACKGROUND_RED
#define BRI BACKGROUND_RED |\
            BACKGROUND_INTENSITY
//GREEN:
#define BG  BACKGROUND_GREEN
#define BGI BACKGROUND_GREEN |\
            BACKGROUND_INTENSITY
//BLUE:
#define BB  BACKGROUND_BLUE
#define BBI BACKGROUND_BLUE |\
            BACKGROUND_INTENSITY
//YELLOW:
#define BY  BACKGROUND_RED |\
			BACKGROUND_GREEN
#define BYI BACKGROUND_RED |\
			BACKGROUND_GREEN |\
			BACKGROUND_INTENSITY
//CYAN:
#define BC  BACKGROUND_BLUE |\
			BACKGROUND_GREEN
#define BCI BACKGROUND_BLUE |\
			BACKGROUND_GREEN |\
            BACKGROUND_INTENSITY
//MAGENTA:
#define BM  BACKGROUND_RED |\
			BACKGROUND_BLUE
#define BMI BACKGROUND_RED |\
			BACKGROUND_BLUE |\
            BACKGROUND_INTENSITY
//WHITE:
#define BW  BACKGROUND_RED |\
			BACKGROUND_BLUE |\
			BACKGROUND_GREEN
#define BWI BACKGROUND_RED |\
			BACKGROUND_BLUE |\
			BACKGROUND_GREEN |\
            BACKGROUND_INTENSITY
#define BNULL 0

namespace utils {

	static void PrintColour(const char *_str, const WORD &_corFG = FGI, const WORD &_corBG = 0) {
		setlocale(LC_ALL, "Portuguese");
		// Win32 API function SetConsoleTextAttribute() takes 2 arguments. 1-standard output handle, 2-16bit WORD bit mask containg 0 or more bits.
		// Being bits, they can be OR'd together to make 15 combinations (blk included):
		static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, _corBG|_corFG);
		std::cout << _str;
		SetConsoleTextAttribute(hOut, FWI); // Returns to default white on black fore to background
	}

	static void PrintColour_(const char *_str, const WORD &_corFG = FGI, const WORD &_corBG = 0) {
		setlocale(LC_ALL, "Portuguese");
		static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, _corBG|_corFG);
		std::cout << _str << std::endl;
		SetConsoleTextAttribute(hOut, FWI); // Returns to default white on black fore to background
	}

}; // utils
