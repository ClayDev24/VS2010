#pragma once
// a choice which handles focus set/kill (for testing)
class Choice : public wxChoice {
public:
    Choice(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0, const wxString choices[] = NULL,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxChoiceNameStr)
        : wxChoice(parent, id, pos, size, n, choices, style, validator, name)
	{}
protected:
    void OnFocusGot(wxFocusEvent& event) {
        wxLogMessage(wxT("MyChoice::OnFocusGot"));
        event.Skip();
    }
    void OnFocusLost(wxFocusEvent& event) {
        wxLogMessage(wxT("MyChoice::OnFocusLost"));
        event.Skip();
    }
private:
    wxDECLARE_EVENT_TABLE();
};