#include <iostream>
#include "utils.h"
using namespace std;

int main() {

	utils::dicShow("mathematics", "Produtos Notáveis");
	
	// São multiplicações que se destacam na matemática por serem frequentemente utilizadas.
	// P1- Quadrado da SOMA de dois termos: (Obs.: (a x b)^2 = (a^2 x b^2)
	cout << "(a + b)^2 = a^2 + 2ab + b^2" << endl;
	// p2- Quadrado da DIFERENÇA de dois termos:
	cout << "(a - b)^2 = a^2 - 2ab + b^2" << endl;
	// P3- Produto da soma pela diferença de dois termos:
	cout << "(a + b)(a - b) = a^2 - b^2" << endl;
	// Para expoentes maiores que 2 usar o Triângulo de Pascal:
	//            n (expoentes)
	//     1     -0
	//   1 2 1   -1
	//  1 3 3 1  -2
	// 1 4 6 4 1 -3
	// P4- Cubo da Soma ou diferença de termos:
	cout << "(a + b)^3 = 1a^3b^0 3a^2b^1 3a^1b^2 1a^0b^3" << endl;
	cout << "            a^3 + 3a^2b + 3ab^2 + b^3" << endl; // No caso de soma (se for diferença muda o sinal para -)

	//_proporcao();

	system("pause");
	return(0);
}