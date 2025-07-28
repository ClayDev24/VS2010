#pragma once
// Propriedades:
// P1- O mdc entre dois ou mais números primos é sempre 1.
// P2- Se a é divisor de b, então o mdc(a, b) é o próprio a: mdc(6, 18)=6
// P3- mdc(8, 12)=4. Se multiplicar tudo por qq valor, o resultado é o mesmo valor multiplicado:
// Ex.: mdc(2x8, 2x12)=2x4 = mdc(16, 24)=8
// P4- Relação entre mmc e mdc. P/ multiplicar o mmc pelo mdc basta multiplicar ambos os valores.(desde que não sejam primos entre si) e consequentemente tenham resultado 1.
// Ex.: mmc(4,20) x mdc(4,20)= 4x20 = 80
namespace math {

	// Método 1=> Decomposição em fatores primos:
	int mdc(const int _sz, ...);
	// método 2=> Algorítmo de Euclídes (divisões sucessivas):
	int mdc2(const int _sz, ...);
	// método 3=> Versão com mmc truncado (até todos os ns dividirem por um mesmo n. primo.)
	int mdc3(const int _sz, ...);
	// **************<<_USAGE_>>****************
	void mdcUsage();

} // math