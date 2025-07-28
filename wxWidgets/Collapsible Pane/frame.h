#pragma once
#include "../_Framework/headers.h"
#include "wx/collpane.h"
#include "wx/stattext.h"
#include "IDs.h"

class Frame: public wxFrame {
    wxCollapsiblePane *m_collPane;
    wxBoxSizer        *m_paneSizer;

public:
    Frame();
	virtual ~Frame() {};
    // Menu commands
    void OnCollapse(  wxCommandEvent &event);
    void OnExpand(    wxCommandEvent &event);
    void OnSetLabel(  wxCommandEvent &event);
    void OnShowDialog(wxCommandEvent &event);
	void Quit(        wxCommandEvent &event) { Close(true); }
    void OnAbout(     wxCommandEvent &event);
    // UI update handlers
    void OnCollapseUpdateUI(wxUpdateUIEvent &event);
    void OnExpandUpdateUI(  wxUpdateUIEvent &event);

private:
    wxDECLARE_NO_COPY_CLASS(Frame);
	wxDECLARE_EVENT_TABLE();
};

class Dialog : public wxDialog {
    wxCollapsiblePane *m_collPane;
    wxGridSizer       *m_paneSizer;
public:
    Dialog(wxFrame *parent);
    void OnToggleStatus(wxCommandEvent &WXUNUSED(ev));
    void OnAlignButton( wxCommandEvent &WXUNUSED(ev));
    void OnPaneChanged( wxCollapsiblePaneEvent &event);
private:
    wxDECLARE_EVENT_TABLE();
    wxDECLARE_NO_COPY_CLASS(Dialog);
};