//#include "vld.h" // No memory leaks DETECTED!
#include "consumo.h"
#include "utils.h" // _colour.h
using namespace std;

int main() {
	utils::_setLocale();	//habilita a acentuação para o português
	utils::Console cmd(80, 30, "<<_POWER COMSUPTION_>>");
	utils::PrintColour_("<<_POWER COMSUPTION_>>\n", FYI); // Defaults to blackBG | greenFG

	int var = 10;

	elec::_consumoUsage();
	
	system("pause");
	return(0);
}