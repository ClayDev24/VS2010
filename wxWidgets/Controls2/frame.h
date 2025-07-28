#pragma once
#include <wx/frame.h>
#include "panel.h"

class CFrame: public wxFrame {
	Panel *m_panel;
#if wxUSE_STATUSBAR
    void UpdateStatusBar(const wxPoint &pos, const wxSize &size);
#endif // wxUSE_STATUSBAR
public:
    CFrame(const wxChar *title, int x, int y);

    void OnAbout(wxCommandEvent &event);
	inline void OnClearLog(wxCommandEvent &event) { m_panel->m_text->Clear(); }
	inline void OnQuit(    wxCommandEvent &event) { Close(true); }

#if wxUSE_TOOLTIPS
    void OnSetTooltipDelay(wxCommandEvent &event);
    void OnToggleTooltips( wxCommandEvent &event);
#ifdef __WXMSW__
    void OnSetMaxTooltipWidth(wxCommandEvent& event);
#endif // __WXMSW__
#endif // wxUSE_TOOLTIPS

    void OnEnableAll(wxCommandEvent &event);
    void OnHideAll(  wxCommandEvent &event);
    void OnHideList( wxCommandEvent &event);
	inline void OnContextHelp(wxCommandEvent &event) { wxContextHelp chelp(this); }
	inline void OnMaximized( wxMaximizeEvent &event) { wxLogMessage(wxT("CFrame maximized")); }

    void OnIdle( wxIdleEvent &event );
    void OnSize( wxSizeEvent &event );
    void OnMove( wxMoveEvent &event );
	void OnIconized( wxIconizeEvent &event );

    Panel *GetPanel() const { return m_panel; }
private:
    wxDECLARE_EVENT_TABLE();
};