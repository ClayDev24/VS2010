#include "frame.h"
// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------
Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size, long style)
       : wxFrame(NULL, wxID_ANY, title, pos, size, style)
{
    // set the frame icon
    SetIcon(wxICON(sample));

#if wxUSE_MENUS
    // create a menu bar
    wxMenu *menuDisplay = new wxMenu;
    menuDisplay->Append(Display_FromPoint, _("Find from &point..."));
    menuDisplay->AppendSeparator();
    menuDisplay->AppendCheckItem(Display_FullScreen, _("Full &screen\tF12"));
    menuDisplay->AppendSeparator();
    menuDisplay->Append(Display_Quit, _("E&xit\tAlt-X"), _("Quit this program"));

    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(Display_About, _("&About\tF1"), _("Show about dialog"));

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuDisplay, _("&Display"));
    menuBar->Append(helpMenu, _("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create status bar
    CreateStatusBar();
#endif // wxUSE_STATUSBAR
    // create child controls
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    m_book = new wxBookCtrl(panel, wxID_ANY);
    const size_t count = wxDisplay::GetCount();
    for(size_t nDpy = 0; nDpy < count; nDpy++) {
        wxDisplay display(nDpy);

        wxWindow *page = new wxPanel(m_book, wxID_ANY);

        // create 2 column flex grid sizer with growable 2nd column
        wxFlexGridSizer *sizer = new wxFlexGridSizer(2, 10, 20);
        sizer->AddGrowableCol(1);

        const wxRect r(display.GetGeometry());
        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("Origin: ")));
        sizer->Add(new wxStaticText
                       (page,
                        wxID_ANY,
                        wxString::Format(wxT("(%d, %d)"),
                                         r.x, r.y)));

        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("Size: ")));
        sizer->Add(new wxStaticText(
                        page,
                        wxID_ANY,
                        wxString::Format(wxT("(%d, %d)"),
                                         r.width, r.height)));

        const wxRect rc(display.GetClientArea());
        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("Client area: ")));
        sizer->Add(new wxStaticText(
                        page,
                        wxID_ANY,
                        wxString::Format(wxT("(%d, %d)-(%d, %d)"),
                                         rc.x, rc.y, rc.width, rc.height)));

        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("Name: ")));
        sizer->Add(new wxStaticText(page, wxID_ANY, display.GetName()));

        wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
        sizerTop->Add(sizer, 1, wxALL | wxEXPAND, 10);

#if wxUSE_DISPLAY
        wxChoice *choiceModes = new wxChoice(page, Display_ChangeMode);
        const wxArrayVideoModes modes = display.GetModes();
        const size_t count = modes.GetCount();
        for(size_t nMode = 0; nMode < count; nMode++) {
            const wxVideoMode& mode = modes[nMode];

            choiceModes->Append(VideoModeToText(mode),
                                new VideoModeClientData(mode));
        }

        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("&Modes: ")));
        sizer->Add(choiceModes, 0, wxEXPAND);

        sizer->Add(new wxStaticText(page, wxID_ANY, wxT("Current: ")));
        sizer->Add(new wxStaticText(page, Display_CurrentMode,
                                    VideoModeToText(display.GetCurrentMode())));

        // add it to another sizer to have borders around it and button below
        sizerTop->Add(new wxButton(page, Display_ResetMode, wxT("&Reset mode")),
                      0, wxALL | wxCENTRE, 5);
#endif // wxUSE_DISPLAY

        page->SetSizer(sizerTop);
        m_book->AddPage(page, wxString::Format(wxT("Display %lu"), (unsigned long)nDpy));
    }
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(m_book, 1, wxEXPAND);
    panel->SetSizer(sizer);
    sizer->SetSizeHints(this);
}

#if wxUSE_DISPLAY

wxString Frame::VideoModeToText(const wxVideoMode &mode) {
    wxString s;
    s.Printf(wxT("%dx%d"), mode.w, mode.h);

    if(mode.bpp)
        s += wxString::Format(wxT(", %dbpp"), mode.bpp);
    if(mode.refresh)
        s += wxString::Format(wxT(", %dHz"), mode.refresh);
    return s;
}

#endif // wxUSE_DISPLAY

// event handlers
void Frame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
    wxMessageBox(wxT("Demo program for wxDisplay class.\n\n(c) 2003-2006 Vadim Zeitlin"),
                 wxT("About Display Sample"),
                 wxOK | wxICON_INFORMATION,
                 this);
}

void Frame::OnFromPoint(wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_STATUSBAR
    SetStatusText(wxT("Press the mouse anywhere..."));
#endif // wxUSE_STATUSBAR

    CaptureMouse();
}

void Frame::OnFullScreen(wxCommandEvent &event) {
    ShowFullScreen(event.IsChecked());
}

#if wxUSE_DISPLAY

void Frame::OnChangeMode(wxCommandEvent &event) {
    wxDisplay dpy(m_book->GetSelection());

    // you wouldn't write this in real code, would you?
    if(!dpy.ChangeMode(((VideoModeClientData *)
                wxDynamicCast(event.GetEventObject(), wxChoice)->
                    GetClientObject(event.GetInt()))->mode)) {
        wxLogError(wxT("Changing video mode failed!"));
    }
}

void Frame::OnResetMode(wxCommandEvent &WXUNUSED(event)) {
    wxDisplay dpy(m_book->GetSelection());

    dpy.ResetMode();
}

#endif // wxUSE_DISPLAY

void Frame::OnLeftClick(wxMouseEvent &event) {
    if(HasCapture()) {
        // mouse events are in client coords, wxDisplay works in screen ones
        const wxPoint ptScreen = ClientToScreen(event.GetPosition());
        int dpy = wxDisplay::GetFromPoint(ptScreen);
        if(dpy == wxNOT_FOUND) {
            wxLogError(wxT("Mouse clicked outside of display!?"));
        }
        wxLogStatus(this, wxT("Mouse clicked in display %d (at (%d, %d))"), dpy, ptScreen.x, ptScreen.y);
        ReleaseMouse();
    }
}

#if wxUSE_DISPLAY

void Frame::OnDisplayChanged(wxDisplayChangedEvent &event) {
    // update the current mode text
    for(size_t n = 0; n < m_book->GetPageCount(); n++) {
        wxStaticText *label = wxDynamicCast(m_book->GetPage(n)->FindWindow(Display_CurrentMode), wxStaticText);
        if(label)
            label->SetLabel(VideoModeToText(wxDisplay(n).GetCurrentMode()));
    }
    wxLogStatus(this, wxT("Display resolution was changed."));
    event.Skip();
}

#endif // wxUSE_DISPLAY

