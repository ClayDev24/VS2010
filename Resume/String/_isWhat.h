#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace resume {

	static void _isWhat() {
		printf("\nType any keyboard character: ");
		char ch = getchar();
		if(isalnum(ch))
			printf("%c It is alphanumeric\n", ch);
		if(isalpha(ch))
			printf("%c It is letter\n", ch);
		if(iscntrl(ch))
			printf("%c It is control character\n", ch);
		if(isdigit(ch))
			printf("%c It is digit.\n", ch);
		if(isgraph(ch))
			printf("%c It is graphical.\n", ch);
		if(isprint(ch))
			printf("%c It is printable\n", ch);
		if(ispunct(ch))
			printf("%c It is ponctuation\n", ch);
		if(isspace(ch))
			printf("%c It is white space\n", ch);
		if(isupper(ch))
			printf("%c It is upper case (capital letter).\n", ch);
		if(islower(ch))
			printf("%c It is lower case.\n", ch);
		if(isxdigit(ch))
			printf("%c It is hexadecimal\n", ch);
	}

} // resume