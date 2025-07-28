#include <iostream>
#include "quadratic.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();
	utils::PrintColour_("<<_QUADRATIC_EQUATIONS_>>", BRI);

	math::_quadraticUsage();

	system("pause");
	return(0);
}