#pragma once
#include <wx/frame.h>
#include <wx/clrpicker.h>
#include <wx/textctrl.h>

#include <wx/panel.h>
#include <wx/sizer.h>
#include "IDs.h"

class FramePicker : public wxFrame {
	wxTextCtrl *m_textCtrl;
    void OnColourChanged(wxColourPickerEvent &evt);

public:
    FramePicker(const wxString &title);

private:
    wxDECLARE_EVENT_TABLE();
};

// Add the event handler to the event table. As you can see we use the
// window ID to link the event handler to the wxColourPickerCtrl we created.
wxBEGIN_EVENT_TABLE(FramePicker, wxFrame)
    EVT_COLOURPICKER_CHANGED(ColourPickerID, FramePicker::OnColourChanged)
wxEND_EVENT_TABLE()

FramePicker::FramePicker(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // Create a wxTextCtrl to have some text we can select the color of
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "Some text of the selected color.",
        wxDefaultPosition, wxSize(200, wxDefaultCoord));

    // Create a wxColourPickerCtrl control
    wxColourPickerCtrl *colourPickerCtrl = new wxColourPickerCtrl(panel, ColourPickerID);

    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_textCtrl, 0, wxEXPAND | wxALL, 15);
    panelSizer->Add(colourPickerCtrl, 0, wxEXPAND | wxALL, 15);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void FramePicker::OnColourChanged(wxColourPickerEvent &evt) {
    // Use the wxColourPickerEvent::GetColour() function to get the selected
    // color and set the color of the text control accordingly.
    m_textCtrl->SetForegroundColour(evt.GetColour());
	//m_textCtrl->SetBackgroundColour(evt.GetColour());
    m_textCtrl->Refresh();
}