#pragma once
#include "panel.h"
// Define a new frame type: this is going to be our main frame
class Frame : public wxFrame {
	Panel      *m_panel;
public:
    wxTextCtrl *m_logWindow;
public:
    Frame(const wxString &title, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    // event handlers (these functions should _not_ be virtual)
    void OnAbout(   wxCommandEvent &event);
    void OnClearLog(wxCommandEvent &event);
	void OnQuit(    wxCommandEvent &event) { Close(true); }

#if wxUSE_DATEPICKCTRL
    void OnAskDate( wxCommandEvent &event);
    void OnUpdateUIStartWithNone(wxUpdateUIEvent &event);
#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL
    void OnAskTime(wxCommandEvent  &event);
#endif // wxUSE_TIMEPICKCTRL

#ifdef wxHAS_NATIVE_CALENDARCTRL
    void OnCalGeneric(wxCommandEvent &WXUNUSED(event)) {
        m_panel->ToggleUseGeneric();
    }
#endif // wxHAS_NATIVE_CALENDARCTRL

    void OnCalAutoWeekday(wxCommandEvent &event);
    void OnCalSunday(     wxCommandEvent &event);
    void OnCalMonday(     wxCommandEvent &event);
    void OnCalHolidays(   wxCommandEvent &event);
    void OnCalSpecial(    wxCommandEvent &event);

    void OnCalAllowMonth( wxCommandEvent &event);
    void OnCalLimitDates( wxCommandEvent &event);
    void OnCalSeqMonth(   wxCommandEvent &event);
    void OnCalShowSurroundingWeeks(wxCommandEvent &event);
    void OnCalShowWeekNumbers(     wxCommandEvent &event);

    void OnSetDate( wxCommandEvent &event);
    void OnToday(   wxCommandEvent &event);
    void OnBeginDST(wxCommandEvent &event);

    void OnCalToggleResizable(  wxCommandEvent &event);

    void OnUpdateUIGenericOnly(wxUpdateUIEvent &event) {
        event.Enable(m_panel->IsUsingGeneric());
    }
    void OnCalRClick(wxMouseEvent &event);

private:
    wxDECLARE_EVENT_TABLE();
};