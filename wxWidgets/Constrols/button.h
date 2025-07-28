#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/button.h>

// a button which intercepts double clicks (for testing...)
class Button : public wxButton {
public:
    Button(wxWindow *parent,
             wxWindowID id,
             const wxString &label = wxEmptyString,
             const wxPoint  &pos   = wxDefaultPosition,
             const wxSize   &size  = wxDefaultSize) : wxButton(parent, id, label, pos, size)
    {}
    void OnDClick(wxMouseEvent &event) {
        wxLogMessage(wxT("Button::OnDClick"));
        event.Skip();
    }
private:
	wxDECLARE_EVENT_TABLE();
};