//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\qsort.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.

int compare(const void *v1, const void *v2) {
	return (*(int*)v1 - *(int*)v2);
}

void quick_sorting() {
	int values[] = {40, 10, 100, 90, 20, 25};
	int i;
	qsort(values, 6, sizeof(int), compare);
	for(i=0; i<6; i++)
		printf("values[%d]:%d\n", i, values[i]);
}