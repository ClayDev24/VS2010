#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace resume {

	static void _reserve() {
		using namespace std;
		string str;
		ifstream file("_reserve.h",ios::in|ios::end);
		size_t filesize = static_cast<size_t>(file.tellg());
		// Requests a change in capacity o'allocated storage space in string to be at least (>=) filesize.
		try {
			str.reserve(filesize);
		} catch(int i) { // if > string::max_size
				cout << "length_error exception: " << i << endl;
		}
		file.seekg(0);
		// reserves enough capacity in the string to store an entire file,
		// which is then read char by char. By reservin'a capacity 4 the str o'at least the sz o'the
		// entire file, we avoid all the automatic reallocations that the obj str could suffer
		// each time that a new char surpassed the sz o'its previously allocated storage space.
		while(!file.eof())
			str += file.get();
		cout << str << endl;
	}

	static void _resize() {
		using namespace std;
		string str("I like to code in C");
		cout << str << endl;

		size_t sz = str.size();
		str.resize(sz+2, '+'); // Resizes str content to n chars. Fillin' it with '+'.
		cout << str << endl;

		str.resize(14); // Throws length_error exception
		cout << str << endl;
	}

} // resume