#ifndef _BUTTON_
#define _BUTTON_
#include "component.h"

namespace clb {

	class Button : public Component {
	protected:
	public:
		//Button(){};
		Button(char *Label, const int& Left, const int &Top, const WORD &Colour);
		Button(char *Label, const int& Left, const int &Top, const int& Right, const int &Bottom, const WORD &Colour);
		~Button(){};
		void paint();
	};

}

#endif // _BUTTON_