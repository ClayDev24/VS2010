#pragma once
#include <iostream>

static void _operator() {
	using namespace std;
	int n;
	char str[10];
	
	cout << "Enter a number: ";
	cin  >> n;
	cout << "You have entered: " << n << endl;
	
	cout << "Enter a hexadecimal number: ";
	cin  >> hex >> n;            // manipulator
	cout << "Its decimal equivalent is: " << n << endl;
	
	cout << "Enter a word: ";
	cin.width(5);        // limit width
	cin  >> str;
	cout << "The first 4 chars of your word are: " << str << endl;
}