#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/aboutdlg.h>
#include <wx/sizer.h>
#include <vector>
#include "IDs.h"
#include "textControl.h"
#include "button.h"
#include "menu.h"

class Frame: public wxFrame {
	wxWindow   *m_parent;
	MenuBar    *m_menuBar;
	wxTextCtrl *m_textctrl;

	wxBoxSizer *m_panelSizer;
	wxBoxSizer *m_topSizer;
//	std::vector<Button> vBtn;
	int idbt;
	int idmn;

	void OnClicked(wxCommandEvent &evt) {	
		fPtr f;
		wxEventType type = evt.GetEventType();
		if(type==wxEVT_MENU)
			f = vFuncMen.at(evt.GetId());
		if(type==wxEVT_BUTTON)
			f = vFuncBtn.at(evt.GetId());
		//fPtr f = vFuncMen.at(evt.GetId());
		(*f)(m_parent);
	}
public:
	Frame(wxWindow *parent,
            wxWindowID id,
            const wxString &title,
            const wxPoint  &pos  = wxDefaultPosition,
            const wxSize   &size = wxDefaultSize,
            long  style = wxDEFAULT_FRAME_STYLE,
            const wxString &name = wxFrameNameStr);
	~Frame(void) {}

private:
	wxDECLARE_EVENT_TABLE();
};

