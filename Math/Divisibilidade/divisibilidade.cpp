#include <iostream>
#include "divisibilidade.h"
#include "..\Math\_divBy.h"
#include "..\Math\_raizDigital.h"
#include "..\Math\_abs.h"
#include "defines.h"

// Divisibilidade por 2=> Qualquer n. par
bool math::divBy2(const unsigned long &_n) { utils::require(_n>=0);
	int i = _n%10; // Primeiro digito à direita do n.
	if(i==0 || i==2 || i==4 || i==6 || i==8)
		return true;
	return false;
}
// Divisibilidade por 3=> Raiz digital divisível por 3, 6 e 9;
bool math::divBy3(const unsigned long &_n) { utils::require(_n>=0);
	int i = _raizDigital(_n);
	if(i==3 || i==6 || i==9) 
		return true;
	return false;
}
// Divisibilidade por 4=> Qndo os dois últimos digitos do n. forem divisíveis por 4:
bool math::divBy4(const unsigned long &_n) { utils::require(_n>=0);
	int dig = _n%100; // Os 2 primeiros digitos à direita do n.
	for(int i=100; i>=0; i-=4)
	if(dig==i)
		return true;
	return false;
}
// Divisibilidade por 5=> Qualquer n. terminado em 0 ou 5.
bool math::divBy5(const unsigned long &_n) { utils::require(_n>=0);
	int i = _n%10; // Primeiro digito à direita do n.
	if(i==0 || i==5)
		return true;
	return false;
}
// Divisibilidade por 6=> Qualquer n. divisível por 2 && 3:
bool math::divBy6(const unsigned long &_n) { utils::require(_n>=0);
	if(_divBy(_n,2) && _divBy(_n,3))
		return true;
	return false;
}
// Divisibilidade por 7=>
bool math::divBy7(const unsigned long long &_n) { utils::require(_n>=0);
	std::string str = utils::_toStr<unsigned long long>(_n); 
	int sz = str.length();
	int cnt=0;
	int resto = sz%3;
	std::string str2;
	str2.append(str,0,resto);
	str2+='.';
	for(int i=resto; i<sz; i++) {
		char c = str.at(i);
		str2+=c;
		if(++cnt==3) {
			cnt=0;
			str2+='.';
		}
	}
	utils::Tokenizer token(str2,".");
	int soma=0;
	for(int i=0; i<token.get_size(); i++) {
		int d = utils::_strTo<int>(token.get_at(i).c_str());
		if(i%2) // par
			d*=-1;
		soma+=d%7;
	}
	if(!(soma%7))
		return true;
	return false;
}
// Divisibilidade por 8=> Qndo os 3 últimos digitos do n. forem divisíveis por 8.
bool math::divBy8(const unsigned long &_n) { utils::require(_n>=0);
	std::string str = utils::_toStr<unsigned long long>(_n); 
	int sz = str.length();
	int cnt=0;
	int resto = sz%3;
	std::string str2;
	str2.append(str,0,resto);
	str2+='.';
	for(int i=resto; i<sz; i++) {
		char c = str.at(i);
		str2+=c;
		if(++cnt==3) {
			cnt=0;
			str2+='.';
		}
	}
	utils::Tokenizer token(str2,".");
	//P_(token.get_size())
	int d = utils::_strTo<int>(token.get_at(token.get_size()-1).c_str());
	//P_(d)
	if(!(d%8))
		return true;
	//P_(str2)
	//P_(_n)
	return false;
}
// Divisibilidade por 9=> Raiz digital divisível por 9
bool math::divBy9(const unsigned long &_n) { utils::require(_n>=0);
	int i = _raizDigital(_n);
	if(!(i%9)) // resto 0 = divisível
		return true;
	return false;
}
bool math::divBy9b(const unsigned long &_n) { utils::require(_n>=0);
	std::string str = utils::_toStr<long>(_n); 
	int soma = 0;
	bool out = false;
	for(unsigned int i=0; i < str.length(); i++)
		soma += str[i]-48;
	if(soma >=10) // recursive call
		out = divBy9b(soma);
	if(!(soma%9))
		return true;
	return out;
}
// Divisibilidade por 10=> Qualquer n. terminado no digito 0 (n>0).
bool math::divBy10(const unsigned long &_n) { utils::require(_n>=0); 
	if(_n%10==0) // Primeiro digito à direita do n.
		return true;
	return false;
}
// Divisibilidade por 11=> 
bool math::divBy11(const unsigned long &_n) { utils::require(_n>=0);
	std::string str = utils::_toStr<unsigned long long>(_n); 
	int sz = str.length();
	int pares=0;
	int impares=0;
	for(int i=0; i<sz; i++) {
		int d = str[i]-48;
		if(i%2)
			impares+=d;
		else // pares
			pares+=d;
	}
	int soma = math::_abs(pares-impares);
	if(!(soma%11))
		return true;
	return false;
}
// Divisibilidade por 12=> Qndo o n. for divisível por 3 && 4 (já que 3x4=12)
bool math::divBy12(const unsigned long &_n) { utils::require(_n>=0);
	if(_divBy(_n,3) && _divBy(_n,4))
		return true;
	return false;
}
// Divisibilidade por 15=> 3x5=15 (e assim sucessivamente com outros ns.
bool math::divBy15(const unsigned long &_n) { utils::require(_n>=0);
	if(_divBy(_n,3) && _divBy(_n,5))
		return true;
	return false;
}

