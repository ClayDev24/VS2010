#pragma once
#include "graphical.h"

namespace utils {

	static void button1OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	static void button2OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	static void button3OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

	static void button4OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
	}

} // utils