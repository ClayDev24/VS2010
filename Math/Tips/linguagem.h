#pragma once
#include "..\..\Utilidades\Utilidades\_setLocale.h"
#include "defines.h"

namespace math {

	static void linguagem() {

		utils::_setLocale();
		utils::PrintColour_("<<_INTERPRETAÇÃO_DE_TEXTOS_EM_RESOLUÇÃO_DE_PROBLEMAS_>>", FRI);
		utils::PrintColour_("de, da, do --> multiplicação\n" \
			"por -->divisão\n" \
			"equivale, será, é, tem...--> igualdade\n" \
			"referente a um número desconhecido (x) --> dobro (2x), triplo (3x), metade (x/2), terça parte(x/3)...\n" \
			"A soma de x e y      --> (x + y)\n" \
			"A diferença de a e b --> (a - b)\n" \
			"O produto de x e y   --> (x . y) ou (xy)\n" \
			"O quociente entre m e n --> (m:n)\n" \
			"x é 10 unidades maior que y --> x = y + 10\n" \
			"a é  5 unidades maior que b --> a = b - 5\n" \
			"c é  8 unidades menor que d --> c = d - 8\n" \
			"x excede a y em 6      --> x = y + 6\n" \
			"2 números consecutivos --> x, x+1\n" \
			"3 números consecutivos --> x, x+1, x+2\n" \
			"um número par   --> 2x\n" \
			"um número ímpar --> (2x - 1) ou (2x + 1)\n" \
			"2 números pares consecutivos   --> 2x, 2x+2\n" \
			"2 números ímpares consecutivos --> 2x-1, 2x-1+2 ou 2x+1\n" \
			"O oposto  de x (na adição)      --> x = -x\n" \
			"O inverso de x (na multiplicação) --> x = 1/x\n", FY);
	}
} // math