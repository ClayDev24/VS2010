#pragma once
#include <iostream>
#include "utils.h"

namespace math {

	// Números Perfeitos:
	// São Os ns cuja soma de seus divisores (excluindo ele mesmo) resultem nele mesmo.
	// Ex.: D(6) = {1, 2, 3} = 1+2+3 = 6 (=6) - PERFECT
	// Ex.: D(8) = {1, 2, 4} = 1+2+4 = 7 (#8) - NOT PERFECT

 	bool perfect(const unsigned long long &_n);
	// **************<<_USAGE_>>****************
	void perfectUsage();

} 