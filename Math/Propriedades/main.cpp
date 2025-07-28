#include "associativa.h"
#include "comutativa.h"
#include "distributiva.h"

int main() {

	utils::PrintColour_("\n<<_PROPRIEDADES_>>\n", BRI);
	math::_associativa();
	math::_distributiva();
	math::_comutativa();

	system("pause");
	return(0);
}