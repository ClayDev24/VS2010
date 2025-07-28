#pragma once

// C/C++  Multiple declarations of a function:
void _func_misuse(float); // __func_misuse
void _func_misuse(float);
// C++ Function overloading declaration:
// C   Unsafe Type Checking (arg type mismatch):
void _func_misuse(int);		// (33.3, 1.23) works
void _func_misuse(float);	// (33.3, 1.23) works
void _func_misuse(char);	// (33.3, 1.23) works
void _func_misuse(long);	// (33.3, 1.23) works
void _func_misuse(short);	// (33.3, 1.23) works

// C++ Function overloading definition:
// C   Compiler: already defined in main.obj
//void _func_misuse(int i) {}; // Must be only 1 available. No matter arg types
