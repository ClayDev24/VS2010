#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "frame.h"

class App:public wxApp {
public:
	App(void) {}
	virtual bool OnInit();
};

bool App::OnInit() {
	if(!wxApp::OnInit())
		return false;

	Frame *frame = new Frame(nullptr, id::ID_MAINWINDOW, _("Simple Window Sample"));
	frame->Show();

	return true;
}

IMPLEMENT_APP(App);
DECLARE_APP(App);
