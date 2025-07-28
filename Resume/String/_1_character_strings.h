#pragma once
#include <iostream>
#include <stdio.h>

namespace resume {

#define PR(x) \
			cout << #x << ": " << x << endl;

	static void concatenation() {
		// String concatenation:
		char s1[80], s2[80];
		printf("<enter> String s1: ");
		//gets(s1); // DEPRECATED / UNSAFE
		gets_s(s1, sizeof(s1)); // Use gets_s instead
		printf("<enter> String s2: ");
		gets_s(s2, sizeof(s2));

		errno_t err = strcat_s(s1, sizeof(s1), s2);
		if (err == 0) {
			std::cout << "Concatenated: " << s1 << '\n';
		} else {
			std::cerr << "Concatenation FAILED (buffer too small or null ptr).\n";
		}

		printf("<enter> String s1: ");
		gets_s(s1, sizeof(s1));
		printf("<enter> String s1: ");
		gets_s(s2, sizeof(s2));

		err = strncat_s(s1, sizeof(s1), s2, strlen(s2));
		if (err == 0) {
			std::cout << "Concatenated: " << s1 << '\n';  // Output: Data: SensitiveI
		} else {
			std::cerr << "ERROR concatenating strings.\n";
		}
	}

	static void search_char() {
		// memchr() devolve um ponteiro para a primeiro ocorrencia
		// apos encontrar o char. Devolve nulo caso nao encontre.
		char *p  = (char*)memchr("This is a simple test...", 'i', 14);
		// same as above:
		//char *p2 =        strchr("This is a simple test...", ' ');

		if(p != NULL)
			printf("%s\n", p);
		else
			printf("Ocurrence not found!\n");
	}

	static void search_char2() {
		// strcspn() devolve um inteiro na primeira string para a ocorrencia
		// de qualquer um dos caracteres da segunda string.
		unsigned int len = strcspn("This is a test...", "sa");
		printf("%d\n", len);
	}

	static void search_last_char() {
		// devolve a ultima ocorrencia do char (byte menos significativo) da str2 no str1
		const char *p = strrchr("This is a simple test.", 'e');
		printf("%s\n", p);
	}

	static void search_string() {
		const char *p = strstr("This is a test...", "is");
		printf("%s\n", p);

	}

#define SIZE 80

	static void memory_copy() {
		// memory copy:
		char buf1[SIZE], buf2[SIZE];
		// cópia segura para buf1
		strcpy_s(buf1, SIZE, "Quando, no curso do...");
		// cópia de memória para buf2
		memcpy(buf2, buf1, SIZE); // (dest, source, size in bytes)
		printf("%s\n", buf2);
	}

	static void string_compare() { // String compare:
		int i = strncmp("123", "123", 8);
		if(!i)
			printf("Both are equal.\n");
		else if(i > 0)
			printf("The first is greater.\n");
		else
			printf("The seconde is greater.\n");
	}

} // resume