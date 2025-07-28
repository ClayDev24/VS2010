#include <wx/app.h>
#include "StaticText.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

bool App::OnInit() {
	if(!wxApp::OnInit())
		return false;

    StaticText *frame = new StaticText(_("WxStaticText1"));
    frame->Show(true);

    return true;
}

wxIMPLEMENT_APP(App);
DECLARE_APP(App)