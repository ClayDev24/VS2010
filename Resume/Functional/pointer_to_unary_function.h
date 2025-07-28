#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

static void _pointer_to_unary_function() {
	using namespace std;
	pointer_to_unary_function <double,double> LogObject(log);
	double numbers[] = {10.0, 20.0, 40.0, 80.0, 160.0};
	double logs[5];
	transform(numbers, numbers+5, logs, LogObject);
	for(int i=0; i<5; i++)
		cout << logs[i] << " ";
	cout << endl;
}