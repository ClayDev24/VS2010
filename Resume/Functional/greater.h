#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _greater() {
	using namespace std;
	int numbers[] = { 20, 40, 50, 10, 30 };
	sort(numbers, numbers+5, greater<int>());
	for(int i=0; i<5; i++)
		cout << numbers[i] << " ";
	cout << endl;
}