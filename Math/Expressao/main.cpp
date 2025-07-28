//#include "vld.h" // No memory leaks DETECTED!
#include "Expressao.h"
using namespace std;
using namespace utils;
using namespace math;

int main() {
	_setLocale();	//habilita a acentuação para o português
	//Console cmd(80, 24000, "<<_EXPRESSAO_>>");
	PrintColour("Expressões Example.\n"); // Defaults to blackBG | greenFG

	_monomioUsage();
	//_expressaoUsage();

	// Using static general functions:
	//utils::_cin("Digite uma palavra:");
	//P_(utils::_strTo<int>("456"))
	//P_(utils::_toStr<int>(888))

	system("pause");
	return(0);
}