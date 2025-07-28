#include "vld.h"
#include <iostream> // cout
using namespace std;

char *timeTable[16] = {
		"milisecond(s)",
		"microsecond(s)",
		"nanosecond(s)",
		"picosecond(s)",
		"femtosecond(s)",
		"attosecond(s)",
		"zeptosecond(s)",
		"yoktosecond(s)"
};

int main() {
	//char nome[30];
	float  m_mhz = 14.5;

	cout << timeTable[0] << endl;
	int hz  = 1;
	int khz = hz  * 1000;
	int mhz = khz * 1000;
	int ghz = mhz * 1000;

	m_mhz =60;//*= mhz;
	cout << "120mhz = " << m_mhz << "hertz..." << endl;
	printf("%20.18f\: \n", m_mhz);
	
	float f = (float)1/m_mhz;
	printf("%20.18f seconds \n", f);
	float f2 = f*1000;
	printf("%20.18f miliseconds \n", f2);
	float f3 = f2*1000;
	printf("%20.18f microseconds \n", f3);
	float f4 = f3*1000;
	printf("%20.18f nanoseconds \n", f4);
	cout << 

	//scanf( "%[^\n]", nome );
	//cout << nome << endl;

	system("pause");
	return(0);
}