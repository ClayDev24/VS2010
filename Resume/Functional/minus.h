#pragma once
#include <iostream>
#include <functional>
#include <numeric>

static void _minus() {
	using namespace std;
	int numbers[] = { 10, 20, 30 };
	int result;
	result = accumulate(numbers, numbers+3, 100, minus<int>());
	cout << "The result of 100-10-20-30 is " << result << ".\n";
}