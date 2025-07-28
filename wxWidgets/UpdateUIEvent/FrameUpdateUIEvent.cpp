#include "FrameUpdateUIEvent.h"
#include <wx/menu.h>
#include <wx/panel.h>

FrameUpdateUIEvent::FrameUpdateUIEvent(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)), m_checkbox(0)
{
    wxMenuBar* menuBar = new wxMenuBar;

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    // Add a checkbox that will determine
    // whether the Exit menu is enabled or not
    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(*wxWHITE);
    m_checkbox = new wxCheckBox(panel, wxID_ANY, "Enable Exit menu", 
        wxPoint(50, 30));
}

void FrameUpdateUIEvent::OnExitUpdate(wxUpdateUIEvent& evt) {
    evt.Enable(m_checkbox->GetValue());
}

wxBEGIN_EVENT_TABLE(FrameUpdateUIEvent, wxFrame)
    EVT_MENU(     wxID_EXIT, FrameUpdateUIEvent::OnExit)
    EVT_UPDATE_UI(wxID_EXIT, FrameUpdateUIEvent::OnExitUpdate)
wxEND_EVENT_TABLE()