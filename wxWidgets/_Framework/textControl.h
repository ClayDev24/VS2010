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
	TextControl(wxWindow *parent,
               wxWindowID id,
               const wxString &value = wxEmptyString,
               const wxPoint  &pos   = wxDefaultPosition,
               const wxSize   &size  = wxDefaultSize,
               long  style    = 0,
               const wxValidator &validator = wxDefaultValidator,
               const wxString    &name = wxTextCtrlNameStr)
	:wxTextCtrl(parent, id, value, pos, size, style, validator, name)
	{}
	~TextControl() {}
	//static void addFunction(fPtr _f) {
		//vFuncTex.push_back(_f);
	//}
//private:
//	wxDECLARE_EVENT_TABLE();
};