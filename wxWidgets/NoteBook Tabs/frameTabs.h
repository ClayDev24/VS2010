#pragma once
#include <wx/frame.h>

#include <wx/aui/aui.h>
#include <wx/textctrl.h>
//#include <wx/aui/auibook.h>

class FrameTabs : public wxFrame {
public:
    FrameTabs(const wxString& title);
};

FrameTabs::FrameTabs(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // Create the wxAuiNotebook widget
    wxAuiNotebook *auiNotebook = new wxAuiNotebook(panel, wxID_ANY);

    // Add 2 pages to the wxNotebook widget
    wxTextCtrl *textCtrl1 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 1 Contents");
    auiNotebook->AddPage(textCtrl1, L"Tab 1");
    wxTextCtrl *textCtrl2 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 2 Contents");
    auiNotebook->AddPage(textCtrl2, L"Tab 2");

    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(auiNotebook, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->SetMinSize(250, 200);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}