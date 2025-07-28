#pragma once
#include <stdarg.h> // va_list args()
#include "utils.h"
namespace media {
	// Média Aritmética Simples:
	//     x1 + x2 + x3 + xn
	// x = _________________
	//             n
	static double _aritmetica(int _n,...) {
		double x = 0.0;
		double n = _n;
		int   sz = _n;
		
		va_list args;
		va_start(args, _n); // initialize argptr
		while(_n--) // sum the parameters
			x += va_arg(args, double); // A = (v1+v2+v3+vn) / n
		va_end(args);

		return x/n;
	}
	// Media Aritmética Ponderada:
	// Valores = {x1, x2, ..., xn}
	// Pesos   = {p1, p2, ..., pn}
	// Fórmula: (valores / pesos)
	//      v1.p1 + v2.p2 + vn.pn
	// P =  _____________________
	//         p1 + p2 + pn
	static double _aritmeticaPonderada(int _n,...) {
		assert(!(_n%2)); // Par 
		int   sz = _n/2;
		double n = _n;
		double *valores = new(std::nothrow) double[sz/2];
		double *pesos   = new(std::nothrow) double[sz/2];
		MEMSET(valores,3);
		MEMSET(pesos,  3);
		
		va_list args;
		va_start(args, _n); // initialize argptr
		for(int i=0; i<sz; i++)
			valores[i]=va_arg(args, double);
		for(int i=0; i<sz; i++)
			pesos[i]=va_arg(args, double);
		va_end(args);
		//PARRAY2(valores, sz, double)
		//PARRAY2(pesos,   sz, double)
		double dividendo, divisor;
		dividendo = divisor = 0;
		// P = (v1.p1 + v2.p2 + vn.pn) / (p1 + p2 + pn)
		for(int i=0; i<sz; i++) {
			dividendo += valores[i]*pesos[i]; // Soma dividendod: (x1.p1 + x2.p2 + xn.pn)
			divisor   += pesos[i];			  // Soma divisores:  (p1 + p2 + pn)
		}
		//P_(dividendo)
		//P_(divisor)
		delete valores;
		delete pesos;
		// Média Ponderada
		return dividendo / divisor;
	}
	// **************<<_USAGE_>>****************
	static void _aritmeticaUsage() {
		//PROBLEMA: Uma sala de aula é constituída por 10% de mulheres e 90% de homens.
	}
}
