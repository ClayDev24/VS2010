#pragma once
#include <iostream>

static void _peek() {
	using namespace std;
	int  n;
	char str[256];
	
	cout << "Enter a number or a word: ";
	// 1- Peek:
	char c = cin.peek();

	// 2- Putback:
	//char c = cin.get();
	//cin.putback(c);

	// 3- Unget:
	//char c = cin.get();
	//cin.unget();
	if((c >= '0') && (c <= '9')) {
		cin  >> n;
		cout << "You have entered number " << n << endl;
	} else {
		cin  >> str;
		cout << " You have entered word " << str << endl;
	}
}