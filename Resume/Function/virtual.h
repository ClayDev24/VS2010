#pragma once
#include <cstdlib> 	// Declare "system()"
#include <iostream> // cout
#include <typeinfo>

class Shape {
public:
	// LATE BINDING: The code bein' called aint determined until runtime
	// virtual keyword must be only in the base class
	virtual void erase() { std::cout << "Shape.erase()\n"; };
	// EARLY BINDING: The compiler generates a call to a specific function name n' the linker resolves this
	// call to the absolut address o'code to be executed.
	inline void draw() { std::cout << "Shape.draw()\n"; };
};

// Circle "IS-A" shape due to matching methods overriding
class Circle:public Shape {
public:
	// virtual needless here:
	inline void erase() { std::cout << "Circle.erase()\n"; };
	inline void draw()  { std::cout << "Circle.draw()\n";  };
};

// Circle2 "IS-LIKE-A" Shape due to extra method move()
class Triangle:public Shape {
public:
	inline void erase() { std::cout << "Triangle.erase()\n"; };
	inline void draw()  { std::cout << "Triangle.draw()\n";  };
	inline void move()  { std::cout << "Triangle.roll()\n";  };
};

static void doStuff(Shape& s) { // Upcastin' derived classes to its base Shape type.
	// Polimorphism: The right specific type method will be executed only if the word virtual was placed in the derived class.
	s.erase();
	s.draw();
};
	
static void _virtual() {
	Shape  s;
	Circle  c;
	Triangle t;
	// upcastin':
	doStuff(s);
	doStuff(c);
	doStuff(t);
}
