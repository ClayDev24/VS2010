#pragma once
#include <iostream>
#include <string>
#include <new>

namespace elec {

	static float _efficiency(float entrada, float saida) {
		// F�rmula:
		// % efici�ncia = (energia convertida / energia total dispon�vel) x 100
		return ((saida / entrada) * 100);
	}

	static float _eConvertida(float eficiencia, float entrada) {
		// F�rmula:
		// energia convertida = (eficiencia / energia total dispon�vel) x 100
		return ((eficiencia * entrada) / 100);
	}

	static float _eDisponivel(float eficiencia, float saida) {
		// F�rmula:
		// % eDisponivel = (energia convertida / % efici�ncia) x 100
		return ((saida / eficiencia) * 100);
	}

} // elec