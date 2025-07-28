#pragma once
#include <stdarg.h> // va_list args()
#include <math.h>
#include "utils.h"

namespace media {
	// Média Geométrica: Utilizada para taxa de crescimento
	// Fórmula:
	// g = sqrN(v1 * v2 * v3 * vn);
	static double _geometrica(int _n,...) {
		double media = 1.0;
		double exp   = static_cast<double>(_n);

		va_list args;
		va_start(args, _n); // initialize argptr
		while(_n--) // sum the parameters
			media *= va_arg(args, double);
		va_end(args);
		//P_(media)
		//P_(expoente)
		// A raiz cubica de X é igual a X^(1/3).
		
		return pow(media, 1.0/exp); // base/expoente
	}
}
