#pragma once
#include "wx/wxprec.h"
// a combo which intercepts chars (to test Windows behaviour)
class ComboBox : public wxComboBox {
public:
    ComboBox(wxWindow *parent, wxWindowID id,
               const wxString &value = wxEmptyString,
               const wxPoint  &pos   = wxDefaultPosition,
               const wxSize   &size  = wxDefaultSize,
               int   n     = 0, const wxString choices[] = NULL,
               long  style = 0,
               const wxValidator &validator = wxDefaultValidator,
               const wxString    &name      = wxComboBoxNameStr)
        : wxComboBox(parent, id, value, pos, size, n, choices, style,
                     validator, name) {}
protected:
    void OnChar(      wxKeyEvent &event);
    void OnKeyDown(   wxKeyEvent &event);
    void OnKeyUp(     wxKeyEvent &event);
    void OnFocusGot(wxFocusEvent &event) {
        wxLogMessage(wxT("MyComboBox::OnFocusGot"));
        event.Skip();
    }
private:
    wxDECLARE_EVENT_TABLE();
};