#include "frame.h"

// My frame constructor
Frame::Frame()
       : wxFrame(NULL, wxID_ANY, wxT("wxCollapsiblePane sample"),
                 wxDefaultPosition, wxSize(420, 300),
                 wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE)
{
    SetIcon(wxICON(sample));

#if wxUSE_STATUSBAR
    CreateStatusBar(2);
#endif // wxUSE_STATUSBAR

    // Make a menubar
    wxMenu *paneMenu = new wxMenu;
    paneMenu->Append(PANE_COLLAPSE, wxT("Collapse\tCtrl-C"));
    paneMenu->Append(PANE_EXPAND,   wxT("Expand\tCtrl-E"));
    paneMenu->AppendSeparator();
    paneMenu->Append(PANE_SETLABEL, wxT("Set label...\tCtrl-L"));
    paneMenu->AppendSeparator();
    paneMenu->Append(PANE_SHOWDLG,  wxT("Show dialog...\tCtrl-S"));
    paneMenu->AppendSeparator();
    paneMenu->Append(PANE_QUIT);

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(PANE_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(paneMenu, wxT("&Pane"));
    menuBar->Append(helpMenu, wxT("&Help"));
    SetMenuBar(menuBar);

    m_collPane = new wxCollapsiblePane(this, -1, wxT("test!"));
    wxWindow *win = m_collPane->GetPane();

    m_paneSizer = new wxBoxSizer( wxHORIZONTAL );
    wxBoxSizer* paneSubSizer = new wxBoxSizer( wxVERTICAL );
    m_paneSizer->AddSpacer( 20 );
    m_paneSizer->Add( paneSubSizer, 1 );

    paneSubSizer->Add( new wxStaticText(win, -1, wxT("Static text") ), 0, wxALIGN_LEFT | wxALL, 3 );
    paneSubSizer->Add( new wxStaticText(win, -1, wxT("Yet another one!") ), 0, wxALIGN_LEFT | wxALL, 3 );
    paneSubSizer->Add( new wxTextCtrl( win, PANE_TEXTCTRL, wxT("Text control"), wxDefaultPosition, wxSize(80,-1) ), 0, wxALIGN_LEFT | wxALL, 3 );
    paneSubSizer->Add( new wxButton(   win, PANE_BUTTON, wxT("Press to align right") ), 0, wxALIGN_LEFT | wxALL, 3 );

    win->SetSizer( m_paneSizer );
}
// menu command handlers
void Frame::OnCollapse(wxCommandEvent& WXUNUSED(event)) {
    m_collPane->Collapse();
}

void Frame::OnExpand(wxCommandEvent &WXUNUSED(event)) {
    m_collPane->Expand();
}

void Frame::OnSetLabel(wxCommandEvent &WXUNUSED(event)) {
    wxString text = wxGetTextFromUser(
                        wxT("Enter new label"),
                        wxGetTextFromUserPromptStr,
                        m_collPane->GetLabel());
    m_collPane->SetLabel(text);
}

void Frame::OnShowDialog(wxCommandEvent &WXUNUSED(event)) {
    Dialog dlg(this);
    dlg.ShowModal();
}

void Frame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
    wxAboutDialogInfo info;
    info.SetName(_("wxCollapsiblePane sample"));
    info.SetDescription(_("This sample program demonstrates usage of wxCollapsiblePane"));
    info.SetCopyright(wxT("(C) 2006 Francesco Montorsi <frm@users.sourceforge.net>"));

    wxAboutBox(info);
}

void Frame::OnCollapseUpdateUI(wxUpdateUIEvent& event) {
    event.Enable(!m_collPane->IsCollapsed());
}

