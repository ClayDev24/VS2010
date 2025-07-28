#pragma once
#include <wx/button.h>
#include "functions.h"
//#include <wx/gdicmn.h> // wxPoint()

class Button : public wxButton {
	wxWindow *m_parent; // ==  parent Frame
	static int id;

	void OnButtonClicked(wxCommandEvent &evt);

public:
    Button(wxWindow *hwd, const wxString &title, wxPoint &Point);
	~Button() {}
	void addFunction(fPtr _f) {
		vFuncBtn.push_back(_f);
	}
//private:
//    wxDECLARE_EVENT_TABLE();
};

//wxBEGIN_EVENT_TABLE(Button, wxButton)
	//EVT_BUTTON(IDS::ID_1, Button::OnButtonClicked)
//wxEND_EVENT_TABLE()
