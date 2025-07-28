#include <wx/numdlg.h>
#include "frame.h"
#include "IDs.h"

CFrame::CFrame(const wxChar *title, int x, int y)
       : wxFrame(NULL, wxID_ANY, title, wxPoint(x, y), wxSize(700, 450))
{
    SetHelpText( wxT("Controls sample demonstrating various widgets") );
    // Give it an icon
    // The wxICON() macros loads an icon from a resource under Windows
    // and uses an #included XPM image under GTK+ and Motif

    SetIcon( wxICON(sample) );

    wxMenu *file_menu = new wxMenu;

    file_menu->Append(CONTROLS_CLEAR_LOG, wxT("&Clear log\tCtrl-L"));
    file_menu->AppendSeparator();
    file_menu->Append(CONTROLS_ABOUT, wxT("&About\tF1"));
    file_menu->AppendSeparator();
    file_menu->Append(CONTROLS_QUIT, wxT("E&xit\tAlt-X"), wxT("Quit controls sample"));

    wxMenuBar *menu_bar = new wxMenuBar;
    menu_bar->Append(file_menu, wxT("&File"));

#if wxUSE_TOOLTIPS
    wxMenu *tooltip_menu = new wxMenu;
    tooltip_menu->Append(CONTROLS_SET_TOOLTIP_DELAY, wxT("Set &delay\tCtrl-D"));
    tooltip_menu->AppendSeparator();
    tooltip_menu->Append(CONTROLS_ENABLE_TOOLTIPS, wxT("&Toggle tooltips\tCtrl-T"),
            wxT("enable/disable tooltips"), true);
    tooltip_menu->Check(CONTROLS_ENABLE_TOOLTIPS, true);
#ifdef __WXMSW__
    tooltip_menu->Append(CONTROLS_SET_TOOLTIPS_MAX_WIDTH, "Set maximal &width");
#endif // __WXMSW__
    menu_bar->Append(tooltip_menu, wxT("&Tooltips"));
#endif // wxUSE_TOOLTIPS

    wxMenu *panel_menu = new wxMenu;
    panel_menu->Append(CONTROLS_ENABLE_ALL, wxT("&Disable all\tCtrl-E"),
                       wxT("Enable/disable all panel controls"), true);
    panel_menu->Append(CONTROLS_HIDE_ALL, wxT("&Hide all\tCtrl-I"),
                       wxT("Show/hide thoe whole panel controls"), true);
    panel_menu->Append(CONTROLS_HIDE_LIST, wxT("Hide &list ctrl\tCtrl-S"),
                       wxT("Enable/disable all panel controls"), true);
    panel_menu->Append(CONTROLS_CONTEXT_HELP, wxT("&Context help...\tCtrl-H"),
                       wxT("Get context help for a control"));
    menu_bar->Append(panel_menu, wxT("&Panel"));

    SetMenuBar(menu_bar);

#if wxUSE_STATUSBAR
    CreateStatusBar(2);
#endif // wxUSE_STATUSBAR

    m_panel = new Panel( this, 10, 10, 300, 100 );
}

#if wxUSE_STATUSBAR
void CFrame::UpdateStatusBar(const wxPoint &pos, const wxSize &size) {
	if(m_frameStatusBar) {
		wxString msg;
		wxSize sizeAll = GetSize(),
			sizeCl     = GetClientSize();
		msg.Printf(_("pos=(%d, %d), size=%dx%d or %dx%d (client=%dx%d)"),
			pos.x, pos.y,
			size.x, size.y,
			sizeAll.x, sizeAll.y,
			sizeCl.x, sizeCl.y);
		SetStatusText(msg, 1);
	}
}
#endif // wxUSE_STATUSBAR

void CFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxBusyCursor bc;

    wxMessageDialog dialog(this, wxT("This is a control sample"), wxT("About Controls"), wxOK);
    dialog.ShowModal();
}

void CFrame::OnHideAll(wxCommandEvent& WXUNUSED(event)) {
    static bool s_show = true;
    s_show = !s_show;
    m_panel->Show(s_show);
}

