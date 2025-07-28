#pragma once
#include "utils.h"

namespace math {
	// Número COMPOSTO=> Apresenta mais de dois divisores. O contrário do n. primo.
	// Pode ser arranjado numa forma retagular (linha x coluna)
	static vetorInt* _listCompost(const unsigned int &_from, const unsigned int &_to) {
		vetorInt *vi = new vetorInt();
		int  total = 0;
		for(unsigned int n=_from; n<=_to; n++, total++)
			if(!_prime(n))
				vi->push_back(n);
		return vi;
	}
	// **************<<_USAGE_>>****************
	static void _listCompostUsage() {
		utils::Console cmd(50, 65, "<<_LISTA_DE_NÚMEROS_COMPOSTOS_>>");
		cmd.setColour(FGI);
		cmd.prtColorReturn("\n******<<_LISTA_DE_NÚMEROS_COMPOSTOS_>>******\n", FRI);
		cmd.prtColorReturn("listCompost(0, 50):\n", FY);

		vetorInt *vi = _listCompost(0, 50);
		utils::_showVetor(*vi);
		std::cout << "total=> " << vi->size() << std::endl;

		delete vi;
	}
} // math