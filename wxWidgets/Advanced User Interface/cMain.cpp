#include "../_Framework/frame.h"
#include "frame.h"

// Define a new application type, each program should derive a class from wxApp

class App : public wxApp {
	wxLocale m_locale;
public:
	App():m_locale(wxLANGUAGE_DEFAULT) {}
	virtual bool OnInit() wxOVERRIDE;
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;
    // Create the main application window
    Frame *calendar = new Frame("Calendar wxWidgets sample"
                               ,wxPoint(50, 50), wxSize(450, 340));
    calendar->Show(true);

    return true;
}

