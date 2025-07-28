#include <conio.h> // _getche()
#include "button.h"
using namespace std;

//*****************************************************************************
clb::Button::Button():Component() {
	//paint();
	DS_("Button()...")
}
//*****************************************************************************
clb::Button::Button(char *_label, const int &_x1, const int &_y1, const WORD &_cor):Component(_label, _x1, _y1, (_x1+15), (_y1+2), _cor) {
	paint();
	DS_("Button(label, x, y, cor)...")
}
//*****************************************************************************
clb::Button::Button(char *_label, const int &_x1, const int &_y1, const int &_x2, const int &_y2, const WORD &_cor):Component(_label, _x1, _y1, _x2, _y2, _cor) {
	paint();
	DS_("Button(label, x1, y1, x2, y2, cor)...")
}
//*****************************************************************************
void clb::Button::paint() {
	int   len = strlen(m_label);
	float pos = static_cast<float>((((m_right-m_left)-len)/2)+m_left);
	canvas(' ', m_colour, m_left, m_top, m_right, m_bottom);
	write2Console(m_label, pos, m_top+1, 0);
}
//*****************************************************************************