void Frame::OnExpandUpdateUI(wxUpdateUIEvent& event) {
    event.Enable(m_collPane->IsCollapsed());
}
// --------------------------------------------------------
// MyDialog
// --------------------------------------------------------
Dialog::Dialog(wxFrame *parent)
                : wxDialog(parent, wxID_ANY, wxT("Test dialog"),
                            wxDefaultPosition, wxDefaultSize,
                            wxRESIZE_BORDER|wxDEFAULT_DIALOG_STYLE )
{
    wxSizer *sz = new wxBoxSizer(wxVERTICAL);
    sz->Add(new wxStaticText(this, -1,
        wxT("This dialog allows you to test the wxCollapsiblePane control")),
        0, wxALL, 5);
    sz->Add(new wxButton(this, PANEDLG_TOGGLESTATUS_BTN, wxT("Change status")),
        1, wxGROW|wxALL, 5);

    m_collPane = new wxCollapsiblePane(this, -1, wxT("Click here for a surprise"));
    sz->Add(m_collPane, 0, wxGROW|wxALL, 5);
    sz->Add(new wxTextCtrl(this, -1, wxT("just a test")), 0, wxGROW|wxALL, 5);
    sz->AddSpacer(10);
    sz->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT|wxALL, 5);

    // now add test controls in the collapsible pane
    wxWindow *win = m_collPane->GetPane();
    m_paneSizer = new wxGridSizer(4, 1, 5, 5);

    m_paneSizer->Add( new wxStaticText(win, -1, wxT("Static text") ), 0, wxALIGN_LEFT );
    m_paneSizer->Add( new wxStaticText(win, -1, wxT("Yet another one!") ), 0, wxALIGN_LEFT );
    m_paneSizer->Add( new wxTextCtrl(win, PANE_TEXTCTRL, wxT("Text control"), wxDefaultPosition, wxSize(80,-1) ), 0, wxALIGN_LEFT );
    m_paneSizer->Add( new wxButton(win, PANE_BUTTON, wxT("Press to align right") ), 0, wxALIGN_LEFT );
    win->SetSizer( m_paneSizer );

    win->SetSizer( m_paneSizer );
    m_paneSizer->SetSizeHints(win);

    SetSizer(sz);
    sz->SetSizeHints(this);
}

void Dialog::OnToggleStatus(wxCommandEvent& WXUNUSED(ev)) {
    m_collPane->Collapse(!m_collPane->IsCollapsed());
}

void Dialog::OnAlignButton(wxCommandEvent& WXUNUSED(ev)) {
   wxSizerItem *item = m_paneSizer->GetItem( FindWindow(PANE_TEXTCTRL), true );
   item->SetFlag(  wxALIGN_RIGHT );

   Layout();
}

void Dialog::OnPaneChanged(wxCollapsiblePaneEvent& event) {
    wxLogMessage(wxT("The pane has just been %s by the user"),
               event.GetCollapsed() ? wxT("collapsed") : wxT("expanded"));
}

// **************<<_FRAME EVENT TABLE_>>********************
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(PANE_COLLAPSE, Frame::OnCollapse)
    EVT_MENU(PANE_EXPAND,   Frame::OnExpand)
    EVT_MENU(PANE_SETLABEL, Frame::OnSetLabel)
    EVT_MENU(PANE_SHOWDLG,  Frame::OnShowDialog)
    EVT_MENU(PANE_ABOUT,    Frame::OnAbout)
    EVT_MENU(PANE_QUIT,     Frame::Quit)

    EVT_UPDATE_UI(PANE_COLLAPSE, Frame::OnCollapseUpdateUI)
    EVT_UPDATE_UI(PANE_EXPAND,   Frame::OnExpandUpdateUI)
wxEND_EVENT_TABLE()
// **************<<_DIALOG EVENT TABLE_>>********************
wxBEGIN_EVENT_TABLE(Dialog, wxDialog)
    EVT_BUTTON(PANEDLG_TOGGLESTATUS_BTN,  Dialog::OnToggleStatus)
    EVT_COLLAPSIBLEPANE_CHANGED(wxID_ANY, Dialog::OnPaneChanged)
    EVT_BUTTON(PANE_BUTTON, Dialog::OnAlignButton)
wxEND_EVENT_TABLE()

