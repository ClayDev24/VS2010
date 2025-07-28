#pragma once

//The usage of access specifiers doesn't grant the order o'member will be consistent as C.
struct B {
// IMPLEMENTATION:
private: // Hiddin'member variables
	char  c1;
// INTERFACE:
public:
	void set(char c) {	// Exposin'its interface
		c1 = c;			// Now on ya can change internals at will
	};
	void show() {
		std::cout << "c1: " << c1 << std::endl;
	};
};

static void _private() {
	B b;
	// Start'up a public struct interface can broken existin'code;
	//b.c1 = 'a'; // ERROR
	//std::cout << "Showin'up c1: " << b.c1 << std::endl;// ERROR
	// Access to B member variables only through its public interface:
	b.set('z');
	b.show();

// The compiler is the only thing that knows about the protection level of class members. 
// There's no access control info mangled in2 the member name that carries through 2 the linker.
// All the protection checkin'is done by the compiler. It has vanished by runtime. For instance:

	// Breakin'up the private access to B member var accessin'it direct through a pointer:
	std::cout << "sizeof(B):" << sizeof(B) << std::endl; // Exatly 1 byte, just like a char
	char* pc = reinterpret_cast<char*>(&b);				 // Cast to a ptr o'char
	*pc = 'w';	// Changin' its value w/out passin' through its public interface
	b.show();	
};