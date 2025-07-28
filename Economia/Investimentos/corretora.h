#pragma once
#include <windows.h> // SetConsoleOutputCP(65001); // para acentua��o correta no console
#include <iostream>
#include "utils.h"
#include "_colour.h" // utils::PrintColour()

namespace economy {

	class Corretora { // A��o
	private: // defaults to private
		std::string m_name;
		std::string m_server;
		std::string m_web_site;
		int m_agency;
		int m_account;
		int m_password;
		int m_appPW;
		int m_email;

		//double  m_value;

	protected:
	public:
		// Construtor padr�o:
		Corretora():m_name("NULL") {} //DS_("Corretora()...") /*utils::require()*/ } 
		Corretora(const char* name): m_name(name) { }//DS_("Corretora(const int, const int)...") /*utils::require()*/ } 
		~Corretora() { /*std::cout << "~Corretora()..." << std::endl;*/ }
		// Opera��es:
		// (...)
		// Streamming de sa�da:

		// *Fun��o para calcular o Magic Number em Fundos Imobili�rios (FIIs)
		friend std::ostream& operator<<(std::ostream& _os, const Corretora &corretora) {
			_os << corretora.m_name << std::endl;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _corretoraUsage() {
		using namespace std;
		utils::dicShow("economy", "Corretora");
		// Search for a keyword
		//string key = "N�mero M�gico";//"N�mero M�gico";
		//utils::PrintColour(key.c_str(), BMI);
		//cout << ": " << dicionario.search(key.c_str()) << endl << endl;

		Corretora Itau("Itau Corretora");
		cout << Itau << endl;
	}

} // utils