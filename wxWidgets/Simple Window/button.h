#pragma once
#include <wx/button.h>
#include <wx/gdicmn.h>   // wxPoint()
#include "functions.h"
#include "IDs.h"

// A frame containin' a button and a textcontrol objs.
class Button : public wxButton {
	wxWindow *m_parent; // ==  parent Frame
//	void OnButtonClicked(wxCommandEvent &evt) {
		//OnAbout(evt);
		//evt.GetId();
//		fPtr f = vFuncBtn.at(evt.GetId());
//		(*f)(m_parent);
//	}
	static int id_button;

public:
    Button(wxWindow *hwd, int id, const wxString &title, wxPoint &Point)
		:wxButton(hwd, id, title, Point)	
	{
		m_parent = hwd->GetParent();
	}
	~Button() {}
	static void addFunction(fPtr _f) {
		vFuncBtn.push_back(_f);
	}
//private:
//    wxDECLARE_EVENT_TABLE();
};

//wxBEGIN_EVENT_TABLE(Button, wxButton)
	//EVT_BUTTON(IDS::ID_1, Button::OnButtonClicked)
	//EVT_BUTTON(IDS::ID_2, Button::OnButtonClicked)
//wxEND_EVENT_TABLE()

//wxBEGIN_EVENT_TABLE(Menu, wxMenu)
//	EVT_MENU(IDS::ID_1, Menu::OnMenuClicked)
	//EVT_MENU(0, Menu::OnMenuClicked)
//wxEND_EVENT_TABLE()
