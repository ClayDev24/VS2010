#include <wx/app.h>
#include "frameSplitter.h"
#include "frameSplitter2.h"

// The minimal needed to compile sucefully:
class App1 : public wxApp {
public:
    virtual bool OnInit();
};

// Provides the application main entrypoint (main/WinMain - console/gui)
wxIMPLEMENT_APP(App1);

bool App1::OnInit() {

    FrameSplitter *frame = new FrameSplitter("Frame Splitter");
    frame->Show(true);

    FrameSplitter2 *frame2 = new FrameSplitter2("Frame Splitter 2");
    frame2->Show(true);

    return true;
}