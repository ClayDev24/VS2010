#include <iostream>
#include "utils.h"
using namespace std;

int main() {

	utils::Console cmd;
	utils::PrintColour_("<<_NÚMEROS_DECIMAIS_>>\n", BRI);
	cout << "Indica um número que não é inteiro." << endl;
	cout << "Ex.: 5,28" << endl;
	utils::PrintColour_("Podem ser de 3 tipos:", FGI);
	utils::PrintColour_("1-Racionais: (que podem ser escritos em forma de fração) \n" \
		               "a/b => a,b E Z (a e b são pertencentes ao conjunto dos ns. inteiros \n" \
					   "b # 0 (b diferente de zero.", FGI);
	utils::PrintColour_("-Exatos: 0,8 (4/5)", FRI);
	utils::PrintColour_("-Dízimas Periócidas: 0,3333... (1/3)\n", FRI);
	utils::PrintColour_("2-Números irracionais:", FGI);
	utils::PrintColour_("-sqr(2)=1,4142..., sqr(qualquer n. primo positivo), o n. Pi = 3,14159265...", FRI);

	system("pause");
	return(0);
}