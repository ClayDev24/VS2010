#include <wx/app.h>
#include "frameTabs.h"
#include "frameEvents.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// File Open Dialog Example:

    FrameTabs   *tabs = new FrameTabs("Form Tabs Sample");
    tabs->Show(true);

    FrameEvents *evts = new FrameEvents("Form Tabs Events Sample");
    evts->Show(true);
  
    return true;
}