#include <iostream>
#include "sistema.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();
	utils::PrintColour_("<<_SISTEMA_DE_EQUAÇÕES_>>", BRI);

	math::_sistemUsage();

	system("pause");
	return(0);
}