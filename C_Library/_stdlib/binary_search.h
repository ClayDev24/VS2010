//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\bsearch.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.
#include <string.h>

int compareints(const void *a, const void *b);

bin_search() {
	int values[] = { 10, 20, 25, 40, 90, 100 };
	char strvalues[][20] = {"some", "example", "strings", "here"};

	int  *pItem;
	int  key = 40;
	char *pItem2;
	char key2[20] = "example";
	
	pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
	if(pItem)
		printf("%d is in the array.\n", *pItem);
	else
		printf("%d is not in the array.\n", key);
	
	/* sort elements in array: */
	qsort(strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);
	
	/* search for the key: */
	pItem2 = (char*)bsearch(key2, strvalues, 4, 20, (int(*)(const void*, const void*))strcmp);
	
	if(pItem2)
		printf("%s is in the array.\n", pItem2);
	else
		printf("%s is not in the array.\n", key2);
}

int compareints(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

