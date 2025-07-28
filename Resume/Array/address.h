#pragma once
#include <iostream>

// Array Address:
static void _arrayAddress() {
	int a[10];
	std::cout << "sizeof(int) = "<< sizeof(int) << std::endl;
	for(int i = 0; i < 10; i++)
		std::cout << "&a[" << std::hex << i << "] = " << (long)&a[i] << std::endl;
}