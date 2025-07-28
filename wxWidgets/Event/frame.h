// For compilers that support precompilation, includes "wx/wx.h".
#include "../_Framework/headers.h"

#include <wx/statline.h>
#include <wx/log.h>
#include "IDs.h"

class EvtTestButton : public wxButton {
public:
    static long BUTTON_ID;
    EvtTestButton(wxWindow *parent, const wxString &label)
        : wxButton(parent, BUTTON_ID, label)
    {   // Add a dynamic handler for this button event to button itself
        Connect(wxEVT_BUTTON, wxCommandEventHandler(EvtTestButton::OnClickDynamicHandler));
    }
private:
    void OnClickDynamicHandler(wxCommandEvent &event) {
        wxLogMessage("Step 3 in \"How Events are Processed\":\n"
                     "Button::ownDynamicHandler");
        event.Skip();
    }
    void OnClickStaticHandler(wxCommandEvent &event) {
        wxLogMessage("Step 4 in \"How Events are Processed\":\n"
                     "Button::ownStaticHandler");
        event.Skip();
    }
    wxDECLARE_EVENT_TABLE();
};

	// Define a custom button used to highlight the events handling order
	long EvtTestButton::BUTTON_ID = wxNewId();
// Define a new frame type: this is going to be our main frame
class Frame : public wxFrame {
public:
    Frame(const wxString& title, const wxPoint &pos, const wxSize &size);
    virtual ~Frame();

    void OnQuit( wxCommandEvent &event) { Close(true); }
    void OnAbout(wxCommandEvent &event);
#ifdef wxHAS_EVENT_BIND
    void OnBind( wxCommandEvent &event);
#endif // wxHAS_EVENT_BIND
    void OnConnect(wxCommandEvent &event);
    void OnDynamic(wxCommandEvent &event);
    void OnPushEventHandler(wxCommandEvent &event);
    void OnPopEventHandler( wxCommandEvent &event);
    void OnTest(wxCommandEvent &event);

    void OnFireCustom(   wxCommandEvent &event);
    void OnProcessCustom(wxCommandEvent &event);

    void OnUpdateUIPop( wxUpdateUIEvent &event);

    // regular event handlers used to highlight the events handling order
    void OnClickDynamicHandlerFrame( wxCommandEvent &event);
    void OnClickDynamicHandlerButton(wxCommandEvent &event);
    void OnClickStaticHandlerFrame(  wxCommandEvent &event);

private:
    // symbolic names for the status bar fields
    enum {
        Status_Main = 0,
        Status_Dynamic,
        Status_Push
    };
    void UpdateDynamicStatus(bool on) {
#if wxUSE_STATUSBAR
        if(on) {
            SetStatusText("You can now use \"Dynamic\" item in the menu");
            SetStatusText("Dynamic: on", Status_Dynamic);
        } else {
            SetStatusText("You can no more use \"Dynamic\" item in the menu");
            SetStatusText("Dynamic: off", Status_Dynamic);
        }
#endif // wxUSE_STATUSBAR
    }

    // number of pushed event handlers
    unsigned m_nPush;
    // the button to whose event we connect dynamically
    wxButton *m_btnDynamic;
    // the button used to highlight the event handlers execution order
    EvtTestButton *m_testBtn;
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();
};

// Define a custom event handler
class EvtHandler : public wxEvtHandler {
	unsigned m_level;
public:
    EvtHandler(size_t level) { m_level = level; }

