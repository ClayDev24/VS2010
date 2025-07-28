#pragma once
#include "IDs.h"
//********************<<_PANEL_>>************************
wxBEGIN_EVENT_TABLE(Panel, wxPanel)
EVT_IDLE      (                        Panel::OnIdle)
EVT_BOOKCTRL_PAGE_CHANGING(ID_BOOK,    Panel::OnPageChanging)
EVT_BOOKCTRL_PAGE_CHANGED(ID_BOOK,     Panel::OnPageChanged)
EVT_LISTBOX   (ID_LISTBOX,             Panel::OnListBox)
EVT_LISTBOX   (ID_LISTBOX_SORTED,      Panel::OnListBox)
EVT_LISTBOX_DCLICK(ID_LISTBOX,         Panel::OnListBoxDoubleClick)
EVT_BUTTON    (ID_LISTBOX_SEL_NUM,     Panel::OnListBoxButtons)
EVT_BUTTON    (ID_LISTBOX_SEL_STR,     Panel::OnListBoxButtons)
EVT_BUTTON    (ID_LISTBOX_CLEAR,       Panel::OnListBoxButtons)
EVT_BUTTON    (ID_LISTBOX_APPEND,      Panel::OnListBoxButtons)
EVT_BUTTON    (ID_LISTBOX_DELETE,      Panel::OnListBoxButtons)
EVT_BUTTON    (ID_LISTBOX_FONT,        Panel::OnListBoxButtons)
EVT_CHECKBOX  (ID_LISTBOX_ENABLE,      Panel::OnListBoxButtons)
#if wxUSE_CHOICE
EVT_CHOICE    (ID_CHOICE,              Panel::OnChoice)
EVT_CHOICE    (ID_CHOICE_SORTED,       Panel::OnChoice)
EVT_BUTTON    (ID_CHOICE_SEL_NUM,      Panel::OnChoiceButtons)
EVT_BUTTON    (ID_CHOICE_SEL_STR,      Panel::OnChoiceButtons)
EVT_BUTTON    (ID_CHOICE_CLEAR,        Panel::OnChoiceButtons)
EVT_BUTTON    (ID_CHOICE_APPEND,       Panel::OnChoiceButtons)
EVT_BUTTON    (ID_CHOICE_DELETE,       Panel::OnChoiceButtons)
EVT_BUTTON    (ID_CHOICE_FONT,         Panel::OnChoiceButtons)
EVT_CHECKBOX  (ID_CHOICE_ENABLE,       Panel::OnChoiceButtons)
#endif
EVT_COMBOBOX  (ID_COMBO,               Panel::OnCombo)
EVT_TEXT      (ID_COMBO,               Panel::OnComboTextChanged)
EVT_TEXT_ENTER(ID_COMBO,               Panel::OnComboTextEnter)
EVT_BUTTON    (ID_COMBO_SEL_NUM,       Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_SEL_STR,       Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_CLEAR,         Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_APPEND,        Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_DELETE,        Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_FONT,          Panel::OnComboButtons)
EVT_BUTTON    (ID_COMBO_SET_TEXT,      Panel::OnComboButtons)
EVT_CHECKBOX  (ID_COMBO_ENABLE,        Panel::OnComboButtons)
EVT_RADIOBOX  (ID_RADIOBOX,            Panel::OnRadio)
EVT_RADIOBOX  (ID_RADIOBOX2,           Panel::OnRadio)
EVT_BUTTON    (ID_RADIOBOX_SEL_NUM,    Panel::OnRadioButtons)
EVT_BUTTON    (ID_RADIOBOX_SEL_STR,    Panel::OnRadioButtons)
EVT_BUTTON    (ID_RADIOBOX_FONT,       Panel::OnRadioButtons)
EVT_CHECKBOX  (ID_RADIOBOX_ENABLE,     Panel::OnRadioButtons)
EVT_RADIOBUTTON(ID_RADIOBUTTON_1,      Panel::OnRadioButton1)
EVT_RADIOBUTTON(ID_RADIOBUTTON_2,      Panel::OnRadioButton2)
EVT_BUTTON    (ID_SET_FONT,            Panel::OnSetFont)
#if wxUSE_SLIDER
EVT_SLIDER    (ID_SLIDER,              Panel::OnSliderUpdate)
#endif // wxUSE_SLIDER
#if wxUSE_SPINBTN
EVT_SPIN      (ID_SPIN,                Panel::OnSpinUpdate)
EVT_SPIN_UP   (ID_SPIN,                Panel::OnSpinUp)
EVT_SPIN_DOWN (ID_SPIN,                Panel::OnSpinDown)
#if wxUSE_PROGRESSDLG
EVT_UPDATE_UI (ID_BTNPROGRESS,         Panel::OnUpdateShowProgress)
EVT_BUTTON    (ID_BTNPROGRESS,         Panel::OnShowProgress)
#endif // wxUSE_PROGRESSDLG
#endif // wxUSE_SPINBTN
#if wxUSE_SPINCTRL
EVT_SPINCTRL  (ID_SPINCTRL,            Panel::OnSpinCtrl)
EVT_SPIN_UP   (ID_SPINCTRL,            Panel::OnSpinCtrlUp)
EVT_SPIN_DOWN (ID_SPINCTRL,            Panel::OnSpinCtrlDown)
EVT_TEXT      (ID_SPINCTRL,            Panel::OnSpinCtrlText)
#endif // wxUSE_SPINCTRL
EVT_BUTTON    (ID_BTNNEWTEXT,          Panel::OnNewText)
EVT_TOGGLEBUTTON(ID_BUTTON_LABEL,      Panel::OnUpdateLabel)
EVT_CHECKBOX  (ID_CHANGE_COLOUR,       Panel::OnChangeColour)
EVT_BUTTON    (ID_BUTTON_TEST1,        Panel::OnTestButton)
EVT_BUTTON    (ID_BUTTON_TEST2,        Panel::OnTestButton)
EVT_BUTTON    (ID_BITMAP_BTN,          Panel::OnBmpButton)
EVT_TOGGLEBUTTON(ID_BITMAP_BTN_ENABLE, Panel::OnBmpButtonToggle)

