#include <conio.h> // _getche()
#include "component.h"
using namespace std;

//*****************************************************************************
/*clb::Component::Component(){
	m_area.Top = 0;
	m_area.Left = 0;
	m_area.Right = 0;
	m_area.Bottom = 0;
	//paint();
};*/
clb::Component::Component(char *_label, const int &_x1, const int &_y1, const int &_x2, const int &_y2, const WORD &_cor):
	m_label(_label),
	m_colour(_cor),
	left(_x1),
	top(_y1),
	right(_x2),
	bottom(_y2)
{
	cout << "Component()..." << _label << "\n";
	paint();
}
//*****************************************************************************
void clb::Component::paint() {
	int   len = strlen(m_label);
	float pos = static_cast<float>((((right-left)-len)/2)+left);
	doubleBuffering(" ", m_colour, 10.0, true, left, top, right, bottom);
	write2Console(m_label, pos, top+1, 0);
}
//*****************************************************************************