#pragma once
#include <iostream>
#include <map>
#include "utils.h"
#include "mat.h"

namespace math {

	// Permutação com repetição:
	// anagrama do verbo "amar"
	// Fórmula: Pn^k,l,...= n! / (k! * l!...))
	// (P)ermutação, n(termos), (k,l)n.de termos repetidos, !(fatoração)
	static int permutacaoRepetidos(const char *_str) { // sz, n, k...l...etc
		std::map<int, int>  repetitions;
		std::map<int, int>::iterator it;
		std::vector<std::map<int, int>> v;

		vetorInt valores;
/*		for(unsigned int i=0; i<strlen(_str); i++) 
			valores[i]=_str[i];

		for(unsigned int i=0; i<valores.size(); i++)
			repetitions[valores[i]]++;

	for(it = repetitions.begin(); it != repetitions.end(); it++)
		if(it->second > 1) {// Modal
			v.push_back(static_cast<std::map<int,int>>(*it));
			std::cout << it->first << "=> " << it->second << std::endl;
		} else // Amodal
			std::cout << "ERROR! no repetitions...\n";
*/
		system("pause");
		int P = 0;            // permutação
		int n = strlen(_str); // total de letras
		int divisor=1; // 
		
		for(unsigned int i=1; i<v.size(); i++)
			divisor *= math::_factorial(valores[i]); // k! * l!...
		P = _factorial(n) / divisor;

		return P;
	}
	// **************<<_USAGE_>>****************
	static void permutacaoUsage() {

		// Permutação com letras repetidas:
		P_(permutacaoRepetidos("amar"))// total=4,repetidos = a=2
	}

} // math
