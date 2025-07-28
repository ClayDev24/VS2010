#pragma once
#include <string>
#include "typedefs.h"

namespace math {
	// Decomposi��o em FATORES PRIMOS:
	// Todo n. composto pode ser escrito num produto em que s� aparecem fatores primos, como 2, 3, 6, 7, 11, 13...
	vetorULLng fatoresPrimos(unsigned long long _n);
	// Vers�o com ponteiros:
	vetorULLng *fatoresPrimosP(unsigned long long _n);
	// Vers�o Did�tica:
	vetorULLng fatoresPrimosD(unsigned long long _n, bool _show=true);
	// **************<<_USAGE_>>****************
	void testFatoresPrimos();
	void fatoresPrimosUsage();

} // math