#pragma once
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>

class FrameTextCtrl2 : public wxFrame {
public:
    FrameTextCtrl2(const wxString& title);
};

FrameTextCtrl2::FrameTextCtrl2(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create the wxTextCtrl widget
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY,
        L"The quick brown fox jumps over the lazy dog\nand runs away",
        wxDefaultPosition, wxSize(350, 150), wxTE_MULTILINE);

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(textCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}