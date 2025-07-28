#pragma once
#include <iostream>

#define P(EX) 	cout.width(20); \
				cout.fill('_'); \
				cout.setf(std::ios::left); \
				cout << #EX << ": " << EX << endl;

typedef struct {
	char   c;
	short   s;
	int      i;
	long      l;
	float      f;
	double      d;
	long double ld;
} Primitives; // <= Global var declared.

static void _arithmetic() {
	using std::cout;
	using std::endl;
	cout.setf(std::ios::left);

	int   ai[10];
	double d[10];
	int*    ip = ai;
	double* dp = d;
	P(sizeof(int))
	P(sizeof(double));
	P((long)  ip)
	P((long)++ip) // ONLY Addition n' Subtraction are allowed in pointer arithmetics:
	P((long)  dp)
	P((long)++dp)
// Works with structs (classese & unions) either:
	Primitives  p[10];
	Primitives* pp = p;
	P(sizeof(Primitives))
	P((long)  pp)
	P((long)++pp)
	
	int val[10];
	for(int i=0; i<10; i++)
		val[i] = i; // Give it index values

	int* ip2 = val;
	P(*ip2);
	P(*++ip2)	// Increases ptr (++ > *) then it dereferences it(val).
	P((*ip2)++)	// Dereferences ptr (val) then Increases ptr.
	P(*ip2)		// Dereferences it
	P(*(ip2+5))
	//ip+ip2; // ERROR! Cannot add two pointers!
}