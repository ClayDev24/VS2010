#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _bind1st() {
	using namespace std;
	int numbers[] = {10, 20, 30, 40, 50, 10, 37, 44, 37, 37} ;
	int cx;
	cx = count_if(numbers, numbers+10, bind1st(equal_to<int>(), 37));
	cout << "There are " << cx << " elements that are equal to 37.\n";
}