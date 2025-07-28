#pragma once
#include <iostream>
#include "utils.h"

namespace elec {

	// Consumo M�dio de um eletr�nico:
	// ENTRADAS:
	//	- Tens�o de rede (V)
	//	- Corrente  (I)
	//	- Tempo     (t - em horas de uso por m�s)
	//	- Tarifa: 0,534 R$/kWh (Distribuidora: Enel SP /  Vig�ncia: 04/07/2020)
	
	// SA�DAS:
	//	- Pot�ncia (P): V.I (em watts)
	//	- Potencia Mensal (kWh): P.t / 1000 (wh para kWh)
	//	- Consumo mensal: kWh x Tarifa = reais por m�s
	void _Show(double tensao, double corrente, double tempo, double tax, double potencia, double kWh, double consumo) {
		using namespace utils;
		using namespace std;
		PrintColour_("<<__Consumo M�dio__>>\n", 0, FRI);

		PrintColour("Tens�o da REDE     (V)=> ", 0, FGI); cout << tensao   << " volt(s)  \n";
		PrintColour("Corrente Medida    (I)=> ", 0, FGI); cout << corrente << " ampere(s)\n";
		PrintColour("Tempo (em horas)   (t)=> ", 0, FGI); cout << tempo    << " hora(s)  \n";
		PrintColour("Pre�o do kWh (ENEL-SP)=> ", 0, FGI); cout << kWh      << " kWh    \n\n";
		 
		PrintColour("Pot�ncia           (P)=> ", 0, FGI); cout << potencia << " watt(s) \n";
		PrintColour("Consumo Mensal(em kWh)=> ", 0, FGI); cout << consumo  << " reais   \n";
		PrintColour("Custo de energia  (R$)=> ", 0, FGI); cout << tax      << " reais \n\n";
	}

	double _consumo(double _tensao, double _corrente, double _tempo, double _tax=0.534, bool _show=true) {
		double consumo = 0.0;
		double potencia, kWh, custo;

		potencia = _tensao * _corrente;    // watts
		kWh = (potencia * _tempo) / 1000; // kWh
		consumo = kWh * _tax; // reais

		if(_show)
			_Show(_tensao, _corrente, _tempo, _tax, potencia, kWh, consumo);

		return consumo;
	}
	// **************<<_USAGE_>>****************
	static void _consumoUsage() {
		P_(_consumo(127.0, 1.4, 30.0))
		P_(_consumo(127.0, 36.0, 15.0, 0.61))
	}

} // elec