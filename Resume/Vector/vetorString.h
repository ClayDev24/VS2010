#pragma once
#include <iostream> // cout
#include <vector>	// vector

typedef std::vector<std::string>::iterator it2; // define iterator type through STL

static void _vetorString() {
	using namespace std;
	vector<string> vLines;
	ifstream in("main.cpp");
	string str;
	//while(in >> str) // Get words
	while(getline(in, str)) // Get lines
		vLines.push_back(str); // Add the line to the end
	// Add line numbers:
	for(unsigned int i=0; i<vLines.size(); i++)
		cout << (i+1) << ": " << vLines[i] << endl;

	while(true) {
		cout << "Enter required number (x to exit):";
		int n = 0;
		getline(cin, str);
		if(!str.compare("x")) // Inequality: val <> 0
			break;
		it2 pos = find(vLines.begin(), vLines.end(), str);
		if(pos != vLines.end())
			cout << "Found at position " << (pos - vLines.begin()) << endl;
		else
			cout << str << " not found" << endl;
	} // while
} // _vetorString