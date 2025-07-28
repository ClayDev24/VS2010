#include <conio.h> // _getche()
#include "component.h"
using namespace std;

//*****************************************************************************
utils::Component::Component():Graphical(),
	m_top(0),
	m_left(0),
	m_right(0),
	m_bottom(0),
	m_colour(0),
	m_label("null")
{
	//SV_("Component()...", m_label)
	//paint();
};
//*****************************************************************************
utils::Component::Component(char *_label, const int &_x1, const int &_y1, const int &_x2, const int &_y2, const WORD &_cor):
	Graphical(),
	m_label(_label),
	m_colour(_cor),
	m_left(_x1),
	m_top(_y1),
	m_right(_x2),
	m_bottom(_y2)
{
	paint();
	//SV_("Component(label, x1, x2, y1, y2, cor)...", _label)
}
//*****************************************************************************
void utils::Component::paint() {
	int   len = strlen(m_label);
	//float startLine   = static_cast<float>((((m_right-m_left)-len)/2)+m_left);
	//float startColumn = static_cast<float>((((m_bottom-m_top)-1)/2)+m_top);
	int startLine   = (((m_right-m_left)-len)/2)+m_left;
	int startColumn = (((m_bottom-m_top)-1)/2)+m_top;
	gotoxy(0, 0);

	canvas(' ', m_colour, m_left, m_top, m_right, m_bottom);
	write2Console(m_label, startLine, startColumn+1, 0|FWI);
}