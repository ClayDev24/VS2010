#pragma once

namespace math {

	// Decomposição em FATORES PRIMOS:
	// Todo n. composto pode ser escrito num produto em que só aparecem fatores primos, como 2, 3, 6, 7, 11, 13...etc.
	vetorUInt fatorationTree(unsigned int _dividendo, bool show = true);
	// **************<<_USAGE_>>****************
	void _fatorationTree();

} // math