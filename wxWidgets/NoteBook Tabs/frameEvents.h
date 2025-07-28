#pragma once
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/aui/aui.h>
#include <sstream> // std::wstringstream contents;
#include <wx/textctrl.h>
#include <sstream>

#include <wx/defs.h>
const wxWindowID NotebookID = wxID_HIGHEST + 1;

class FrameEvents : public wxFrame {
    wxTextCtrl  *m_mainContents;
    unsigned int m_pageChangingCount;
	void OnPageChanging(wxAuiNotebookEvent& evt);
    void OnPageChanged( wxAuiNotebookEvent& evt);

public:
    FrameEvents(const wxString& title);

private:
    wxDECLARE_EVENT_TABLE();
};
// Add the 2 event handlers to the event table. As you can see we use
// the window ID to link the event handlers to the wxAuiNotebook we created.
wxBEGIN_EVENT_TABLE(FrameEvents, wxFrame)
    EVT_AUINOTEBOOK_PAGE_CHANGING(NotebookID, FrameEvents::OnPageChanging)
    EVT_AUINOTEBOOK_PAGE_CHANGED( NotebookID, FrameEvents::OnPageChanged)
wxEND_EVENT_TABLE()

FrameEvents::FrameEvents(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_mainContents(0), m_pageChangingCount(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel *panel = new wxPanel(this, wxID_ANY);
	m_pageChangingCount = 0;

    // Create the wxAuiNotebook widget
    wxAuiNotebook *auiNotebook = new wxAuiNotebook(panel, NotebookID,
        wxDefaultPosition, wxSize(150, 200));

    // Add 2 pages to the wxNotebook widget
    wxTextCtrl  *textCtrl1 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 1 Contents");
    auiNotebook->AddPage(textCtrl1, L"Tab 1");
    wxTextCtrl  *textCtrl2 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 2 Contents");
    auiNotebook->AddPage(textCtrl2, L"Tab 2");

    // Create the right-hand side panel, it's simply a textbox
    m_mainContents = new wxTextCtrl(panel, wxID_ANY,
		L"Main Contents Area", wxDefaultPosition, 
        wxSize(200, wxDefaultCoord));
	//m_mainContents->SetValue("aaaa");

    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(auiNotebook,    0, wxEXPAND);
    panelSizer->Add(m_mainContents, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->SetMinSize(400, 200);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

// Called when the selected page in the wxNotebook is going to be
// changed. We simply keep a count that we display on the right-hand
// side to show that the function is being called.
// In practice you may not need to write a handler for this event at
// all.
void FrameEvents::OnPageChanging(wxAuiNotebookEvent& evt) {
    ++m_pageChangingCount;
    evt.Skip();
}

// Called when the selected page in the wxNotebook has been changed.
// In our example we update the contents of the righ-hand side textbox.
void FrameEvents::OnPageChanged(wxAuiNotebookEvent& evt) {
    std::wstringstream contents;
    switch(evt.GetSelection()) {
    case 0:
        contents << L"Tab 1 selected, page changed ";
        break;
    case 1:
        contents << L"Tab 2 selected, page changed ";
        break;
    }
    contents << m_pageChangingCount << " times";
	wxString s="aaa";
    if(m_mainContents)
        m_mainContents->SetValue(contents.str());
    evt.Skip();
}