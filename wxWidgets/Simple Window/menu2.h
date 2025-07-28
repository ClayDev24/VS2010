#pragma once
#include <wx/menu.h>
#include <wx/artprov.h> // SetBitmap() to set the icon
#include "functions.h"
#include "IDs.h"

class MenuBar:public wxMenuBar {
	wxWindow  *m_parent; // ==  parent Frame
	//wxMenuBar *m_menuBar;
	int m_id;
	void OnMenuClicked(wxCommandEvent &evt) {
//		fPtr f = vFuncMen.at(0);//evt.GetId());
//		(*f)(m_parent);
//		Men1Click(m_parent);

		wxAboutDialogInfo m_info;
		m_info.SetDescription(wxT("Menu1 Clicked!"));
		wxAboutBox(m_info);
	}
public:
	MenuBar(wxWindow *parent, const int &_id)
	:m_parent(parent), m_id(_id) //m_menuBar(_m), 
	{
		wxMenu     *fileMenu = new wxMenu();
		wxMenu     *subMenu  = new wxMenu();
		wxMenuItem *quitItem = new wxMenuItem(fileMenu, wxID_EXIT);

		quitItem->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
		subMenu->Append(m_id, _("MenuTest")); wxID_CUT);
		subMenu->Append(wxID_COPY);
		subMenu->Append(wxID_PASTE);

		fileMenu->Append(wxID_NEW);
		fileMenu->AppendSeparator(); // __________________________
		fileMenu->AppendSubMenu(subMenu, _("SubMenu"));
		fileMenu->Append(wxID_ANY, _("&Test\tCtrl+T")); // custom wxMenuItem
		fileMenu->AppendSeparator(); // __________________________
		fileMenu->Append(quitItem);  // Provides an icon to the menu

		Append(fileMenu,_("&File"));
	}
	~MenuBar() {}
	static void addFunction(fPtr _f) {
		vFuncMen.push_back(_f);
	}
	void AddMenu(int id, const wxString &title) {
		wxMenu *fileMenu = new wxMenu();
	}
	void AddSubMenu(int id, const wxString &title, wxMenu *_menu) {
	}

//private:
//	wxDECLARE_EVENT_TABLE();
};

