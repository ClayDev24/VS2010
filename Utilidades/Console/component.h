#pragma once
#include <vector>
#include "graphical.h"

namespace utils {

	enum Controls { // Untagged enum (no type name):
		BUTTON = 0
	}; 

	class Component : public Graphical {
	protected:
		WORD m_colour;
	public:
		int m_left, m_top, m_right, m_bottom;	
		char *m_label;
		Component();
		Component(char *Label, const int &Left, const int &Top, const int &Right, const int &Bottom, const WORD &Colour);
		~Component() { std::cout << "~Component()..." << std::endl; };
		virtual void paint();
	};

} // utils

typedef std::vector<utils::Component*> vetorComponents;
typedef std::vector<utils::Component*>::iterator it;

typedef std::vector<char*> vetorString;

typedef void (*functionPointer)(utils::Graphical*, utils::Component*);

typedef std::vector<functionPointer> vetorFunctionPointers;
//typedef std::vector<funcPtr>::iterator it2;