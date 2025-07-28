#include <wx/app.h>
#include "frameMin.h"

// The minimal needed to compile sucefully:
class MinimalApp1 : public wxApp {
public:
    virtual bool OnInit();
};

// Provides the application main entrypoint (main/WinMain - console/gui)
wxIMPLEMENT_APP(MinimalApp1);

bool MinimalApp1::OnInit() {
    // Normally you would initialize the UI here
    // and return true on success

	// Uncomment this to minimal visible application:
    //FrameMinimal *frame = new FrameMinimal("MinimalApp2");
    //frame->Show(true);
    return true;
}