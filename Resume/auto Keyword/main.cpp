//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <string>
#include <vector>

// I can change return type at will with no side effect on the code below:
char* getName() {
	//std::string getName() {
	return "claybom";
}

int main() {
	using namespace std;
	// (1)-auto can holds all the build-in types, plus the user-defined ones:
	int  a  = 5;
	auto a1 = a;
	auto a2 = "claybom";
	auto a3 = 3.7L;
	auto a4 = 4.5f;
	auto a5 = 'a';
	cout << typeid(a1).name() << ": " << a1 << endl;
	cout << typeid(a2).name() << ": " << a2<< endl;
	cout << typeid(a3).name() << ": " << a3 << endl;
	cout << typeid(a4).name() << ": " << a4 << endl;
	cout << typeid(a5).name() << ": " << a5 << endl;

	std::string name = getName();
	//P_(name)

	// It's nice to know the exatly type o'return type yo code is tylin'on.
	// So avoid to use auto as left-value assignments.
	auto name2 = getName(); // Relies on string type. 
	//PRT_(name2.size())    // compiler ERROR!
	cout << name2;		    // This peace of code will compile either with string of char prts.

	//*******************<<_(2) Example 2_>>*************************
	std::vector<std::string> strings;
	strings.push_back("orange");
	strings.push_back("apples");
	// Prints out strings contents:

	//for(std::vector<std::string>::iterator it = strings.begin();
	// Use auto instead of the massive code above.
	for(auto it = strings.begin(); it != strings.end(); it++) {
		cout << *it;
		//cout << typeid(it).name() << endl;
	}
	


	// auto is still more shorter than the typedefs:
	// Use auto instead of the massive code above.
	typedef std::vector<std::string>::iterator ItString;
	for(ItString it = strings.begin(); it != strings.end(); it++) {
		cout << *it;
	}

	system("pause");
	return(0);
}