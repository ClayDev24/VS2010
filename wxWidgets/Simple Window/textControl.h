#pragma once
#include <wx/textctrl.h>
#include "functions.h"

class TextControl:public wxTextCtrl {
	wxWindow  *m_parent; // ==  parent Frame
	wxMenuBar *m_menuBar;
	void OnTextClicked(wxCommandEvent &evt) {
//		fPtr f = vFuncMen.at(0);//evt.GetId());
//		(*f)(m_parent);
//		Men1Click(m_parent);

		wxAboutDialogInfo m_info;
		m_info.SetDescription(wxT("TextControl1 Clicked!"));
		wxAboutBox(m_info);
	}
public:
	TextControl(wxWindow *parent, int id, const wxString &title)
	:m_parent(parent)
	{
	}
	~TextControl() {}
	static void addFunction(fPtr _f) {
		//vFuncTex.push_back(_f);
	}
//private:
//	wxDECLARE_EVENT_TABLE();
};