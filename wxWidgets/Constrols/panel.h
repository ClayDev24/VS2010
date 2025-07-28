#pragma once
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#if wxUSE_SPINCTRL
    #include "wx/spinctrl.h"
#endif // wxUSE_SPINCTRL

#include "wx/spinbutt.h"
#include "wx/tglbtn.h"
#include "wx/bookctrl.h"
#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/gbsizer.h"

#include "IDs.h"
//----------------------------------------------------------------------
// MyPanel
//----------------------------------------------------------------------
class Panel: public wxPanel {
public:
    Panel(wxFrame *_frame, int x, int y, int w, int h);
    virtual ~Panel();

#if wxUSE_TOOLTIPS
    void SetAllToolTips();
#endif // wxUSE_TOOLTIPS

    void OnIdle( wxIdleEvent &event );
    void OnListBox( wxCommandEvent &event );
    void OnListBoxDoubleClick( wxCommandEvent &event );
    void OnListBoxButtons( wxCommandEvent &event );
#if wxUSE_CHOICE
    void OnChoice( wxCommandEvent &event );
    void OnChoiceButtons( wxCommandEvent &event );
#endif
    void OnCombo( wxCommandEvent &event );
    void OnComboTextChanged(wxCommandEvent &event );
    void OnComboTextEnter( wxCommandEvent &event );
    void OnComboButtons( wxCommandEvent  &event );
    void OnRadio(        wxCommandEvent  &event );
    void OnRadioButtons( wxCommandEvent  &event );
    void OnRadioButton1( wxCommandEvent  &event );
    void OnRadioButton2( wxCommandEvent  &event );
    void OnSetFont(      wxCommandEvent  &event );
    void OnPageChanged(  wxBookCtrlEvent &event );
    void OnPageChanging( wxBookCtrlEvent &event );
    void OnSliderUpdate( wxCommandEvent  &event );
    void OnUpdateLabel(  wxCommandEvent  &event );
#if wxUSE_SPINBTN
    void OnSpinUp(     wxSpinEvent &event );
    void OnSpinDown(   wxSpinEvent &event );
    void OnSpinUpdate( wxSpinEvent &event );
#if wxUSE_PROGRESSDLG
    void OnUpdateShowProgress( wxUpdateUIEvent& event );
    void OnShowProgress( wxCommandEvent &event );
#endif // wxUSE_PROGRESSDLG
#endif // wxUSE_SPINBTN
    void OnNewText( wxCommandEvent &event );
#if wxUSE_SPINCTRL
    void OnSpinCtrl(    wxSpinEvent   & event);
    void OnSpinCtrlUp(  wxSpinEvent   & event);
    void OnSpinCtrlDown(wxSpinEvent   & event);
    void OnSpinCtrlText(wxCommandEvent &event);
#endif // wxUSE_SPINCTRL

    void OnEnableAll(   wxCommandEvent   & event);
    void OnChangeColour(wxCommandEvent   & event);
    void OnTestButton(  wxCommandEvent   & event);
    void OnBmpButton(   wxCommandEvent   & event);
    void OnBmpButtonToggle(wxCommandEvent& event);

    void OnSizerCheck (wxCommandEvent &event);

    wxListBox     *m_listbox,
                  *m_listboxSorted;
#if wxUSE_CHOICE
    wxChoice      *m_choice,
                  *m_choiceSorted;
#endif // wxUSE_CHOICE

    wxComboBox    *m_combo;
    wxRadioBox    *m_radio;
#if wxUSE_GAUGE
    wxGauge       *m_gauge,
                  *m_gaugeVert;
#endif // wxUSE_GAUGE
#if wxUSE_SLIDER
    wxSlider      *m_slider;
#endif // wxUSE_SLIDER
    wxButton      *m_fontButton;
    wxButton      *m_lbSelectNum;
    wxButton      *m_lbSelectThis;
#if wxUSE_SPINBTN
    wxSpinButton  *m_spinbutton;
#if wxUSE_PROGRESSDLG
    wxButton      *m_btnProgress;
#endif // wxUSE_PROGRESSDLG
#endif // wxUSE_SPINBTN
    wxStaticText *m_wrappingText;
    wxStaticText *m_nonWrappingText;

#if wxUSE_SPINCTRL
    wxSpinCtrl   *m_spinctrl;
#endif // wxUSE_SPINCTRL

    wxTextCtrl   *m_spintext;
    wxCheckBox   *m_checkbox;

    wxTextCtrl   *m_text;
	wxBookCtrl   *m_book;

    wxStaticText *m_label;

    wxBoxSizer   *m_buttonSizer;
    wxButton     *m_sizerBtn1;
    wxButton     *m_sizerBtn2;
    wxButton     *m_sizerBtn3;
    wxButton     *m_sizerBtn4;
    wxBoxSizer   *m_hsizer;
    wxButton     *m_bigBtn;
private:
    wxLog *m_logTargetOld;

    wxDECLARE_EVENT_TABLE();
};