#include "defines.h"
#include "Fatoracao.h"
#include "..\Math\_prime.h"

vetorInt math::Fatoracao::fatorationTree(unsigned int _dividendo, bool _show) {
	using namespace std;
	vetorInt vi;
	int divisor = _dividendo;//+1; //<- efetua a primeira divisão 84 / 84 = 1
	while(--divisor >= 1) {
		if(!(_dividendo % divisor)) {
			int quociente = _dividendo / divisor;
			if(_show) {
				cout << setw(4) << _dividendo << " / " << setw(4) << divisor << " = " << quociente;
				if(_prime(quociente))
					cout << " => primo\n";
				else 
					cout << " => composto\n";
			}
			vi.push_back(divisor);
			_dividendo = divisor; // Retorna todos os divisores de um n.
		}
	}
	return vi;
}
// **************<<_USAGE_>>****************
void math::_fatoracao() {
	//Fatoracao f1;
	Fatoracao f2(1);

	//PRT_(f1.getFator())
	//PRT_(f2.getFator())

	//f1.setFator(33);
	f2.setFator(84);

	//PRT_(f1.getFator())
	P_(f2.getFator())

	vetorInt vi1 = f2.getDivisores();
	utils::_showVetor(vi1);
}
