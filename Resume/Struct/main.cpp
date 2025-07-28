//#include "vld.h" // No memory leaks DETECTED!
#include "matrix_de_estruturas.h"
#include "struct_as_parameters.h"

// Defaults to public:
typedef struct self  { int   i; // name might change...
					   self* s; } strc;  // typedef   named struct (for selfreferencin' usage)
typedef struct		 { int   i;
					   float f; } strc2; // typedef unnamed struct
		struct strc3 { int   i;			 //					struct
					   float f; } num;	 // Declarin'a global var num.

// C/C++ compiler produdes identical sizes on codes when compilin'structs w/ functions on'em.
// The funcs doesn't overweight the structs. This reassures t2 C programmers Hard coded codes:
struct with_func {
	int   i;
	float f;
	void  a(); // Structs w/ funcs are said to be new data types (state n' behavior).
};
void with_func::a() {};

struct just_memb {
	int   i;
	float f;
};

// Anomaly struct (no data members) - Sole task: Scope function names:
struct zero_memb { void a(); };
void zero_memb::a() {};

int main() {
	using namespace std;
	strc		 s1;	// C/C++ Clean   typedef
	self		 s2;	// C++   Clean   struct
	struct self  s3;	// C/C++ Awkward struct
	strc2		 s4;	// C/C++ Clean   typedef
	//struct strc2 s5;  //       ERROR!  Unnamed struct
	strc3		 s6;	// C++   Clean   struct
	struct strc3 s7;	// C/C++ Awkward syntax

	

	cout << "Structure's size is the combination of all o'its members:\n"; // But sometimes for processor efficiency purposes it adds some extra bytes
	cout << "sizeof(with_func):" << sizeof(with_func) << endl;
	cout << "sizeof(just_memb):" << sizeof(just_memb) << endl;
	cout << "sizeof(zero_memb):" << sizeof(zero_memb) << endl;
	cout << " zero-sized structs would produces the same adrs o'the next obj...\n";
	// ...and so they wont be distinct. 
	// One o'the fundamental rules o'OOP is that each obj must have an unique adrs.

	_matrixDeEstruturas();
	_structAsParameters();

	system("pause");
	return(0);
}