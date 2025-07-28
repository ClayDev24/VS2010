//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\div.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.
#include <string.h>
//#include <cstdio>	// Standard C lib in C++ lib.
//#include <cstdlib>// Standard C lib in C++ lib.
//#include <cstring>
//using namespace std; // Used with Borland C++ compiler.

void division() {
	div_t  divresult;
	ldiv_t ldivresult;
// div (int):
	divresult = div(38, 5);
	printf("38 div 5 => %d, remainder: %d.\n", divresult.quot, divresult.rem);
// ldiv (long):
	ldivresult = ldiv(1000000L, 132L);
	printf ("1000000 div 132 => %ld, remainder %ld.\n", ldivresult.quot, ldivresult.rem);
}


