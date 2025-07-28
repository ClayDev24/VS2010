#pragma once
#include <stdio.h>

struct strc    { int   i;
				 float f; };
union  uni     { int   i;
				 float f; };
enum   collors { red2,
				 blue2 };

// No data member struct:
//struct no_data {}; // C++

// No function support:
//struct with_func { void func();}; // ERROR!
//void with_func::func() {};		// ERROR!

static void _struct() {
// No access specifiers allowed:
//public:		// C++
//private:		// C++
//protected:	// C++
	//strc		 s1;	// C++		Clean	struct
	struct strc  s2;	// C		Awkward struct
	//uni 	     c1;	// C++		Clean   union
	union uni    c2;	// C/C++	Awkward union
	//collors	 e1;	// C++		Clean   enum
	enum collors e2;	// C/C++	Awkward enum

	// jus'to stop warnings:
	s2.i = 0;
	s2.f = 0.0;

	c2.i = 0;
	c2.f = 0.0;
};