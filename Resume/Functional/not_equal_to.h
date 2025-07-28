#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _not_equal_to() {
	using namespace std;
	int numbers[] = {10,10,10,20,20};
	int* pt = adjacent_find( numbers, numbers+5, not_equal_to<int>() ) +1;
	cout << "The first different element is " << *pt << endl;
}