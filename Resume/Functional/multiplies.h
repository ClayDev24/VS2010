#pragma once
#include <iostream>
#include <functional>
#include <numeric>

static void _multiplies() {
	using namespace std;
	int numbers[9];
	int factorials[9];

	for(int i=0; i<9; i++)
		numbers[i] = i+1;

	partial_sum(numbers, numbers+9, factorials, multiplies<int>());

	for(int i=0; i<9; i++)
		cout << numbers[i] << "! is " << factorials[i] << "\n";
}