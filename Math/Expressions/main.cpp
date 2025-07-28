//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "Equation.h"
#include "Monomio.h"
#include "utils.h"
using namespace std;

int main() {

	utils::PrintColour_("<<_EVALUATION OF EXPRESSIONS_>>", FRI);
	string expression = "2 x 3 = 10 - 4";

	S_(expression)

	utils::Tokenizer *tokens = new utils::Tokenizer(expression);

	for(int i=0; i<tokens->get_size(); i++) {
		cout << tokens->get_at(i) << endl;
	}

	math::_monomio();

	delete tokens;
	system("pause");
	return(0);
}

