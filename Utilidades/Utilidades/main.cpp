#include "vld.h"		// No memory leaks DETECTED!
#include <windows.h>	// SetConsoleTitle()
#include <iostream>
#include "utils.h"

// add the complete or relative path of the power include directory:
//#include "../../include/power.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories:
// <"../../include/power.h">

//ALT+F7->Configuration Properties->Linker->Input->Additional Dependencies: <power.lib>

//ALT+F7->Configuration Properties->Linker->General->Additional Library Dependencies: <..\..\utils\lib>
//Directories:
//Include: <I:\Programming\CPP\include>
//Lib    : <I:\Programming\CPP\lib>
//Windows environment variables: (CPP)=> "I:\Programming\CPP\"
//Include: $(CPP)\include
//Lib    : $(CPP)\Lib
//or relative: <..\..\utils\lib>

int main(int argc, char *argv[]) {
	SetConsoleTitle("<<_UTILIDADES_>>"); // windows.h
	//using namespace utils;

	// STATIC FUNCTIONS:
	
	//utils::_allocCountUsage();
	//utils::_assertUsage();      // NOT IMPLEMENTED YET
	//utils::_charIsWhatUsage();
	//utils::_chronometerUsage();
	//utils::_commandLineArgsUsage(argc, argv);
	//utils::_conversions();
	//utils::_countVectorUsage();
	//utils::_fileCopyCatUsage();
	//utils::_inputLineUsage();   // gets the whole line
	//utils::_inputWordUsage();   // gets only the first word
	//utils::_isNumberUsage();
	//utils::_randomUsage();
	//utils::_randomWordsUsage();
	//utils::_requireUsage();
	//utils::_setLocaleUsage();
	//utils::_exeUsage();
	//utils::_showVetorUsage();
	//utils::_sleepUsage();
	//utils::_sortUsage();
	//utils::_testMemoryUsage(); // c�digo com erro de funcionalidade...
	//utils::_2UpperUsage();
	//utils::_typeNumberUsage();

	// Non-STATIC FUNCTIONS:

	//utils::CStrUsage();  // NOT IMPLEMENTED YET
	utils::dictionaryUsage();
	//utils::dicShowUsage();
	//utils::EnterValueUsage();
	//utils::ExtensoUsage();
	//utils::_memsetUsage();
	//utils::PrintBinaryUsage();
	//utils::TimeElapsedUsage();
	//utils::TokenizerUsage();
	//utils::VetorComparisonUsage();
	int *i = new int(55);
	system("pause");
	return(0);
}