void CFrame::OnHideList(wxCommandEvent& WXUNUSED(event)) {
    static bool s_show = true;
    s_show = !s_show;
    m_panel->m_listbox->Show(s_show);
}

void CFrame::OnMove(wxMoveEvent& event) {
#if wxUSE_STATUSBAR
    UpdateStatusBar(event.GetPosition(), GetSize());
#endif // wxUSE_STATUSBAR

    event.Skip();
}

void CFrame::OnIconized(wxIconizeEvent& event) {
    wxLogMessage(wxT("CFrame %s"), event.IsIconized() ? wxT("iconized") : wxT("restored"));
    event.Skip();
}

void CFrame::OnSize( wxSizeEvent& event ) {
#if wxUSE_STATUSBAR
    UpdateStatusBar(GetPosition(), event.GetSize());
#endif // wxUSE_STATUSBAR
    event.Skip();
}

void CFrame::OnEnableAll(wxCommandEvent& WXUNUSED(event)) {
    static bool s_enable = true;

    s_enable = !s_enable;
    m_panel->Enable(s_enable);
    static bool s_enableCheckbox = true;
    if(!s_enable) {
        // this is a test for correct behaviour of either enabling or disabling
        // a child when its parent is disabled: the checkbox should have the
        // correct state when the parent is enabled back
        m_panel->m_checkbox->Enable(s_enableCheckbox);
        s_enableCheckbox = !s_enableCheckbox;
    }
}

void CFrame::OnIdle( wxIdleEvent& WXUNUSED(event) ) {
    // track the window which has the focus in the status bar
    static wxWindow *s_windowFocus = NULL;
    wxWindow *focus = wxWindow::FindFocus();
    if ( focus != s_windowFocus ) {
        s_windowFocus = focus;

        wxString msg;
        if ( focus ) {
            msg.Printf(
                    "Focus: %s"
#ifdef __WXMSW__
                    ", HWND = %08x"
#endif
                    , s_windowFocus->GetName().c_str()
#ifdef __WXMSW__
                    , (unsigned)wxPtrToUInt(s_windowFocus->GetHWND())
#endif
                      );
        }
        else
            msg = wxT("No focus");

#if wxUSE_STATUSBAR
        SetStatusText(msg);
#endif // wxUSE_STATUSBAR
    }
}

#if wxUSE_TOOLTIPS
void CFrame::OnSetTooltipDelay(wxCommandEvent& WXUNUSED(event)) {
    static long s_delay = 5000;

    wxString delay;
    delay.Printf( wxT("%ld"), s_delay);

    delay = wxGetTextFromUser(wxT("Enter delay (in milliseconds)"),
            wxT("Set tooltip delay"),
            delay,
            this);
    if ( !delay )
        return; // cancelled

    wxSscanf(delay, wxT("%ld"), &s_delay);

    wxToolTip::SetDelay(s_delay);

    wxLogStatus(this, wxT("Tooltip delay set to %ld milliseconds"), s_delay);
}

void CFrame::OnToggleTooltips(wxCommandEvent& WXUNUSED(event)) {
    static bool s_enabled = true;

    s_enabled = !s_enabled;

    wxToolTip::Enable(s_enabled);

    wxLogStatus(this, wxT("Tooltips %sabled"), s_enabled ? wxT("en") : wxT("dis") );
}

#ifdef __WXMSW__

void CFrame::OnSetMaxTooltipWidth(wxCommandEvent& WXUNUSED(event)) {
    static int s_maxWidth = 0;

    wxNumberEntryDialog dlg(
                         this,
                         "Change maximal tooltip width",
                         "&Width in pixels:",
                         GetTitle(),
                         s_maxWidth,
                         -1,
                         600);
    if ( dlg.ShowModal() == wxID_CANCEL )
        return;

    s_maxWidth = dlg.GetValue();
    wxToolTip::SetMaxWidth(s_maxWidth);

    // we need to set the tooltip again to test the new width
    m_panel->SetAllToolTips();
}

#endif // __WXMSW__

#endif // wxUSE_TOOLTIPS