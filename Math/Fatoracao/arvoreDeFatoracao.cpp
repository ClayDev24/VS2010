#include "..\Utilidades\Console\console.h"
#include "..\Math\_prime.h"
#include "typedefs.h"
#include "fatorationTree.h"

vetorUInt math::fatorationTree(unsigned int _dividendo, bool _show) {
	using namespace std;
	vetorUInt vi;
	unsigned int divisor = _dividendo+1;//+1; //<- efetua a primeira divisão 84 / 84 = 1
	while(--divisor >= 1) {
		if(!(_dividendo % divisor)) {
			int quociente = _dividendo / divisor;
		//	if(show
			cout << setw(4) << _dividendo << " / " << setw(4) << divisor << " = " << quociente;// << endl;
			if(_prime(quociente))
				cout << " =>" << " primo" << endl;
			else 
				cout << " =>" << " composto" << endl;
			vi.push_back(divisor);
			_dividendo = divisor;
		}
	}
	return vi;
}
// **************<<_USAGE_>>****************
void math::_fatorationTree() {

	utils::Console cmd;//(50, 20, "<<_FATORATION_TREE_>>");
	cmd.setColour(FGI);
	cmd.prtColorReturn("\n******<<_ÁRVORE_DE_FATORAÇÃO_PRIMA>>******\n", FRI);
	cmd.prtColorReturn("fatorationTree(52184):\n", FY);

	vetorUInt vi = fatorationTree(18446744073709551615);
	utils::_showVetor(vi);

	vi = fatorationTree(9999);
	utils::_showVetor(vi);
}