#pragma once
#include <wx/menu.h>
#include <wx/artprov.h> // SetBitmap() to set the icon
#include "functions.h"
#include "IDs.h"

class MenuBar:public wxMenuBar {
	wxWindow *m_parent; // ==  parent Frame
	int m_id;
public:
	MenuBar(wxWindow *parent):m_parent(parent), m_id(0) {}
	~MenuBar() {}
	inline void addFunction(fPtr _f) { vFuncMen.push_back(_f); }
	wxMenu* AddMenu(const wxString &_title="", const wxString &_titleBar="", bool _separator=false);
	void AddSubMenu(wxMenu *_menu, const wxString &_menuNome, bool _separator=false, const wxString &_subMenuNome="");
	wxMenu* MenuBar::CreateMenu(int _sz, ...);
	wxMenu* MenuBar::CreateSubMenu(wxMenu*, int sz, ...);
	//private:
	//	wxDECLARE_EVENT_TABLE();
};
