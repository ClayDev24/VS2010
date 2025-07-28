#pragma once
#include "utils.h"

namespace math {

	static void _comutativa() {
		// Propriedade comutativa=> (multiplicação/adição) Não importa a ordem de soma/multiplicação
		utils::PrintColour_("<<_COMUTATIVA_>>", BBI);
		std::cout << "a + b = b + a | a x b = b x a \n\n";
	}
} // math