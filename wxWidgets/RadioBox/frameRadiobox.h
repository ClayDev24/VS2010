#pragma once
#include <wx/frame.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>

#include <wx/panel.h>
#include <wx/sizer.h>
#include "IDs.h"

class FrameRadiobox : public wxFrame {
	wxRadioBox *m_radioBox;
    wxTextCtrl *m_textctrl;
    void OnRadioBoxChange(wxCommandEvent& evt);

public:
    FrameRadiobox(const wxString& title);

private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(FrameRadiobox, wxFrame)
    EVT_RADIOBOX(wxID_RADIOBOX, FrameRadiobox::OnRadioBoxChange)
wxEND_EVENT_TABLE()

FrameRadiobox::FrameRadiobox(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textctrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create the wxRadioBox control
    wxArrayString choices;
    choices.Add("Option 1");
    choices.Add("Option 2");
    choices.Add("Option 3");
    m_radioBox = new wxRadioBox(panel, wxID_RADIOBOX, 
        "Select one of the options", wxDefaultPosition, 
        wxDefaultSize, choices, 3, wxRA_VERTICAL);

    // Create a wxTextCtrl that will show the currently
    // selected option
    m_textctrl = new wxTextCtrl(panel, wxID_ANY, 
    m_radioBox->GetString(m_radioBox->GetSelection()),
    wxDefaultPosition, wxSize(140, wxDefaultCoord));

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(m_radioBox, 1, wxEXPAND | wxALL, 15);
    panelSizer->Add(m_textctrl, 0, wxCENTER);
    panelSizer->AddSpacer(15);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(215, 50);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void FrameRadiobox::OnRadioBoxChange(wxCommandEvent& evt) {
    wxString text = m_radioBox->GetString(evt.GetSelection());
    m_textctrl->SetValue(text);
}