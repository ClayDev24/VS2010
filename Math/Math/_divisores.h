#pragma once
#include <new>		// std::nothrow
//#include "..\..\ChartDirector6.3\simpleLine\simpleLine.h"
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>
#include "utils.h" // _colour.h
//#include "..\Utilidades\Console\console.h"
#include "_fatoresPrimos.h"
#include "_prime.h"

namespace math {
	// Qndo a divisão de um n. por outro é exata este n. é divisível pelo outro.
	// -O n. 1 é divisível por qualquer número.
	// -O zero não é divisor de n. nenhum.
	// -Todo n. é divisor de si mesmo.
	// Versão FAST:
	template <typename T>
	static std::vector<T> _divisores(T _n) {
		std::vector<T> vPrimos, vDivisores;
		T divisor = 2;
		T raiz    = static_cast<T>(sqrt(static_cast<double>(_n)));
		// Fatoração de ns primos:
		while(_n>1 && divisor<=raiz) {
			while(!(_n%divisor)) {
				vPrimos.push_back(divisor);
				_n/=divisor;
			}
			divisor++;
		}
		if(_n>1) // => primo
			vPrimos.push_back(_n);
		// Derivando os divisores comuns dos fatores primos:
		vDivisores.push_back(1);
		
		int last=0;
		for(unsigned int a=0; a<vPrimos.size(); a++) {
			unsigned int bSz=vDivisores.size();
			int cnt=0;
			for(unsigned int b=0; b<bSz; b++) {
				// first time?
				if(a && (vPrimos[a]==vPrimos[a-1]) && !b)
					b=(bSz)-last; // index
				
				vDivisores.push_back(vPrimos[a]*vDivisores[b]);
				cnt++;
			}
			last=cnt;
		}

		sort(vDivisores.begin(), vDivisores.end());
		return vDivisores;
	}
	// Versão didática:
	template <typename T>
	static std::vector<T> _divisoresD(T _n, bool _show=true) {
		using namespace std;
		int len = strlen(utils::_toStr(_n).c_str());
		std::vector<T> v, v2;
		v2.push_back(1);

		T divisor = 1;//2;
		T limite  = static_cast<T>(sqrt(static_cast<double>(_n)));
		if(_show)
			cout << setw(len) << "." << " |    " << 1 << endl;
		int z=0;
	
		while(_n>1 && divisor++<=limite) {
			while(!(_n%divisor)) {
				v.push_back(divisor);
				if(_show)
					cout << setw(len) << _n << " | " << divisor << ", ";
					unsigned int sz=v2.size();
					int cnt=0;
					for(unsigned int b=0; b<sz; b++) {
						int a = v.size()-1;
						if(a && (v[a]==v[a-1]) && !b) // first time?
							b=(sz)-z;//b=a; // index
						T u = v[a]*v2[b];
						if(_show)
							cout << u << ", ";

						v2.push_back(u);
						cnt++;
					}
					if(_show)
						cout << endl;
					z=cnt;
				//}
				_n /= divisor; // quociente
			}
		}
		if(_n>1)// => primo
			v.push_back(_n);
		
		if(v.size()>0) {
			if(_n>1) {// => primo
				if(_show)
					cout << setw(len) << _n << " | " << _n << ", ";// << endl;
				int sz=v2.size();
				for(int b=0; b<sz; b++) {
					T u = v[v.size()-1]*v2[b];
					if(_show)
						cout << u << ", ";
					v2.push_back(u);
				}
				if(_show)
					N
			}

			if(_show) {
				for(int i=0; i<len+2; i++)
					cout << " ";
				for(int i=0; i<len*1.5; i++)
					cout << "_";
				N
				cout << setw(len) << _n/_n << " | ";
		
				for(unsigned int i=0; i<v.size()-1; i++)
					cout << v[i] << ".";
				cout << v[v.size()-1] << endl;
			}
		}
		sort(v2.begin(), v2.end());
		return v2;
	}
	// Força (B)ruta: Máximo dividendo 4294967295 (unsigned int / long / long int - 4-bytes)
	// Maior do que 4294967295 o programa roda pra sempre.
	template <typename T>
	static std::vector<T> _divisoresB(const T &_n) {
		std::vector<T> v; // unsignedt int (4-byte) to hold the maximum value 4294967295.
		T i = 0;		  // divisor
		while(++i <= (_n/2)+1)
			if(!(_n%i))   // _n = dividendo
				v.push_back(i);
		v.push_back(_n); // Add dividend itself

		sort(v.begin(), v.end());
		return v;
	}
	// Versão (P)ointer:
	template <typename T>
	static std::vector<T>* _divisoresP(T _n) {
		std::vector<T> v, *v2;
		v2 = new std::vector<T>;
		v2->push_back(1);

		T divisor = 1;//2;
		T limite  = static_cast<T>(sqrt(static_cast<double>(_n)));
		int last=0;

		while(_n>1 && divisor++<=limite) {
			while(!(_n%divisor)) {
				v.push_back(divisor);

					unsigned int sz=v2->size();
					int cnt=0;
					for(unsigned int b=0; b<sz; b++) {
						unsigned int a = v.size()-1;
						if(a && (v[a]==v[a-1]) && !b) // first time?
							b=(sz)-last; // index

						v2->push_back(v[a]*v2->at(b));
						cnt++;
					}
					last=cnt;

				_n /= divisor; // quociente
			}
		}
		if(_n>1)// => primo
			v.push_back(_n);
		
		if(v.size()>0) {
			if(_n>1) {// => primo
				int sz=v2->size();
				for(int b=0; b<sz; b++)
					v2->push_back(v[v.size()-1]*v2->at(b));
			}
		}
		sort(v2->begin(), v2->end());
		return v2;
	}

