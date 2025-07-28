#include "frame.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(App)

// 'Main program' equivalent: the program execution "starts" here
bool App::OnInit() {
    if ( !wxApp::OnInit() )
        return false;

#ifdef __WXMSW__
    if ( argc == 2 && !wxStricmp(argv[1],  wxT("/dx")) ) {
        wxSystemOptions::SetOption(wxT("msw.display.directdraw"), 1);
    }
#endif // __WXMSW__

    // create the main application window
    Frame *frame = new Frame(_("Display wxWidgets Sample"), wxDefaultPosition, wxDefaultSize);
    frame->Show();

    return true;
}