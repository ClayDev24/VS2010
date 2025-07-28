#include "vld.h"
#include <iostream>
#include <string>
#include "conversions.h"
using namespace std;

int main() {
	//cout << "_MSC_VER" << _MSC_VER << endl;
	clb::Conversions c;

	cout << c.bin2dec ("11111111111111111111111111111111")  << endl;
	cout << c.bin2dec ("1111111111111111111111111111") << endl;
	cout << c.bin2dec ("111111111111111111111111") << endl;
	cout << c.bin2dec ("11111111111111111111")  << endl;
	cout << c.bin2dec ("1111111111111111")   << endl;
	cout << c.bin2dec ("111111111111")    << endl;
	cout << c.bin2dec ("11111111")      << endl;
	cout << c.bin2dec ("1111")        << endl;
	cout << c.bin2dec2("1010")       << endl;
	cout << c.dec2bin(10)            << endl;
//	cout << c.dec2bin2(1359) << endl;	
//	cout << c.hex2bin ("ABCD")   << endl;
//	cout << c.hex2bin ("7") << endl;
//	cout << c.bin2hex ("0000000110101011")     << endl; // 01AB ERROR: w/out spacer
//	cout << c.bin2hex ("%0000_1111_1010_1011") << endl; // 01AB
//	cout << c.bin2dec ("000101") << endl;
//	Enter the str w/out any spacers:
//	cout << c.zero_extend("10101010", clb::WORD, '_') << endl;
//	cout << c.sign_extend("10101010", clb::WORD, '_') << endl;

	int    i1 = 0;
	float  f1 = 0.0;
	double d1 = 0.0;

	i1 = c.str2int("57");
	f1 = c.str2float("57.64");
	d1 = c.str2double("57.6547");
	cout << i1 << endl;
	cout << f1 << endl;	
	cout << d1 << endl;

	i1 = c.str2int2("57");
	f1 = c.str2float2("57.64");
	d1 = c.str2double2("57.6547");
	cout << i1 << endl;
	cout << f1 << endl;	
	cout << d1 << endl;

	system("pause");
	return(0);
}
