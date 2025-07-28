#pragma once
#include "defines.h"

namespace math {

	static unsigned long long _power(unsigned int _base, int _exponent) {
		// special case:
		if(_exponent == 0)
			return 1;
		unsigned long long pow = static_cast<unsigned long long>(_base);
		while(_exponent-- > 1)
			pow *= _base; 
		return pow;
	}
	// ***************** <<_USAGE_>> *****************
	static void _powerUsage() {

		//utils::dicShow("mathematics", "Potenciação");

		utils::Console cmd;//(50, 20, "<<_POWER USAGE_>>");
		cmd.setColour(FGI);
		cmd.prtColorReturn("\n******<<_POWER USAGE_>>******\n", FRI);
		utils::PrintColour_("23 digit limit:\n", FGI);

		for(int base=2; base<=10; base++)
			for(int exp=0; exp<23; exp++) // 23 digit limit
				P_(_power(base, exp))
		
		for(int exp=0; exp<60; exp++) // 23 digit limit
			P_(_power(2, exp))
	}
}; // math