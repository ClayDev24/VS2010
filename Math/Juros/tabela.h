#pragma once
#include "utils.h"
#include "compostos.h"
#include "simples.h"
#include "..\..\Utilidades\Utilidades\_setLocale.h"

namespace mat {
	static void _tabela() {
		utils::_setLocale();
		double capital   = 300.0;
		double taxaAnual =  12.14;
		double tempo     =   144.0;
		double simples   = capital;
		double compostos = capital;
		double juros = 0.0;
		for(int mes = 1; mes <= 144; mes++) {
			juros    =  _simplesJuros(simples,   taxaAnual, tempo);
			simples +=  juros;
			compostos = _compostosJuros(compostos, taxaAnual, tempo);

			std::cout << "mês " << std::setw(2) << mes << " | ";
			std::cout << std::fixed << std::setprecision(2) << std::setw(14) << simples << " | ";
			std::cout << std::fixed << std::setprecision(2) << compostos << std::endl;
		}
		compostos = _compostosJuros(capital, taxaAnual, 1000);
		P_(compostos)
	}
} // mat