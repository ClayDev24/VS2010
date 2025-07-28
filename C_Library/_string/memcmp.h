#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _memcmp() {
	char str1[256];
	char str2[256];
	int i;
	size_t sz1, sz2;
	printf("Enter a sentence: ");
	gets(str1);
	printf("Enter another sentence: ");
	gets(str2);
	sz1 = strlen(str1);
	sz2 = strlen(str2);
	i = memcmp(str1, str2, sz1>sz2?sz1:sz2 );
	if(i>0)
		printf("'%s' is greater than '%s'.\n", str1, str2);
	else if(i<0)
		printf("'%s' is less than '%s'.\n", str1, str2);
	else
		printf("'%s' is the same as '%s'.\n", str1, str2);
}
