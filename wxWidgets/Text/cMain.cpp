#include <wx/app.h>
#include "frameText.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    FrameText* frame = new FrameText("DrawingText1");
    frame->Show(true);

    return true;
}