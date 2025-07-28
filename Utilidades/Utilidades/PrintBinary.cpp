#include <iostream>
#include "PrintBinary.h"

void utils::PrintBinary(const unsigned char &val, const char &_fill) {
	for(int i=7; i>=0; i--)
		if(val & (1 << i))
			std::cout << "1";
		else
			std::cout << "0";
	std::cout << _fill;
}
void utils::PrintBinaryDouble(double &_d, const char &_fill) {
	// Printing a double:
	unsigned char* cp = reinterpret_cast<unsigned char*>(&_d);
	std::cout << "\ndouble d = " << _d << std::endl;
	for(int i=sizeof(double); i>0; i-=2) {
		utils::PrintBinary(cp[i-1]);
		utils::PrintBinary(cp[i]);
	}
	std::cout << std::endl;
}
void utils::PrintBinaryInt(int &_i, const char &_fill) {
	// Printing an int:
	unsigned char* cp = reinterpret_cast<unsigned char*>(&_i);
	std::cout << "\nint i = " << _i << std::endl;
	for(int i=sizeof(_i); i>0; i--)
		utils::PrintBinary(cp[i-1]);
	std::cout << std::endl;
}
void utils::PrintBinaryLongLong(long long &_ll, const char &_fill) {
	// Printing a double:
	unsigned char* cp = reinterpret_cast<unsigned char*>(&_ll);
	//std::cout << "\nlong long ll = " << _ll << std::endl;
	for(int i=sizeof(long long); i>0; i--)
		utils::PrintBinary(cp[i-1]);

	std::cout << std::endl;
}
// ***************** <<_USAGE_>> *****************
void utils::PrintBinaryUsage() {
	using namespace std;
	// Printing a single char:
	unsigned char c = 48;
	cout << "char c = " << c << endl;
	utils::PrintBinary(c);

	// Printing a double:
	double d = 568.745;
	PrintBinaryDouble(d);
	int i = 1;
	PrintBinaryInt(i);

	long long bit = 1;//0xFFFFFFFFFFFFFFFF;
	for(int i=0; i<64; i++) {
		PrintBinaryLongLong(bit);
		bit <<= 1;
	}
}