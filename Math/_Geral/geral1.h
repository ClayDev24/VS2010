#pragma once
#include "utils.h"
#include "mat.h"

// Toda vez que um n. tiver um n.ímpar de divisores, ele terá necessariamente um quadrado perfeito.

static void _geral1() {
	utils::PrintColour_("Divisores ímpares = quadrado perfeito:\n", FRI);
	for(unsigned long n=1; n<100; n++) {
		vetorULng v = math::_divisores(n);
		int divisores = v.size();
		bool b=math::_isSquare(n);
		if(divisores%2) { // se ímpar
			P_(n)
			P_(divisores)
			P_(b)
			utils::PrintColour_("IMPAR!:\n", FGI);
			if(!b) {
				utils::PrintColour_("NOT SQUARE!!!:\n", FRI);
				utils::_showVetor(v);
				system("pause");
			} N
		}
	}
}
static void _geral2() {
	utils::PrintColour_("Divisores ímpares = quadrado perfeito:\n", FRI);
	for(unsigned long n=1; n<100; n++) {
		vetorULng v   = math::_divisores(n);
		int divisores = v.size();
		bool b=math::_isSquare(n);
		if(!(divisores%2)) { // se par
			P_(n)
			P_(divisores)
			P_(b)
			utils::PrintColour_("PAR!:\n", FGI);
			if(b) {
				utils::PrintColour_("SQUARE!!!:\n", FRI);
				utils::_showVetor(v);
				system("pause");
			} N
		}
	}
}