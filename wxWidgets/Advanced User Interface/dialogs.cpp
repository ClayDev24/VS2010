#include "panel.h"
// --------------------------------------------------
// MyTimeDialog Implementation
// --------------------------------------------------
#if wxUSE_TIMEPICKCTRL

TimeDialog::TimeDialog(wxWindow *parent)
        : wxDialog(parent, wxID_ANY, wxString("Calendar: Choose time"))
{
    wxWindow *timePickerWindow = NULL;

#if wxUSE_TIMEPICKCTRL_GENERIC
    m_timePickerGeneric = NULL;
    m_timePicker = NULL;

    wxFrame *frame = (wxFrame *)wxGetTopLevelParent(parent);
    if(frame && frame->GetMenuBar()->IsChecked(Calendar_TimePicker_Generic)) {
        m_timePickerGeneric = new wxTimePickerCtrlGeneric(this, wxID_ANY);
        timePickerWindow    = m_timePickerGeneric;
    }
    else
#endif // wxUSE_TIMEPICKCTRL_GENERIC
    m_timePicker = new wxTimePickerCtrl(this, wxID_ANY);

    if(!timePickerWindow)
        timePickerWindow = m_timePicker;

    m_timeText = new wxStaticText(this, wxID_ANY, GetTime().FormatISOTime());

    const wxSizerFlags flags = wxSizerFlags().Centre().Border();
    wxFlexGridSizer *const sizerMain = new wxFlexGridSizer(2);
    sizerMain->Add(new wxStaticText(this, wxID_ANY, "Enter &time:"), flags);
    sizerMain->Add(timePickerWindow, flags);

    sizerMain->Add(new wxStaticText(this, wxID_ANY, "Time in ISO format:"),
                   flags);
    sizerMain->Add(m_timeText, flags);

    wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
    sizerTop->Add(sizerMain, flags);
    sizerTop->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL), flags);

    SetSizerAndFit(sizerTop);
}

void TimeDialog::OnTimeChange(wxDateEvent &event) {
    m_timeText->SetLabel(event.GetDate().FormatISOTime());
}

#endif // wxUSE_TIMEPICKCTRL

// --------------------------------------------------
// MyDateDialog Implementation
// --------------------------------------------------
#if wxUSE_DATEPICKCTRL

DateDialog::DateDialog(wxWindow *parent, const wxDateTime &dt, int dtpStyle)
        : wxDialog(parent, wxID_ANY, wxString("Calendar: Choose a date"))
{
    wxWindow *datePickerWindow = NULL;

#if wxUSE_DATEPICKCTRL_GENERIC
    m_datePickerGeneric = NULL;
    m_datePicker = NULL;

    wxFrame *frame = (wxFrame *)wxGetTopLevelParent(parent);
    if(frame && frame->GetMenuBar()->IsChecked(Calendar_DatePicker_Generic)) {
        m_datePickerGeneric = new wxDatePickerCtrlGeneric(this, wxID_ANY, dt,
                                                          wxDefaultPosition,
                                                          wxDefaultSize,
                                                          dtpStyle);
        m_datePickerGeneric->SetRange(wxDateTime(1, wxDateTime::Jan, 1900),
                                      wxDefaultDateTime);

        datePickerWindow = m_datePickerGeneric;
    }
    else
#endif // wxUSE_DATEPICKCTRL_GENERIC
    {
        m_datePicker = new wxDatePickerCtrl(this, wxID_ANY, dt,
                                            wxDefaultPosition, wxDefaultSize,
                                            dtpStyle);
        m_datePicker->SetRange(wxDateTime(1, wxDateTime::Jan, 1900),
                               wxDefaultDateTime);

        datePickerWindow = m_datePicker;
    }
    m_dateText = new wxStaticText(this, wxID_ANY,
                                  dt.IsValid() ? dt.FormatISODate()
                                               : wxString());

    const wxSizerFlags flags = wxSizerFlags().Centre().Border();
    wxFlexGridSizer* const sizerMain = new wxFlexGridSizer(2);
    sizerMain->Add(new wxStaticText(this, wxID_ANY, "Enter &date:"), flags);
    sizerMain->Add(datePickerWindow, flags);

    sizerMain->Add(new wxStaticText(this, wxID_ANY, "Date in ISO format:"),
                   flags);
    sizerMain->Add(m_dateText, flags);

    wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
    sizerTop->Add(sizerMain, flags);
    sizerTop->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL), flags);

    SetSizerAndFit(sizerTop);
}

void DateDialog::OnDateChange(wxDateEvent &event) {
    const wxDateTime dt = event.GetDate();
    if(dt.IsValid())
        m_dateText->SetLabel(dt.FormatISODate());
    else
        m_dateText->SetLabel(wxEmptyString);
}

#endif // wxUSE_DATEPICKCTRL

#if wxUSE_TIMEPICKCTRL
wxBEGIN_EVENT_TABLE(TimeDialog, wxDialog)
    EVT_TIME_CHANGED(wxID_ANY, TimeDialog::OnTimeChange)
wxEND_EVENT_TABLE()
#endif // wxUSE_TIMEPICKCTRL

#if wxUSE_DATEPICKCTRL
wxBEGIN_EVENT_TABLE(DateDialog, wxDialog)
    EVT_DATE_CHANGED(wxID_ANY, DateDialog::OnDateChange)
wxEND_EVENT_TABLE()
#endif // wxUSE_DATEPICKCTRL