#include <wx/app.h>
#include "frameSizer.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    FrameSizer *frame = new FrameSizer("SimpleFit1");
    frame->Show(true);

    return true;
}