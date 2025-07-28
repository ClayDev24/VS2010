#pragma once
#include <iostream>
#include <string>
#include <cmath>

namespace utils {

	static void fracao() {
		using namespace std;
		double x = 14.86;
		
		double intPart, fractPart;
		fractPart = modf(x, &intPart);
		cout << x << " = " << intPart << " + " << fractPart << endl;

		x = -31.201;
		fractPart = modf(x, &intPart);
		cout << x << " = " << intPart << " + " << fractPart << endl;
	}
}