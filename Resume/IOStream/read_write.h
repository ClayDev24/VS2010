// Copy a file
#pragma once
#include <fstream>
#include <iostream>

static void _read_write() {
	using namespace std;
	char *buf;
	unsigned int sz;
	
	ifstream ifile("read_write.h", ifstream::binary);
	ofstream ofile("read_write.txt", ofstream::binary);
	
	// get size of file
	ifile.seekg(0, ifstream::end);
	sz = static_cast<unsigned int>(ifile.tellg());
	ifile.seekg(0);
	// allocate memory for file content
	buf = new char[sz];
	// read content of infile
	ifile.read(buf, sz);
	// write to outfile
	ofile.write(buf, sz);
	cout.write(buf, sz);
	
	// release dynamically-allocated memory
	delete buf;	
	ofile.close();
	ifile.close();
}