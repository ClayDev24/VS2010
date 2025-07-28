#include "fatoresComuns.h"
#include "..\Math\_divisores.h"

vetorUInt* math::fatoresComuns(int _sz, ...) {
	vetorUInt *matching;
	vetorUInt *missing  = new vetorUInt();
	bool miss = true;

	va_list args;
	va_start(args, _sz);
	vetorUInt *A = _divisoresP(static_cast<unsigned int>(va_arg(args, int)));
	vetorUInt *B;

	for(int i=0; i<_sz-1; i++) {
		B = _divisoresP(static_cast<unsigned int>(va_arg(args, int)));
		matching = new vetorUInt();
		for(unsigned int a=0; a < A->size(); a++) {
			for(unsigned int b=0; b < B->size(); b++)
				if(A->at(a) == B->at(b)) {
					matching->push_back(A->at(a));
					miss = false;
				}
				if(miss)
					missing->push_back(A->at(a));
				miss = true;
		}
		delete A;
		A = matching;
	}
	va_end(args);
	return matching;
}
// **************<<_USAGE_>>****************
void math::_fatoresComuns() {

	utils::Console cmd(50, 20, "<<_DIVISORES_COMUNS_>>");
	cmd.setColour(FGI);
	cmd.prtColorReturn("\n******<<_DIVISORES_COMUNS_>>******\n", FRI);
	cmd.prtColorReturn("divisoresComuns(24, 36, 60):\n", FY);

	vetorUInt *vi = fatoresComuns(3, 24, 36, 60);
	utils::_showVetor(*vi);

	delete vi;	
}