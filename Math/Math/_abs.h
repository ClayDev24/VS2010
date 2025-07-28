#pragma once
#include "utils.h"
#include "defines.h"
//#include "..\..\Utilidades\Utilidades\Dictionary.h"

namespace math {
	// M�dulo ou valor ABSoluto de um n�mero:
	static signed long _abs(const signed long &_n) {
		//signed long absolute = _n;
		if(_n<0)
			return _n*(-1);//_absolute *= 
		return _n;
	}
	//******************_Didatic Version_*********************
	static signed long _absD(const signed long &_n) {
		signed long abs=_n;
		if(_n<0)
			abs *= -1;//_absolute *= 
	
		std::cout << "|" << abs << "|" << std::endl;
		return abs;
	}
	// *********************<<_USAGE_>>***********************
	static void _absUsage() {
		utils::PrintColour_("<<__ABSOLUTE Value (ABS)__>>", FRI);
		utils::dicShow("mathematics", "Abs");

		// Valor (ABS)oluto:
		P_(abs(-2))
		P_(abs(-1))
		P_(abs(0))
		P_(abs(1))
		P_(abs(2))
		_absD(2);
		_absD(-2);
	}

} // math