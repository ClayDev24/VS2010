#pragma once
#include <iostream>
#include <string>
// string::find

namespace resume {

	static void _find() {
		using namespace std;
		string str("There are two needles in this haystack with needles.");
		string key("needle");
		size_t found;
		// different member versions of find in the same order as above:
		found = str.find(key);
		if(found != string::npos) // npos == not found
			cout << "1st 'needle' at: " << int(found) << " -" << str.c_str()+found << endl;

		found =str.find("needles are small", found+1, 6); // 6 = length
		if(found != string::npos)
			cout << "2nd 'needle' at: " << int(found) << " -" << str.c_str()+found << endl;

		found = str.find("haystack");
		if(found != string::npos)
			cout << "'haystack' at: " << int(found) << endl;

		found = str.find('.'); // (char c, pos=0)
		if(found != string::npos)
			cout << "Period'.' at: " << int(found) << endl;
		// let's replace the 1st needle:
		found = str.find(key);
		str.replace(found, key.length(), "preposition");
		cout << str << endl;
		// let's replace the 2nd needle:
		found = str.find(key, found+1);
		str.replace(found, key.length(), "preposition");
		cout << str << endl;
	}

	void _find_first_not_of() {
		using namespace std;
		string str("Look For Non-Alphabetic Characters...");

		size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
		if(found != string::npos) // npos = not found
			cout << "1st non-alpha char: '" << str[found] << "' at pos: " << int(found) << endl;

		found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ", found+1);
		if(found != string::npos)
			cout << "2nd non-alpha char: '" << str[found] << "' at pos: " << int(found) << endl;
	}
	// Find first occurrency of char in str:
	void _find_first_of() {
		using namespace std;
		string str("Replace the vowels in this sentence by asterisks.");
		size_t found  = str.find_first_of("aeiou");
		while( found != string::npos) {
			str[found] = '*';
			found = str.find_first_of("aeiou", found+1);
		}
		cout << str << endl;
	}

	void _find_last_not_of() {
		using namespace std;
		string str("erase trailing white-spaces   \n");
		string whitespaces(" \t\f\v\n\r");
		size_t fnd = str.find_last_not_of(whitespaces);
		if(fnd != string::npos)
			str.erase(fnd+1);
		else
			str.clear();            // str is all whitespace

		cout << '"' << str << '"' << endl;
	}

	void _find_last_of() {
		using namespace std;
		string str("c:\\windows\\winhelp.exe");
		cout << "Splitting: " << str << endl;

		size_t found = str.find_last_of("/\\");
		cout << "folder: " << str.substr(0, found) << endl;
		cout << "file  : " << str.substr(found +1) << endl;
	}

	void _rfind() {
		using namespace std;
		string str("The sixth sick sheik's sixth sheep's sick.");
		string key("sixth");
		size_t found = str.rfind(key); // Reverse find (last occurrence).
		if(found != string::npos)
			str.replace(found, key.length(), "seventh");
		cout << str << endl;

		found = str.rfind(key, 20); // Reverse find. Searchs begin at pos 0-20
		if(found != string::npos)
			str.replace(found, key.length(), "seventh");
		cout << str << endl;
	}

} // resume