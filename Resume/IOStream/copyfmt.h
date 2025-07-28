#pragma once
#include <iostream>
#include <fstream>

static void _copyfmt() {
	using namespace std;
	ofstream ofs;
	ofs.open("test.txt");
	
	cout.fill('*');
	cout.width(10);
	ofs.copyfmt(cout);
	
	cout << 40;
	ofs  << 40;
}