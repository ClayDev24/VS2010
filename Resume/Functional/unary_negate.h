#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

struct IsOdd_class : std::unary_function<int,bool> {
	bool operator() (const int& x) const {
		return x%2==1;
	}
} IsOdd_object;

static void _unary_negate() {
	using namespace std;
	unary_negate<IsOdd_class> IsEven_object(IsOdd_object);
	int values[] = {1,2,3,4,5};
	int cx;
	cx = count_if(values, values+5, IsEven_object);
	cout << "There are " << cx << " elements with even values.\n";
}