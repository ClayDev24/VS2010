// Singleton: Static member of same type, ensures that
// only one obj of this type exists.
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream> // cout
#include "defines.h"
using namespace std;

class Egg {
	static Egg e; // Definin' singleton
	int m_i;
	Egg(int _i):m_i(_i) {} // Private constructor
	Egg(const Egg&); // Prevent copy-construction. No definition is needed 'cuz it's never gets called.
public:
	static Egg* instance() { return &e; }
	inline void print() const { cout << "m_i: " << m_i << endl; }
};

Egg Egg::e(47); // Declarin' singleton

int main() {
	//Egg x(1); // Error -- can't create an Egg
	// You can access the single instance:
	Egg::instance()->print();
	Egg *e1 = Egg::instance();
	Egg *e2 = Egg::instance();
	e1->print();
	e2->print();

	P_(e1)
	P_(e2)

	// Copyin' singleto obj:
	//Egg egg3(*egg);
	//cout << "egg3: " << &egg3 << endl;

	system("pause");
	return(0);
}
