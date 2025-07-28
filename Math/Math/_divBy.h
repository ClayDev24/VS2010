#pragma once
#include "utils.h"
#include "defines.h"

namespace math {

	static bool _divBy(const unsigned int &_n, const int &_by) { utils::require(_n>=0);
		return !(_n%_by);
	}
	// **************<<_USAGE_>>****************
	static void _divByUsage() {
		utils::PrintColour_("<<__DIVISIBILIDADE Usage__>>", FBI);
		utils::dicShow("mathematics", "Divisibilidade");

		P_(_divBy(99, 9))
		P_(_divBy(97, 9))
		P_(_divBy(12, 2))
		P_(_divBy(11, 2))
	}

} // math
