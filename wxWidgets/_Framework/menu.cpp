//#include <wx/artprov.h> // SetBitmap() to set the icon
#include "menu.h"

wxMenu* MenuBar::CreateMenu(wxMenu *_subMenu, int _sz, ...) {
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
	if(_subMenu)
		_subMenu->AppendSubMenu(menu, v[v.size()-1]);
	else
		Append(menu, v[v.size()-1]);
	return menu;
}

