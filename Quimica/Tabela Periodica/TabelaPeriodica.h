#pragma once
#include <vector>
#include <map>
#include <string>
#include "atomo.h"

namespace quimica {

	class TabelaPeriodica {
	private:
		std::vector<Atomo> elementos;
		std::map<int, std::vector<Atomo>> grupos;

	public:
		void adicionarElemento(const Atomo& atomo);
		void exibirPorGrupo() const;
	};

} // quimica
