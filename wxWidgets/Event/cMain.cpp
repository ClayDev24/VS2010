#include "frame.h"

// Define a new application type, each program should derive a class from wxApp
class App : public wxApp {
public:
    virtual bool OnInit();
    void OnClickDynamicHandlerApp(wxCommandEvent &event);
    void OnClickStaticHandlerApp( wxCommandEvent &event);
    // we override wxConsoleApp::FilterEvent used to highlight the events handling order
    virtual int FilterEvent(wxEvent& event);
private:
    wxDECLARE_EVENT_TABLE();
};


// 'Main program' equivalent: the program execution "starts" here
bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;
    // create the main application window
    Frame *frame = new Frame(wxT("Event wxWidgets Sample"), wxPoint(50, 50), wxSize(600, 340));
    frame->Show(true);
    // Add a dynamic handler at the application level for the test button
    Connect(EvtTestButton::BUTTON_ID, wxEVT_BUTTON,
            wxCommandEventHandler(App::OnClickDynamicHandlerApp));

    return true;
}

IMPLEMENT_APP(App)
// This is always the first to handle an event !
int App::FilterEvent(wxEvent &event) {
    if(event.GetEventType() == wxEVT_BUTTON &&
            event.GetId() == EvtTestButton::BUTTON_ID) {
        wxLogMessage("Step 0 in \"How Events are Processed\":\n"
                     "App::FilterEvent");
    }
    return wxApp::FilterEvent(event);
}

void App::OnClickDynamicHandlerApp(wxCommandEvent &event) {
    wxLogMessage("Step 7, 3 in \"How Events are Processed\":\n"
                 "App::DynamicHandler_InAppTable");
    event.Skip();
}

void App::OnClickStaticHandlerApp(wxCommandEvent &event) {
    wxLogMessage("Step 7, 4 in \"How Events are Processed\":\n"
                 "App::StaticHandler_InAppTable");

    wxLogMessage("Button click processed, there should be no more messages "
                 "about handling events from the button.\n\n"
                 "The log below shows the order in which the handlers "
                 "were executed.");
    wxLog::FlushActive();
    event.Skip();
}

// The event tables connect the wxWidgets events with the functions (event
// handlers) which process them.
wxBEGIN_EVENT_TABLE(App, wxApp)
    // Add a static handler for button Click event in the app
    EVT_BUTTON(EvtTestButton::BUTTON_ID, App::OnClickStaticHandlerApp)
wxEND_EVENT_TABLE()

	wxDEFINE_EVENT(wxEVT_MY_CUSTOM_COMMAND, wxCommandEvent);

// it may also be convenient to define an event table macro for this event type
#define EVT_MY_CUSTOM_COMMAND(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        wxEVT_MY_CUSTOM_COMMAND, id, wxID_ANY, \
        wxCommandEventHandler(fn), \
        (wxObject *) NULL \
    ),

wxBEGIN_EVENT_TABLE(EvtTestButton, wxButton)
    // Add a static handler to this button itself for its own event
    EVT_BUTTON(BUTTON_ID, EvtTestButton::OnClickStaticHandler)
wxEND_EVENT_TABLE()

// This can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(Event_Quit,  Frame::OnQuit)
    EVT_MENU(Event_About, Frame::OnAbout)

#ifdef wxHAS_EVENT_BIND
    EVT_MENU(Event_Bind,  Frame::OnBind)
#endif // wxHAS_EVENT_BIND
    EVT_MENU(Event_Connect, Frame::OnConnect)

    EVT_MENU(Event_Custom,  Frame::OnFireCustom)
    EVT_MENU(Event_Test,    Frame::OnTest)
    EVT_MENU(Event_Push,    Frame::OnPushEventHandler)
    EVT_MENU(Event_Pop,     Frame::OnPopEventHandler)

    EVT_UPDATE_UI(Event_Pop, Frame::OnUpdateUIPop)

    EVT_MY_CUSTOM_COMMAND(wxID_ANY, Frame::OnProcessCustom)

    // the line below would also work if OnProcessCustom() were defined as
    // taking a wxEvent (as required by EVT_CUSTOM) and not wxCommandEvent
    //EVT_CUSTOM(wxEVT_MY_CUSTOM_COMMAND, wxID_ANY, MyFrame::OnProcessCustom)

    // Add a static handler in the parent frame for button event
    EVT_BUTTON(EvtTestButton::BUTTON_ID, Frame::OnClickStaticHandlerFrame)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(EvtHandler, wxEvtHandler)
    EVT_MENU(Event_Test, EvtHandler::OnTest)
wxEND_EVENT_TABLE()


