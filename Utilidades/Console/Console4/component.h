#ifndef _COMPONENT_
#define _COMPONENT_
#include "graphical.h"

namespace clb {

	class Component : public Graphical {
	protected:
		DWORD m_colour;
	public:
		int left, top, right, bottom;
		char *m_label;
		//Component();
		Component(char *Label, const int &Left, const int &Top, const int &Right, const int &Bottom, const WORD &Colour);
		~Component(){};
		virtual void paint();
	};

}

#endif // _COMPONENT_