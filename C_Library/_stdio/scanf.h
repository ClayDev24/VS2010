#include <stdio.h> // Standard C Lib.

void _scanf() {
	char str[80];
	int i;
	
	printf("Enter line o'text: ");
	scanf("%s", str);  
	printf("Enter : ");
	scanf("%d", &i);
	printf("Line and number entered: %s, %d\n", str, i);
	printf("Enter a hex number: ");
	scanf("%x", &i);
	printf("Hex number entered %#x (%d).\n", i, i);
}