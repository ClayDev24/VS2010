#pragma once

namespace elec {
	float voltage(const float &_current, const float &_resistance) {
		// Fórmula:
		// (V)oltage = Current(I) x (R)esistance
		return _current * _resistance;
	}

	float current(const float &_voltage, const float &_resistance) {
		// Fórmula:
		// Current(I) = (V)oltage / (R)esistance
		return _voltage / _resistance;
	}

	float resistance(const float &_voltage, const float &_current) {
		// Fórmula:
		// (R)esistance = (V)oltage / Current(I)
		return _voltage / _current;
	}

} // elec