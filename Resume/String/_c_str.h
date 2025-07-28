#pragma once
#include <iostream>
#include <cstring>
#include <string>

namespace resume {

	static void _c_str() {
		using namespace std;

		char* cstr;
		string str("c_str() example...");

		// Alocação dinâmica segura de memória
		cstr = new char[str.size() + 1]; // +1 para o caractere nulo

		// Copia segura da string
		strcpy_s(cstr, str.size() + 1, str.c_str()); // strcpy_s(to, from.sz, from)

		// Atenção: o ponteiro retornado por c_str() aponta para memória interna da string
		const char* tmp = str.c_str();		// Acesso temporário, mas NÃO SEGURO se a string mudar

		cout << "tmp : " << tmp << endl;
		str.assign("Changed string");		// Modifica o conteúdo interno da string
		cout << "tmp : " << tmp << endl;	// tmp agora aponta para conteúdo alterado
		cout << "cstr: " << cstr << endl;	// cstr mantém o valor original copiado

		delete[] cstr;
	}
	// string::data
	// Same as c_str() but not returning a zero-terminating char:
	static void _data() {
		using namespace std;
		string str = "data() test string...";
		char *cstr = "data() test string...";
		if(str.length() == strlen(cstr)) {
			cout << "str and cstr have the same length.\n";
			if(!memcmp(cstr, str.data(), str.length()))
				cout << "str and cstr have the same content.\n";
		} 
	}

} // resume