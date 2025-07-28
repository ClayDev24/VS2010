#pragma once
#include <iostream>
#include <string>

namespace resume {

	static void _empty() {
		using namespace std;
		string content;
		string line;
		cout << "Please introduce a text. Enter an empty line to finish:\n";
		do {
			getline(cin, line);
			content += line + '\n';
		} while(!line.empty());
		cout << "The text you introduced was:\n" << content;
	}

} // resuem