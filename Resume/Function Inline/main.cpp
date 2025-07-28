//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;

class C {
	int i;
public:
	// Any function defined within a class body is automatically inline
	C():i(0) {} // Inline constructor. Not hidden activities.
	void show() { cout << "i: " << i << endl; };
	inline void  inc(int = 0, int = 0);
	void inc2(int = 0, int = 0); // NOT inlined
	// NOT INLINE, two complicated (contains for loop):
	inline void complicated() {
		for(int i=0; i<100; i++)
			cout << "i:= " << i << endl;
	};
};

inline void C::inc(int, int)  { i++; }; // Inline func due to keyword
void C::inc2(int, int) { i++; }; // NOT Inlined

class Member { 
	int i, j, k;
public: 
	Member(int x = 0) : i(x), j(x), k(x) {} 
	~Member() { cout << "~Member()..." << endl; } 
}; 

class WithMembers { 
	Member q, r, s; // Have constructors 
	int i; 
public: 
	WithMembers(int ii) : i(ii) {} // Trivial? 
	~WithMembers() { 
		cout << "~WithMembers()..." << endl; 
	} 
}; 

const int clay = 24;

int main() {
	C c;
	//c.show();
	//c.inc();
	//c.show();
	
	// Inline functions. 
	// The inline code does occupy space, but if the function is small, this can actually take less
	// space than the code generated to do an ordinary function call: compile with: bcc32 -S Inline.cpp 
	// and see the file Inline.asm:
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	c.inc();
	// not inline
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	c.inc2();
	
	c.complicated();
	
	WithMembers wm(1);

	cout << clay << endl;
	
	system("pause");
	return(0);
}