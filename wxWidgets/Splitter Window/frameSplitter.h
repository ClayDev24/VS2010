#pragma once
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/textctrl.h>

class FrameSplitter : public wxFrame {
public:
    FrameSplitter(const wxString& title);
};

FrameSplitter::FrameSplitter(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create the wxSplitterWindow window
    // and set a minimum pane size to prevent unsplitting
    wxSplitterWindow* splitterWindow = new wxSplitterWindow(this, wxID_ANY);
    splitterWindow->SetMinimumPaneSize(50);

    // Create the left panel
    wxPanel* panel1 = new wxPanel(splitterWindow, wxID_ANY);
    wxTextCtrl* textCtrl1 = new wxTextCtrl(panel1, wxID_ANY, L"Panel 1 Text",
        wxDefaultPosition, wxSize(150, 150));
    wxBoxSizer* panel1Sizer = new wxBoxSizer(wxHORIZONTAL);
    panel1Sizer->Add(textCtrl1, 1, wxEXPAND);
    panel1->SetSizer(panel1Sizer);

    // Create the right panel
    wxPanel* panel2 = new wxPanel(splitterWindow, wxID_ANY);
    wxTextCtrl* textCtrl2 = new wxTextCtrl(panel2, wxID_ANY, L"Panel 2 Text",
        wxDefaultPosition, wxSize(150, 150));
    wxBoxSizer* panel2Sizer = new wxBoxSizer(wxHORIZONTAL);
    panel2Sizer->Add(textCtrl2, 1, wxEXPAND);
    panel2->SetSizer(panel2Sizer);

    // Split the window vertically and set the left and right panes
    splitterWindow->SplitVertically(panel1, panel2);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(splitterWindow, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}