#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _not2() {
	using namespace std;
	int foo[] = {10,20,30,40,50};
	int bar[] = {0, 15,30,45,60};
	pair<int*,int*> firstmatch, firstmismatch;
	firstmismatch = mismatch(foo, foo+5, bar, equal_to<int>() );
	firstmatch    = mismatch(foo, foo+5, bar, not2(equal_to<int>()) );
	cout << "First mismatch in bar is " << *firstmismatch.second << "\n";
	cout << "First match    in bar is " << *firstmatch.second    << "\n";
}