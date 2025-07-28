#pragma once

namespace elec {

	static float _potencia(const float &_voltage, const float &_current) {
		// F�rmula:
		// (P)ot�ncia = (V)oltage x Current(I)
		return _voltage * _current;
	}
	static float _current(const float &_power, const float &_voltage) {
		// F�rmula:
		// Current(I) = (P)ot�ncia / (V)oltage
		return _power / _voltage;
	}

	static float _voltage(const float &_power, const float &_current) {
		// F�rmula:
		// (V)oltage = (P)ot�ncia / Current(I)
		return _power / _current;
	}

} // elec