//#include "vld.h"
#include "agregation.h"
#include "composition.h"

int main() {

	_agregationUsage();
	_compositionUsage();


	system("pause");
	return(0);
}

/*
Por que é composição?
	-Essas partes (engine, wheel, left, right) são membros por valor, ou seja, são criadas automaticamente junto com o objeto Car.
	-Quando o objeto Car é destruído, os membros engine, wheel[] e left/right também são destruídos automaticamente.
	-Portanto, a relação é de composição: Car possui (owns) seus componentes.
*/