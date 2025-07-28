// Cálculo de EFICIÊNCIA:
#include "utils.h"
#include "Ohm.h"
#include "potencia.h"
using namespace std;

int main() {
	utils::_setLocale();

	float voltage, current, resistance, power;
	voltage = current = resistance = power = 0;
/*
	cout << "Cálculo da LEI DE OHM:" << endl;
	cout << "Type what you wanna know <enter>:" << endl;
	prtColour("1- Voltage;   ", 0, FWI); cout << endl;
	prtColour("2- Current;   ", 0, FWI); cout << endl;
	prtColour("3- Resistance;", 0, FWI); cout << endl;

	int i;
	cin >> i;
	switch(i) { // just accept integer types at compile-time.
	case 1:
		cout << "Type the CURRENT    (I): "; cin >> current;
		cout << "Type the RESISTANCE (R): "; cin >> resistance;
		cout << "EMF = " << _voltage(current, resistance) << "V\n\n";
		break;
	case 2:
		cout << "Type the VOLTAGE    (V): "; cin >> voltage;
		cout << "Type the RESISTANCE (R): "; cin >> resistance;
		cout << "I = " << _current(voltage, resistance) << "A\n\n";
		break;
	case 3:
		cout << "Type the VOLTAGE (V):"; cin >> voltage;
		cout << "Type the CURRENT (I):"; cin >> current;
		cout << "R = " << _resistance(voltage, current) << " Ohms\n\n";
		break;
	default: cout << "Error...default msg!\n";
	}
	*/
	cout << "Cálculo de POTÊNCIA:" << endl;
	cout << "Type what you wanna know <enter>:" << endl;
	utils::PrintColour_("1- Power;   ", 0, FWI);
	utils::PrintColour_("12- Voltage; ", 0, FWI);
	utils::PrintColour_("3- Current. ", 0, FWI);

	int i;
	cin >> i;
	switch(i) { // just accept integer types at compile-time.
	case 1:
		cout << "Type the VOLTAGE (V): "; cin >> voltage;
		cout << "Type the CURRENT (I): ";  cin >> current;
		cout << "P = " << elec::_potencia(voltage, current) << " watts\n\n";
		break;
	case 2:
		cout << "Type the POWER   (P): "; cin >> power;
		cout << "Type the CURRENT (I): "; cin >> current;
		cout << "I = " << elec::_voltage(power, current) << " volts\n\n";
		break;
	case 3:
		cout << "Type the POWER   (P): "; cin >> power;
		cout << "Type the VOLTAGE (V): "; cin >> voltage;
		cout << "R = " << elec::_current(power, voltage) << " A\n\n";
		break;
	default: cout << "Error...default msg!\n";
	}

	system("pause");
	return(0);
}

