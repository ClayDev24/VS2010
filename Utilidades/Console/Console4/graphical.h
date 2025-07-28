#ifndef _GRAPHICAL_
#define _GRAPHICAL_
#include "console.h"

namespace clb {

	class Graphical : public Console {
	private:
	
	protected:
		void samples(char* _str, WORD _corFG, WORD _corBG);
	public:
		Graphical():Console() {}
		Graphical(const int &_x, const int &_y, char* _str):Console(_x, _y, _str) {};
		~Graphical(){};
		void box(const unsigned int &X, const unsigned int &Y, const unsigned int &X2, const unsigned int &Y2, char* Label);		
		void colourSamples();
		void teste();
	};

}

#endif // _GRAPHICAL_