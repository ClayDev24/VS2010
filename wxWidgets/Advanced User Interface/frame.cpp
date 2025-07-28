#include "frame.h"
// --------------------------------------------------
// Frame Implementation
// --------------------------------------------------
Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
       : wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size)
{
    // set the frame icon
    SetIcon(wxICON(sample));
    // create a menu bar
    wxMenuBar *menuBar  = new wxMenuBar;
    wxMenu    *menuFile = new wxMenu;
	wxMenu    *menuCal  = new wxMenu;

    menuFile->Append(Calendar_File_About, "&About\tCtrl-A", "Show about dialog");
    menuFile->AppendSeparator();
    menuFile->Append(Calendar_File_ClearLog, "&Clear log\tCtrl-L");
    menuFile->AppendSeparator();
    menuFile->Append(Calendar_File_Quit, "E&xit\tAlt-X", "Quit this program");
    menuBar->Append(menuFile, "&File");

#ifdef wxHAS_NATIVE_CALENDARCTRL
    menuCal->AppendCheckItem(Calendar_Cal_Generic, "Use &generic version\tCtrl-G",
                             "Toggle between native and generic control");
    menuCal->AppendSeparator();
#endif // wxHAS_NATIVE_CALENDARCTRL
    menuCal->AppendRadioItem(Calendar_Cal_AutoWeekday,
                    "Automatic &first weekday\tCtrl-V");
    menuCal->AppendRadioItem(Calendar_Cal_Sunday,
                    "Sunday &first weekday\tCtrl-Z");
    menuCal->AppendRadioItem(Calendar_Cal_Monday,
                    "Monday &first weekday\tCtrl-F");
    menuCal->Append(Calendar_Cal_Holidays, "Show &holidays\tCtrl-H",
                    "Toggle highlighting the holidays", true);
    menuCal->Append(Calendar_Cal_Special, "Highlight &special dates\tCtrl-S",
                    "Test custom highlighting", true);
    menuCal->Append(Calendar_Cal_SurroundWeeks,
                    "Show s&urrounding weeks\tCtrl-W",
                    "Show the neighbouring weeks in the prev/next month", true);
    menuCal->Append(Calendar_Cal_WeekNumbers,
                    "Show &week numbers",
                    "Toggle week numbers", true);
    menuCal->AppendSeparator();
    menuCal->Append(Calendar_Cal_SeqMonth,
                    "Toggle month selector st&yle\tCtrl-Y",
                    "Use another style for the calendar controls", true);
    menuCal->Append(Calendar_Cal_Month, "&Month can be changed\tCtrl-M",
                    "Allow changing the month in the calendar", true);
    menuCal->AppendCheckItem(Calendar_Cal_LimitDates, "Toggle date ra&nge\tCtrl-N",
                    "Limit the valid dates");
    menuCal->AppendSeparator();
    menuCal->Append(Calendar_Cal_SetDate, "Call &SetDate(2005-12-24)", "Set date to 2005-12-24.");
    menuCal->Append(Calendar_Cal_Today,   "Call &Today()", "Set to the current date.");
    menuCal->Append(Calendar_Cal_BeginDST,"Call SetDate(GetBeginDST())");
    menuCal->AppendSeparator();
    menuCal->AppendCheckItem(Calendar_Cal_Resizable, "Make &resizable\tCtrl-R");
    menuBar->Append(menuCal, "&Calendar");

#if wxUSE_DATEPICKCTRL
    wxMenu *menuDate = new wxMenu;
    menuDate->AppendCheckItem(Calendar_DatePicker_ShowCentury,
                              "Al&ways show century");
    menuDate->AppendCheckItem(Calendar_DatePicker_DropDown,
                              "Use &drop down control");
    menuDate->AppendCheckItem(Calendar_DatePicker_AllowNone,
                              "Allow &no date");
    menuDate->AppendCheckItem(Calendar_DatePicker_StartWithNone,
                              "Start &with no date");
#if wxUSE_DATEPICKCTRL_GENERIC
    menuDate->AppendCheckItem(Calendar_DatePicker_Generic,
                              "Use &generic version of the control");
#endif // wxUSE_DATEPICKCTRL_GENERIC
    menuDate->AppendSeparator();
    menuDate->Append(Calendar_DatePicker_AskDate, "&Choose date...\tCtrl-D", "Show dialog with wxDatePickerCtrl");
    menuBar->Append(menuDate, "&Date picker");
#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL
    wxMenu *menuTime = new wxMenu;
#if wxUSE_TIMEPICKCTRL_GENERIC
    menuTime->AppendCheckItem(Calendar_TimePicker_Generic,
                              "Use &generic version of the control");
    menuTime->AppendSeparator();
#endif // wxUSE_TIMEPICKCTRL_GENERIC
    menuTime->Append(Calendar_TimePicker_AskTime, "&Choose time...\tCtrl-T", "Show dialog with wxTimePickerCtrl");
    menuBar->Append(menuTime, "&Time picker");
#endif // wxUSE_TIMEPICKCTRL

    menuBar->Check(Calendar_Cal_AutoWeekday, true);
    menuBar->Check(Calendar_Cal_Sunday,      false);
    menuBar->Check(Calendar_Cal_Monday,      false);
    menuBar->Check(Calendar_Cal_Holidays,    true);
    menuBar->Check(Calendar_Cal_Month,       true);
    menuBar->Check(Calendar_Cal_LimitDates,  false);

#if wxUSE_DATEPICKCTRL
    menuBar->Check(Calendar_DatePicker_ShowCentury, true);
#endif // wxUSE_DATEPICKCTRL

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY,
                                            wxDefaultPosition, wxDefaultSize,
                                            wxSP_NOBORDER);
    m_panel = new Panel(splitter);
    m_logWindow = new wxTextCtrl(splitter, wxID_ANY, wxEmptyString,
                                 wxDefaultPosition, wxDefaultSize,
                                 wxTE_READONLY | wxTE_MULTILINE);
    splitter->SplitHorizontally(m_panel, m_logWindow);
    splitter->SetMinimumPaneSize(20);
    wxLog::SetActiveTarget(new wxLogTextCtrl(m_logWindow));
}

