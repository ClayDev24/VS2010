#pragma once
#include <typeinfo.h>	// typeid()
#include "utils.h"

template <typename T>
static void _typename(T _t) {
	std::cout << "The type of " << _t << " is " << typeid(_t).name() << std::endl;
};
// ***************** <<_USAGE_>> *****************
static void _typenameUsage() {

	utils::PrintColour_("<<_Typename Usage_>>", BRI);
	int var = 48;
	_typename(static_cast<char>(var));
//	_typename(static_cast<bool>(var)); // warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)
	_typename(static_cast<short>(var));
	_typename(static_cast<short int>(var));
	_typename(static_cast<int>(var));
	_typename(static_cast<long>(var));
	_typename(static_cast<long int>(var));
	_typename(static_cast<long long>(var));
	_typename(static_cast<float>(var));
	_typename(static_cast<double>(var));
//	_typename(static_cast<long float>(var)); // nonstandard extension used: long float WARNING
	_typename(static_cast<long double>(var));
	_typename(static_cast<unsigned char>(var));
	_typename(static_cast<unsigned short>(var));
	_typename(static_cast<unsigned short int>(var));
	_typename(static_cast<unsigned int>(var));
	_typename(static_cast<unsigned long>(var));
	_typename(static_cast<unsigned long int>(var));
	_typename(static_cast<unsigned long long>(var));
}	