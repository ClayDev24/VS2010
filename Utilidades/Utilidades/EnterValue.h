#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#include <typeinfo.h>
#include <string>

namespace utils {

	template<class Type1>
	class EnterValue {
	protected:
		Type1 data1;
		const char *msg;
	public:
		// Default constructor:
		EnterValue(const char *_msg = "Type a positive integer number: "):msg(_msg) {}
		~EnterValue() {}
		Type1 getVal() {
			using namespace std;
			string str;
			cout << msg; // Negative numbers to be implemented yet.
			getline(cin, str);
			int i = 0;
			stringstream(str) >> data1;
			bool type;
			type = (typeid(data1) == typeid(int));
			if(type)
				cout << "the type is int.\n";
			type = (typeid(data1) == typeid(float));
			if(type)
				cout << "the type is float.\n";
			type = (typeid(data1) == typeid(double));
			if(type)
				cout << "the type is double.\n";
			type = (typeid(data1) == typeid(char));
			if(type)
				cout << "the type is char.\n";
			type = (typeid(data1) == typeid(string));
			if(type)
				cout << "the type is string.\n";

			/*if(isNumber(str)) {
			a1[cont++] = value;
			continue;
			} else {
			puts("(valor nao numerico)");
			continue;
			}*/
			return data1;
		}
		//NOT Implemented yet:
		//int    getInt() {}
		//float  getFloat() {}
		//double getDouble() {}
		//char   getChar() {}
		//std::string getString() {}
	};
	// ***************** <<_USAGE_>> *****************
	void EnterValueUsage();

}; // utils