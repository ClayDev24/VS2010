#pragma once
#include <iostream>
#include <locale.h> // setlocale()

namespace utils {

	static void _setLocale(char* locale = "Portuguese") {
		setlocale(LC_ALL, locale);
	}
	// ***************** <<_USAGE_>> *****************
	static void _setLocaleUsage() {
	// Teste do SetLocale:
		using namespace std;
		cout << "Frase com acentuação..." << endl;
		_setLocale();
		cout << "Frase com acentuação..." << endl;
	}

} // utils


