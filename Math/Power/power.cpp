#pragma once
#include "power.h"

double math::power(double _base, int _exponent) {
	// special case:
	if(_exponent == 0)
		return 1;
	double pow = _base;
	if(_exponent > 0)
		while(_exponent-- > 1)
			pow *= _base;
	else // > 0
		while(_exponent++ < 1)
			pow /= _base;

	return pow;
}
// 22-digit limit:
static unsigned long long math::power2(unsigned int _base, int _exponent) {
	// special case:
	if(_exponent == 0)
		return 1;
	unsigned long long pow = static_cast<unsigned long long>(_base);
	while(_exponent-- > 1)
		pow *= _base; 
	return pow;
}
// ***************** <<_USAGE_>> *****************
void math::powerUsage() {

	for(int base=2; base<=10; base++)
		for(int exp=0; exp<21; exp++) {
			printf("%0.0f\n", power(base, exp));		// 23 digit limit
			std::cout << power2(base, exp) << std::endl;// 20 digit limit
		}

//	for(int e=0; e<65; e++) {// 23 digit limit
//		printf("%0.0f\n", power(2, e));			// 20 digit limit
//		std::cout << power2(2, e) << std::endl;	// 19 digit limit
//	}

//	for(int e=0; e<22; e++) {// 23 digit limit
//		printf("%0.0f\n", power(9, e));			// 21 digit limit
//		std::cout << power2(9, e) << std::endl;	// 20 digit limit
//	}
}