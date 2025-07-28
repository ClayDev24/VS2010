#pragma once
#include "utils.h"

namespace math {

	// Método da Substituição:
	static void _substitution() {//double a, double b, double c) {
		using namespace std;
		cout << "_Método da Substituicao...\n";
		cout << "{3x + 4y = 13" << endl;
		cout << "{ x - 2y = 1"  << endl << endl;

		cout << "1- Pega-se a equação mais simples e isola-se a icógnita;\n";
		cout << "x = 1 + 2y \n";
		cout << "2- Substitui na outra equação e resolve-se normalmente:\n";
		cout << "3(1 + 2y) + 4y = 13 \n";
		cout << "(...)\n";
	}

	// Método da Adição:
	static void _addition() {
		using namespace std;
		cout << "_Método da Adição...\n";
		cout << "{5x - 3y = 11" << endl;
		cout << "{ x +  y = -1"  << endl << endl;
		cout << "_____________\n";
		cout << " 6x -2y  = 10 (ERROR- Continuamos com duas incógnitas)\n"; 

		cout << "1- Pega-se a segunt equação e multiplica-se toda ela por um n. tal que na soma cancele um dos termos:\n";
		cout << "3(x + y = -1) = 3x + 3y = -3 \n";
		cout << "Soma-se ambas:\n";
		cout << "5x - 3y = 11 \n";
		cout << "3x + 3y = -3 \n";
		cout << "_____________\n";
		cout << "8x =  8 \n";
		cout << "Daqui pra frente segue-se a resolução normal das equações de primeiro grau...\n";
		
	}

	// **************<<_USAGE_>>****************
	static void _sistemUsage() {
		_substitution();
		_addition();

	}
}