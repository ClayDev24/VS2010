#pragma once
#include <iostream>
#include <iterator>

static void _istream() {
	using namespace std;
	double val1, val2;
	cout << "Please, insert two values: ";
	
	istream_iterator<double> eos;     // end-of-stream iterator
	istream_iterator<double> it(cin); // stdin iterator
	
	if(it!=eos)
		val1 = *it;
	
	it++;
	if(it!=eos)
		val2 = *it;
	
	cout << val1 << "*" << val2 << "=" << (val1*val2) << endl;
}