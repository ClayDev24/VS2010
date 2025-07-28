#include "mdc.h"
#include "testing.h"
#include "..\Math\_divisores.h"

// Números Primos entre si=> são dois números que possuem o MDC = 1. Eg.: 3 e 4

// Método 1-Decomposição em fatores primos:
int math::mdc(const int _sz, ...) { REQUIRE(_sz >= 2)
	vetorUInt *match;
	va_list args;
	va_start(args, _sz);
	vetorUInt *A = _divisoresP<unsigned int>(va_arg(args, int));
	vetorUInt *B;

	for(int i=0; i<_sz-1; i++) {
		B = _divisoresP<unsigned int>(va_arg(args, int));
		match = new vetorUInt();
		for(unsigned int a=0; a < A->size(); a++)
			for(unsigned int b=0; b < B->size(); b++)
				if(A->at(a) == B->at(b))
					match->push_back(A->at(a));
		delete A;
		delete B;
		A = match;
	}
	va_end(args);
	int mdc = match->at(match->size()-1);
	delete match;
	return mdc;
}
// método 2-(Versão didática): Método de Euclides (divisões sucessivas)
int math::mdc2(const int _sz, ...) { REQUIRE(_sz >= 2)
	using namespace std;
	utils::Console cmd;

	int dividendo, divisor, quociente, resto;
	vetorInt *vi = new vetorInt();
	va_list args;
	va_start(args, _sz);
	for(int i=0; i<_sz; i++) {
		vi->push_back(va_arg(args, int));
		cmd.setColour(FY);
		cout << "<" << vi->at(i) << ">";
		cmd.setColour(FWI);
	} va_end(args);
	cout << endl;

	divisor = vi->at(0);
	for(int i=1; i<_sz; i++) {
		dividendo = vi->at(i);
		if(dividendo < divisor) {
			//int troca = dividendo;
			//dividendo = divisor;
			//divisor   = troca;
		}
		do {
			cout << setw(4) << dividendo << setw(3) << " | " << setw(3) << divisor;
			resto     = dividendo % divisor;
			quociente = dividendo / divisor;
			cout << " (q: " << quociente << ", resto: " << resto << ")\n";
			dividendo = divisor;
			if(resto) {
				divisor = resto;
			} 
		} while(dividendo % divisor);
	}
	return divisor;
}
// Versão com mmc truncado (até todos os ns dividirem por um mesmo n. primo.)
int math::mdc3(const int _sz, ...) { REQUIRE(_sz >= 2)
	vetorUInt *vt1 = new vetorUInt();
	vetorUInt *vt2;// = new vetorUInt();
	vetorUInt *vt3 = new vetorUInt();
	vetorUInt result, resultMDC, resto;
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
	bool mmc  = true;
	while(true) {
		remainder = 0;
		done = false;
		mmc  = true;
		//divisor++;
		for(int i=0; i<_sz; i++) {
			dividend  = vt2->at(i);
			remainder = dividend % divisor;
			quocient  = dividend / divisor;
			if(!remainder) { // divisão exata
				done = true;
				vt3->push_back(quocient);
				//resto.push_back(quocient);
			} else { // divisão inexata
				vt3->push_back(dividend);
				mmc=false;
			}
		}
		if(done&&mmc) {
			resultMDC.push_back(divisor);
			//showVetor2(*vt3);		
			//std::cout << std::setw(4) << " | " << divisor << std::endl;
		}
		if(done) {
			result.push_back(divisor);
			//showVetor2(*vt2);		
			//std::cout << std::setw(4) << " | " << divisor << std::endl;
		} else
			divisor++;

		delete vt2;
		vt2 = vt3;
		vt3 = new vetorUInt();
		// Se todas as divisões resultarem nem 1:
		int soma = 1;
		for(unsigned int i=0; i<vt2->size(); i++)
			soma *= vt2->at(i);
		if(soma == 1) break;
	}
	for(unsigned int i=0; i<resultMDC.size(); i++)
		matching *= resultMDC.at(i);
	//delete vt1;
	//delete vt3;
	return matching;
}
// **************<<_USAGE_>>****************
void math::mdcUsage() {
	utils::Console cmd;//(50, 20, "<<_(M)ÁXIMO_(D)IVISOR_(C)OMUM_>>");
	cmd.setColour(FGI);
	cmd.prtColorReturn("\n<<_(M)ÁXIMO_(D)IVISOR_(C)OMUM_>>\n", FRI);
	cmd.prtColorReturn("mdc(168, 56, 175, 49):\n", FY);

	// Números primos entre si=> Qndo o mdc entre eles for igua à i
	P_(mdc (4,5)) // O m. 4 não é primos, mas o conjunto {4, 5} é primo

	cmd.prtColorReturn("Método 1=> Decomposicão em fatores primos:\n", FRI);
	P_(mdc (2, 168, 56, 175, 49))

	cmd.prtColorReturn("Método 2=> Algorítmo de Euclídes:\n", FRI);
	P_(mdc2(2, 168, 56, 175, 49));
	//P_(mdc2(4, 49, 56, 168, 175))
	//P_(mdc2(4, 56, 49, 168, 175))
	
	cmd.prtColorReturn("Método 3=> Métdo MMC truncado:\n", FRI);
	P_(mdc3(2, 168, 56, 175, 49))

	//_teste();//MDC);
}
