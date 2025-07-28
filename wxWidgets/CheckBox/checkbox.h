#pragma once
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include "IDs.h"

class CheckBox:public wxCheckBox {
	wxTextCtrl *m_textctrl;
	wxWindow   *m_parent;
	
	void OnCheckBoxEvent(wxCommandEvent &evt) {
		//OnAbout(evt);
		//evt.GetId();
		//		fPtr f = vFuncBtn.at(evt.GetId());
		//		(*f)(m_parent);
	}

public:
	CheckBox(wxWindow *panel, wxWindowID id, const wxString &label):wxCheckBox(panel, id, label) {
		m_parent = panel;
	}
	~CheckBox() {}
	void SetSizer(wxPanel *panel, wxTextCtrl *m_textctrl) {
		// Set up the sizer for the panel
		wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
		panelSizer->AddSpacer(15);
		panelSizer->Add(this->GetParent(), 0, wxCENTER);//checkbox,  0, wxCENTER);
		panelSizer->AddSpacer(15);
		panelSizer->Add(m_textctrl, 0, wxCENTER);
		panelSizer->AddSpacer(15);
		panel->SetSizer(panelSizer);
		// Set up the sizer for the frame and resize the frame
		// according to its contents
		wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
		topSizer->SetMinSize(215, 50);
		topSizer->Add(panel, 1, wxEXPAND);
		SetSizerAndFit(topSizer);
	}

private:
	wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(CheckBox, wxCheckBox)
	EVT_CHECKBOX(wxID_CHECKBOX, CheckBox::OnCheckBoxEvent)
wxEND_EVENT_TABLE()

//void CheckBox::OnCheckBoxEvent(wxCommandEvent &evt) {
	//if(evt.IsChecked())
	//    m_textctrl->SetValue("Checkbox checked");
	//else
    //m_textctrl->SetValue("Checkbox not checked");
//}