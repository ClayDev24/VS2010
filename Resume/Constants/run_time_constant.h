#pragma once
#include <iostream>

int claybom;

static void _run_time_constant() {
	// DYNAMIC CONST:
	std::cout << "Type a character & CR:";
	// Initialization MUST occur at the point o'declaration:
	const char  c = std::cin.get(); // Storage required. Value entered at run-time. Compiler ain't hold anything in its symbol table.
	const char c2 = c + 1;
	std::cout << c2 << std::endl;
	//c2 = 'a'; // ERROR! Cannot change const value.
}