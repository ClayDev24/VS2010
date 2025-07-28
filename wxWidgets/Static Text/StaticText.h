#pragma once
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/sizer.h>

class StaticText : public wxFrame {
public:
    StaticText(const wxString &title);
};

//#include "StaticText.h"

StaticText::StaticText(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // Create the wxStaticText control
    wxStaticText *staticText = new wxStaticText(panel, wxID_ANY, "Static Text");

    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(staticText, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->SetMinSize(515, 250);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}