// **************<<_USAGE_>>****************

void math::_display(const int &_div, const int &_loop, bool show) {
	//utils::Console cmd;
	bool passed = true;
	int total   = 0;
	int ampulheta = 10000;
	int z = 0;

	char buf[9]={'/','-','\\','|','/','-','\\','|',0};
	//cmd.gotoxy(25,1);
	//utils::PrintColour("testin'...", FWI);
	for(int i=1; i<=_loop; i++) {

		/*		if((ampulheta++) % 10000) {
		if(!show) {
		cmd.gotoxy(35,1);
		std::cout << (char)buf[z];
		}
		z++;
		if(z==7)
		z=0;
		}
		*/	
		unsigned int n = i;//random(2, 1000000000); // (min / max)N();

		int a, b;
		switch(_div) { // just accept integer types at compile-time.
		case 2:
			a = _divBy(n,2);
			b = divBy2(n);
			break;
		case 3:
			a = _divBy(n,3);
			b = divBy3(n);
			break;
		case 4:
			a = _divBy(n,4);
			b = divBy4(n);
			break;
		case 5:
			a = _divBy(n,5);
			b = divBy5(n);
			break;
		case 6:
			a = _divBy(n,6);
			b = divBy6(n);
			break;
		case 7:
			a = _divBy(n,7);
			b = divBy7(n);
			break;
		case 8:
			a = _divBy(n,8);
			b = divBy8(n);
			break;
		case 9:
			a = _divBy(n,9);
			b = divBy9(n);
			break;
		case 10:
			a = _divBy(n,10);
			b = divBy10(n);
			break;
		case 11:
			a = _divBy(n,11);
			b = divBy11(n);
			break;
		case 12:
			a = _divBy(n,12);
			b = divBy12(n);
			break;
		case 15:
			a = _divBy(n,15);
			b = divBy15(n);
			break;
		default: std::cout << "Error!, Test type not defined yet.\n";
		}

		if(a!=b) {
			utils::PrintColour("FAILED!...", FRI);
			std::cout << n << std:: endl;
			passed = false;
			system("pause");
		} 
		if(a) total++;
		if(show && a)
			P_(n)
	}
	if(passed) {
		P(total)
			std::cout << " numeros divisiveis por " << _div << std::endl;
		utils::PrintColour("PASSED!\n", FGI);
	}
}
void math::_display2(const int &_n, const int &_loop, bool show) {
/*	int total = 0;

	for(int i=_n; i<=_loop; i++)
		if(_divBy(i,_n)) {
			total++;
		}
		if(total) {
			vetorInt *v = math::_multiplos(_n, 1, total);
			utils::_showVetor(*v);
			delete v;
		}
		P(total)
			std::cout << " numeros divisiveis por " << _n << std::endl;
		utils::PrintColour("PASSED!\n", FGI);*/
}

void math::_testDiv() {
/*	for(int i=2; i<=500; i++) {
		_display2(i, 1000, false);
		//utils::_sleep(5000);
	}*/
	//_display(15, 1000, false); 
}
void math::_divisibilidadeUsage() {
	using namespace std;
	
	utils::dicShow("mathematics", "Divisibilidade");

	//for(int i=0; i<31; i++) 
	//	P_(math::divBy15(i))

	P_(math::divBy2(279536))
	P_(math::divBy3(812472))
	P_(math::divBy7(22389651536))
	P_(math::divBy8(3958743328))
	P_(math::divBy9(4901067))
	P_(math::divBy10(4901060))

	//math::_testDiv();
}
