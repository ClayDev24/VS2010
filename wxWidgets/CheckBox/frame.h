#pragma once
#include <wx/frame.h>
#include <wx/textctrl.h>

#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include "checkbox.h"
#include "IDs.h"

class Frame: public wxFrame {
	wxTextCtrl *m_textctrl;
    void OnCheckBoxEvent(wxCommandEvent &evt);
public:
    Frame(const wxString &title);

private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_CHECKBOX(wxID_CHECKBOX, Frame::OnCheckBoxEvent)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title), m_textctrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    panel->SetBackgroundColour(*wxWHITE);

    m_textctrl = new wxTextCtrl(panel, wxID_ANY, "Checkbox not checked", 
        wxDefaultPosition, wxSize(140, wxDefaultCoord));

    // Create the wxCheckBox control
    //wxCheckBox *checkbox = new wxCheckBox(panel, wxID_CHECKBOX, "Checkbox 1");
	CheckBox *checkbox = new CheckBox(panel, wxID_CHECKBOX, "Checkbox 1");
	//checkbox->SetSizer(panel, m_textctrl);
		// Set up the sizer for the panel
		wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
		//panelSizer->AddSpacer(15);
		panelSizer->Add(checkbox,  0, wxCENTER);
		//panelSizer->AddSpacer(15);
		panelSizer->Add(m_textctrl, 0, wxCENTER);
		//panelSizer->AddSpacer(15);
		panel->SetSizer(panelSizer);
		// Set up the sizer for the frame and resize the frame
		// according to its contents
		wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
		topSizer->SetMinSize(215, 50);
		topSizer->Add(panel, 1, wxEXPAND);
		SetSizerAndFit(topSizer);
}

void Frame::OnCheckBoxEvent(wxCommandEvent &evt) {
    if(evt.IsChecked())
        m_textctrl->SetValue("Checkbox checked");
    else
        m_textctrl->SetValue("Checkbox not checked");
}