void Frame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
    wxMessageBox("wxCalendarCtrl sample\n(c) 2000--2008 Vadim Zeitlin",
                 "About Calendar", wxOK | wxICON_INFORMATION, this);
}

void Frame::OnClearLog(wxCommandEvent &WXUNUSED(event)) {
	m_logWindow->Clear();
}

void Frame::OnCalAutoWeekday(wxCommandEvent&) {
    m_panel->ToggleCalStyle(false, wxCAL_SUNDAY_FIRST);
    m_panel->ToggleCalStyle(false, wxCAL_MONDAY_FIRST);
}

void Frame::OnCalSunday(wxCommandEvent &event) {
    m_panel->ToggleCalStyle(false, wxCAL_MONDAY_FIRST);
    m_panel->ToggleCalStyle(event.IsChecked(), wxCAL_SUNDAY_FIRST);
}

void Frame::OnCalMonday(wxCommandEvent &event) {
    m_panel->ToggleCalStyle(false, wxCAL_SUNDAY_FIRST);
    m_panel->ToggleCalStyle(event.IsChecked(), wxCAL_MONDAY_FIRST);
}

void Frame::OnCalHolidays(wxCommandEvent &event) {
    m_panel->GetCal()->EnableHolidayDisplay(event.IsChecked());
}

void Frame::OnCalSpecial(wxCommandEvent &event) {
    m_panel->HighlightSpecial(GetMenuBar()->IsChecked(event.GetId()));
}

void Frame::OnCalLimitDates(wxCommandEvent &event) {
    m_panel->LimitDateRange(GetMenuBar()->IsChecked(event.GetId()));
}

void Frame::OnCalAllowMonth(wxCommandEvent &event) {
    m_panel->GetCal()->EnableMonthChange(event.IsChecked());
}

