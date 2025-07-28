#pragma once
#include <iostream>
#include <iterator>
#include <string>

static void _ostreambuf() {
	using namespace std;

	string s("Some text here...\n");
	ostreambuf_iterator<char> out_it(cout); // stdout iterator
	
	copy(s.begin(), s.end(), out_it);
} 