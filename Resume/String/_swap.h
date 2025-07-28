#pragma once
#include <iostream>
#include <string>
#include "_1_character_strings.h"

namespace resume {

	static void _swap() {
		using namespace std;
		string buyer("money");	PR(buyer)
		string seller("goods");	PR(seller)

		seller.swap(buyer); // Swap'em contents
		cout << "After swap:";	PR(buyer)
		cout << "After swap:";	PR(seller)
	}

} // resume