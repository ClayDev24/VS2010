#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _logical_and() {
	using namespace std;
	bool foo[] = { true, false, true,  false };
	bool bar[] = { true, true,  false, false };
	bool result[4];
	transform(foo, foo+4, bar, result, logical_and<bool>());
	cout << /*boolalpha <<*/ "Logical AND:\n";
	for(int i=0; i<4; i++)
		cout << foo[i] << " AND " << bar[i] << " = " << result[i] << "\n";
}