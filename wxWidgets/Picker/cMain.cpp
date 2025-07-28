#include <wx/app.h>
#include "picker.h"
#include "fileDialog.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// Picker Example:
    Picker* picker = new Picker("Picker Example");
    picker->Show(true);

    return true;
}