EVT_CHECKBOX  (ID_SIZER_CHECK1,        Panel::OnSizerCheck)
EVT_CHECKBOX  (ID_SIZER_CHECK2,        Panel::OnSizerCheck)
EVT_CHECKBOX  (ID_SIZER_CHECK3,        Panel::OnSizerCheck)
EVT_CHECKBOX  (ID_SIZER_CHECK4,        Panel::OnSizerCheck)
EVT_CHECKBOX  (ID_SIZER_CHECK14,       Panel::OnSizerCheck)
EVT_CHECKBOX  (ID_SIZER_CHECKBIG,      Panel::OnSizerCheck)

wxEND_EVENT_TABLE()
//*******************<<_BUTTON_>>************************
wxBEGIN_EVENT_TABLE(Button, wxButton)
    EVT_LEFT_DCLICK(Button::OnDClick)
wxEND_EVENT_TABLE()
//******************<<_COMBO_BOX_>>**********************
wxBEGIN_EVENT_TABLE(ComboBox, wxComboBox)
    EVT_CHAR(    ComboBox::OnChar)
    EVT_KEY_DOWN(ComboBox::OnKeyDown)
    EVT_KEY_UP(  ComboBox::OnKeyUp)

    EVT_SET_FOCUS(ComboBox::OnFocusGot)
wxEND_EVENT_TABLE()
//******************<<_RADIOBOX_>>***********************
wxBEGIN_EVENT_TABLE(RadioBox, wxRadioBox)
    EVT_SET_FOCUS(  RadioBox::OnFocusGot)
    EVT_KILL_FOCUS( RadioBox::OnFocusLost)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(Choice, wxChoice)
    EVT_SET_FOCUS(  Choice::OnFocusGot)
    EVT_KILL_FOCUS( Choice::OnFocusLost)
wxEND_EVENT_TABLE()
//********************<<_CFrame_>>************************
wxBEGIN_EVENT_TABLE(CFrame, wxFrame)
    EVT_MENU(CONTROLS_QUIT,      CFrame::OnQuit)
    EVT_MENU(CONTROLS_ABOUT,     CFrame::OnAbout)
    EVT_MENU(CONTROLS_CLEAR_LOG, CFrame::OnClearLog)
#if wxUSE_TOOLTIPS
    EVT_MENU(CONTROLS_SET_TOOLTIP_DELAY,  CFrame::OnSetTooltipDelay)
    EVT_MENU(CONTROLS_ENABLE_TOOLTIPS,    CFrame::OnToggleTooltips)
#ifdef __WXMSW__
    EVT_MENU(CONTROLS_SET_TOOLTIPS_MAX_WIDTH, CFrame::OnSetMaxTooltipWidth)
#endif // __WXMSW__
#endif // wxUSE_TOOLTIPS

    EVT_MENU(CONTROLS_ENABLE_ALL,   CFrame::OnEnableAll)
    EVT_MENU(CONTROLS_HIDE_ALL,     CFrame::OnHideAll)
    EVT_MENU(CONTROLS_HIDE_LIST,    CFrame::OnHideList)
    EVT_MENU(CONTROLS_CONTEXT_HELP, CFrame::OnContextHelp)

    EVT_MAXIMIZE(CFrame::OnMaximized)
	EVT_ICONIZE( CFrame::OnIconized)
    EVT_SIZE(    CFrame::OnSize)
    EVT_MOVE(    CFrame::OnMove)
    EVT_IDLE(    CFrame::OnIdle)
wxEND_EVENT_TABLE()
