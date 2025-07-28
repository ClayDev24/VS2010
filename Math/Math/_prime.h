#pragma once
#include <iostream>
#include "utils.h"
#include "typedefs.h"
#include "_colour.h"

namespace math {
	// Número PRIMO=> Apenas 2 divisores (ele próprio eo o n.1). Não tem lei (ou fórmula) de formação.
	// Número COMPOSTO=> Apresenta mais de dois divisores. O contrário do n. primo.
	// Se um n. é < 121 e não é divisível por 2, 3, 5 e 7 é de antemão  um n. PRIMO.
	// Se um n. é < 289 e não é divisível por 2, 3, 5, 7, 11 e 13 não é um n. PRIMO.

	// Algoritmo mais rápido:
	// Para determinar se um certo número inteiro é primo basta dividi-lo por
	// todos os primos menores ou iguais à sua raiz quadrada.
	static bool _prime(const unsigned long long &_n) {
		unsigned long total= 0; // n. de testagens
		if(_n<3) // Special case: 0, 1 e 2:
			return !((_n+7)%3);
		if(!(_n%2)) // Testa divisibilidade por 2:
			return false;
		unsigned long long raiz = static_cast<unsigned long long>(sqrt(static_cast<double>(_n)));
		//P_(raiz)
		unsigned long long divisor=0;
		for(unsigned long long i=3; i<=raiz; i+=2) {
			total++;
			divisor=i;
			if(!(_n%i)) {
				//P_(total)
				return false;
			}// else //div dif zero
			//	if(i >= (_n/i)) // i >= quociente
			//		return true;
		}
		//P_(total)
		//P_(divisor)
		return true;
	}
	// **************<<_USAGE_>>****************
	static void _primeUsage() {
		utils::PrintColour_("<<__Números Primos__>>", FRI);
		utils::dicShow("mathematics", "Números Primos");

		utils::PrintColour_("\nEste algoritmo testa os ns. primos positivos entre 1 e 18.446.744.073.709.551.615\n", BBI);
		utils::PrintColour_("Maior n. primo possivel por este algoritmo:\n", BYI);
		//P_(_prime(18446744073709551557))

		utils::PrintColour_("Testando ns. primos de 1 à n:\n", BYI);
		// Teste aqui qualquer n.:
		P_(_prime(25))
		int total=0;
		//for(unsigned long u=0; u<294967294; u++)

		for(unsigned long u=0; u<100; u++)
			if(_prime(u))
				total++;
	
		//utils::_showVetor(v);
		//P_(v.size())
		P_(total)
	}
} // math