#include "prime.h"

// Teste de força bruta:
bool math::prime(const unsigned long long &_n) { // O n. 1 não é nem primo nem composto.
	if(_n<3) // Special case: 0, 1 e 2:
		return !((_n+7)%3);
	// divisibilidade por 3 em diante, até o fim do n:
	for(unsigned long long i=2; i<_n; i++) // i+=2 pular os pares
		if(!(_n%i))
			return false;
	return true;
}
// Força bruta2: 
bool math::prime2(const unsigned long long &_n) { // O n. 1 não é nem primo nem composto.
	if(_n<3) // Special case: 0, 1 e 2:
		return !((_n+7)%3);
	if(!(_n%2)) // Testa divisibilidade por 2:
		return false;
	// divisibilidade por 3 em diante, até metade de n:
	unsigned long long max = (_n/2)+1;
	for(unsigned long long i=3; i<max; i+=2)
		if(!(_n%i))
			return false;
	return true;
}
// O n. é primo se as divisões sucessivas por ns. primos resultarem resto diferente de zero
// até o divisor ser maior ou igual ao quociente.
bool math::prime3(const unsigned long long &_n) {
	if(_n<3) // Special case: 0, 1 e 2:
		return !((_n+7)%3);
	if(!(_n%2)) // Testa divisibilidade por 2:
		return false;
	// IMPORTANTE: Com o método do quociente não pode usar o método da raiz: unsigned long long raiz = static_cast<unsigned long long>(sqrt(static_cast<double>(_n)));
	for(unsigned long long i=3; i<_n; i+=2)
		if(!(_n%i))
			return false;
		else //div dif zero
			if(i>= (_n/i)) // i >= quociente. Ou seja, Quociente > divisor = raiz de _n
				return true;
	return true;
}
// Para determinar se um certo número inteiro é primo basta dividi-lo por
// todos os primos menores ou iguais à sua raiz quadrada.
bool math::prime4(const unsigned long long &_n) {
	if(_n<3) // Special case: 0, 1 e 2:
		return !((_n+7)%3);
	if(!(_n%2)) // Testa divisibilidade por 2:
		return false;
	unsigned long long raiz = static_cast<unsigned long long>(sqrt(static_cast<double>(_n)));
	for(unsigned long long i=3; i<=raiz; i+=2)
		if(!(_n%i))
			return false;
	return true;
}
// **************<<_USAGE_>>****************
static int  _MAX  = 0;
static int  _total= 0;
static bool _show = false;
math::vfPtr2 v;

static void math::test() {
	for(unsigned long long i=179414903; i<=_MAX; i++)
		if(v[v.size()-1](i)) {
			if(_show)
				P_(i)
			_total++;
		}
}

static void math::test2() {
	int i=1;
	do {
		i++;
		if(v[v.size()-1](i)) {
			if(_show)
				P_(i)
			_total++;
		}
	} while(_total<=_MAX);
}
void math::primeTest() {
	utils::PrintColour_("\n<<_TESTING_PRIMES_>>\n", BRI);
//	P_(prime3(18446744073709551557)) // maior n. primo!
//	P_(prime4(18446744073709551557))
	
	_MAX  = 179424673;
	_show = true;
	v.push_back(&prime4);
//	v.push_back(&prime3);
//	v.push_back(&prime2);
//	v.push_back(&prime);
	int sz = v.size();
	for(int i=0; i<sz; i++) {
		std::cout << std::fixed;
		P_(utils::_chronometer(&test))
		std::cout << "Teste" << i+1 << "- ";
		P_(_total)
		
		v.pop_back();
		_total=0;
	}
}