    void OnTest(wxCommandEvent& event) {
        wxLogMessage(wxT("This is the pushed test event handler #%u"), m_level);

        // if we don't skip the event, the other event handlers won't get it:
        // try commenting out this line and see what changes
        event.Skip();
    }
private:
    wxDECLARE_EVENT_TABLE();
};
// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------
Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
       : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetIcon(wxICON(sample));

    // init members
    m_nPush = 0;
    m_btnDynamic = NULL;

    // create a menu bar
    wxMenu *menuFile = new wxMenu;

    menuFile->Append(Event_About, wxT("&About\tCtrl-A"), wxT("Show about dialog"));
    menuFile->AppendSeparator();
	menuFile->Append(Event_Quit, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

    wxMenu *menuEvent = new wxMenu;
#ifdef wxHAS_EVENT_BIND
    menuEvent->AppendCheckItem(Event_Bind, "&Bind\tCtrl-B",
                               "Bind or unbind a dynamic event handler");
#endif // wxHAS_EVENT_BIND
    menuEvent->AppendCheckItem(Event_Connect, wxT("&Connect\tCtrl-C"),
                     wxT("Connect or disconnect the dynamic event handler"));
    menuEvent->Append(Event_Dynamic, wxT("&Dynamic event\tCtrl-D"),
                      wxT("Dynamic event sample - only works after Connect"));
    menuEvent->AppendSeparator();
    menuEvent->Append(Event_Push, wxT("&Push event handler\tCtrl-P"),
                      wxT("Push event handler for test event"));
    menuEvent->Append(Event_Pop, wxT("P&op event handler\tCtrl-O"),
                      wxT("Pop event handler for test event"));
    menuEvent->Append(Event_Test, wxT("Test event\tCtrl-T"),
                      wxT("Test event processed by pushed event handler"));
    menuEvent->AppendSeparator();
    menuEvent->Append(Event_Custom, wxT("Fire c&ustom event\tCtrl-U"),
                      wxT("Generate a custom event"));

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, wxT("&File"));
    menuBar->Append(menuEvent, wxT("&Event"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

#if wxUSE_STATUSBAR
    CreateStatusBar(3);
    SetStatusText(wxT("Welcome to wxWidgets event sample"));
    SetStatusText(wxT("Dynamic: off"), Status_Dynamic);
    SetStatusText(wxT("Push count: 0"), Status_Push);
#endif // wxUSE_STATUSBAR

    wxPanel * const panel = new wxPanel(this);
    wxSizer * const mainSizer = new wxBoxSizer(wxVERTICAL);
    wxSizer * const sizer = new wxBoxSizer(wxHORIZONTAL);
    const wxSizerFlags centreY(wxSizerFlags().Centre().Border());
    sizer->Add(new wxStaticText(panel, wxID_ANY,
        "This button will only work if its handler is dynamically connected"),
        centreY);
    m_btnDynamic = new wxButton(panel, Event_Dynamic, "&Dynamic button");
    sizer->Add(m_btnDynamic, centreY);

    mainSizer->Add(sizer, 1, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);

    m_testBtn = new EvtTestButton(panel, "Test Event Handlers Execution Order");

    // After being created, an instance of MyEvtTestButton already has its own
    // event handlers (see class definition);

    // Add a dynamic handler for this button event in the parent frame
    Connect(m_testBtn->GetId(), wxEVT_BUTTON,
            wxCommandEventHandler(Frame::OnClickDynamicHandlerFrame));

    // Bind a method of this frame (notice "this" argument!) to the button
    // itself
    m_testBtn->Connect(wxEVT_BUTTON,
                       wxCommandEventHandler(Frame::OnClickDynamicHandlerButton),
                       NULL, this);
    mainSizer->Add(m_testBtn);
    panel->SetSizer(mainSizer);
}

Frame::~Frame() {
    // we must pop any remaining event handlers to avoid memory leaks and crashes!
    while(m_nPush-- != 0)
        PopEventHandler(true /* delete handler */);
}

// ----------------------------------------------------------------------------
// standard event handlers
// ----------------------------------------------------------------------------
void Frame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
    wxMessageBox("Event sample shows different ways of using events\n"
                 "(c) 2001-2009 Vadim Zeitlin",
                 "About wxWidgets Event Sample",
                 wxOK | wxICON_INFORMATION, this);
}

void Frame::OnClickStaticHandlerFrame(wxCommandEvent &event) {
    wxLogMessage("Step 6, 4 in \"How Events are Processed\":\n"
                 "parentWin::StaticHandler_InFrameTable");
    event.Skip();
}
// ----------------------------------------------------------------------------
// dynamic event handling stuff
// ----------------------------------------------------------------------------
void Frame::OnClickDynamicHandlerFrame(wxCommandEvent &event) {
    wxLogMessage("Step 6, 3 in \"How Events are Processed\":\n"
                 "parentWin::DynamicHandler_InFrameTable");
    event.Skip();
}

