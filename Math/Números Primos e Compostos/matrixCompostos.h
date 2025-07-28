#pragma once
#include "utils.h"
#include "mat.h"

namespace math {
	// Todo n. composto pode ser decomposto num conjunto de fatores primos.
	// que pode formar uma matrix bidimensional (retangular), de ns. primos e compostos.

	typedef struct Par {
		int coluna;      
		int linha;  
	} Stash;

	class Par2 {
		int coluna;
		int linha;
	};

	static int _composto() {
		int composto = 0;
		while(!composto) {
			composto = utils::_random(4, 25);
			if(math::_prime(composto))
				composto = 0;
		}
		return composto;
	}

	static void _matrixCompostos() {
		// Criando lista de 10 retângulos:
		int n1 = _composto();
		P_(n1)
		vetorULLng *vl = math::_fatoresPrimos(n1);
		utils::_showVetor(*vl);
		//matrix(4, 6);
		_getche();
		//matrix(12, 2);
		_getche();
		//matrix(8, 3);
		_getche();
	}

} // math