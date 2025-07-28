#pragma once
#include <wx/defs.h>
// -----------------------------------------------------------
// ID's
// -----------------------------------------------------------
enum {
    CONTROLS_QUIT  = wxID_EXIT,
    CONTROLS_ABOUT = wxID_ABOUT,
    CONTROLS_TEXT  = 100,
    CONTROLS_CLEAR_LOG,
    // tooltip menu
    CONTROLS_SET_TOOLTIP_DELAY = 200,
    CONTROLS_ENABLE_TOOLTIPS,
    CONTROLS_SET_TOOLTIPS_MAX_WIDTH,
    // panel menu
    CONTROLS_ENABLE_ALL,
    CONTROLS_HIDE_ALL,
    CONTROLS_HIDE_LIST,
    CONTROLS_CONTEXT_HELP
};

const int  ID_BOOK              = 1000;

const int  ID_LISTBOX           = 130;
const int  ID_LISTBOX_SEL_NUM   = 131;
const int  ID_LISTBOX_SEL_STR   = 132;
const int  ID_LISTBOX_CLEAR     = 133;
const int  ID_LISTBOX_APPEND    = 134;
const int  ID_LISTBOX_DELETE    = 135;
const int  ID_LISTBOX_FONT      = 136;
const int  ID_LISTBOX_ENABLE    = 137;
const int  ID_LISTBOX_SORTED    = 138;

const int  ID_CHOICE            = 120;
const int  ID_CHOICE_SEL_NUM    = 121;
const int  ID_CHOICE_SEL_STR    = 122;
const int  ID_CHOICE_CLEAR      = 123;
const int  ID_CHOICE_APPEND     = 124;
const int  ID_CHOICE_DELETE     = 125;
const int  ID_CHOICE_FONT       = 126;
const int  ID_CHOICE_ENABLE     = 127;
const int  ID_CHOICE_SORTED     = 128;

const int  ID_COMBO             = 140;
const int  ID_COMBO_SEL_NUM     = 141;
const int  ID_COMBO_SEL_STR     = 142;
const int  ID_COMBO_CLEAR       = 143;
const int  ID_COMBO_APPEND      = 144;
const int  ID_COMBO_DELETE      = 145;
const int  ID_COMBO_FONT        = 146;
const int  ID_COMBO_ENABLE      = 147;
const int  ID_COMBO_SET_TEXT    = 148;

const int  ID_RADIOBOX          = 160;
const int  ID_RADIOBOX_SEL_NUM  = 161;
const int  ID_RADIOBOX_SEL_STR  = 162;
const int  ID_RADIOBOX_FONT     = 163;
const int  ID_RADIOBOX_ENABLE   = 164;
const int  ID_RADIOBOX2         = 165;
const int  ID_RADIOBUTTON_1     = 166;
const int  ID_RADIOBUTTON_2     = 167;

const int  ID_SET_FONT          = 170;

#if wxUSE_SLIDER
const int  ID_SLIDER            = 181;
#endif // wxUSE_SLIDER

const int  ID_SPIN              = 182;
#if wxUSE_PROGRESSDLG
const int  ID_BTNPROGRESS       = 183;
#endif // wxUSE_PROGRESSDLG
const int  ID_BUTTON_LABEL      = 184;
const int  ID_SPINCTRL          = 185;
const int  ID_BTNNEWTEXT        = 186;

const int  ID_BUTTON_TEST1      = 190;
const int  ID_BUTTON_TEST2      = 191;
const int  ID_BITMAP_BTN        = 192;
const int  ID_BITMAP_BTN_ENABLE = 193;

const int  ID_CHANGE_COLOUR     = 200;

const int  ID_SIZER_CHECK1      = 201;
const int  ID_SIZER_CHECK2      = 202;
const int  ID_SIZER_CHECK3      = 203;
const int  ID_SIZER_CHECK4      = 204;
const int  ID_SIZER_CHECK14     = 205;
const int  ID_SIZER_CHECKBIG    = 206;