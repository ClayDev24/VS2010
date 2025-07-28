#pragma once
#include <iostream>
#include "mat.h"
#include "utils.h"

namespace math {

	static void _primosEntreSi() {
		P_(math::_mdc(2, 3, 4))
		P_(math::_mdc(2, 13, 23))
	}
	// Dois números a e b são primos entre si qno o mdc(a, b) = 1.
	// Ex.: mdc(3,4)=1 (Os números 3 e 4 são primos entre si)

} // math