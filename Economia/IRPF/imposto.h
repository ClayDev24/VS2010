#pragma once
#include <iostream>
#include <string>
#include "utils.h"

namespace economy {

	class Imposto {
	private: // defaults to private
		std::string   m_nome;
		unsigned int  m_idade;
		long long     m_CPF; // 11 números
		long long     m_titulo_eleitoral;
	protected:
	public:
		// Default Constructor::
		Contribuinte():m_nome("-",0,0) { }//DS_("Frame()...") /*utils::require()*/ } 
		Contribuinte(const std::string &_nome, const unsigned int &_idade, const long long &_cpf, const long long &_titulo): m_nome(_nome),
																					m_idade(_idade),
																					m_CPF(_cpf),
																					m_titulo_eleitoral(_titulo) { }//DS_("Frame(const int, const int)...") /*utils::require()*/ } 
		~Contribuinte() { std::cout << "~Contribuinte()...\n"; }
		// Operações:
		// (...)
		// Streamming de saída:
		// SETTER:
		void setNome (std::string  _nome ) { m_nome  = _nome;  }
		void setIdade(unsigned int _idade) { m_idade = _idade; }
		void setCPF  (long long      _cpf) { m_CPF   = _cpf;   }
		void setTituloEleitoral(long long _t)   { m_titulo_eleitoral = _t; }
		// GETTER:
		std::string  getNome()  const { return m_nome;  }
		unsigned int getIdade() const { return m_idade; }
		long long 	 getCPF()   const { return m_CPF;   }
		long long	 getTituloEleitoral() const { return m_titulo_eleitoral; }
		friend std::ostream& operator<<(std::ostream& _os, const Contribuinte _pessoa) {
			//Contribuinte *pessoa = _pessoa;
			_os << "nome            : " + _pessoa.m_nome                         + "\n";
			_os << "idade           : " + utils::_toStr<unsigned int>(_pessoa.m_idade)          + "\n";
			_os << "CPF             : " + utils::_toStr<long long>(_pessoa.m_CPF)             + "\n";
			_os << "Título Eleitoral: " + utils::_toStr<long long>(_pessoa.m_titulo_eleitoral) + "\n";
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _contribuinteUsage() {
		Contribuinte pessoa1 = Contribuinte("Clailton Ferreira da Silva",
											50,
											24710827850,
											265911100191);
		std::cout << pessoa1 << std::endl;
	}

} // economy