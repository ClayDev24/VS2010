#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _divides() {
	using namespace std;
	int  first[] = { 10, 40, 90, 40, 10 };
	int second[] = { 1,   2,  3,  4,  5 };
	int results[5];
	transform(first, first+5, second, results, divides<int>());
	for(int i=0; i<5; i++)
		cout << results[i] << " ";
	cout << endl;
}