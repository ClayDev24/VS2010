#pragma once
#include "component.h"

namespace utils {

	class Button : public Component {
	protected:
	public:
		Button();
		Button(char *Label, const int& Left, const int &Top, const WORD &Colour);
		Button(char *Label, const int& Left, const int &Top, const int& Right, const int &Bottom, const WORD &Colour);
		~Button() { std::cout << "~Button()..." << std::endl; };
		void paint();
	};

} // utils