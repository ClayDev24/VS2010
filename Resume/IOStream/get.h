#pragma once
#include <fstream>

static void _get() {
	using namespace std;
	char str[256];
	ifstream file;
	
	cout << "Enter the name of an existing text file: ";
	cin.get(str, 256);
	
	file.open(str);
	while(file.good())
		cout << (char)file.get();
	
	file.close();
}