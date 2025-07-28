#pragma once
#include "utils.h"
#include "defines.h"
// Regime de Capitaliza��o Simples = (Juros Simples)
// Progress�o ARITM�TICA
// Ex.: Capital ($100,0 - 10%am - 4meses)
// 10/01_____ R$100,00
// 10/02_____ R$110,00 (+R$10,00)
// 10/03_____ R$120,00 (+R$10,00)
// 10/04_____ R$130,00 (+R$10,00)
// Em juro simples 1% ao m�s = 12% ao ano
// M = C + J (Montante = Capital + juros)
// A taxa e o tempo dever�o estar sob a mesma unidade tempo (dia/m�s/ano)
// F�rmula
// J = C.i.t (Juros = Capital x taxa(unit�ria/de multiplica��o) x tempo-(em meses)) 
static double _simplesJuros(double C, double taxaAnual, double meses) {
	double t = meses;
	double i = taxaAnual / 100.0 / 12.0; // taxa mensal (decimal)
	double j = C * i * t;
	return j;
}
static double _simplesTaxa(double j, double C, double t) {
	double i = j / (C * t);
	return i; // taxa unit�ria (ex.: 0,25) Multiplicar or 100 ara obter a taxa percentual (ex.: 25%)
}
static double _simplesCapital(double j, double i, double t) {
	double C = j / (i * t);
	return C;
}
static double _simplesTempo(double j, double C, double i) {
	double t = j / (C * i);
	return t;
}
// O M�S COMERCIAL � SEMPRE de 30 dias! 
// **************<<_USAGE_>>****************
static void _simplesUsage() {
	
	utils::dicShow("mathematics", "Juros Simples");

	P_(_simplesJuros  (100.0, 12.14, 12.0))
	P_(_simplesTaxa   (12.14, 100.0, 12.0))
	P_(_simplesCapital(12.14, 0.010116666, 12.0))
	P_(_simplesTempo  (12.14, 100.00, 0.010116666))

}