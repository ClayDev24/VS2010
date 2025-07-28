//: C02:HiLo.cpp
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

static int _invariant() {
	cout << "Think of a number between 1 and 100\n";
	cout << "I will make a guess; ";
	cout << "tell me if I'm (H)igh or (L)ow\n";
	int low = 1, high = 100;
	bool gotcha = false;
	while(!gotcha) {
		// Invariant condition: the number MUST BE in the range [low, high]
		if(low > high) {  // Invariant violation
			cout << "You cheated! I quit\n"; // você trapaceou! Eu desisto!
			return EXIT_FAILURE;
		}
		// Binary search:
		int guess = (low + high) / 2;
		cout << "My guess is " << guess << ". ";
		cout << "(H)igh, (L)ow, or (E)qual? ";
		string response;
		cin >> response;
		switch(toupper(response[0])) {
	  case 'H':
		  low = guess + 1;
		  break;
	  case 'L':
		  high = guess - 1;
		  break;
	  case 'E':
		  gotcha = true;
		  break;
	  default:
		  cout << "Invalid response\n";
		  continue;
		}
	}
	cout << "I got it!\n";
	return EXIT_SUCCESS; // = 0 - EXIT_FAILURE macros declared in <cstdlib>
}