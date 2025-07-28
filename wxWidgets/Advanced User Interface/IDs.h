#pragma once
#include <wx/defs.h>

// IDs for the controls and the menu commands
enum {
    // menu items
    Calendar_File_About = wxID_ABOUT,
    Calendar_File_ClearLog = wxID_CLEAR,
    Calendar_File_Quit = wxID_EXIT,
    Calendar_Cal_Generic = 200,
    Calendar_Cal_AutoWeekday,
    Calendar_Cal_Sunday,
    Calendar_Cal_Monday,
    Calendar_Cal_Holidays,
    Calendar_Cal_Special,
    Calendar_Cal_Month,
    Calendar_Cal_LimitDates,
    Calendar_Cal_SeqMonth,
    Calendar_Cal_SurroundWeeks,
    Calendar_Cal_WeekNumbers,
    Calendar_Cal_SetDate,
    Calendar_Cal_Today,
    Calendar_Cal_BeginDST,
    Calendar_Cal_Resizable,
#if wxUSE_DATEPICKCTRL
    Calendar_DatePicker_AskDate = 300,
    Calendar_DatePicker_ShowCentury,
    Calendar_DatePicker_DropDown,
    Calendar_DatePicker_AllowNone,
    Calendar_DatePicker_StartWithNone,
#if wxUSE_DATEPICKCTRL_GENERIC
    Calendar_DatePicker_Generic,
#endif // wxUSE_DATEPICKCTRL_GENERIC
#endif // wxUSE_DATEPICKCTRL
#if wxUSE_TIMEPICKCTRL
    Calendar_TimePicker_AskTime = 400,
#if wxUSE_TIMEPICKCTRL_GENERIC
    Calendar_TimePicker_Generic,
#endif // wxUSE_TIMEPICKCTRL_GENERIC
#endif // wxUSE_TIMEPICKCTRL
    Calendar_CalCtrl = 1000
};