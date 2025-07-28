#include "atomo.h"

namespace quimica {

	Atomo::Atomo(int z, const std::string& simb, const std::string& nome,
		const std::string& familia, int grupo, int periodo, const std::string& tipo)
		: numero_atomico(z), simbolo(simb), nome(nome), familia(familia),
		grupo(grupo), periodo(periodo), tipo(tipo) {}

	int Atomo::getNumeroAtomico()	const { return numero_atomico; }
	std::string Atomo::getSimbolo() const { return simbolo; }
	std::string Atomo::getNome()	const { return nome; }
	std::string Atomo::getFamilia() const { return familia; }
	int Atomo::getGrupo()			const { return grupo; }
	int Atomo::getPeriodo()			const { return periodo; }
	std::string Atomo::getTipo()	const { return tipo; }

} // quimica