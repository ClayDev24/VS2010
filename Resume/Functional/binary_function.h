#pragma once
#include <iostream>
#include <functional>

struct Compare : public std::binary_function<int, int, bool> {
	bool operator() (int a, int b) { return (a==b); }
};

static void _binary_function() {
	using namespace std;
	Compare comp;
	Compare::first_argument_type  input1;
	Compare::second_argument_type input2;
	Compare::result_type          result;
	
	cout << "Please enter first number: ";
	cin  >> input1;
	cout << "Please enter second number: ";
	cin  >> input2;
	
	result = comp(input1, input2);
	
	cout << "Numbers " << input1 << " and " << input2;
	if(result)
		cout << " are equal.\n";
	else
		cout << " are not equal.\n";
}