#include <wx/app.h>
#include "frameRadiobox.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// RadioBox Example:
    FrameRadiobox* radio = new FrameRadiobox("Single Line Text Control");
    radio->Show(true);

    return true;
}