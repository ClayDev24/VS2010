// Several meanings:- Controls location storage; visibility and linkage of a name.
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;

// 1- File scoped var (internal linkage). Only available in this file:
static int fs = 0;
// External Linkage. (Static Storage)
//int global = 0;
// same as:
//extern int global = 0;

// Global vars n' funcs definition defaults to external linkage. Use...
// static to force internal linkage;
// extern to state external linkage (redundant in C. Sometimes needed in C++).
//*static/static*/ void func() {
void func() {
	// 2- Persistent value. Used Inside a function:
	static int i = 0;
	cout << "i = " << ++i << endl;
}

// 3- Static Class Member:
class Base {
	static int instCnt; // 3-a Retain its value between obj intances
	int m_id; // Automatic vars have no linkage. The compiler dont know 'bout its existence.
	static const int num; // 3-b Used as a class constant. External linkage. Could be seen by all instances of the class.
	// enumhack:
	enum { i2 = 100 };
	// Automatic counting works with static arrays.
	// Arrays, Non-integral and non-const statics 
	// must be initialized externally:
	static const int scInts[];
public:
	Base() {
		m_id = ++instCnt;
		cout << "Base()" << m_id << endl;
	}
	~Base() {
		cout << "~Base()" << m_id << endl;
		--instCnt;
	}
	inline int count() const { return instCnt; }
	// Static member function: Like a global one but dont pollute the global or local namespace
	static void func() { cout << "Static member function called..." << endl; };
};

// The same instance for all objs ot the classa Base. Defined only once:
int Base::instCnt = 0;

const int Base::scInts[] = {
	99, 47, 33, 11, 7
};

// For functions (changes only the visibility):
extern void f() {}; // External linkage
// same as sayin: void f() {};
static void g() {}; // Internal linkage. Visible only in this translation unit.

int main(void) {
	// 2- Persistent value:
	for(int i=0; i<10; i++)
		func();

	// 3- Static Class Member:
	Base *b[10];	
	for(int i=0; i<10; i++)
		b[i] = new Base;
	
	cout << "Instance count #1: " << b[0]->count() << endl;
	
	for(int i=0; i<9; i++)
		delete b[i];
	
	cout << "Instance count #2: " << b[9]->count() << endl;
	delete b[9]; // No more instances o'Base obj...

	// Local var as extern:
	extern int localExt; // must be defined externally.
	cout << "localExt: " << localExt << endl;

	// Both ways to call a static member function:
	// 1- using scope resolution, without a instance obj:
	Base::func();
	// 2- Within an instance of a class:
	Base ba;
	ba.func();
	
	system("pause");
	return(0);
}