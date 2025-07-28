//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "rotate.h"
using namespace std;

// Stringizing: Takes a identifier and turn it into a character array.
#define P(x) cout << #x << "=> " << x << endl;

int main() {
	int   a,  b;
	float f1, f2;  // Applies to doubles, too
	a  = 5;   b  = 5;
	f1 = 5.0; f2 = 5.0;
	P(a);  P(b);
	P(f1); P(f2);

	cout << "\nUnary Operators:\n";
	P(!a); // Logical NOT
	P(~a); // Complements (inverts all bits)
	P(-a); // (-a)*1. Produces a negative number if positive n' vice-versa.
	P(+a); // (+a)*1. Actually do nothing.

	cout << "\nUnary Increase and Decrease Postfix Operators:\n";
	P(a++); // Evaluates last
	P(a--); // Idem

	cout << "\nUnary Increase and Decrease Prefix Operators:\n";
	P(++a); // Evaluates first
	P(--a); // Idem

	cout << "\nArithmetic Operators:\n";
	P(a + b); // subtraction
	P(a - b); // addition
	P(a * b); // multiplication
	P(a / b); // division
	P(a % b); // modulo (returns the remainder o'tha division)

	cout << "\nCompound Assignment Operators:\n";
	P((a  = b)); // lvalue = rvalue;
	P((a *= b));
	P((a /= b));
	P((a %= b)); // The following only works with integers:
	P((a += b));
	P((a -= b));
	// defined twice below:
	P((a <<=b));
	P((a >>=b));
	P((a &= b));
	P((a ^= b));
	P((a |= b));

	cout << "\nComma Operator(,):\n";
	P((a = (b=3, b+2))); // Would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3.

	cout << "\nRelational and Equality Operators (returns 1(true) or 0(false):\n";
	cout.setf(ios::boolalpha);
	P((a==b)); // Equal to
	P((a!=b)); // Not Equal to
	P((a> b)); // Greater Than
	P((a< b)); // Less Than
	P((a>=b)); // Greater Than or Equal to
	P((a<=b)); // Less Than or Equal to
	cout.unsetf(ios::boolalpha);

	cout << "\nLogical Operators:\n";
	P(( !a )); // NOT op
	P((a&&b)); // AND op
	P((a||b)); // OR  op

	cout << "\nConditional (ternary) Operator:\n";
	P((7==5?4:3)); // 7=>3 - 5=>3

	cout << "\nBitwise Operators:\n"; // Manipulate individual bits in a number (works jus'w/ ints).
	// Unary:
	P(( ~a )); // NOT. one complement (bit inversion)
	// Binary:
	P((a & b)); // AND
	P((a | b)); // Inclusive OR
	P((a ^ b)); // Exclusive OR (XOR)
	// Shift Ops:
	P((a << b)); // SHR. Shift Left 
	P((a >> b)); // SHL. Shift Right
	// Rotate Ops:
	P(int(rol(1)));
	P(int(ror(1)));

	cout << "\nBitwise Compound assignment operators:\n";
	P((a  &= b)); // AND
	P((a  |= b)); // Inclusive OR
	P((a  ^= b)); // Exclusive OR (XOR)
	P((a <<= b)); // SHR. Shift Left
	P((a >>= b)); // SHL. Shift Right		

	cout << "\nExplicit Type Casting Operator:\n";
	P((int)f1);
	P(int(f1)); // another way

	cout << "\nsizeof() Operator:\n";
	P(sizeof(char));

// Precedence o' Operators:
// See:
// E:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\doc\tutorial\operators.html
// on page

	system("pause");
	return(0);
}
