#pragma once
// a radiobox which handles focus set/kill (for testing)
class RadioBox : public wxRadioBox {
public:
    RadioBox(wxWindow *parent,
               wxWindowID id,
               const wxString& title = wxEmptyString,
               const wxPoint&  pos   = wxDefaultPosition,
               const wxSize&   size  = wxDefaultSize,
               int   n = 0, const wxString choices[] = NULL,
               int   majorDim = 1,
               long  style = wxRA_SPECIFY_COLS,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxRadioBoxNameStr)
        : wxRadioBox(parent, id, title, pos, size, n, choices, majorDim, style, validator, name)
    {}
protected:
    void OnFocusGot(wxFocusEvent& event) {
        wxLogMessage(wxT("MyRadioBox::OnFocusGot"));

        event.Skip();
    }
    void OnFocusLost(wxFocusEvent& event) {
        wxLogMessage(wxT("MyRadioBox::OnFocusLost"));

        event.Skip();
    }
private:
    wxDECLARE_EVENT_TABLE();
};
