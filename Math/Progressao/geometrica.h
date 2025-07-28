#pragma once
#include "defines.h"

// (a1, a2, a3, a4...)
static void _progressaoGeometica(int _n,...) {
	// Média Aritmética Simples:
	//     x1 + x2 + x3 + xn
	// x = _________________
	//             n
}

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

// **************<<_USAGE_>>****************
static void _geometricaUsage() {
	utils::PrintColour_("<<_Progressão Geométrica_>>", FRI);
	_progressaoGeometica(5, 3, 6, 12, 24, 48);
}