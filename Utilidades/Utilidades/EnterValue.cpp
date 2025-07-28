#include <iostream>
#include <string>
#include "EnterValue.h"

//Type1 utils::EnterValue::getVal() {}

// ***************** <<_USAGE_>> *****************
void utils::EnterValueUsage() {
	using namespace std;
	EnterValue<int> val("Type an integer number: ");
	cout << val.getVal() << endl;
	EnterValue<float> val1("Type a float number: ");
	cout << val1.getVal() << endl;
	EnterValue<double> val2("Type an double number: ");
	cout << val2.getVal() << endl;
	EnterValue<char> val3("Type a char value: ");
	cout << val3.getVal() << endl;
	EnterValue<string> val4("Type a string value: ");
	cout << val4.getVal() << endl;
}