#pragma once
#include <iostream>

static void _sync() {
	using namespace std;
	char first, second;
	
	cout << "Please, enter a word: ";
	first = cin.get();
	cin.sync();
	
	cout << "Please, enter another word: ";
	second = cin.get();
	
	cout << "The first word began by "  << first  << endl;
	cout << "The second word began by " << second << endl;
}