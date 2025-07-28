#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _greater_equal() {
	using namespace std;
	int numbers[] = { 20, -30, 10, -40, 0 };
	int cx = count_if(numbers, numbers+5, bind2nd(greater_equal<int>(), 0));
	cout << "There are " << cx << " non-negative elements.\n";
}