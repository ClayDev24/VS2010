#ifndef _COMPONENT_
#define _COMPONENT_
#include <vector>
#include "graphical.h"

namespace clb {

	enum Controls { // Untagged enum (no type name):
		BUTTON = 0
	}; 

	class Component : public Graphical {
	protected:
		DWORD m_colour;
	public:
		int m_left, m_top, m_right, m_bottom;	
		char *m_label;
		Component();
		Component(char *Label, const int &Left, const int &Top, const int &Right, const int &Bottom, const WORD &Colour);
		~Component() { DS_("~Component()...") };
		virtual void paint();
	};

}

typedef std::vector<clb::Component*> vetorComponents;
typedef std::vector<clb::Component*>::iterator it;

typedef std::vector<char*> vetorString;

typedef void (*functionPointer)(clb::Graphical*, clb::Component*);

typedef std::vector<functionPointer> vetorFunctionPointers;
//typedef std::vector<funcPtr>::iterator it2;


#endif // _COMPONENT_