void Frame::OnCalSeqMonth(wxCommandEvent &event) {
    m_panel->ToggleCalStyle(event.IsChecked(),
                            wxCAL_SEQUENTIAL_MONTH_SELECTION);
}

void Frame::OnCalShowSurroundingWeeks(wxCommandEvent &event) {
    m_panel->ToggleCalStyle(event.IsChecked(), wxCAL_SHOW_SURROUNDING_WEEKS);
}

void Frame::OnCalShowWeekNumbers(wxCommandEvent &event) {
    m_panel->ToggleCalStyle(event.IsChecked(), wxCAL_SHOW_WEEK_NUMBERS);
}

void Frame::OnSetDate(wxCommandEvent &WXUNUSED(event)) {
    m_panel->SetDate(wxDateTime(24, wxDateTime::Dec, 2005, 22, 00, 00));
}

void Frame::OnToday(wxCommandEvent &WXUNUSED(event)) {
    m_panel->SetDate(wxDateTime::Today());
}

void Frame::OnBeginDST(wxCommandEvent &WXUNUSED(event)) {
    m_panel->SetDate(wxDateTime::GetBeginDST(m_panel->GetDate().GetYear()));
}

void Frame::OnCalToggleResizable(wxCommandEvent &event) {
    wxSizer * const sizer = m_panel->GetSizer();
    wxSizerItem * const item = sizer->GetItem(m_panel->GetCal());
    if(event.IsChecked()) {
        item->SetProportion(1);
        item->SetFlag(wxEXPAND);
    } else { // not resizable
        item->SetProportion(0);
        item->SetFlag(wxALIGN_CENTER);
    }
    sizer->Layout();
}

void Frame::OnCalRClick(wxMouseEvent &event) {
    wxDateTime dt;
    wxDateTime::WeekDay wd;

    const wxPoint pt = event.GetPosition();
    wxString msg = wxString::Format("Point (%d, %d) is ", pt.x, pt.y);

    switch(m_panel->GetCal()->HitTest(pt, &dt, &wd)) {
        default:
            wxFAIL_MSG( "unexpected" );
            wxFALLTHROUGH;
        case wxCAL_HITTEST_NOWHERE:
            msg += "nowhere";
            break;
        case wxCAL_HITTEST_HEADER:
            msg += wxString::Format("over %s", wxDateTime::GetWeekDayName(wd));
            break;
        case wxCAL_HITTEST_DAY:
            msg += wxString::Format("over %s", dt.FormatISODate());
            break;
        case wxCAL_HITTEST_INCMONTH:
            msg += "over next month button";
            break;
        case wxCAL_HITTEST_DECMONTH:
            msg += "over previous month button";
            break;
        case wxCAL_HITTEST_SURROUNDING_WEEK:
            msg += "over a day from another month";
            break;
    }
    wxLogMessage("%s", msg);
}

#if wxUSE_DATEPICKCTRL

void Frame::OnUpdateUIStartWithNone(wxUpdateUIEvent& event){
    // it only makes sense to start with invalid date if we can have no date
    event.Enable( GetMenuBar()->IsChecked(Calendar_DatePicker_AllowNone) );
}

void Frame::OnAskDate(wxCommandEvent& WXUNUSED(event)){
    wxDateTime dt = m_panel->GetCal()->GetDate();

    int style = wxDP_DEFAULT;
    if(GetMenuBar()->IsChecked(Calendar_DatePicker_ShowCentury) )
        style |= wxDP_SHOWCENTURY;
    if(GetMenuBar()->IsChecked(Calendar_DatePicker_DropDown) )
        style |= wxDP_DROPDOWN;
    if(GetMenuBar()->IsChecked(Calendar_DatePicker_AllowNone) ) {
        style |= wxDP_ALLOWNONE;

        if(GetMenuBar()->IsChecked(Calendar_DatePicker_StartWithNone) )
            dt = wxDefaultDateTime;
    }

    DateDialog dlg(this, dt, style);
    if(dlg.ShowModal() == wxID_OK) {
        dt = dlg.GetDate();
        if(dt.IsValid()) {
            const wxDateTime today = wxDateTime::Today();

            if(dt.GetDay()==today.GetDay() && dt.GetMonth()==today.GetMonth())
                wxMessageBox("Happy birthday!", "Calendar Sample");
            m_panel->SetDate(dt);

            wxLogStatus("Changed the date to your input");
        }
        else
            wxLogStatus("No date entered");
    }
}

