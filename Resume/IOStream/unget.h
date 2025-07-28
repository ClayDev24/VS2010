#pragma once
#include <iostream>

static void _unget() {
	using namespace std;
	char c;
	int  n;
	char str[256];
	
	cout << "Enter a number or a word: ";
	c = cin.get();
	
	if((c >= '0') && (c <= '9')) {
		cin.unget(); // same as peek();
		cin  >> n;
		cout << "You have entered number " << n << endl;
	} else {
		cin.unget(); // same as peek();
		cin  >> str;
		cout << " You have entered word " << str << endl;
	}
}