#include <iostream>
#include "radical.h"
#include "utils.h"

int main() {
	using namespace std;

	utils::PrintColour_("<<_RADICAL_>>", FRI);

	math::radicalUsage();

	system("pause");
	return(0);
}