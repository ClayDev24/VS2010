// modify flags
#pragma once
#include <iostream>

static const char *flagNames[] = {
		"skipws		",
		"unitbuf	",
		"uppercase	",
		"showbase	",
		"showpoint	",
		"showpos	",
		"left		",
		"right		",
		"internal	",
		"dec		",
		"oct		",
		"hex		",
		"scientific	",
		"fixed		",
		"boolapha	"
};

static void showIosFlags(std::ios &iosObj) {
	using namespace std;
	cout << "==== ios flag status" << endl;
	long k=1;
	for(int i=0; i<15; i++) {
		cout << flagNames[i] << " is ";
		if(k & iosObj.flags())
			cout << "ON" << endl;
		else
			cout << "off" << endl;
		k <<= 1; // rotate k
	}
	cout << endl;
};

static void _flags() {
	using namespace std;
	// values not explicit set are cleared:
	cout.flags(ios::right | ios::hex | ios::showbase);
	cout.width(10);
	cout << 100;

	showIosFlags(cout);
	cout.setf(ios::uppercase | ios::scientific);
	showIosFlags(cout);
	
	cout  << "showpos:" << endl;
	int i = 100;
	cout.setf(ios::showpos);
	cout << i << endl;
	cout.unsetf(ios::showpos);
	cout << i << endl;
	
	cout  << "hex:" << endl;
	cout.setf(ios::hex);// ou cout << hex << i << endl;
	cout << i << endl;
	cout.unsetf(ios::hex);
	cout << i << endl;
	
	cout  << "uppercase & scientific:" << endl;
	float f = (float)100.12;
	cout.setf(ios::uppercase | ios::scientific);
	cout << f << endl;
	cout.unsetf(ios::uppercase);
	cout << f << endl;
	cout.unsetf(ios::scientific);
	cout << f << endl;
	
	cout  << "precision:" << endl;
	double d = 1234.123412341234;
	cout << "d = " << d << endl;
	cout.precision(3);
	cout << "d = " << d << endl;
	cout.precision(8);
	cout << "d = " << d << endl;
	
	cout << "preenche espaços vazios:" << endl;
	cout.precision(3);
	cout.width(10);
	cout.fill('*');
	cout << "d = " << d << endl;
	cout.precision(8);
	cout.width(10);
	cout.fill('*');
	cout.setf(ios::left);
	cout << "d = " << d << endl;

	d = 3.14159;
	cout.setf(0, ios::floatfield);            // floatfield not set
	cout.precision(5);
	cout << d << endl;
	cout.precision(10);
	cout << d << endl;
	cout.setf(ios::fixed, ios::floatfield);   // floatfield set to fixed
	cout << d << endl;
}