#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _logical_or() {
	using namespace std;
	bool foo[] = {true,false,true, false};
	bool bar[] = {true,true, false,false};
	bool result[4];
	transform(foo, foo+4, bar, result, logical_or<bool>());
	cout << /*boolalpha <<*/ "Logical OR:\n";
	for(int i=0; i<4; i++)
		cout << foo[i] << " OR " << bar[i] << " = " << result[i] << "\n";
}