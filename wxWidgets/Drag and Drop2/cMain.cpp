#include "frameDrop.h"
#include <wx/app.h>

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    FrameDrop* frame = new FrameDrop("DragAndDropText1");
    frame->Show(true);

    return true;
}