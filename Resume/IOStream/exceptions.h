#pragma once
#include <iostream>
#include <fstream>

static void _exceptions() {
	using namespace std;

	ifstream file;
	file.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
	try {
		file.open("test.txt");
		while(!file.eof())
			file.get();
		file.close();
	} catch(ifstream::failure e) {
		cout << "Exception reading file";
	}
}