#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL

void Frame::OnAskTime(wxCommandEvent& WXUNUSED(event)) {
    TimeDialog dlg(this);
    if(dlg.ShowModal() == wxID_OK)
        wxLogMessage("You entered %s", dlg.GetTime().FormatISOTime());
}

#endif // wxUSE_TIMEPICKCTRL

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------
// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(Calendar_File_About,    Frame::OnAbout)
    EVT_MENU(Calendar_File_ClearLog, Frame::OnClearLog)
    EVT_MENU(Calendar_File_Quit,     Frame::OnQuit)

#if wxUSE_DATEPICKCTRL
    EVT_MENU(Calendar_DatePicker_AskDate, Frame::OnAskDate)
    EVT_UPDATE_UI(Calendar_DatePicker_StartWithNone, Frame::OnUpdateUIStartWithNone)
#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL
    EVT_MENU(Calendar_TimePicker_AskTime, Frame::OnAskTime)
#endif // wxUSE_TIMEPICKCTRL

#ifdef wxHAS_NATIVE_CALENDARCTRL
    EVT_MENU(Calendar_Cal_Generic, Frame::OnCalGeneric)
#endif // wxHAS_NATIVE_CALENDARCTRL

    EVT_MENU(Calendar_Cal_AutoWeekday, Frame::OnCalAutoWeekday)
    EVT_MENU(Calendar_Cal_Sunday,      Frame::OnCalSunday)
    EVT_MENU(Calendar_Cal_Monday,      Frame::OnCalMonday)
    EVT_MENU(Calendar_Cal_Holidays,    Frame::OnCalHolidays)
    EVT_MENU(Calendar_Cal_Special,     Frame::OnCalSpecial)
    EVT_MENU(Calendar_Cal_Month,       Frame::OnCalAllowMonth)
    EVT_MENU(Calendar_Cal_LimitDates,  Frame::OnCalLimitDates)
    EVT_MENU(Calendar_Cal_SeqMonth,      Frame::OnCalSeqMonth)
    EVT_MENU(Calendar_Cal_SurroundWeeks, Frame::OnCalShowSurroundingWeeks)
    EVT_MENU(Calendar_Cal_WeekNumbers,   Frame::OnCalShowWeekNumbers)
    EVT_MENU(Calendar_Cal_SetDate,    Frame::OnSetDate)
    EVT_MENU(Calendar_Cal_Today,      Frame::OnToday)
    EVT_MENU(Calendar_Cal_BeginDST,   Frame::OnBeginDST)
    EVT_MENU(Calendar_Cal_Resizable,  Frame::OnCalToggleResizable)
    EVT_UPDATE_UI(Calendar_Cal_SeqMonth, Frame::OnUpdateUIGenericOnly)

#ifdef __WXGTK20__
    EVT_UPDATE_UI(Calendar_Cal_AutoWeekday, Frame::OnUpdateUIGenericOnly)
    EVT_UPDATE_UI(Calendar_Cal_Sunday,      Frame::OnUpdateUIGenericOnly)
    EVT_UPDATE_UI(Calendar_Cal_Monday,      Frame::OnUpdateUIGenericOnly)
    EVT_UPDATE_UI(Calendar_Cal_Holidays,    Frame::OnUpdateUIGenericOnly)
#endif
    EVT_UPDATE_UI(Calendar_Cal_Special, Frame::OnUpdateUIGenericOnly)
    EVT_UPDATE_UI(Calendar_Cal_SurroundWeeks, Frame::OnUpdateUIGenericOnly)
wxEND_EVENT_TABLE()

