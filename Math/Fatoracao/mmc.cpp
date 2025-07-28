#include "mmc.h"
#include "testing.h"
#include "..\Utilidades\Utilidades\_require.h"
#include "..\Math\Math\_multiplos.h" // multiplos2.h

// Método 1=> Decomposição em fatores primos.
// Busca sequencial:
unsigned long int math::mmc(int _sz, ...) { utils::require(_sz >= 2); // STACK version
	vetorUInt vi;
	unsigned int inflateA = 1;
	unsigned int inflateB = 1;
	int i = _sz+1;
	va_list args;
	va_start(args, _sz);
	while(--i)
		vi.push_back(va_arg(args, int));
	va_end(args);
	sort(vi.begin(), vi.end());
	unsigned int a = vi.at(i++) * inflateA;
	unsigned int b = vi.at(i++) * inflateB;
	while(true)
		if(a==b) {
			while((_sz--)-2) // is it the end?
				a = mmc(2, vi.at(i++), a);
			return a;
		} else
			if(a<b)
				a = vi.at(0) * inflateA++;
			else
				b = vi.at(1) * inflateB++;
}
unsigned long int math::mmc2(int _sz, ...) { utils::require(_sz >= 2); // STACK version
	const int MAX = 3; // 3=> best result performance!
	vetorUInt vi, vta, vtb;
	unsigned int inflateA = MAX;
	unsigned int inflateB = MAX;
	unsigned int matching = 0;
	int i = _sz+1;
	va_list args;

	va_start(args, _sz);
	while(--i)
		vi.push_back(va_arg(args, int));
	va_end(args);
	sort(vi.begin(), vi.end());

	_multiplos2(vi.at(i++), 1, inflateA, vta);
	_multiplos2(vi.at(i++), 1, inflateB, vtb);
	for(unsigned int a=0; a<vta.size(); a++) {
		for(unsigned int b=0; b<vtb.size(); b++)
			if(vta.at(a) == vtb.at(b)) {
				matching = vta.at(a);
				while((_sz--)-2) // is it the end?
					matching = mmc2(2, vi.at(i++), matching);
				return matching;
			}
		if(a==(vta.size()-1)) { // the last one
			if(vta.at(vta.size()-1) < vtb.at(vtb.size()-1)) {
				inflateA += MAX;
				_multiplos2(vi.at(0), inflateA-MAX, inflateA+MAX, vta);
				a=0;
			} else {
				inflateB += MAX;
				_multiplos2(vi.at(1), inflateB-MAX, inflateB+MAX, vtb);
				a=0;
			}
		}
	}
}
unsigned long int math::mmc3(int _sz, ...) { utils::require(_sz >= 2); // HEAP version
	const int MAX = 6; // 6=> Best result performance!
	vetorUInt vi;
	unsigned int inflateA = MAX;
	unsigned int inflateB = MAX;
	unsigned int matching = 0;
	int i = _sz+1;
	va_list args;

	va_start(args, _sz);
	while(--i)
		vi.push_back(va_arg(args, int));
	va_end(args);
	sort(vi.begin(), vi.end());

	vetorUInt *A = _multiplos<unsigned int>(vi.at(i++), 1, inflateA); // A recebe o ownership. Memory must be released!
	vetorUInt *B = _multiplos<unsigned int>(vi.at(i++), 1, inflateB); // A recebe o ownership. Memory must be released!
	for(unsigned int a=0; a<A->size(); a++) {
		for(unsigned int b=0; b<B->size(); b++)
			if(A->at(a) == B->at(b)) {
				matching = A->at(a);
				while((_sz--)-2)
					matching = mmc3(2, vi.at(i++),  matching);
				delete A;
				delete B;
				return matching;
			}
		if(a==A->size()-1) {// last one?
			if(A->at(A->size()-1) < B->at(B->size()-1)) {
				inflateA += MAX;
				delete A;
				A = _multiplos<unsigned int>(vi.at(0), inflateA-MAX, inflateA+MAX);
				a=0;
			} else {
				inflateB += MAX;
				delete B;
				B = _multiplos<unsigned int>(vi.at(1), inflateB-MAX, inflateB+MAX);
				a=0;
			}
		}
	}
}
// Busca NON-Sequencial (search):
unsigned long int math::mmc4(int _sz, ...) { utils::require(_sz >= 2);
	const int MAX=50; // 50=> 105,418s
	vetorUInt vi, vta, vtb, match;
	unsigned int inflateA = MAX;
	unsigned int inflateB = MAX;
	int i=_sz+1;
	va_list args;

	va_start(args, _sz);
	while(--i)
		vi.push_back(va_arg(args, int));
	va_end(args);
	sort(vi.begin(), vi.end());

	_multiplos2(vi.at(i++), 1, inflateA, vta);
	_multiplos2(vi.at(i++), 1, inflateB, vtb);
	while(true)
		if(search2(vta, vtb, match)) {
			while((_sz--)-2)
				match[0] = mmc4(2, vi.at(i++), match[0]);
			return match[0];
		} else
			if(vta.at(vta.size()-1) < vtb.at(vtb.size()-1)) {
				inflateA += MAX;
				_multiplos2(vi.at(0), inflateA-MAX, inflateA+MAX, vta);
			} else {
				inflateB += MAX;
				_multiplos2(vi.at(1), inflateB-MAX, inflateB+MAX, vtb);
			}
}