void Frame::OnClickDynamicHandlerButton(wxCommandEvent &event) {
    wxLogMessage("Step 3 in \"How Events are Processed\":\n"
                 "parentWin::DynamicHandler_InButtonTable");
    event.Skip();
}

void Frame::OnDynamic(wxCommandEvent &event) {
    wxString origin;
    if(event.GetEventObject() == this)
        origin = "menu item";
    else if ( event.GetEventObject() == m_btnDynamic )
        origin = "button";
    else
        origin = "unknown event source";

    wxMessageBox (
        "This message box is shown from the dynamically connected "
        "event handler in response to event generated by " + origin,
        "wxWidgets Event Sample", wxOK | wxICON_INFORMATION, this
    );
}

#ifdef wxHAS_EVENT_BIND

void Frame::OnBind(wxCommandEvent &event) {
    if(event.IsChecked()) {
        // as we bind directly to the button, there is no need to use an id
        // here: the button will only ever get its own events
        m_btnDynamic->Bind(wxEVT_BUTTON, &Frame::OnDynamic,
                           this);
        // but we do need the id for the menu command as the frame gets all of
        // them
        Bind(wxEVT_MENU, &Frame::OnDynamic, this,
             Event_Dynamic);
    } else { // disconnect
        m_btnDynamic->Unbind(wxEVT_BUTTON, &Frame::OnDynamic, this);
        Unbind(wxEVT_MENU, &Frame::OnDynamic, this,
               Event_Dynamic);
    }
    UpdateDynamicStatus(event.IsChecked());
}

#endif // wxHAS_EVENT_BIND

void Frame::OnConnect(wxCommandEvent &event) {
    if(event.IsChecked()) {
        m_btnDynamic->Connect(wxID_ANY, wxEVT_BUTTON,
                              wxCommandEventHandler(Frame::OnDynamic),
                              NULL, this);
        Connect(Event_Dynamic, wxEVT_MENU,
                wxCommandEventHandler(Frame::OnDynamic));
    } else { // disconnect
        m_btnDynamic->Disconnect(wxID_ANY, wxEVT_BUTTON,
                                 wxCommandEventHandler(Frame::OnDynamic), NULL, this);
        Disconnect(Event_Dynamic, wxEVT_MENU,
                   wxCommandEventHandler(Frame::OnDynamic));
    }
    UpdateDynamicStatus(event.IsChecked());
}
// ----------------------------------------------------------------------------
// push/pop event handlers support
// ----------------------------------------------------------------------------
void Frame::OnPushEventHandler(wxCommandEvent &WXUNUSED(event)) {
    PushEventHandler(new EvtHandler(++m_nPush));

#if wxUSE_STATUSBAR
    SetStatusText(wxString::Format(wxT("Push count: %u"), m_nPush), Status_Push);
#endif // wxUSE_STATUSBAR
}

void Frame::OnPopEventHandler(wxCommandEvent &WXUNUSED(event)) {
    wxCHECK_RET( m_nPush, wxT("this command should be disabled!") );

    PopEventHandler(true /* delete handler */);
    m_nPush--;

#if wxUSE_STATUSBAR
    SetStatusText(wxString::Format(wxT("Push count: %u"), m_nPush), Status_Push);
#endif // wxUSE_STATUSBAR
}

void Frame::OnTest(wxCommandEvent &WXUNUSED(event)) {
    wxLogMessage(wxT("This is the test event handler in the main frame"));
}

void Frame::OnUpdateUIPop(wxUpdateUIEvent &event) {
    event.Enable( m_nPush > 0 );
}
// ----------------------------------------------------------------------------
// custom event methods
// ----------------------------------------------------------------------------

void Frame::OnFireCustom(wxCommandEvent &WXUNUSED(event)) {
 //   wxCommandEvent eventCustom(wxEVT_MY_CUSTOM_COMMAND);
 //   wxPostEvent(this, eventCustom);
}

void Frame::OnProcessCustom(wxCommandEvent &WXUNUSED(event)) {
    wxLogMessage(wxT("Got a custom event!"));
}