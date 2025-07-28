#pragma once
#include <iostream>

static void _breaking_constness() {
	const int i = 2;
	std::cout << "__Breaking constness via pointer:\n";
	std::cout << "i: " << i << std::endl;
	//int *p = &i; // Illegal i const.
	int *p = (int*)&i; // Legal but bad practice.
	//(*p)++;
	*p = 3;
	std::cout << "&i: " << &i << std::endl; 
	std::cout << "p : " <<  p << std::endl; 
	std::cout << "i : " <<  i << std::endl;
	std::cout << "*p: " << *p << std::endl;
}