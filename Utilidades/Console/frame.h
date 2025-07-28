#pragma once
#include "component.h"
#include "panel.h"
#define MAXPANELS 5

namespace utils {

	class Frame : public Component {
	protected:

	public:
		Panel *panels[MAXPANELS];
		Frame();
		Frame(Console &cmd, const int &Columnm, const int &Line);
		~Frame() { std::cout << "~Frame()..." << std::endl; };
		//Panel* getFrame() { return panels[]; }
		//void paint();
	};

} // utils