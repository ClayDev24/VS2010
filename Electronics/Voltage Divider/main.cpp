// Cálculo de EFICIÊNCIA:
#include <iostream> // cout
#include <string>
#include "divider.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();
	
	utils::PrintColour_("<< VOLTAGE DIVIDER >>\n", BRI);
	utils::PrintColour("");
	float Vs, R1, R2;
	Vs = 9.0;
	R1 = 470.0;
	R2 = 50.0;
	P_(Vs);
	P_(R1);
	P_(R2);

	for(int i=1; i<=100; i++) {
		utils::PrintColour("V'out = ", FRI);
		//printf("%*2.3f", -divider(9, )
		R2+=100;
		cout << elec::_voltage_out(Vs, R1, R2) << " volts" << endl;
	}

	system("pause");
	return(0);
}