#include <iostream>
#include "Transistor.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();	//habilita a acentua��o para o portugu�s
	TAB TAB
	utils::Console cmd(80, 30, "<<_TRANSISTOR_>>");
	utils::PrintColour_("<<_TRANSISTOR_>>\n", FRI);

	elect::_transistorUsage();

	system("pause");
	return(0);
}