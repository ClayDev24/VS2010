#include <wx/app.h>
#include "frameFilePicker.h"
#include "frameDirPicker.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// File Picker Example:
    FrameFilePicker* file = new FrameFilePicker("File Picker Example");
    file->Show(true);
	// Dir Picker Example:
    FrameDirPicker* dir = new FrameDirPicker("Directory Picker Example");
    dir->Show(true);

    return true;
}