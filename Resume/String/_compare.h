#pragma once
#include <iostream>
#include <string>

namespace resume {

	static void _compare() {
		using namespace std;
		string str1("Antonio  F Silva");
		string str2("Beatriz M F Silva");

		if(str1.compare(str2)) // Inequality: val <> 0
			cout << str1 << " != " << str2 << "\n";
		if(!str1.compare(9, 7, "F Silva")) // Equality: val == 0
			cout << str1.substr(9, 7) << " == F Silva\n";
		if(!str1.compare(9, 7, str2, 10, 7))
			cout << str1.substr(9, 7) << " == " << str2.substr(10, 7) << "\n";

		if(str1.compare(str2) < 0)
			cout << str1 << " < " << str2 << "\n";
		else if(str1.compare(str2) > 0)
			cout << str1 << " > " << str2 << "\n";
		else
			cout << str1 << " == " << str2 << "\n";
	}

} // resume