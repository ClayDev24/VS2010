#include <wx/app.h>
#include "framePicker.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// RadioBox Example:
    FramePicker *picker = new FramePicker("Colour Picker Control Example");
    picker->Show(true);

    return true;
}