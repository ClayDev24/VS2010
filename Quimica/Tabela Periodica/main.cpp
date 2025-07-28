#include <iostream>
#include "TabelaPeriodica.h"

int main() {
	using namespace quimica;

    TabelaPeriodica tabela;

    tabela.adicionarElemento(Atomo(1, "H", "Hidrogênio", "Sem família", 1, 1, "Não-metal"));
    tabela.adicionarElemento(Atomo(2, "He", "Hélio", "Gases Nobres", 18, 1, "Gás Nobre"));
    tabela.adicionarElemento(Atomo(3, "Li", "Lítio", "Metais Alcalinos", 1, 2, "Metal"));
    tabela.adicionarElemento(Atomo(11, "Na", "Sódio", "Metais Alcalinos", 1, 3, "Metal"));
    tabela.adicionarElemento(Atomo(17, "Cl", "Cloro", "Halogênios", 17, 3, "Não-metal"));

    std::cout << "=== TABELA PERIÓDICA ORGANIZADA POR GRUPO ===\n";
    tabela.exibirPorGrupo();

    return 0;
}
