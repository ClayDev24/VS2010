// For compilers that support precompilation, includes "wx/wx.h".
#include "..\_Framework\headers.h"

#include "wx/aboutdlg.h"
#include "wx/artprov.h"
#include "wx/colordlg.h"
#include "wx/wfstream.h"

#include "frame.h"

#if !wxUSE_ANIMATIONCTRL
    #error Cannot compile this sample if wxAnimationCtrl is not enabled
#endif
// -----------------------------------------------------------
// application class
// -----------------------------------------------------------
class App : public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(App)
// Initialise this in OnInit, not statically
bool App::OnInit() {
    if (!wxApp::OnInit())
        return false;

    // Create the main frame window:
    Frame* frame = new Frame(nullptr, wxID_ANY, wxT("Animation Demo"),
                                 wxDefaultPosition, wxSize(500, 400),
                                 wxDEFAULT_FRAME_STYLE);
    frame->Show(true);

    return true;
}
