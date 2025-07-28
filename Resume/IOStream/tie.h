// redefine tied object
#pragma once
#include <iostream>
#include <fstream>

static void _tie() {
	using namespace std;
	ostream *prevstr;
	ofstream ofs;
	ofs.open("tie.txt");
	
	cout << "tie example:" << endl;
	
	*cin.tie() << "This is inserted into cout";
	prevstr = cin.tie(&ofs);
	*cin.tie() << "This is inserted into the file";
	cin.tie(prevstr);
	
	ofs.close();
}