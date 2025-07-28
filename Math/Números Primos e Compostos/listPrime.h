#pragma once
#include "utils.h"
#include "..\Math\Math\_prime.h"

namespace math {
	// N. PRIMO=> Divisível apenas por 1 e por ele mesmo.
	static vetorInt* _listPrime(const unsigned long &_from, const unsigned long &_to) {
		vetorInt *vi = new vetorInt();
		int  total = 0;
		for(unsigned int n=_from; n<=_to; n++, total++)
			if(math::_prime(n))
				vi->push_back(n);
		return vi;
	}
	// **************<<_USAGE_>>****************
	static void _listPrimeUsage() {
		utils::Console cmd(50, 65, "<<_LISTA_DE_NUMEROS_PRIMOS_>>");
		cmd.setColour(FGI);
		cmd.prtColorReturn("\n******<<_LISTA_DE_NúMEROS_PRIMOS_>>******\n", FRI);
		cmd.prtColorReturn("listPrime(0, 50):\n", FY);
		
		vetorInt *vi = _listPrime(0, 50);
		utils::_showVetor(*vi);
		std::cout << "total=> " << vi->size() << std::endl;

		delete vi;
	}
} // math