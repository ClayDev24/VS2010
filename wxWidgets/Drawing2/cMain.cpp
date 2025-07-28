#include <wx/app.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>
#include "frameDrawing.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    FrameDrawing *frame = new FrameDrawing("Drawing1");
    frame->Show(true);

    return true;
}
