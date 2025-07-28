#pragma once
#include <math.h> // pow
#include "defines.h"

// Regime de Capitaliza��o Composta - (Juros Compostos)
// Progress�o GEOM�TRICA
// Ex.: Capital ($100,0 - 10%am - 4meses)
// 10/01_____ R$100,00
// 10/02_____ R$110,00 (+R$10,00 - x 1,1)
// 10/03_____ R$121,00 (+R$11,00 - x 1,1)
// 10/04_____ R$133,10 (+R$12,10 - x 1,1)
// F�rmula:
// M = C(1 + i)^t => Montante = Capital(1 + taxa)^tempo *******A taxa e o tempo sempre CONCORDAM em meses ou anos!********
static double _compostosJuros(double capital, double taxaAnual, double meses) {
	// Taxa de Juros Compostos SEM APORTE MENSAL:
	double C = capital;
	double i = taxaAnual / 100.0; // taxa anual (decimal)
	double t = meses / 12.0;	  // tempo em anos
	double M = C * pow((1 + i), t);

	return M;
}
// Taxa de Juros Compostos COM APORTE MENSAL:
static double _compostosJuros2(double principal, double taxaAnual, double meses, double aporteMensal=0.0) {
    // Converte a taxa anual em taxa peri�dica (mensal) e o tempo em per�odos (meses).
    double taxaMensal = taxaAnual / 12.0 / 100.0; // taxa mensal decimal
    //double meses = anos * 12;
    // Calcula o montante acumulado com juros compostos e aporte mensal.
    double montante = principal;

    for (int i = 0; i < meses; i++) {
        montante *= (1 + taxaMensal);
        montante += aporteMensal;
    }
    return montante;
}

static double _compostosJuros3(double capital, double taxaAnual, double meses, double aporteMensal=0.0) {
	double C   = capital;		// Capital (montante inicial)
	double i   = taxaAnual / 100.0; // taxa de juros anual (decimal)
	double n   = 12.0;			// � o n�mero de vezes que o juro � composto por ano (normalmente 12 para juros compostos mensais).
	double t   = meses / 12.0;		// � o per�odo de tempo em meses.
	double PMT = aporteMensal;	//PMT � o aporte mensal adicional.
	// F�rmula:
	//M = C * (1 + i/n)^(n*t) + (PMT * ((1 + i/n)^(n*t) - 1) / (i/n))
	double aporte = PMT * ((pow((1 + i/n), (n*t))-1) / (i/n));
	P_(aporte)
	double M = C * (pow((1 + (i/n)), n*t)) + aporte; // Montante
	
	return M;
}

// F�rmula para obter o tempo:
// t = j / (C * i)
// Formula para obter a taxa de juros:
// i = j / (C * t)
// **************<<_USAGE_>>****************
static void _compostosUsage() {
	
	utils::dicShow("mathematics", "Juros Compostos");

	P_(_compostosJuros (300.0, 12.14, 1.0))
	P_(_compostosJuros2(300.0, 12.14, 1.0));//, 300.0))
	P_(_compostosJuros3(300.0, 12.14, 1.0));//, 300.0))
}