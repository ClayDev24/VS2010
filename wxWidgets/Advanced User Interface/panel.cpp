#include "panel.h"
#include "frame.h"
// --------------------------------------------------
// MyPanel Implementation
// --------------------------------------------------
Panel::Panel(wxWindow *parent)
       : wxPanel(parent, wxID_ANY)
{
#ifdef wxHAS_NATIVE_CALENDARCTRL
    m_usingGeneric = false;
#else
    m_usingGeneric = true;
#endif

    wxString date;
    date.Printf("Selected date: %s",
                wxDateTime::Today().FormatISODate());
    m_date = new wxStaticText(this, wxID_ANY, date);
    m_calendar = DoCreateCalendar(wxDefaultDateTime,
                                  wxCAL_SHOW_HOLIDAYS);

    // adjust to vertical/horizontal display
    bool horizontal = ( wxSystemSettings::GetMetric(wxSYS_SCREEN_X) > wxSystemSettings::GetMetric(wxSYS_SCREEN_Y) );
    m_sizer = new wxBoxSizer( horizontal ? wxHORIZONTAL : wxVERTICAL );

    m_sizer->Add(m_date, 0, wxALIGN_CENTER | wxALL, 10 );
    m_sizer->Add(m_calendar, 0, wxALIGN_CENTER | wxALIGN_LEFT);

    SetSizer( m_sizer );
    m_sizer->SetSizeHints( this );
}

void Panel::OnCalendar(wxCalendarEvent &event) {
    // clicking the same date twice unmarks it (convenient for testing)
    static wxDateTime s_dateLast;
    const bool mark = !s_dateLast.IsValid() || event.GetDate() != s_dateLast;

    s_dateLast = event.GetDate();

    m_calendar->Mark(event.GetDate().GetDay(), mark);
    wxLogMessage("Selected (and %smarked) %s from calendar.",
                 mark ? "" : "un", s_dateLast.FormatISODate());
}

void Panel::OnCalendarChange(wxCalendarEvent &event) {
    wxString s;
    s.Printf("Selected date: %s", event.GetDate().FormatISODate());

    m_date->SetLabel(s);
    wxLogStatus(s);
}

void Panel::OnCalMonthChange(wxCalendarEvent &event) {
    wxLogStatus("Calendar month changed to %s %d",
                wxDateTime::GetMonthName(event.GetDate().GetMonth()),
                event.GetDate().GetYear());
}

void Panel::OnCalendarWeekDayClick(wxCalendarEvent& event) {
    wxLogMessage("Clicked on %s",
                 wxDateTime::GetWeekDayName(event.GetWeekDay()));
}

void Panel::OnCalendarWeekClick(wxCalendarEvent& event) {
    wxLogMessage("Clicked on week %d", event.GetDate().GetWeekOfYear());
}

wxCalendarCtrlBase *Panel::DoCreateCalendar(const wxDateTime& dt, long style) {
    wxCalendarCtrlBase *calendar;
#ifdef wxHAS_NATIVE_CALENDARCTRL
    if(m_usingGeneric)
        calendar = new wxGenericCalendarCtrl(this, Calendar_CalCtrl,
                                             dt,
                                             wxDefaultPosition,
                                             wxDefaultSize,
                                             style);
    else
#endif // wxHAS_NATIVE_CALENDARCTRL
        calendar = new wxCalendarCtrl(this, Calendar_CalCtrl,
                                      dt,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      style);

    calendar->Bind(wxEVT_RIGHT_DOWN,
                   &Frame::OnCalRClick,
                   (Frame *)wxGetTopLevelParent(this));
    return calendar;
}

void Panel::RecreateCalendar(long style) {
    wxCalendarCtrlBase *calendar = DoCreateCalendar(m_calendar->GetDate(), style);

    m_sizer->Replace(m_calendar, calendar);
    delete m_calendar;
    m_calendar = calendar;

    m_sizer->Layout();
}

void Panel::ToggleCalStyle(bool on, int flag) {
    long style = m_calendar->GetWindowStyle();
    if(on)
        style |= flag;
    else
        style &= ~flag;

    if(flag == wxCAL_SEQUENTIAL_MONTH_SELECTION
        || flag == wxCAL_SHOW_WEEK_NUMBERS)
    {
        // changing this style requires recreating the control
        RecreateCalendar(style);
    } else { // just changing the style is enough
        m_calendar->SetWindowStyle(style);
        m_calendar->Refresh();
    }
}

void Panel::HighlightSpecial(bool on) {
    if(on) {
        wxCalendarDateAttr
            *attrRedCircle   = new wxCalendarDateAttr(wxCAL_BORDER_ROUND,  *wxRED),
            *attrGreenSquare = new wxCalendarDateAttr(wxCAL_BORDER_SQUARE, *wxGREEN),
            *attrHeaderLike  = new wxCalendarDateAttr(*wxBLUE, *wxLIGHT_GREY);

        m_calendar->SetAttr(17, attrRedCircle);
        m_calendar->SetAttr(29, attrGreenSquare);
        m_calendar->SetAttr(13, attrHeaderLike);
    } else { // off
        m_calendar->ResetAttr(17);
        m_calendar->ResetAttr(29);
        m_calendar->ResetAttr(13);
    }
    m_calendar->Refresh();
}

// Toggle a restricted date range to the six months centered on today's date.
void Panel::LimitDateRange(bool on) {
    if(on) {
        // limit the choice of date to 3 months around today
        const wxDateSpan diff  = wxDateSpan::Months(3);
        const wxDateTime today = wxDateTime::Today();

        // Set the restricted date range.
        if(m_calendar->SetDateRange(today - diff, today + diff)) {
            wxLogStatus("Date range limited to 3 months around today.");
            wxDateTime firstValidDate;
            wxDateTime lastValidDate;
            if(m_calendar->GetDateRange(&firstValidDate, &lastValidDate)) {
                wxLogMessage("First valid date: %s, last valid date: %s",
                             firstValidDate.FormatISODate(),
                             lastValidDate.FormatISODate());
            } else
                wxLogWarning("Failed to get back the valid dates range.");
        } else
            wxLogWarning("Date range not supported.");
    }
    else { // off
        // Remove the date restrictions.
        if(m_calendar->SetDateRange())
            wxLogStatus("Date choice is unlimited now.");
        else
            wxLogWarning("Date range not supported.");
    }
    m_calendar->Refresh();
}

wxBEGIN_EVENT_TABLE(Panel, wxPanel)
    EVT_CALENDAR(Calendar_CalCtrl, Panel::OnCalendar)
    EVT_CALENDAR_PAGE_CHANGED( Calendar_CalCtrl,   Panel::OnCalMonthChange)
    EVT_CALENDAR_SEL_CHANGED(  Calendar_CalCtrl,   Panel::OnCalendarChange)
    EVT_CALENDAR_WEEKDAY_CLICKED(Calendar_CalCtrl, Panel::OnCalendarWeekDayClick)
    EVT_CALENDAR_WEEK_CLICKED( Calendar_CalCtrl,   Panel::OnCalendarWeekClick)
wxEND_EVENT_TABLE()