#include "frame.h"
// --------------------------------------------------------
// our classes
// --------------------------------------------------------
class App: public wxApp {
public:
    App() {}
    virtual bool OnInit();

    wxDECLARE_NO_COPY_CLASS(App);
};

IMPLEMENT_APP(App)

bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;

    // create and show the main frame
    Frame *frame = new Frame;
    frame->Show(true);

    return true;
}