#pragma once
#include <iostream>
#include <fstream>

static void _clear() {
	using namespace std;
	char buffer[256];
	fstream fs;
	
	fs.open("clear.h", fstream::in);
	
	if(fs.is_open()) {
		fs << "test";
		if(fs.fail()) {
			cout << "Error writing to test.txt\n";
			fs.clear(); // must be set to set fs.goot to true.
		}
		// Readin' first line o'file:
		fs.getline(buffer, 256);
		cout << buffer << endl;
		
		// Reading all the rest:
		if(fs.good()) {
			while(fs.good())
				cout << (char)fs.get();
			cout << "\nsuccessfully read from file.\n";
		} else
			cout << "Error reading file...\n";
		fs.close();
	} else
		cout << "Error opening file\n";
}