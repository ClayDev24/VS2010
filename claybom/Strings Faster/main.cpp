#include <iostream>
#include <string>
#include "utils.h"

void PrintName(const std::string &_name) {
	std::cout << _name << std::endl;
}
void PrintStr(const char* s) {
	std::cout << s << std::endl;
}
void PrintSubstr(const char* s, int init, size_t len) {
	for(unsigned int i=init; i<len; i++)
		std::cout << s[i];
	std::cout << std::endl;
}

void testingMemoSpeed() {
	using namespace std;

const int maxSZ = 100000;
#define USING_HEAP

#ifdef USING_HEAP
	string name = "Clailton Silva"; // allocates memory (heap)

	for(int i=0; i<maxSZ; i++) {
		PrintName(name);
		string firstName = name.substr(0, 8);
		string lastName  = name.substr(9, 13);
		PrintName(firstName);
		PrintName(lastName);
	}
	//PrintName("Maria Ap."); // allocates memory (heap)
#else
	const char *name = "Clailton Silva"; // Stack allocation
	for(int i=0; i<maxSZ; i++) {
		PrintStr(name);
		PrintSubstr(name, 0, 9); // firstname
		PrintSubstr(name, 9, 14); //lastname
	}
#endif

}
int main() {

	P_(utils::_chronometer(&testingMemoSpeed))
	// resultados para 10000 iterações:
	// Stack=> 180s
	// Heap => 179s
	utils::prtAlloc();

	system("pause");
	return(0);
}