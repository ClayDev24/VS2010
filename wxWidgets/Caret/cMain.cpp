#include "canvas.h"

// Define a new application type, each program should derive a class from wxApp
class App : public wxApp {
public:
    virtual bool OnInit();
};

bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;

    // create and show the main application window
    Frame *frame = new Frame(wxT("Caret wxWidgets sample"), wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

IMPLEMENT_APP(App)