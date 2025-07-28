#include "frameDrop.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/dataobj.h>

FrameDrop::FrameDrop(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_sourceTextCtrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a control that will be the source of of the drag and
    // drop operation. We connect an event handler for the
    // left mouse button event.
    m_sourceTextCtrl = new wxStaticText(panel, wxID_ANY, 
        "Hello World!", wxDefaultPosition, wxSize(250,100));
    m_sourceTextCtrl->Connect(wxEVT_LEFT_DOWN, 
        (wxObjectEventFunction)&FrameDrop::OnLeftButtonDown, 0, this);

    // Create a text control that can be the target of a drag an drop operation
    wxTextCtrl* targetTextCtrl = new wxTextCtrl(panel, wxID_ANY, 
        "", wxDefaultPosition, wxSize(250, 100));
    DropTarget* dropTarget = new DropTarget(*targetTextCtrl);
    targetTextCtrl->SetDropTarget(dropTarget);

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_sourceTextCtrl, 0, wxEXPAND | wxALL, 5);
    panelSizer->Add(targetTextCtrl, 0, wxEXPAND | wxALL, 5);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void FrameDrop::OnLeftButtonDown(wxMouseEvent& evt) {
    wxTextDataObject dragData(m_sourceTextCtrl->GetLabelText());
    wxDropSource dragSource(m_sourceTextCtrl);
    dragSource.SetData(dragData);
    wxDragResult result = dragSource.DoDragDrop();
}

FrameDrop::DropTarget::DropTarget(wxTextCtrl& dropTarget)
    : m_dropTarget(dropTarget)
{}

bool FrameDrop::DropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& data) {    
	m_dropTarget.SetValue(data);
    return true;
}

wxBEGIN_EVENT_TABLE(FrameDrop, wxFrame)
    EVT_LEFT_DOWN(FrameDrop::OnLeftButtonDown)
wxEND_EVENT_TABLE()