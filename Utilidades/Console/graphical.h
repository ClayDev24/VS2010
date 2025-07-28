#pragma once
#include "console.h"
namespace utils {

	class Graphical : public Console {
	private:
	
	protected:
		void samples(char* _str, WORD _corFG, WORD _corBG);
	public:
		Graphical():Console() { /*DS_("Graphical()...")*/ }
		Graphical(const int &_x, const int &_y, const char* _str):Console(_x, _y, _str)
		{
			/*DS_("Graphical(x, y, label)...")*/
		};
		~Graphical() { /*DS_("~Graphical()...")*/ };
		void canvas(char _fill, const WORD &_cor, int Left=0, int Top=0, int Right=0, int Bottom=0);
		void entireCanvas();
		void box(char* Label, int Left=0, int Top=0, int Right=0, int Bottom=0);		
		void colourSamples();
	};
	// **************<<_USAGE_>>****************
	void _graphicalUsage();

} // utils