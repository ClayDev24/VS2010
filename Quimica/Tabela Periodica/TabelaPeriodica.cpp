#include <iostream>
#include <iomanip>
#include "TabelaPeriodica.h"

namespace quimica {

	void TabelaPeriodica::adicionarElemento(const Atomo& atomo) {
		elementos.push_back(atomo);
		grupos[atomo.getGrupo()].push_back(atomo);
	}

	void TabelaPeriodica::exibirPorGrupo() const {
		for (const auto& par : grupos) {
			std::cout << "Grupo " << par.first << ":\n";
			for (const Atomo& a : par.second) {
				std::cout << std::setw(3) << a.getSimbolo()
					<< " (" << a.getNome() << "), Z=" << a.getNumeroAtomico()
					<< " - Família: " << a.getFamilia()
					<< ", Tipo: " << a.getTipo()
					<< ", Período: " << a.getPeriodo() << '\n';
			}
			std::cout << "--------------------------\n";
		}
	}

} // quimica
