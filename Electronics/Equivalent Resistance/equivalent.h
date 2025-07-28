#pragma once
#include <iostream>
#include <new>

float _serial(const int* data, int sz) {
	float total = 0;
	// Fórmula:
	// Equivalent Serial Resistace = Currente x Resistance
	// R.eq = R1 + R2 + R3 + Rn...
	for(int i = 0; i < sz; i++) {
		//std::cout << "You've typen: " << data[i] << std::endl;
		total += data[i];
	}
	return total;
}

float _parallel(const int* data, int sz) {
	float R, R_eq, R_total;
	R = R_eq = R_total = 0;

	// Fórmula:
	// R.eq = Rp1 || Rp2 || Rp3 = 1 / (1 / Rp1) + (1 / Rp2) + (1 / Rp3)...

	for(int i = 0; i < sz; i++) {
		R = static_cast<float>(data[i]);
		R_total += (1 / R);
	}

	R_eq = 1 / R_total;
	return R_eq;
}