	static void _testDiv1();
	static void _testDiv2();
	static void _testDiv3();
	static void _testDiv4();
	static int _dividersQuantity(unsigned long long _n);
	template <typename T>
	static void _showVetorPrime(T &vt);
	static unsigned long long maxLong = static_cast<unsigned long long>(18446744073709551615);
	static unsigned long long MIN = maxLong-100;
	static unsigned long long MAX = maxLong;
	static void _testShow(const vetorULLng &_v, const unsigned long long &_n, bool _test=true, bool _show=true);

	// **************<<_USAGE_>>****************
	static void _divisoresUsage() {

		utils::PrintColour_("<<__DIVISORESs__>>", FBI);
		utils::dicShow("mathematics", "Divisores");

		vetorULLng v = _divisoresD(static_cast<unsigned long long>(999));
		//_testShow(v, 9999999999);
		system("pause");

		//Static (D)idatic version:
		//vetorULLng v = _divisoresD(MAX); // Devolve uma cópia de objs vetores criado estaticamente no STACK
		//_testShow(v, MAX);
/*
		// Versão FAST (static-memory):
		vetorULLng v0 = _divisores(static_cast<unsigned long long>(54)); 
		_testShow(v0, 54);

		//Static Força (B)ruta version:
		// ERROR unsigned long long will run FOREVER!:
		vetorULLng v2 = _divisoresB(static_cast<unsigned long long>(54)); // Devolve uma cópia de objs vetores criado estaticamente no STACK
		_testShow(v2, 54);

		// (P)ointer version:
		vetorULLng *v3 = _divisoresP(static_cast<unsigned long long>(54));//4294967295); // devolve ponteiro de vetores criado dinamicamente no HEAP
		_testShow(*v3, 54);
		delete v3;

		vetorULLng v4 = _divisoresD(static_cast<unsigned long long>(54)); // Devolve uma cópia de objs vetores criado estaticamente no STACK
		_testShow(v4, 54);
*/
		MIN =  999999;
		MAX = 10000000;	
//		P_(utils::_chronometer(&_testDiv1))
		//P_(utils::_chronometer(&_testDiv2))
		//P_(utils::_chronometer(&_testDiv3))
		//P_(utils::_chronometer(&_testDiv4))
	}

	static void _testDiv2() {
		for(unsigned long long n=MIN; n<MAX; n++)
			vetorULLng v = _divisoresD(n, false);
	}
	static void _testDiv3() {
		vetorULLng *v;
		for(unsigned long long n=MIN; n<MAX; n++) {
			v = _divisoresP(n);
			_testShow(*v, n, true, true);
		}
		delete v;
	}
	static void _testDiv4() {
		for(unsigned long long n=MIN; n<MAX; n++)
			vetorULLng v = _divisoresB(n);
	}
	static void _testDiv1() {

		int sz = static_cast<int>(MAX-MIN);
		int i2 = 0;
//		double *data = new(std::nothrow)double[sz];
//		const char** label = new(std::nothrow)const char*[sz];

		for(unsigned long long n=MIN; n<MAX; n++, i2++) {
			vetorULLng v = _divisores(n);
			//std::sort(v.begin(), v.end());

			_testShow(v, n, true, true);

//			data[i2] =v.size();
//			const char **ch = new(std::nothrow)const char*[20];
//			itoa(i2, (char*)ch, 10);//= (char*)utils::_toStr(i).c_str();
//			label[i2]=(const char*)ch;
		}
//		chart::_simpleLine(data, label, sz, 2000, 500, true);
	}

	template <typename T>
	static void _showVetorPrime(T &vt) {
		for(unsigned int i=0; i<vt.size(); i++) {
			std::cout << i+1 << "=> " << vt.at(i); TAB
			if(math::_prime(vt.at(i)))
				std::cout << "primo!\n";
			else
				std::cout << std::endl;
		}
	}

	static int _dividersQuantity(unsigned long long _n) {
		vetorULLng vl = _fatoresPrimos2(_n);
		//utils::_showVetor(vl);
		vetorPII *v = utils::_countVector(vl, true, false);
		int cnt=1;
		for(unsigned int i=0; i<v->size(); i++) {
			pairIntInt pair = v->at(i);
			int p = pair.second + 1;
			cnt *= p;
		}
		return cnt;
	}
		
	static void _testShow(const vetorULLng &_v, const unsigned long long &_n, bool _test, bool _show) {
		utils::PrintColour_(utils::_toStr(_n).c_str(), FGI);
		if(_show)
			_showVetorPrime(_v); N
		//test quantity:
		if(_test)
			if(_dividersQuantity(_n) != _v.size()) {
				utils::PrintColour_("DIFERENTE!!!!", FRI);
				system("pause");
			}
	}

} //math