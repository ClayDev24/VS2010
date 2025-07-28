#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.
#include <errno.h>	// Standard C lib.

void conversions() {
	char doubles[] = "365.269 27.32 56.78";
	char szNum[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
	long int li1;
	char *pChar;
	char buf[33];
	unsigned long ul;

// CONVERSIONS:
// ANSI to Float:
	printf("atof(\"123\"): %f\n", atof("123"));
// ANSI to Int:
	printf("atoi(\"123\"): %i\n", atoi("123"));
// ANSI to Long:
	printf("atol(\"123\"): %lu\n", atol("123"));
// Int to ANSI:
	itoa(10, buf, 10);
	printf("dec: %s\n", buf);
	itoa(10, buf, 16);
	printf("hex: %s\n", buf);
	itoa(10, buf, 2);
	printf("bin: %s\n", buf);
// String to Decimal:
	printf("%.2lf\n", strtod(doubles, &pChar));
	printf("%.2lf\n", strtod(pChar,   &pChar));
	printf("%.2lf\n", strtod(pChar,     NULL));
// String to Long:
	li1 = strtol(szNum, &pChar, 10);
	if(errno==ERANGE)
		puts("ERANGE\n");		
	printf("strtol(buf,   &pChar, 10): %ld.\n", li1);
	printf("strtol(pChar, &pChar, 16): %ld.\n", strtol(pChar, &pChar, 16));
	printf("strtol(pChar, &pChar,  2): %ld.\n", strtol(pChar, &pChar,  2));
	printf("strtol(pChar,  NULL,   0): %ld.\n", strtol(pChar,  NULL,   0));
// String to Unsigned Long:
	ul = strtoul("123456789", NULL, 0);
	if(errno==ERANGE)
		puts("ERANGE\n");
	else
		printf("strtoul(\"123456789\", NULL, 0): %lu\n", ul);
}