#pragma once
#include <wx/menu.h>
#include "functions.h"

class MenuBar:public wxMenuBar {
	wxWindow *m_parent; // ==  parent Frame
	int m_id;
public:
	MenuBar(wxWindow *parent)
	  :wxMenuBar(), m_parent(parent), m_id(0) {}
	~MenuBar() {}

	inline void addFunction(fPtr _f) { vFuncMen.push_back(_f); }
	wxMenu* MenuBar::CreateMenu(wxMenu* SubMenu, int sz, ...);
//private:
//	wxDECLARE_EVENT_TABLE();
};