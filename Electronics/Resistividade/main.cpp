#include "resistividade.h"
using namespace std;

int main() {
	clb::Console cmd;//(50,50, "<<_FRAMEWORK_>>");

	clb::PrintColour_("<<_RESISTIVIDADE_>>\n", BRI); // Defaults to blackBG | greenFG
	
	int var = 10;
	assert(var >= 0 && var <=10);
	//require(var >= 0 && var <=10, "Var out of range: (var >= 0 && var <=10)");

	cmd.setColour(FGI);
	elec::_displayResistividadeTABLE();

	system("pause");
	return(0);
}