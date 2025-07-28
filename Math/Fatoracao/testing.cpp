#pragma once
#include "testing.h"
#include "mmc.h"
#include "mdc.h"
#include "..\..\Utilidades\Console\console.h"
#include "include_all.h"

void math::display(const int &_sz, testType _type, bool _show) { utils::require(_sz<=9);
	utils::Console cmd;
	int v[9]; MEMSET(v,_sz)

	for(int i=0; i<_sz; i++) {
		v[i] = utils::_random(2, 200); // (min / max)N();
		//if(primo(v[i])) i--; // filtrando os primos
	}

	unsigned long long a, b;
	switch(_type) { // just accept integer types at compile-time.
	case MMC:
		a = mmc (_sz, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
		b = mmc5(_sz, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
		break;
	case MDC:
		a = mdc (_sz, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
		b = mdc3(_sz, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
		break;
	default: std::cout << "Error!, Test type not defined yet.\n";
	}
	
	if(_show) {
		cmd.setColour(FRI);
		std::cout << "\n<<_" << _sz << "_>>" << std::endl;

		cmd.setColour(FYI);
		for(int i=0; i<_sz; i++)
			std::cout << "<" << v[i] << ">"; // Show vector:

		utils::PrintColour_("", FGI);	
		P_(a) P_(b)
	}

	if(a!=b) {
		P_("ERROR!!!")
		_getche();
	}
}
void math::_teste() { //testType _type) {
	for(int i=0; i<=1000000; i++) {
		int size = utils::_random(2, 4); // =>2~9 (máximo 9)
		display(size, MDC, true);//_type);
	}
}