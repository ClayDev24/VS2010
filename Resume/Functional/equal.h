#pragma once
#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>

static void _equal() {
	using namespace std;
	
	int foo[] = { 10, 20, 30, 40,  50 };
	int bar[] = { 10, 20, 40, 80, 160 };
	pair<int*, int*> ptiter = mismatch(foo, foo+5, bar, equal_to<int>());
	cout << "First mistmatching pair is: " << *ptiter.first;
	cout << " and " << *ptiter.second << endl;
}