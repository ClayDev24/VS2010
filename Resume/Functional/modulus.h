#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _modulus() {
	using namespace std;
	int numbers[] = { 1, 2, 3, 4, 5 };
	int remainders[5];
	transform(numbers, numbers+5, remainders, bind2nd(modulus<int>(), 2));
	for (int i=0; i<5; i++)
		cout << numbers[i] << " is " << (remainders[i]==1?"odd":"even") << "\n";
}