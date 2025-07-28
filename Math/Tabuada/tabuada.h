#pragma once
#include "utils.h"

namespace math {

	class Tabuada {
	protected:
		utils::Console m_cmd;
	public:
		Tabuada():m_cmd(30, 11, "<<_TABUADA_>>")  { DS_("Tabuada()..." ) }
		~Tabuada() { DS_("~Tabuada()...") }
		void show(const int &n); // 0=all
	};
	// **************<<_USAGE_>>****************
	void _tabuada();
} // math