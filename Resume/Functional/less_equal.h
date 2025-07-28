#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _less_equal() {
	using namespace std;
	int numbers[] = { 25, 50, 75, 100, 125 };
	int cx = count_if(numbers, numbers+5, bind2nd(less_equal<int>(), 100));
	cout << "There are " << cx << " elements lower or equal to 100.\n";
}