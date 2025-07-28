#pragma once
#include <iostream>
#include <iterator>
#include <vector>

static void _ostream() {
	using namespace std;

	vector<int> v;
	for(int i=1; i<=10; ++i)
		v.push_back(i*10);
	
	ostream_iterator<int> out_it(cout, ", ");
	copy(v.begin(), v.end(), out_it);
}