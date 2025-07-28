#include <conio.h> // _getche()
#include <string>
#include "panel.h"
using namespace std;

//*****************************************************************************
clb::Panel::Panel():Component() {
	for(int i=0; i<MAX; i++)
		buttons[i] = NULL;
	DS_("Panel()...")
}
//*****************************************************************************
clb::Panel::Panel(panelType _type, char *_label, const int &_x1, const int &_y1, const int &_x2, const int &_y2, const WORD &_cor):Component(_label, _x1, _y1, _x2, _y2, _cor) {
	string str(_label);
	m_type = _type;
	//if(_type == TOP) //!str.compare("Top Panel")) // Inequality: val <> 0
	//	createComponent(button);
	for(int i=0; i<MAX; i++)
		buttons[i] = NULL;
	paint();
	DS_("Panel(label, x1, y1, x2, y2, cor)...")
}
//*****************************************************************************
void clb::Panel::paint() {
	canvas(' ', m_colour, m_left, m_top, m_right, m_bottom);
}
//*****************************************************************************
void clb::Panel::createComponent(vetorString _vStr, Controls _type) {
	int x = 11;
	int y = 10;
	
	switch(_type) {
	case BUTTON:
		for(unsigned int i=0; i<_vStr.size(); i++) {
			buttons[i] = new Button(_vStr[i], x, y, BB);
			y += 4;
		}
		break;
	//default:;
	}
}
//*****************************************************************************