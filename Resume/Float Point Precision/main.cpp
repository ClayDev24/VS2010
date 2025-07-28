// Floating-point_number_precision.c
// Compile options needed: none. Value of c is printed with a decimal
// point precision of 10 and 6 (printf rounded value by default) to
// show the difference
#include <iostream>
#include <stdio.h>
#include "utils.h"

#define EPSILON 0.00001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

bool floatEq(const double &_x, const double &_constant) {
	using namespace std;
	bool result=false;
	P_(_constant)
	P_(EPSILON)
	cout << _constant - EPSILON << " < " << _x << " = " << ((_constant - EPSILON) < _x) << endl;
	cout << _constant + EPSILON << " > " << _x << " = " << ((_constant + EPSILON) > _x) << endl;
	result = (((_constant - EPSILON) < _x) && (_x <( _constant + EPSILON)));
	return result;
}

int main() {
	float a, b, c;

	a = 1.345f;
	b = 1.123f;
	c = a + b + 0.00001;

	P_(floatEq(c, 2.468))

	if (FLOAT_EQ(c, 2.468)) // Remove comment for correct result
		//if (c == 2.468)            // Comment this line for correct result
		printf_s("They are EQUAL!\n The value of c is \n %13.10f \n "
		"or \n %f\n",c,c);
	else
		printf_s("They are NOT equal!\n The value of c is \n %13.10f \n "
		"or \n %f\n",c,c);


	system("pause");
	return(0);
}