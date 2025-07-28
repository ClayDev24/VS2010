#pragma once
#include "utils.h"

namespace elec {
	
	static float _voltage_out(float _Vs, float  _R1, float _R2) {
		float V2 = 0;
		// Fórmula: (3 equivant versions:
		// V2 = (_R2 / (_R1 + _R2)) * _Vs; // (Vsupply)
		// V2 = (_Vs / (_R1 + _R2)) * _R2;
		// V2 = (_Vs * _R2) / (_R1 + _R2)

		// V2 = (_R2 / (_R1 + _R2)) * _Vs;
		// V2 = (_Vs / (_R1 + _R2)) * _R2;

		V2 = (_Vs*_R2) / (_R1+_R2);
		return V2;
	}
	static float _resistor2() {
		float R2 = 0;
		// Fórmula:
		return R2;
	}
} // elec