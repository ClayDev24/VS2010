#pragma once
#include <iostream>
#include <string>
#include <new>

namespace elec {

	static float _efficiency(float entrada, float saida) {
		// Fórmula:
		// % eficiência = (energia convertida / energia total disponível) x 100
		return ((saida / entrada) * 100);
	}

	static float _eConvertida(float eficiencia, float entrada) {
		// Fórmula:
		// energia convertida = (eficiencia / energia total disponível) x 100
		return ((eficiencia * entrada) / 100);
	}

	static float _eDisponivel(float eficiencia, float saida) {
		// Fórmula:
		// % eDisponivel = (energia convertida / % eficiência) x 100
		return ((saida / eficiencia) * 100);
	}

} // elec