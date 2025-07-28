#pragma once

namespace elec {

	static float _potencia(const float &_voltage, const float &_current) {
		// Fórmula:
		// (P)otência = (V)oltage x Current(I)
		return _voltage * _current;
	}
	static float _current(const float &_power, const float &_voltage) {
		// Fórmula:
		// Current(I) = (P)otência / (V)oltage
		return _power / _voltage;
	}

	static float _voltage(const float &_power, const float &_current) {
		// Fórmula:
		// (V)oltage = (P)otência / Current(I)
		return _power / _current;
	}

} // elec