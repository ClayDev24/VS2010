// C�lculo de EFICI�NCIA:
#include <iostream> // cout
#include <sstream>
#include <string>
#include "efficiency.h"
#include "utils.h"
using namespace std;
using namespace utils;

int main() {
	utils::_setLocale();

	float eficiencia, entrada, saida = 0;

	cout << "C�lculo de EFICI�NCIA:" << endl;
	cout << "Type what you wanna know <enter>:" << endl;
	PrintColour_("1- % efici�ncia;                      ", 0, FWI);
	PrintColour_("2- energia convertida       (sa�da);  ", 0, FWI);
	PrintColour_("3- energia total dispon�vel (entrada).", 0, FWI);
	int i;
	cin >> i;

	switch(i) { // just accept integer types at compile-time.
	case 1:
		cout << "Entre com a energia total dispon�vel (entrada): "; cin >> entrada;
		cout << "Entre com a energia convertida       (sa�da)  : "; cin >> saida;
		cout << "Efici�ncia = " << elec::_efficiency(entrada, saida) << "%\n\n";
		break;
	case 2:
		cout << "Entre com a efici�ncia em porcentagem         : "; cin >> eficiencia;
		cout << "Entre com a energia total dispon�vel (entrada): "; cin >> entrada;
		cout << "Energia convertida (de sa�da) = " << elec::_eConvertida(eficiencia, entrada) << " joules\n\n";
		break;
	case 3:
		cout << "Entre com a efici�ncia em porcentagem       : "; cin >> eficiencia;
		cout << "Entre com a energia convertida       (sa�da): "; cin >> saida;
		cout << "Energia total dispon�vel (entrada) = " << elec::_eDisponivel(eficiencia, saida) << " joules\n\n";
		break;
	default: cout << "Error...default msg!\n";
	}
	
	PrintColour(" ", FWI, BRI);

	system("pause");
	return(0);
}

