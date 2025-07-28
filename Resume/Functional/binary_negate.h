#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _binary_negate() {
	using namespace std;
	equal_to<int> equality;
	binary_negate<equal_to<int>> nonequality(equality);
	int foo[] = {10, 20, 30, 40, 50};
	int bar[] = {0,  15, 30, 45, 60};
	pair<int*, int*> firstmatch, firstmismatch;
	firstmismatch = mismatch(foo, foo+5, bar, equality);
	firstmatch    = mismatch(foo, foo+5, bar, nonequality);
	cout << "First mismatch in bar is " << *firstmismatch.second << "\n";
	cout << "First match    in bar is " << *firstmatch.second    << "\n";
	cout << "First mismatch in foo is " << *firstmismatch.first  << "\n";
	cout << "First match    in foo is " << *firstmatch.first     << "\n";
}