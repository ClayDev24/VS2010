#pragma once
#include "utils.h"

namespace math {
	// -O zero é múltiplo de qualquer n.
	// -Todo n. é múltiplo de si mesmo.
	// -O conjunto dos múliplos de um n. diferente de zero é INFINITO.

	// Retorna vector<Type>:
	template <typename Type>
	static std::vector<Type> *_multiplos(const Type &_n, const int &_from, const int &_to) {
		std::vector<Type> *v = new std::vector<Type>;
		for(int i=_from; i<=_to; i++)
			v->push_back(_n*i);
		return v;
	}

	template <typename Type>
	static void _multiplos2(const Type &_n, const int &_from, const int &_to, std::vector<Type> &_v) {
		_v.clear();
		for(int i=_from; i<=_to; i++)
			_v.push_back(_n*i);
	}
	// **************<<_USAGE_>>****************
	static void _multiplosUsage() {

		//utils::dicShow("mathematics", "Múltiplos");

		utils::Console cmd;//(50, 20, "<<_MULTIPLOS_>>");
		cmd.setColour(FGI);
		cmd.prtColorReturn("\n******<<_MULTIPLOS_>>******\n", FRI);
		cmd.prtColorReturn("multiplos(5, 0, 5):\n", FY);

		vetorInt *v1 = _multiplos<int>(5, 0, 5);
		utils::_showVetor(*v1); N
			delete v1;

		vetorInt v2;
		_multiplos2(3, 0, 3, v2); // Preenche o vetor v2.
		utils::_showVetor(v2); N

		_multiplos2(4, 0, 25, v2); // Altera o conteúdo de v2.
		utils::_showVetor(v2); N

		vetorInt *v3 = _multiplos<int>(184, 0, 100);
		utils::_showVetor(*v3); N
		P_(v3->at(100))
		P_(v3->size())
		delete v3;

		vetorInt v4;
		_multiplos2(184, 0, 2000000, v4); // Preenche o vetor v2.
		//utils::_showVetor(v3); N
		P_(v4.at(2000000))
		P_(v4.size())
	}

} // math