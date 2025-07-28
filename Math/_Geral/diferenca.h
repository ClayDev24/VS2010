#pragma once
#include "utils.h"

namespace diferenca {

	static enum { PARES=1, MISTOS=2 , IMPARES=3 }; 

	static void _numeros(const int &_sz, const int &_tp) {
		for(int i=0; i<_sz; i++) {
				int  n1 = utils::_random(2, 100000);
				int  n2 = utils::_random(2, 100000);
				bool b1 = (n1%2)==1;
				bool b2 = (n2%2)==1;
			if(_tp==PARES) {
				if(b1)     // se impar
					n1+=1; // vira par
				if(b2)
					n2+=1;
			} else if(_tp==IMPARES) { // IMPARES
				if(!b1)      // se impar
					n1+=1; // vira par
				if(!b2)
					n2+=1;
			} else // MISTOS
				if((!b1 && !b2) || (b1 && b2)) // Se ambos pares ou ambos �mpares.
					n2+=1;

			int resultado = n1-n2;
			if(!(resultado%2)) {
				std::cout << n1 << " - " << n2 << " = " << resultado << std::endl;
				utils::PrintColour_("PAR!\n", FGI);
			} else {
				std::cout << n1 << " - " << n2 << " = " << resultado << std::endl;
				utils::PrintColour_("IMPAR!\n", FRI); // 
				//system("pause");
			}
		}
	}
}

static void _diferencaUsage() {
	//utils::_setLocale();
	//setlocale(LC_ALL, "Portuguese");
	utils::PrintColour_("Diferença entre PARES é sempre PAR:\n", FRI);
	diferenca::_numeros(10, diferenca::PARES);
	utils::PrintColour_("Diferença entre ÍMPARES é sempre PAR:\n", FRI);
	diferenca::_numeros(10, diferenca::IMPARES);
	utils::PrintColour_("Diferença entre PARES E ÍMPARES é sempre ÍMPAR:\n", FRI);
	diferenca::_numeros(10, diferenca::MISTOS);
}