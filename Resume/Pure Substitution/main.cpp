//#include "vld.h" // No memory leaks DETECTED!
#include <cstdlib> 	// Declare "system()"
#include <iostream> // cout
#include <typeinfo>
using namespace std;

class Shape {
public:
	// virtual keyword must be only in the base class
	inline virtual void erase() { cout << "Shape.erase()" << endl; };
	inline void draw()          { cout << "Shape.draw()"  << endl; };
};

// Circle "IS-A" shape due to matching methods overriding
class Circle:public Shape {
public:
	// virtual needless here:
	inline void erase() { cout << "Circle.erase()" << endl; };
	inline void draw()  { cout << "Circle.draw()"  << endl; };
};

// Circle2 "IS-LIKE-A" Circle due to extra method roll()
class Circle2:public Circle {
public:
	inline void erase() { cout << "Circle2.erase()" << endl; };
	inline void draw()  { cout << "Circle2.draw()"  << endl; };
	inline void roll()  { cout << "Circle2.roll()"  << endl; };
};

static void doStuff(Shape& s) { // Upcastin' derived classes to its base Shape type.
	s.erase();
	s.draw();
	// As long as Shape aint got any roll() method it cannot made a "pure substitution" here, so the error:
//	s.roll(); //ERROR 
	//Solution is RTTI:
	Circle2 *c = (Circle2*)&s; // upcasting Shape to Circle2
	c->roll();
};
	
int main() {
	Shape   s;
	Circle  c;
	Circle2 c2;
	// Upcastin':
	doStuff(s);
	doStuff(c);
	doStuff(c2);

	system("pause");
	return(0);
}
