#include "frame.h"
// Define a new application type, each program should derive a class from wxApp
class App : public wxApp {
public:
	virtual bool OnInit();
};

bool App::OnInit() {
    if ( !wxApp::OnInit() )
        return false;

    Frame *frame = new Frame(wxT("wxComboCtrl and wxOwnerDrawnComboBox Sample"));
    frame->Show(true);

    return true;
}

IMPLEMENT_APP(App)