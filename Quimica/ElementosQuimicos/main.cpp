//#include "vld.h"
#include "elements.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();	//habilita a acentua��o para o portugu�s
	clb::Console cmd(80, 120, "<<_ELEMENTOS_QUIMICOS_>>");
	clb::PrintColour("TABELA DE Elementos Qu�micos.\n"); // Defaults to blackBG | greenFG

	qmc::_elementsUsage();

	system("pause");
	return(0);
}