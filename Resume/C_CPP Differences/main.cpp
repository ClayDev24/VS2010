//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <stdio.h>
#include "bool_key.h"
#include "cast_syntax.h"
#include "constants.h"
#include "empty_arg_list.h"
#include "enumerator.h"
//#include "function_overloading.h" // comment out
#include "no_return_type.h"
#include "optional_identifiers.h"
#include "struct.h"
#include "struct_member_function.h"
#include "this_keyword.h"
#include "void_func_pointer.h"

// C Unsage Type Checking (type mismatch):
void _func_misuse(int);		// (33.3, 1.23) works
void _func_misuse(float);	// (33.3, 1.23) works
void _func_misuse(char);	// (33.3, 1.23) works
void _func_misuse(long);	// (33.3, 1.23) works
void _func_misuse(short);	// (33.3, 1.23) works

void _func_misuse2(int i, int i2) {};// (33.3) DONT WORK!

int main() {
	// C - Declarations restricted to the beginnin'o scope:
	// C99 - The updated version o'Standard C, allows vars to be definide at any point in a scope, like C++.
	float f = 4.4f;
	int   i = 5;
	// ERROR: declaration inside control flow structure
	for(/*int*/ i=0; i>10; i++);

	_constants();
//	_bool_key();
//	_cast_syntax();
//	_empty_arg_list();
	_enumerator();
	// C Type unsafe linkage:
	// Compiler DON'T checks for arg TYPES at all:
//	_func_misuse(33.3, 1.23); // No args type & number check
	// Compiler ONLY checks for NUMBER of args:
	//_func_misuse2(33.3); // Compiler: too few arguments for call
//	_no_return_type();
//	_optional_identifiers();
//	_struct();
//	_void_func_pointer();

	system("pause");
	return(0);
}