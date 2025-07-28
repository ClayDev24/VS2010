#include <string>
#include <iostream>
#include "Extenso.h"
//#include "defines.h"

using namespace std;

string unidades[20] = {
	"",
	" um",
	" dois",
	" três",
	" quatro",
	" cinco",
	" seis",
	" sete",
	" oito",
	" nove",
	" dez",
	" onze",
	" doze",
	" treze",
	" quatorze",
	" quinze",
	" dezesseis",
	" dezessete",
	" dezoito",
	" dezenove",
};

string dezenas[10] = {
	"",
	" dez",
	" vinte",
	" trinta",
	" quarenta",
	" cinquenta",
	" sessenta",
	" setenta",
	" oitenta",
	" noventa"
};

string centenas[10] = {
	"",
	" cem",
	" duzentos",
	" trezentos",
	" quatrocentos",
	" quinhentos",
	" seiscentos",
	" setecentos",
	" oitocentos",
	" novecentos"
};

string classes[12] = {
	"",
	" mil",
	" milhoes",
	" bilhoes",
	" trilhoes",
	" quadrilhoes",
	" quintilhoes",
	" sextilhoes",
	" setilhoes",
	" octilhoes",
	" nonilhoes",
	" decilhoes"
};

string classe[12] = {
	"",
	" mil",
	" milhao",
	" bilhao",
	" trilhao",
	" quadrilhao",
	" quintilhao",
	" sextilhao",
	" setilhao",
	" octilhao",
	" nonilhao",
	" decilhao"
};
//"undecilhão", "dodecilhão", "tredecilhão", "quatrodecilhão", "quindecilhão", "sedecilhão", "septendecilhão", "octencilhão", "nonencilhão"};

string utils::Extenso::ordem(signed long long _n) {
	string soFar = ""; 	
	if(_n % 100 < 20) { //até 19
		soFar = unidades[_n%100];
		unidades[_n%100];
		_n /= 100;	  
	} else { // 20..99
		// unidade:
		soFar = unidades[_n%10];
		char *and = "";
		if((_n%10) > 0)
			and = " e";
		_n /= 10;
		// dezena:
		soFar = (string)dezenas[_n%10] + and + (string)soFar;
		_n /= 10;
	}
	//centena:
	if(_n>0)
		if(soFar != "")
			if(_n == 1) // 100..199
				soFar = " cento e" + soFar;
			else // 200..999
				soFar = centenas[_n] + " e" + soFar;
		else // Centenas redosndas: 200, 300, 400, etc
			soFar = centenas[_n];
	return soFar;
}

string utils::Extenso::convert(signed long long _n) {
	std::cout << _n << std::endl;
		/* special case */
		if(_n==0)
			return "zero"; 
	string posfix, soFar;
	if(_n<0) {
		_n = -_n; // transformando em positivo para computar.
		posfix = " negativos";
	}
	int index=0;
	char *and = "";
	do {
		int n = _n%1000; // Gets last 3 digits (até 999)

		if(n!=0) {
			string s = ordem(n); // unidade, dezena e centena.

			if(n>1)
				soFar = s + classes[index] + and + soFar;
			else
				soFar = s + classe[index] + and + soFar;

			if(n<=100 && index<1) // 0..99 && first time
				and = " e";
			else
				and = ",";
		}
		index++;	// next class: mil, milhão, bilhão...
		_n /=1000;  // <= Cut 3 digits
	} while(_n>0); 
	return soFar + posfix;
}
// ***************** <<_USAGE_>> *****************
void utils::ExtensoUsage() {
	Extenso ex;

	for(signed long long i=0; i<=1000000; i++)
		std::cout << ex.convert(i) << std::endl;
		//P_(ex.convert(4790001435574204050))
		//P_(ex.convert(9223372031001055037))
}