unsigned long int math::mmc5(int _sz, ...) { utils::require(_sz >= 2);
	vetorUInt *vt1 = new vetorUInt();
	vetorUInt *vt2;// = new vetorUInt();
	vetorUInt *vt3 = new vetorUInt();
	vetorUInt result;
	unsigned long int remainder, quocient, dividend, divisor;
	unsigned long int matching = 1;

	va_list args;
	va_start(args, _sz);
	for(int i=0; i<_sz; i++)
		vt1->push_back(va_arg(args, int));
	va_end(args);
	sort(vt1->begin(), vt1->end());
	vt2 = vt1;
	//showVetor(vi);
	remainder = 1;
	divisor   = 2;
	bool done = false;
	while(true) {
		remainder = 0;
		done = false;
		//divisor++;
		for(int i=0; i<_sz; i++) {
			dividend  = vt2->at(i);
			remainder = dividend % divisor;
			quocient  = dividend / divisor;
			if(!remainder) { // divisão exata
				done = true;
				vt3->push_back(quocient);
			} else // divisão inexata
				vt3->push_back(dividend);
		}
		if(done) {
			result.push_back(divisor);
			showVetor2(*vt2);		
			std::cout << std::setw(4) << " | " << divisor << std::endl;
			//_getche();
		} else
			divisor++;
		delete vt2;
		vt2 = vt3;
		
		int soma = 1;
		for(unsigned int i=0; i<vt2->size(); i++)
			soma *= vt2->at(i);
		if(soma == 1) {
			delete vt2;
			break;
		}
		vt3 = new vetorUInt();
	}
	
	for(unsigned int i=0; i<result.size(); i++)
		matching *= result.at(i);
	//delete vt1;
	//delete vt3;
	return matching;
}
// **************<<_USAGE_>>****************
void math::mmcUsage() {

	utils::Console cmd;
	//Console cmd(50, 20, "<<_(M)INIMO_(M)ULTIPLO_(C)OMUM_>>");
	cmd.setColour(FGI);
	cmd.prtColorReturn("\n<<_(M)ÍNIMO_(M)ÚLTIPLO_(C)OMUM_>>\n", FRI);
	//cmd.prtColorReturn("mmc(4, 315, 614, 758, 555):\n", FY);
	P_(mmc (5, 18,24,32,40,100))
	P_(mmc2(5, 18,24,32,40,100))
	P_(mmc3(5, 18,24,32,40,100))
	P_(mmc4(5, 18,24,32,40,100))
	P_(mmc5(5, 18,24,32,40,100))

	P_(mmc (4, 315, 614, 758, 555))
	P_(mmc2(4, 315, 614, 758, 555))
	P_(mmc3(4, 315, 614, 758, 555))
	P_(mmc4(4, 315, 614, 758, 555))
	P_(mmc5(4, 315, 614, 758, 555))

	//_teste(MMC);
	//P_(utils::_chronometer(&_teste))
}