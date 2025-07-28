#pragma once
#include <iostream>
#include <fstream>

static void _seek() {
	using namespace std;
	unsigned int  sz;
	char *buf;
	
	ifstream file;
	file.open("seek.h", ios::binary );
	
	// get length of file:
	file.seekg(0, ios::end);
	sz = static_cast<unsigned int>(file.tellg()); // Returns the abs pos o'get ptr.
	file.seekg(0, ios::beg);
	
	// allocate memory:
	buf = new char[sz];
	
	// read data as a block:
	file.read(buf, sz);	
	file.close();
	
	cout.write(buf, sz);
	
	delete []buf;

// position of put pointer
	ofstream outfile;
	outfile.open("test.txt");
	
	outfile.write("This is an apple",16);
	int pos = static_cast<int>(outfile.tellp()); // The abs pos o'put ptr.
	outfile.seekp(pos-7);
	outfile.write(" sam",4);
	
	outfile.close();
}
