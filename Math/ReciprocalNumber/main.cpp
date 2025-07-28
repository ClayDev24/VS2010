#include "include_all.h"
using namespace std;

int main () {
	//Console cmd(50, 10, "<<_RECIPROCAL_NUMBERS_>>");
	float val = 1;

	// RECÍPROCO DE UM NÚMERO=> 2 números são recíprocos se o seu produto é igual a 1.
	// Também chamado inverso.
	cout << "         1/2   = 0,5 \n";
	cout << "         1/0,5 = 2   \n\n";
	utils::PrintColour_("Cálculo do inverso: ", FWI);
	while(val) {
		utils::PrintColour("Type an integer number (0=quit): ", FWI);
		cin >> val;
		if(val)
			utils::PrintColour("O inverso é: ", FWI); cout << (1/val) << endl;
	}

	system("pause");
	return(0);
}
