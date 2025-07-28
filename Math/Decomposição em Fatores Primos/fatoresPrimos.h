#pragma once
#include <string>
#include "typedefs.h"

namespace math {
	// Decomposição em FATORES PRIMOS:
	// Todo n. composto pode ser escrito num produto em que só aparecem fatores primos, como 2, 3, 6, 7, 11, 13...
	vetorULLng fatoresPrimos(unsigned long long _n);
	// Versão com ponteiros:
	vetorULLng *fatoresPrimosP(unsigned long long _n);
	// Versão Didática:
	vetorULLng fatoresPrimosD(unsigned long long _n, bool _show=true);
	// **************<<_USAGE_>>****************
	void testFatoresPrimos();
	void fatoresPrimosUsage();

} // math