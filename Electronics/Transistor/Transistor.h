#pragma once
#include "defines.h" // _colour.h
namespace elect {

	enum kind { NPN, PNP }; // Same as assining names to ints	

	class Transistor {
	private: // defaults to private
		int m_kind;
	protected:
	public:
		// Construtor padrão:
		Transistor():m_kind(NPN) { }//DS_("Transistor()...") /*utils::require()*/ } 
		Transistor(const int &_k): m_kind(_k) { }//DS_("Frame(const int, const int)...") /*REQUIRE()*/ } 
		~Transistor() { DS_("~Transistor()...") }
		// Operações:
		void gain(); // Colector's current / Base's current 
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Transistor &_t) {
			if(_t.m_kind == NPN)
				_os << "NPN Transistor";
			else if(_t.m_kind == PNP)
				_os << "PNP Transistor";
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _transistorUsage() {
		utils::PrintColour_("<<_transistorUsage()_>>\n", FGI);
		Transistor t;
		P_(t)
		t.gain();
	}

}