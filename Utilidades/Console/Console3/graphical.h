#ifndef _GRAPHICAL_
#define _GRAPHICAL_
#include "console.h"

namespace clb {

	class Graphical : public Console {
	private:
	
	protected:
		void samples(char* _str, WORD _corFG, WORD _corBG);
	public:
		Graphical():Console() { DS_("Graphical()...") }
		Graphical(const int &_x, const int &_y, char* _str):Console(_x, _y, _str)
		{
			DS_("Graphical(x, y, label)...")
		};
		~Graphical() { DS_("~Graphical()...") };
		void canvas(char _fill, const WORD &_cor, const int &Left=0, const int &Top=0, const int &Right=0, const int &Bottom=0);
		void box(const unsigned int &X, const unsigned int &Y, const unsigned int &X2, const unsigned int &Y2, char* Label);		
		void colourSamples();
	};
	//<<_USAGE_>>
	void _graphical();
}

#endif // _GRAPHICAL_