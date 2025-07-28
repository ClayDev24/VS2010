#pragma once
#include <wx/frame.h>
#include <wx/textctrl.h>

#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include "IDs.h"

class fileOpenDlg : public wxFrame {
	wxTextCtrl* m_textCtrl;
    void OnOpenFile( wxCommandEvent& evt);
	void OnChooseDir(wxCommandEvent& evt);

public:
    fileOpenDlg(const wxString& title);
	wxTextCtrl *GetTextCtrl() { return m_textCtrl; }

private:
    wxDECLARE_EVENT_TABLE();
};

// Add the event handler for the menu item
// to the event table.
wxBEGIN_EVENT_TABLE(fileOpenDlg, wxFrame)
    EVT_MENU(wxID_OPEN,   fileOpenDlg::OnOpenFile)
	EVT_MENU(ID_DIR_OPEN, fileOpenDlg::OnChooseDir)
wxEND_EVENT_TABLE()

//********************************************************
fileOpenDlg::fileOpenDlg(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
    // The Open dialog is usually accessible from
    // the "File" menu so we create one.
    wxMenuBar *menuBar  = new wxMenuBar();
    wxMenu    *menuFile = new wxMenu();
    //wxMenu    *menuDir  = new wxMenu();
    menuFile->Append(wxID_OPEN);
    menuFile->Append(ID_DIR_OPEN, wxT("Choose &Dir\tCtrl+D"));
	//menuDir->Append(wxID_OPEN);
	//menuDir->Append(wxID_OPEN, wxT("Choose &Dir"), wxT("Show choose directory dialog"));
    menuBar->Append(menuFile, "&File");
    //menuBar->Append(menuDir,  "&File");

    SetMenuBar(menuBar);

    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Add a wxTextCtrl that will be updated when the
    // user selects a file
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
// Event handler for the menu item:
void fileOpenDlg::OnOpenFile(wxCommandEvent& evt) {
    // Create a new wxFileDialog dialog
    wxFileDialog* fileDialog = new wxFileDialog(this);
	wxString fileName("");
    // Displays the choose file dlg:
    if(fileDialog->ShowModal() == wxID_OK) {
        fileName = fileDialog->GetPath();
        m_textCtrl->SetValue(fileName);
    }
    fileDialog->Destroy();
	//return fileName;
}

// Event handler for the menu item.
void fileOpenDlg::OnChooseDir(wxCommandEvent& evt) {
    // Create a new wxDirDialog dlg:
    wxDirDialog* dirDialog = new wxDirDialog(this);
    // Displays the choose dir dlg:
    if(dirDialog->ShowModal() == wxID_OK) {
        wxString dirName = dirDialog->GetPath();
        m_textCtrl->SetValue(dirName);
    }
    dirDialog->Destroy();
}