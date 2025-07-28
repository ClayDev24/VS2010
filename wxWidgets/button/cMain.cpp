 #include <wx/app.h>
#include "frameButton.h"
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

	FrameButton *bt = new FrameButton(_("<<_Button Example_>>"));
	bt->Show(true);

	return true;
}

IMPLEMENT_APP(App)
