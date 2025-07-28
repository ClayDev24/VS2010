#pragma once
#include <iostream>
#include "contribuinte.h"
#include "aliquota.h"

namespace economy {

	class IRPF {
	private: // defaults to private
		Contribuinte m_titular;
		int          m_recibo;
	protected:
	public:
		// Construtor padrão:
		IRPF():m_recibo(0), m_titular() { }//DS_("Frame()...") /*utils::require()*/ } 
		IRPF(const int &_recibo, const std::string &_titular):
													m_recibo(_recibo),
													m_titular() // Default constructor
													{}
		~IRPF() {}// std::cout << "~IRPF()...\n"; }
		// Operações:
		// (...)
		// Streamming de saída:
		// SETTERS (inline functions):
		void setTitular(const Contribuinte &_titular) { m_titular = _titular; }
		void setRecibo (const int          &_recibo ) { m_recibo  = _recibo;  }
		// GETTERS: (inline functions):
		Contribuinte getTitular() const { return m_titular; }
		int          getrecibo()  const { return m_recibo;  }
		friend std::ostream& operator<<(std::ostream& _os, const IRPF &_IRPF) {
			//IRPF *i = _IRPF;
			_os << _IRPF.m_recibo;
			_os << _IRPF.m_titular.getNome();
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _irpfUsage() {
		IRPF imposto = IRPF();
		std::cout << imposto << std::endl;
	}

} // economy