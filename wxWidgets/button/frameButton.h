#pragma once
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <sstream> // std::wstringstream contents;
#include <wx/frame.h>
#include <wx/textctrl.h>
#include "../wxWidgets/_Framework/IDs.h"

// A frame containin' a button and a textcontrol objs.
class FrameButton : public wxFrame {
    wxTextCtrl  *m_textCtrl;
    unsigned int m_ClicksCount;
	void OnButtonClicked(wxCommandEvent &evt);

public:
    FrameButton(const wxString &title);

private:
    wxDECLARE_EVENT_TABLE();
};

//*****************<<_EVENT TABLE_>>************************
wxBEGIN_EVENT_TABLE(FrameButton, wxFrame)
    EVT_BUTTON(ButtonID, FrameButton::OnButtonClicked)
wxEND_EVENT_TABLE()

//**********************************************************
FrameButton::FrameButton(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0), m_ClicksCount(0)
{
    wxPanel  *panel  = new wxPanel(this, wxID_ANY);
    wxButton *button = new wxButton(panel, ButtonID, L"Button One");

    // Add a wxTextCtrl that will be updated when the button is clicked
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY,
        L"Button has never been clicked.", wxDefaultPosition, 
        wxSize(200, wxDefaultCoord));

    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(button,     0, wxEXPAND);
    panelSizer->Add(m_textCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}
//**********************************************************
void FrameButton::OnButtonClicked(wxCommandEvent &evt) {
    ++m_ClicksCount;
    if(m_textCtrl) {
        std::wstringstream contents;
        contents << L"Button has been clicked "
                  << m_ClicksCount
				   << " times";
        m_textCtrl->SetValue(contents.str());
    }
    evt.Skip();
}