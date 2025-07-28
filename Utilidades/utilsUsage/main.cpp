//#include "vld.h"
#include "utils.h"
#include "..\Utilidades\fracao.h"
using namespace std;

// Project->Properties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories:
// <"../../include">

//ALT+F7->Configuration Properties->Linker->Input->Additional Dependencies: <_utils.lib>

int main() {

	// _utils.lib
	// Static Functions:
	
	//utils::_allocCountUsage();
	//utils::_assertUsage();      // NOT IMPLEMENTED YET
	//utils::_charIsWhatUsage();
	//utils::_chronometerUsage();
	//utils::_commandLineArgsUsage(argc, argv);
	//utils::_conversions();
	//utils::_countVectorUsage();
	//utils::_fileCopyCatUsage();
	//utils::_inputLineUsage();   // Gets the whole line
	//utils::_inputWordUsage();   // Gets only the first word
	//utils::_isNumberUsage();
	//utils::_randomUsage();
	//utils::_randomWordsUsage();
	//utils::_requireUsage();
	//utils::_setLocaleUsage();
	//utils::_exeUsage();
	//utils::_showVetorUsage();
	//utils::_sleep(5000);        // 0,5s
	//utils::_sortUsage();
	//utils::_testMemoryUsage(); // CÓDIGO COM ERRO DE FUNCIONALIDADE...
	//utils::_2UpperUsage();
	//utils::_typeNumberUsage();

	// on-static function:
	//utils::EnterValueUsage();
	//utils::ExtensoUsage();
	//utils::MemsetUsage();
	//utils::PrintBinaryUsage();
	//utils::TimeElapsedUsage();
	//utils::TokenizerUsage();
	//utils::VetorComparisonUsage();
	//utils::prtAlloc();

	utils::fracao();

	system("pause");
	return(0);
}