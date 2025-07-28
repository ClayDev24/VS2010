#ifndef _ACTIONS_
#define _ACTIONS_
#include "graphical.h"

namespace clb {

	void button1OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	void button2OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	void button3OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	void button4OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

}

#endif // _ACTIONS_