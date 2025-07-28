#include <iostream>
#include "..\..\Utilidades\Utilidades\_colour.h"
#include "defines.h"

static const char *flagNames[] = {
		"skipws		",
		"unibuf		",
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
		"boolalpha	"
};

static void showIosFlags(std::ios &iosObj) {
	std::cout << "==== ios flag status\n";
	long k = 1;
	for(int i = 0; i < 15; i++) {
		std::cout << flagNames[i] << " is ";
		if(k & iosObj.flags()) {
			utils::PrintColour("", FGI);
			std::cout << "ON\n";
			utils::PrintColour("", FWI);

		} else {
			utils::PrintColour("", FRI);
			std::cout << "off\n";
			utils::PrintColour("", FWI);
		}
		k <<= 1; // rotate k => 00000001...00000010 and so on...
	}
	std::cout << std::endl;

	std::cout << "iosObj.flags():" << iosObj.flags() << std::endl;
	//k & iosObj.flags()
};

static void _flags() {
	using namespace std;
	//showIosFlags(cout);
	//cout.setf(ios::uppercase | ios::scientific);
	cout.unsetf(ios::skipws); 
	cout.unsetf(ios::unitbuf); 
	cout.unsetf(ios::uppercase); 
	cout.unsetf(ios::showbase); 
	cout.unsetf(ios::showpoint); 
	cout.unsetf(ios::showpos); 
	cout.unsetf(ios::left); 
	cout.unsetf(ios::right); 
	cout.unsetf(ios::internal); 
	cout.unsetf(ios::dec); 
	cout.unsetf(ios::oct); 
	cout.unsetf(ios::hex); 
	cout.unsetf(ios::scientific); 
	cout.unsetf(ios::fixed); 
	cout.unsetf(ios::hexfloat);
	cout.unsetf(ios::boolalpha);
	showIosFlags(cout);

	cout.setf(ios::skipws); 
	cout.setf(ios::unitbuf); 
	cout.setf(ios::uppercase); 
	cout.setf(ios::showbase); 
	cout.setf(ios::showpoint); 
	cout.setf(ios::showpos); 
	cout.setf(ios::left); 
	cout.setf(ios::right); 
	cout.setf(ios::internal); 
	cout.setf(ios::dec); 
	cout.setf(ios::oct); 
	cout.setf(ios::hex); 
	cout.setf(ios::scientific); // Depends os ios::hexfloat
	cout.setf(ios::fixed);		// Depends on ios::hexfloat
	cout.setf(ios::hexfloat);   // Sets scentific and fixed automatically
	cout.setf(ios::boolalpha);
	showIosFlags(cout);

	long flag = ios::right;
	P_(flag)

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
	float f = static_cast<float>(100.12);
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
}