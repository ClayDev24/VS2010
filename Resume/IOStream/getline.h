#pragma once
#include <iostream>

static void _getline() {
	using namespace std;
	char name[256], title[256];
	
	cout << "Enter your name: ";
	cin.getline(name, 256);
	
	cout << "Enter your favourite movie: ";
	cin.getline(title, 256 /*, 'z'*/); // '\n' is the default delim char, but can be overwriten.
	
	cout << name << "'s favourite movie is " << title << endl;
	cout << "Favourite movie has " << cin.gcount() << " chars.\n";
}