// Thinking in C++ - Vol1 - 2 edition - Constants (pag 333)
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "const_in_class.h"
#include "compile_time_constant_in_class.h"
#include "breaking_constness.h"
#include "character_array_literals.h"
#include "function_args_n_return_values.h"
#include "linkage.h"
#include "run_time_constant.h"
#include "standard_argument_passing.h"
#include "value_substitution.h"

// (1) LINKAGE:
// Val var declared in linkage.h. Defined right here:
// const int val; // C++ error, must be initialized or declarated as 'extern':
extern const int val = 99;	// C++ definition. C always definition.
// extern const int val;	// C++ declaration.

// (2) POINTER TO CONST:
const int *pc1; // Changeble ptr, unchangeble var.
int const *pc2;

// (3) CONST POINTERS:
int c = 1;
int *const c2 = &c; // Unchangeble ptr, changeble var.

// (4) CONST POINTER TO CONST OBJ:
const int* const d  = &c; // Neither (prt/var) can be changed.
int const* const d2 = &c;

// Formating style: Put one ptr definition per line to avoid confusing.
int *u = &c, v = 0; // Creates an int ptr and a non-ptr int.

const int* const w() {
	static int i = 5555; // Must be static, 'cuz automatic vars are cleaned up after function exits.
	return &i;
}

void Y::print() const { // const keyword must be placed both: definitio n' declaration of the function.
	//i++; // ERROR! Cannot modify member vars inside const func.
	//f(); // ERROR! Cannot call non const func inside const func.
	std::cout << "i: " << i << std::endl;
};
void _value_substitution();
void _standard_argument_passing();
void _const_in_class();
void _run_time_constant();

int main(void) {
	using namespace std;
	_extern_const();
//	_value_substitution();
//	_breaking_constness();
//	_character_array_literals();
//	_standard_argument_passing();
//	_const_in_class();
//	_const_return_values();
	_compile_time_constant_in_class();
//	test3();

	//!  int* ip2 = w(); // Not OK
	const int* const ccip = w(); // OK
	const int* cip2 = w(); // OK
	//!  *w() = 1; // Not OK

	cout << "static automatic var: " << *cip2 << endl;

	system("pause");
	return(0);
}
//const int val = 66; // Actually need a default value!

// HINTS:

// ALWAYS use constant vars whenever possible. This not only provides insurance against anadvertant changes, it also allows
// the compiler to generate more efficient code by eliminating storage and memory reads.