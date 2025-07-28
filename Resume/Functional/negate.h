#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _negate() {
	using namespace std;
	int numbers[] = { 10, -20, 30, -40, 50 };

	transform(numbers, numbers+5, numbers, negate<int>());

	for(int i=0; i<5; i++)
		cout << numbers[i] << endl;
}