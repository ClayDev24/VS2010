#include <vector>
#include <wx/string.h>
#include "menu.h"

wxMenu* MenuBar::CreateSubMenu(wxMenu *_menu, int _sz, ...) {
	int sz=_sz;
	std::vector<char*> v;

	va_list args;
	va_start(args, _sz); // initialize argptr
	while(_sz--)
		v.push_back(va_arg(args, char*)); // A = (v1+v2+v3+vn) / n
	va_end(args);

	wxMenu *menu = new wxMenu();
	for(int i=0; i<sz-1; i++) {
		if(v[i]=="_")
			menu->AppendSeparator(); // _____________
		else
			menu->Append(m_id++, v[i]);
	}
	_menu->AppendSubMenu(menu, v[v.size()-1]);
	return menu;
}

wxMenu* MenuBar::CreateMenu(int _sz, ...) {
	int sz=_sz;
	std::vector<char*> v;

	va_list args;
	va_start(args, _sz); // initialize argptr
	while(_sz--) // sum the parameters
		v.push_back(va_arg(args, char*)); // A = (v1+v2+v3+vn) / n
	va_end(args);

	wxMenu *menu = new wxMenu();
	for(int i=0; i<sz-1; i++) {
		if(v[i]=="_")
			menu->AppendSeparator(); // _____________
		else
			menu->Append(m_id++, v[i]);
	}
	Append(menu, v[v.size()-1]);
	return menu;
}

wxMenu* MenuBar::AddMenu(const wxString &_title, const wxString &_titleSub, bool _separator) {
	wxMenu *menu = new wxMenu();
	if(_title!="")
		menu->Append(m_id++, _title);
	else
		menu->Append(m_id++);// wxID_NEW);

	if(_separator)
		menu->AppendSeparator();   // _____________
	if(_titleSub!="")
		Append(menu, _titleSub);
	return menu;
}

void MenuBar::AddSubMenu(wxMenu *_menu, const wxString &_menuNome, bool _separator, const wxString &_subMenuNome) {
	if(_subMenuNome=="") {
		_menu->Append(m_id++, _menuNome);
		if(_separator)
			_menu->AppendSeparator();  // _____________
	} else {
		wxMenu *menu = new wxMenu();
		menu->Append(m_id++, _menuNome);//_("MenuTest"));//wxID_CUT);
		if(_separator)
			menu->AppendSeparator();    // _____________
		_menu->AppendSubMenu(menu, _subMenuNome);
	}
}

