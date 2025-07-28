#pragma once
#include <iostream>
#include <functional>

struct IsOdd2 : public std::unary_function<int,bool> {
	bool operator() (int number) {return (number%2==1);}
};

static void _unary_function() {
	using namespace std;
	IsOdd2 IsOdd_object;
	IsOdd2::argument_type input;
	IsOdd2::result_type result;
	
	cout << "Please enter a number: ";
	cin >> input;
	
	result = IsOdd_object (input);
	
	cout << "Number " << input << " is " << (result?"odd":"even") << ".\n";
}