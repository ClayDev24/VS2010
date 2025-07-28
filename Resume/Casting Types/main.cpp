//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "static_cast.h"
#include "const_cast.h"
#include "reinterpret_cast.h"
#include "upcasting.h"
using namespace std;

class CDummy {
	float i, j;
public:
	CDummy() { i = 33; j = 44; }
};

class CAddition {
	int x, y;
public:
	CAddition(int a, int b) { x=a; y=b; }
	int result() { return x+y; }
};

class CDad {
	const int m_i;
public:
	CDad():m_i(1) {}
	virtual void print(void) { cout << "Dad() " << m_i << endl; }
};

class CSon:public CDad {
	const int m_i;
public:
	CSon():m_i(2) {}
	virtual void print(void) { cout << "Son() " << m_i << endl; }
};

int main(void) {
	_static_cast();
	_const_cast();
	_reinterpret_cast();
	_upcasting();

	CDummy dummy;
	CAddition * padd;
	// Explicit type-casting allows to convert any pointer into any other pointer type, independently of the types they point to.
	padd = (CAddition*)&dummy; // Explicit type cast leads to error of incompatible type casting.
	cout << padd->result() << endl;
	// Error: Only allowed for polimorphic classes:
	//padd = dynamic_cast<CAddition*>(&dummy);
	CSon s;
	s.print();
	CDad d;
	d.print();
	//	s = d;	NOT ALLOWED
	//	s.print();
	CDad* pd = &d;
	pd->print();
	pd = &s;
	pd->print();
	//	d = s;	NOT ALLOWED
	//	d.print();

	// Function call cast1;
	float a = float(200);
    // This is equivalent to:
    float b = (float)200;

	system("pause");
	return(0);
}