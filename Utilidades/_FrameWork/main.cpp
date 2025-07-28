//#include "vld.h" // No memory leaks DETECTED!
#include "Frame.h"
#include "utils.h" // _colour.h
using namespace std;

int main() {
	utils::_setLocale();	//habilita a acentua��o para o portugu�s
	//utils::Console cmd(80, 30, "<<_FRAMEWORK_>>");
	// Dictionaries path: I:\Programming\CPP\dicion�rios
	utils::dicShow("mathematics", "Fatores Primos");
	utils::PrintColour_("FrameWork Example portugu�s.\n"); // Defaults to blackBG | greenFG

	int var = 10;
//	assert(var >= 0 && var <=10);
	//require(var >= 0 && var <=10, "Var out of range: (var >= 0 && var <=10)");

	utils::_frameUsage();
	// Using static general functions:
//	utils::_charIsWhat('a');
	//utils::_cin("Digite uma palavra:");
//	P_(utils::_strTo<int>("456"))
//	P_(utils::_toStr<int>(888))

	//Frame *f = new Frame();
	system("pause");
	return(0);
}