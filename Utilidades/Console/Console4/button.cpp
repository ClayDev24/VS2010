#include "button.h"
using namespace std;

//*****************************************************************************
clb::Button::Button(char *_label, const int &_x1, const int &_y1, const WORD &_cor):Component(_label, _x1, _y1, (_x1+15), (_y1+2), _cor) {
	cout << "Button()..." << _label << "\n";
	//paint();
}
//*****************************************************************************
clb::Button::Button(char *_label, const int &_x1, const int &_y1, const int &_x2, const int &_y2, const WORD &_cor):Component(_label, _x1, _y1, (_x2), (_y2), _cor) {
	cout << "Button()..." << _label << "\n";
	//paint();
}
//*****************************************************************************
void clb::Button::paint() {
	int   len = strlen(m_label);
	float pos = static_cast<float>((((right-left)-len)/2)+left);
	doubleBuffering(" ", /*m_colour*/ FRI, 10.0, true, left, top, right, bottom);
	write2Console(m_label, pos, top+1, 0);
}
//*****************************************************************************