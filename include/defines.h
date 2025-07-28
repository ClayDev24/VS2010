#pragma once
#include <iostream> // cout
#include <iomanip>  // std::setprecision()

//#define DEBUG // another flag in _require.h
#ifdef  DEBUG
	// Debug formatted VARs:
	#define D_(x) \
			std::cout << std::setprecision(13) << #x "=> " << x << std::endl;
	#define D(x) \
			std::cout << #x "=> " << x;
	// Debug STRing:
	#define DS_(str) \
			std::cout << #str << std::endl;
	#define DS(str) \
			std::cout << #str;
#else
	#define D_(x) \
			((void)0);
	#define D(x) \
			((void)0);

	#define DS_(str) \
			((void)0);
	#define DS(str) \
			((void)0);
#endif

#define P_(x)  std::cout << std::setprecision(13) /*std::setw(8)*/ << #x "=> " << x << std::endl;
#define P(x)   std::cout << #x "=> " << x;
// Print STRing:
#define S_(str) std::cout << #str << std::endl;
#define S(str)  std::cout << #str;

// Print STRing Variable:
#define SV_(str, v) std::cout << #str << v << std::endl;
#define SV(str, v)  std::cout << #str << v;

#define TAB std::cout << "\t";
#define N std::cout << "\n";

static void _define_print() {
	for(int i=0; i<12; i++)
		D_(i)
};

