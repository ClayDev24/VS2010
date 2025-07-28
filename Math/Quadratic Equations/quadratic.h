#pragma once
#include "utils.h"

namespace math {

	static void _delta(double _d) {
		if(_d > 0)
			std::cout << "delta > 0 => 2 raízes reais e diferentes.\n";
		else if(_d == 0)
			std::cout << "delta = 0 => 2 raízes reais e iguais\n";
		else // 
			std::cout << "delta < 0 => não possui raízes reais.\n";

	}
	// Definição:
	// Toda equação na forma ax^2 +- bx +- c = 0
	// Onde a, b e Pertencentes ao conjunto dos números Reais, com a diferente de 0;
	static void _quadratic(double a, double b, double c) {
		double delta = 0;
		double x1, x2;
		x1 = x2 = 0;
		// Delta: b^2 -4ac
		delta = b*b + (-4*a*c);
		_delta(delta);
		P_(delta)
		// Fórmula (resolutiva) de Bhaskara: -b +- sqrt(delta) / 2a
		x1 = (-b + sqrt(delta)) / 2*a;
		x2 = (-b - sqrt(delta)) / 2*a;
		P_(x1)
		P_(x2)
	}
	static void _quadraticSemB(double a, double c) {
		// ax^2 + c = 0
		// ax^2 = -c
		// x = sqrt(-c)
		double x1 = sqrt(-c);
		double x2 = -x1;
		P_(x1)
		P_(x2)
	}
	static void _quadraticSemC(int a, int b) {
		// Fatoração:
		// ax^2 + bx = 0
		// x(ax + b) = 0
		// Neste caso o valor do x1 é automaticamente 0:
		// x1 = 0;
		// Para o x2 sola-se a parte do primeiro grau (entre parênteses). E procede-se como de praxe.
		// ax + b = 0;
		// ax = -b;
		// x2 = -b/a;
	}
	static void _somaEProduto(int a, int b) {
		// Encontrar dois valores de x que possuam respectivamente sua:
		// Soma    = x1 + x2 = -b/a
		// Produto = x1 * x2 = c/a
	}
	// **************<<_USAGE_>>****************
	static void _quadraticUsage() {
		std::cout << "_quadraticUsage()...\n";

		// x^2 + 3x -10
		_quadratic(1, 3, -10);
		_quadraticSemB(1, -64);
		//_quadraticSemC();

		_quadratic(1, 1, -12);
		_quadratic(-1, 14, -49);
		_quadratic(1, -2, 5);

		_quadratic(1, -6, 8);

	}
}