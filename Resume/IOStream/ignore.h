#pragma once
#include <iostream>

static void _ignore() {
	using namespace std;
	cout << "Enter your first and last names: ";
	
	char first = cin.get();
	cin.ignore(128, ' ');
	char last = cin.get();
	
	cout << "Your initials are " << first << last << endl;
}