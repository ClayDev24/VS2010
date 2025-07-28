#pragma once
#include <string>

namespace quimica {

	class Atomo {
	private:
		int numero_atomico;
		std::string simbolo;
		std::string nome;
		std::string familia;
		int grupo;
		int periodo;
		std::string tipo;

	public:
		Atomo(int z, const std::string& simb, const std::string& nome,
			const std::string& familia, int grupo, int periodo, const std::string& tipo);

		int getNumeroAtomico() const;
		std::string getSimbolo() const;
		std::string getNome() const;
		std::string getFamilia() const;
		int getGrupo() const;
		int getPeriodo() const;
		std::string getTipo() const;
	};

} // quimica