#pragma once
//#include <vld.h> // memo leak check
#include <iostream>
#include "defines.h"
using namespace std;

#define SZ(x, type) PARRAY(x, sizeof(x)/sizeof(*x), type); cout << endl;
//show(x, sizeof(x)/sizeof(*x)); cout << endl;

typedef struct Str{
	int   x;
	float y;
	friend ostream& operator<<(ostream& os, const Str &p) {
		return os << p.x << ", " << p.y << endl;
	};
} Point;

class Z {
	int i, j; // privates
public:
	// Compiler default constructor (defaults properties to zero) if there's any constructor declared!
	//Z():i(4), j(4) {}; 
	Z(int _i=0, int _j=0):i(_i), j(_j) {};
	friend ostream& operator<<(ostream& os, const Z &z) {
		return os << z.i << ", " << z.j << endl;
	};
};
// Passin'arrays to functions:
void show(int m[][2], int sz, int sz2); // Multi-dimensional

// Creatin' arrays o'static objs on the static data section:
void _static() {
	const int sz = 5;
	int i = 10;
	//int a0[i]; // ERROR: Expected constant expression
	int a1[10];  // OK
	P_(sizeof(int));
	while(i--)	// Addresses:
		cout << "&a1[" << i << "]: " << (long)&a1[i] << endl;
// Aggregate initializations: (A way 2 initialize array elements w/out a loop)
	int	   a2[sz];					SZ(a2, int) // Not initialized at all
	int    a3[sz] = {};				SZ(a3, int) // Default to 0
	int    a4[sz] = {0};			SZ(a4, int) // Default to 0
	int    a5[sz] = {1};			SZ(a5, int) // Default to 0, but first
	bool   a6[sz] = {true};			SZ(a6, bool)// Default to false, but first
	int    a7[]   = {3, 4, 5};		SZ(a7, int) // Automatic countin'. Array size based on number o'initializers.
	double a8[sz] = {1.0, 1.1, 1.2};SZ(a8, double)// Defaults to zero but the very 3!
	char  *a9[2] = {"John", "Mary"};SZ(a9, char*) // Only for the initialized pointers! 
	// Arrays always takes a contignuous block o'memo:
	char c[]={'H','e','y','a','\0'};SZ(c, char)
	// Initializing arrays with String Literals:
	char c2[] = "Literal";			SZ(c2, char) // null char ('\0') auto appended at the end.
	P_(c2)
	// Pointer to arrays:
	int a10[1] = {333};				SZ(a10,int)
	int *ip    = a10;				SZ(ip, int)
	//a = ip; // ERROR! Arrays arent Lvalues!
	// Arrays o'structs (direct initialization):
	Point p1[]  = {{33, 44.5},  {66, 77.5}};SZ(p1, Point)
	Point p2[3] = {{33, 44.5},  {66, 77.5}};SZ(p2, Point) // The 2nd obj is initialized to zero.
	// Arrays o'classes (initialized through constructors):
	Z z1[]  = {Z(1, 2),Z(3, 4),Z(5, 6)};SZ(z1, Z)
	// Uses default constructors, if any:	
	Z z2[sz];							SZ(z2, Z)
	// Multidim arrays:
	int a15[2][2] = {33, 44, 55, 66};	show(a15, 2, 2);
}

void show(int m[][2], int sz, int sz2) {
	for(int i=0; i<sz; i++)
		for(int i2=0; i2<sz2; i2++)
			cout << "m_dim[" << i << "][" << i2 << "]: " << m[i][i2] << endl;
}