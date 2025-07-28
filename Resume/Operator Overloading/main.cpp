//#include "vld.h" // No memory leaks DETECTED!
#include <fstream>
#include "Byte.h"
#include "Integer.h"
using namespace std;

#define TRY2(OP) \
	cout << "b1 = ";   b1.print(cout); \
	cout << ", b2 = "; b2.print(cout); \
	cout << ";  b1 " #OP " b2 produces "; \
	(b1 OP b2).print(cout); \
	cout << endl;

// Conditionals:
#define TRYC2(OP) \
	cout << "b1 = ";   b1.print(cout); \
	cout << ", b2 = "; b2.print(cout); \
	cout << ";  b1 " #OP " b2 produces "; \
	cout << (b1 OP b2); \
	cout << endl;

#define TRY(OP) \
	cout << "c1 = "; c1.print(cout); \
	cout << ", c2 = "; c2.print(cout); \
	cout << ";  c1 " #OP " c2 produces "; \
	(c1 OP c2).print(cout); \
	cout << endl;

#define TRYC(OP) \
	cout << "c1 = "; c1.print(cout); \
	cout << ", c2 = "; c2.print(cout); \
	cout << ";  c1 " #OP " c2 produces "; \
	cout << (c1 OP c2); \
	cout << endl;

void k(Byte& b1, Byte& b2) {
	b1 = b1 * b2 + b2 % b1;

	b1 = 9; b2 = 47;
	TRY2(+)  TRY2(-)  TRY2(*)   TRY2(/)
	TRY2(%)  TRY2(^)  TRY2(&)   TRY2(|)
	TRY2(<<) TRY2(>>) TRY2(+=)  TRY2(-=)
	TRY2(*=) TRY2(/=) TRY2(%=)  TRY2(^=)
	TRY2(&=) TRY2(|=) TRY2(>>=) TRY2(<<=)
	TRY2(=) // Assignment operator

	b1 = 9; b2 = 47;
	TRYC2(<) TRYC2(>) TRYC2(==) TRYC2(!=) TRYC2(<=)
	TRYC2(>=) TRYC2(&&) TRYC2(||)

	// Chained assignment:
	Byte b3 = 92;
	b1 = b2 = b3;
}

void h(Integer& c1, Integer& c2) {
	// A complex expression:
	c1 += c1 * c2 + c2 % c1;

	TRY(+) TRY(-) TRY(*) TRY(/)
	TRY(%) TRY(^) TRY(&) TRY(|)
	TRY(<<) TRY(>>) TRY(+=) TRY(-=)
	TRY(*=) TRY(/=) TRY(%=) TRY(^=)
	TRY(&=) TRY(|=) TRY(>>=) TRY(<<=)

	// Conditionals:
	TRYC(<) TRYC(>) TRYC(==) TRYC(!=) TRYC(<=)
	TRYC(>=) TRYC(&&) TRYC(||)
} 

int main() {

	cout << "member functions:" << endl;
	Byte b1(47), b2(9);
	k(b1, b2);	

	cout << "friend functions" << endl;
	Integer c1(47), c2(9);
	h(c1, c2);

	system("pause");
	return(0);
}
