#ifndef _PANEL_
#define _PANEL_
#include "component.h"
#include "button.h"
#define MAX 20

namespace clb {

	enum panelType { // Untagged enum (no type name):
		//menu = 0,
		TOP = 0,
		BOTTOM,
		LEFT,
		RIGHT,
		CENTRAL
	}; 		

	class Panel : public Component {

	protected:
		panelType m_type;
		void createComponent(Controls type);
	public:
		Button *buttons[MAX];
		Panel();
		Panel(panelType Type, char *Label, const int& Left, const int &Top, const int& Right, const int &Bottom, const WORD &Colour);
		~Panel() { DS_("Panel()...") };
		void createComponent(vetorString vStr, Controls type);
		void paint();
	};

}

#endif // _PANEL_