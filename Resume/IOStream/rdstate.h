// getting state of stream object
#pragma once
#include <iostream>
#include <fstream>

static void _rdstate() {
	using namespace std;
	ifstream ifs;
	ifs.open("test.txt"); // File not found
	//ifs.clear(ifstream::goodbit); // clears state
	if ((ifs.rdstate() & ifstream::failbit ) != 0)
		cerr << "Error opening 'test.txt'\n";
	else
		ifs.close();
}
