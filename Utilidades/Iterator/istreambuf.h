#pragma once
#include <iostream>
#include <iterator>
#include <string>

static void _istreambuf() {
	using namespace std;

	istreambuf_iterator<char> eos;             // end-of-range iterator
	istreambuf_iterator<char> it(cin.rdbuf()); // stdin iterator
	string s;
	
	cout << "Please, enter your name: ";
	
	while(it!=eos && *it!='\n')
		s += *it++;
	
	cout << "Your name is " << s << ".\n";
}