#pragma once

namespace math {
	// Divisibilidade: Divisão exata de um n. por outro.
	// Qndo um n. é divisível por outro ele tb é multiplo do outro.
	// Para obter o conjunto dos múltiplos de um n. multiplicar este n. pelos elementos do conjunto dos números naturais. (zero em diante)

	// Divisibilidade por 2=> Qualquer n. par (terminado em 0, 2, 4, 6 e 8)
	bool divBy2(const unsigned long  &_n);
	// Divisibilidade por 3=> A soma dos 'valores absolutos' (raiz digital) de seus algarismos é divisível por 3;
	bool divBy3(const unsigned long  &_n);
	// Divisibilidade por 4=> Qndo os 2 últimos digitos do n. forem divisíveis por 4:
	bool divBy4(const unsigned long  &_n);
	// Divisibilidade por 5=> Qualquer n. terminado em 0 ou 5.
	bool divBy5(const unsigned long  &_n);
	bool divBy5b(const unsigned long &_n);	
	// Divisibilidade por 6=> Qualquer n. divisível por 2 && 3:
	bool divBy6(const unsigned long  &_n);
	// Divisibilidade por 7=> 22 389 651 536     (Dividir cada grupo de 3 por 7)
	//                        \/ \/  \/  \/      (Somar o resultado)
	//						  +1 -4  +0  -4 = -7 (Resultdo divisível por 7!)
	bool divBy7(const unsigned long  long &_n);
	// Divisibilidade por 8=> Qndo a som dos 3 últimos digitos do n. forem divisíveis por 8.
	bool divBy8(const unsigned long  &_n);
	// Divisibilidade por 9=> Raiz digital = 9
	bool divBy9(const unsigned long  &_n);
	bool divBy9b(const unsigned long &_n);
	// Divisibilidade por 10=> Qualquer n. terminado no digito 0 (n>0).
	bool divBy10(const unsigned long &_n);
	// Divisibilidade por 11=> Qndo a diferença alternada (pares - ímpares) for divisível por 11.
	bool divBy11(const unsigned long &_n);
	// Divisibilidade por 12=> Qndo o n. for divisível por 3 && 4 (já que 3x4=12)
	bool divBy12(const unsigned long &_n);
	// Divisibilidade por 15=> 3x5=15 (e assim sucessivamente com outros ns.
	bool divBy15(const unsigned long &_n);

	// **************<<_USAGE_>>****************
	void _divisibilidadeUsage();
	void _display(const int &_div, const int &_looping, bool show = true);
	void _display2(const int &_div, const int &_looping, bool show = true);
	void _testDiv();

} // math