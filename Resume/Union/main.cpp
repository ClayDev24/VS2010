// The size and simple use of a union
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "supervar.h"
#include "union_class.h"
using namespace std;

typedef union uni  { int   i;
				 	 float f; } uni; // typedef   named union
typedef union      { int   i;
					 float f; } uni2;// typedef unnamed union
		union uni3 { int   i;
					 float f; } num; // Declarin'a global var num

union Packed { // Declaration similar to a class
	char   c;
	short  s;
	int    i;
	long   l;
	float  f;
	double d; // The largest element
	// The union will be the size of a double
};

int main(void) {
	uni		     u1;	// C/C++ Clean   typedef
	union uni    u2;	// C/C++ Awkward union
	uni2 	     u3;	// C/C++ Clean   typedef
	//union uni2 u4;	//       ERROR! Unnamed union
	uni3 	     u5;	// C++   Clean   union
	union uni3   u6;	// C/C++ Awkward union

	cout << "sizeof(Packed): " 
		 <<  sizeof(Packed) << endl;
	
	// Supervar:
	_supervar();
	// Union Class:
	_union_class();

	system("pause");
	return(0);
}