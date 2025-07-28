//#include "vld.h"
#include "../Advanced User Interface/frame.h"
#include "frame.h"
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

	CFrame *frame = new CFrame(nullptr, id::ID_MAINWINDOW, _("<<_FrameWork Main Window_>>"));
    frame->Show(true);
 
	return true;
}
// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also declares the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP(App)
DECLARE_APP(App)

