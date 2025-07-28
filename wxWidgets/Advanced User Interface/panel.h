#pragma once
// --------------------------------------------------------------
// headers
// --------------------------------------------------------------
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers
#ifndef WX_PRECOMP
    #include "wx/app.h"
    #include "wx/log.h"
    #include "wx/frame.h"
    #include "wx/panel.h"
    #include "wx/stattext.h"
    #include "wx/menu.h"
    #include "wx/layout.h"
    #include "wx/msgdlg.h"
    #include "wx/icon.h"
    #include "wx/button.h"
    #include "wx/sizer.h"
    #include "wx/textctrl.h"
    #include "wx/settings.h"
#endif

#include "wx/calctrl.h"
#include "wx/splitter.h"

#if wxUSE_DATEPICKCTRL
    #include "wx/datectrl.h"
    #if wxUSE_DATEPICKCTRL_GENERIC
        #include "wx/generic/datectrl.h"
    #endif // wxUSE_DATEPICKCTRL_GENERIC
#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL
    #include "wx/timectrl.h"
    #if wxUSE_TIMEPICKCTRL_GENERIC
        #include "wx/generic/timectrl.h"
    #endif // wxUSE_TIMEPICKCTRL_GENERIC
#endif // wxUSE_TIMEPICKCTRL

#ifdef wxHAS_NATIVE_CALENDARCTRL
    #include "wx/generic/calctrlg.h"
#endif

#include "IDs.h"

class Panel : public wxPanel {
    wxCalendarCtrlBase *m_calendar;
    wxStaticText       *m_date;
    wxSizer            *m_sizer;
    bool m_usingGeneric;
	void RecreateCalendar(long style);
	wxCalendarCtrlBase *DoCreateCalendar(const wxDateTime &dt, long style);
public:
    Panel(wxWindow *parent);

    void OnCalendar(wxCalendarEvent &event);
    void OnCalendarWeekDayClick(wxCalendarEvent &event);
    void OnCalendarWeekClick(   wxCalendarEvent &event);
    void OnCalendarChange(      wxCalendarEvent &event);
    void OnCalMonthChange(      wxCalendarEvent &event);

    wxCalendarCtrlBase *GetCal() const { return m_calendar; }
    // turn on/off the specified style bit on the calendar control
    void ToggleCalStyle(bool on, int style);

    bool IsUsingGeneric() const { return m_usingGeneric; }
    void ToggleUseGeneric() {
        m_usingGeneric = !m_usingGeneric;
        RecreateCalendar(m_calendar->GetWindowStyle());
    }
    wxDateTime GetDate() const {  return m_calendar->GetDate(); }
    void SetDate(const wxDateTime& dt) { m_calendar->SetDate(dt); }
    void HighlightSpecial(bool on);
    void LimitDateRange(  bool on);
private:
    wxDECLARE_EVENT_TABLE();
};

//**********************************************************
#if wxUSE_DATEPICKCTRL
// Define a simple modal dialog which asks the user for a date
class DateDialog : public wxDialog {
	wxDatePickerCtrl *m_datePicker;
	wxStaticText     *m_dateText;
    void OnDateChange(wxDateEvent &event);

#if wxUSE_DATEPICKCTRL_GENERIC
    wxDatePickerCtrlGeneric *m_datePickerGeneric;
#endif // wxUSE_DATEPICKCTRL_GENERIC

public:
    DateDialog(wxWindow *parent, const wxDateTime &dt, int dtpStyle);

    wxDateTime GetDate() const
    {
#if wxUSE_DATEPICKCTRL_GENERIC
        if(m_datePickerGeneric)
            return m_datePickerGeneric->GetValue();
#endif // wxUSE_DATEPICKCTRL_GENERIC

        return m_datePicker->GetValue();
    }
private:
    wxDECLARE_EVENT_TABLE();
};
#endif // wxUSE_DATEPICKCTRL

//**********************************************************
#if wxUSE_TIMEPICKCTRL
// Another simple dialog, this one asking for time.
class TimeDialog : public wxDialog {
	wxTimePickerCtrl *m_timePicker;
	wxStaticText     *m_timeText;
    void OnTimeChange(wxDateEvent &event);

#if wxUSE_TIMEPICKCTRL_GENERIC
    wxTimePickerCtrlGeneric *m_timePickerGeneric;
#endif // wxUSE_TIMEPICKCTRL_GENERIC

public:
    TimeDialog(wxWindow *parent);

    wxDateTime GetTime() const
    {
#if wxUSE_TIMEPICKCTRL_GENERIC
        if(m_timePickerGeneric)
            return m_timePickerGeneric->GetValue();
#endif // wxUSE_TIMEPICKCTRL_GENERIC

        return m_timePicker->GetValue();
    }
private:
    wxDECLARE_EVENT_TABLE();
};
#endif // wxUSE_TIMEPICKCTRL