#pragma once
#include <stdarg.h>
#include <iostream>
#include <stdio.h>

static double average(int sz, ...) {
	va_list args;                     // A place to store the list of arguments
	double sum = 0;

	va_start(args, sz);              // Initializing arguments to store all values after num
	for(int i=0; i<sz; i++) {        // Loop until all numbers are added
		sum += va_arg(args, double); // Adds the next value in argument list to sum.
		//std::cout << va_arg(args, double) << " " << std::endl;
	}
	va_end(args);                    // Cleans up the list

	return sum/sz;                   // Returns the average
}

static void _sameType() {
	// Computes the average of 3 numbers:
	std::cout << average(3/*<<<sz*/, 12.2, 22.3, 3.5) << std::endl;
	// Computes the average of 5 numbers:
	std::cout << average(5/*<<<sz*/, 3.3, 2.2, 1.1, 5.5, 4.5) << std::endl;
}