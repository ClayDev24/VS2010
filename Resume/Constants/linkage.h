// const in Header Files=> Definition in a single place. Ready to be redistributed in translation units by #include's
#pragma once
#include <iostream>
// You must always assign a value to a const when you define it, EXCEPT when using extern:
extern const int val; // External Linkage: Several translation units must be able to see it, thus Storage allocation.

void _extern_const() {
	std::cout << val << std::endl;
}
// C   -> Default to External Linkage: Several translation units must be able to see it, thus Storage allocation.
// C++ -> Default to Internal Linkage: It's visibility is within the file it's defined n' cannot be seen in other translation units. Thus NO Storage Allocation is needed.

// C++ cannot always avoid allocatin storage for a const:
// Outside all functions:
const int a  = 100;			// C++ => Internal Linkage: file scoped (visible only whithin this file).
// Constant expression:
const int a2 = a + 10;		// Internal Linkage: Compiler still calculates constant expression: 100+10=110.
char buf[a2 + 10];			
// Address:
const int ad = 0;
long adrs    = (long)&ad;	// External Linkage: Forces Storage to be allocated.

// Aggregation consts:
const int b[] = { 1, 2, 3, 4 }; // External Linkage: Needs storage allocation
//float f[b[3]];				// External Linkage: Cannot know the value o'storage at compile-time.
