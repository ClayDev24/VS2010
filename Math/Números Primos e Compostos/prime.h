#pragma once
#include <iostream>
#include "utils.h"

namespace math {
	// Número PRIMO=> Apenas 2 divisores (ele próprio eo o n.1). Não tem lei (ou fórmula) de formação.
	// Número COMPOSTO=> Apresenta mais de dois divisores. O contrário do n. primo.
	// Se um n. é < 121 e não é divisível por 2, 3, 5 e 7 é de antemão  um n. PRIMO.
	// Se um n. é < 289 e não é divisível por 2, 3, 5, 7, 11 e 13 não é um n. PRIMO.

	// Teste de força bruta: (o mais confiável, porém o mais demorado.
	// Usado para testar os outros algoritmos
 	bool prime(const unsigned long long &_n);
	// Teste de força bruta2
	bool prime2(const unsigned long long &_n);
	// O n. é primo se as divisões sucessivas por ns. primos resultarem resto diferente de zero
	// até o divisor ser maior ou igual ao quociente.
	bool prime3(const unsigned long long &_n);
	// Para determinar se um certo número inteiro é primo basta dividi-lo por
	// todos os primos menores ou iguais à sua raiz quadrada.
	bool prime4(const unsigned long long &_n);

	// **************<<_USAGE_>>****************
	// Function Ptr
	typedef bool (*fPtr)(const unsigned long long &);
	typedef std::vector<fPtr>  vfPtr2;

	static void test();
	static void test2();
	void primeTest();
} // math