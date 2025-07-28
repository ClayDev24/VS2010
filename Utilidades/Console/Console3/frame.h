#ifndef _FRAME_
#define _FRAME_
#include "component.h"
#include "panel.h"
#define MAXPANELS 5

namespace clb {

	class Frame : public Component {
	protected:

	public:
		Panel *panels[MAXPANELS];
		Frame();
		Frame(Console &cmd, const int &Columnm, const int &Line);
		~Frame() { DS_("~Frame()...") };
		//Panel* getFrame() { return panels[]; }
		//void paint();
	};

}

#endif // _FRAME_