#pragma once
#include <iostream>
#include <string>

namespace clb {

	class Conjugador {
	private: // defaults to private
		std::string m_verb;
		int  m_conjugacao;
		void start();
	protected:
	public:
		// Construtor padrão:
		Conjugador():m_verb("ser") { start(); }//DS_("Frame()...") /*REQUIRE()*/ } 
		Conjugador(const char *_v): m_verb(_v) { start(); }//DS_("Frame(const int, const int)...") /*REQUIRE()*/ } 
		~Conjugador() { std::cout << "~Conjugador()..."; }
		// Operações:
		// (...)
		// Streamming de saída:
		void conjugarTodos();
		void conjugar(const char *[6][3]);

		template<size_t rows, size_t cols>
		void conjuga(const char* (&array)[rows][cols]) {
			using namespace std;
			int len = strlen(m_verb.c_str());
			string sufixo, str, prefixo = m_verb.substr(0, len-2);
			for(size_t r=0; r<rows; ++r) {
				str  = array[r][m_conjugacao];
				len   = strlen(str.c_str());
				sufixo = str.substr(4, len-4);
				cout << prefixo+sufixo << endl;
			}
		}

		friend std::ostream& operator<<(std::ostream& _os, const Conjugador &_c) {
			_os << _c.m_verb;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	void _conjugadorUsage();

} // clb