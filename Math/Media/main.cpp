#include <iostream>
#include "aritmetica.h"
#include "geometrica.h"
#include "harmonica.h"
#include "utils.h"
using namespace std;

int main() {
	using namespace std;
	// Desigualdade das médias=> x >= g >= h
	cout << media::_aritmetica(3, 4.0,5.0,9.0);
	cout << " >= ";
	cout << media::_geometrica(3, 4.0,5.0,9.0);
	cout << " >= ";
	cout << media::_harmonica(3, 4.0,5.0,9.0);
	N
	//P_(media::_aritmeticaPonderada(6, /*valores*/5.0,7.0,8.0, /*pesos*/2.0,3.0,4.0))
	//media::_aritmeticaUsage();
	//media::_harmonicaUsage();

	system("pause");
	return(0);
}

