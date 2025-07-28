#pragma once
#include "defines.h" // _colour.h
namespace elect {

	class Mesh { // Malha
	private: // defaults to private
		int m_i;
	protected:
	public:
		// Construtor padrão:
		Mesh():m_i(0) { }//DS_("Mesh()...") /*utils::require()*/ } 
		Mesh(const int &_i): m_i(_i) { }//DS_("Mesh(const int, const int)...") /*REQUIRE()*/ } 
		~Mesh() { DS_("~Mesh()...") }
		// Operações:
		// ...
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Mesh &_m) {
			_os << _m.m_i;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _meshUsage() {
		utils::PrintColour_("<<_meshUsage()_>>\n", FGI);
		Mesh m;
		P_(m)
	}

}