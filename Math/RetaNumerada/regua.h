#pragma once
#include "utils.h"

namespace math {

	void retaNumerada(const int &_begin, const int &_end) {
		using namespace std;

		utils::_setLocale();
		utils::PrintColour_("\n<<_RETA_NUMERADA_>>\n", FRI);

		for(int i=_begin; i<=_end; i++)
			cout << std::setw(10) << i;
		cout << endl;

		for(int i=_begin; i<=_end; i++)
			utils::PrintColour("|_,_,_,_,_", FWI);
		cout << "|\n\n";
	}

	void _retaNumerada() {
		retaNumerada(10, 15);
		retaNumerada(0, 10);
	}

} // math