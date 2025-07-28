#include "wx/clipbrd.h"
#include "cframe.h"
#include "IDs.h"
// -----------------------------------------------------------
// application class
// -----------------------------------------------------------
class App : public wxApp {
public:
    virtual bool OnInit();
};

bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;

    CFrame *cframe = new CFrame("wxClipboard sample");
	LoadMenuFile(cframe->GetMenu());
	LoadMenuHelp(cframe->GetMenu());
	cframe->Show(true);

    return true;
}

IMPLEMENT_APP(App)

