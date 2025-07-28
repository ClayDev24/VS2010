#pragma once
#include <wx/frame.h>
#include <wx/textctrl.h>

#include <wx/menu.h>
#include <wx/wizard.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include "IDs.h"

class FrameWizard : public wxFrame {
	wxTextCtrl *m_textCtrl;
    void OnRunWizard(wxCommandEvent& evt);
public:
    FrameWizard(const wxString& title);

private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(FrameWizard, wxFrame)
    EVT_MENU(ID_WIZARD, FrameWizard::OnRunWizard)
wxEND_EVENT_TABLE()
//*****************************************************************

FrameWizard::FrameWizard(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
    // Create a menu bar with a single item that
    // allows the user to launch the wizard
    wxMenuBar *menuBar  = new wxMenuBar;
    wxMenu    *menuFile = new wxMenu;
    menuFile->Append(ID_WIZARD, "&Run Wizard...");
    menuBar->Append(menuFile,   "&Wizard");
    SetMenuBar(menuBar);

    // Create a top-level panel to hold all the contents
    // of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Add a wxTextCtrl that will be updated when the
    // wizard is completed (unless it is cancelled)
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY,
        L"", wxDefaultPosition, wxSize(400, 200));

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_textCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

// This event handler will be called when the menu item
// is activated
void FrameWizard::OnRunWizard(wxCommandEvent& evt) {
    // Create a wxWizard dialog
    wxWizard *wizard = new wxWizard(this, wxID_ANY);

    // Create the first (and only) page of the wizard.
    // It has a wxTextCtrl where the user can type some text.
    wxWizardPageSimple *page1 = new wxWizardPageSimple(wizard);
    wxStaticText  *staticText = new wxStaticText(page1, wxID_ANY,
        "Enter some text:");
    wxTextCtrl* textCtrl = new wxTextCtrl(page1, wxID_ANY, "", 
        wxDefaultPosition, wxSize(450, 150));

    // Create a wxBoxSizer to do the layout of the page
    wxBoxSizer *page1Sizer = new wxBoxSizer(wxVERTICAL);
    page1Sizer->Add(staticText, 0, wxEXPAND);
    page1Sizer->Add(textCtrl,   1, wxEXPAND);
    page1->SetSizer(page1Sizer);

    // wxWizard has its own sizer to which the pages need
    // to be added so that it can compute the correct size
    // for the wizard.
    wizard->GetPageAreaSizer()->Add(page1);

    // Run the wizard
    if(wizard->RunWizard(page1)) {
        // RunWizard will return true if it is completed without
        // cancelling. In this case transfer the text the user
        // entered in the wizard to the main window.
        m_textCtrl->SetValue(textCtrl->GetValue());
    }
    wizard->Destroy();
}