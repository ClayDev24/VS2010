#include "../_Framework/headers.h"
#include "../_Framework/frameMenuBar.h"
#include "../_Framework/menus.h"
#include "../_Framework/IDs.h"
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

	FrameMenuBar *frame = new FrameMenuBar(nullptr, MAIN_WINDOW, _("Main Window"));
	LoadMenuFile(frame->GetMenu());
	LoadMenuHelp(frame->GetMenu());
	frame->Show(true);

	return true;
}

IMPLEMENT_APP(App)
DECLARE_APP(App)