#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

struct IsOdd : std::unary_function<int, bool> {
	bool operator() (const int& x) const {
		return x%2==1;
	}
};

static void _not1() {
	using namespace std;
	int values[] = {1,2,3,4,5};
	int cx;
	cx = count_if(values, values+5, not1(IsOdd()));
	cout << "There are " << cx << " elements with even values.\n";
}