// I need a copy-constructor only if i'm goin' to passa my obj by value as args or return value.
// If that never happens, i dont need a CC.
#include <iostream>
#include "defines.h"
using namespace std;

class A {
	int m_i;
	static int cnt;
public:
    A() { // default constructor
		//static int cnt = 0; // contador
		m_i = 0;
		cout << "A(" << cnt++ << ")..." << endl;
	};	
	A(const A &a) { // Copy constructor	    
		m_i = a.m_i;
	    cout << "copy constructor (" << cnt++ << ")" << endl;
	};
	~A() { cout << "~A(" << --cnt << ")" << endl; };

	void operator=(A a) {
		cout << "operator= (" << cnt++ << ")" << endl;
	};
	inline void setX(int i) { m_i = i; };
	inline int  getX()      { return m_i; } 
};

int A::cnt = 0;

static void func(A a) // A a = myObj; call copy constructor
{ /* do nothing */ }

static A func1() {
	A a; // default constructor (2)
	return a;  // myClass returned_object = a; call copy constructor
}

int main() {
	A a1;		// default constructor (1)
	A a2 = a1;	// call copy constructor (1)
	A a3(a1);	// call copy constructor
	A b;        // default constructor

	P_(a1.getX())
	P_(a2.getX())
	P_(a3.getX())

	a2.setX(55);

	P_(a1.getX())
	P_(a2.getX())
	P_(a3.getX())
	
	a2 = a1;	// call copy constructor (2) and operator= (1)
	A m3(a1);	// explict call to copy constructor (3)
	func(a1);   // myClass as parameter, call copy constructor (4)
	a2 =		// call operator= (2)
		func1();// myClass as return object, call copy constructor (5)
	A &a4 = a1; // don't call any of these. Reference copy only.
	// Same reference:

	P_(a1.getX())
	P_(a4.getX())

	a4.setX(55);

	P_(a1.getX())
	P_(a4.getX())

	A *p_obj = &a1; // don't call any of these. Pointer copy only.

	P_(p_obj->getX())

	system("pause");
	return(0);
}