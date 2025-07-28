#pragma once
#include <iostream>
#include <stdarg.h> // IMPORTANT! MUST BE INCLUDED!

static double sum_params(int num,...) {
	double sum = 0.0;
	
	va_list args;
	va_start(args, num); // initialize argptr
	while(num--) // sum the parameters
		sum += va_arg(args, double);
	va_end(args);

	return sum;
}

static void _var_params() {
	// the func'll sum only the number especefied by the first arg, as follow:
	std::cout << "the sum is " << sum_params(0, 5.0, 6.0, 7.0) << std::endl;
	std::cout << "the sum is " << sum_params(2, 1.2, 3.4)	   << std::endl;
	std::cout << "the sum is " << sum_params(3, 1.2, 3.4, 4.4) << std::endl;
}