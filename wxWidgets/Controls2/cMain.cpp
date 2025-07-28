#include "..\wxWidgets\headers.h"

#include "panel.h"
#include "button.h"
#include "comboBox.h"
#include "radioBox.h"
#include "frame.h"
#include "choice.h"
#include "frame.h"
#include "eventTable.h"
//----------------------------------------------------------------------
// class definitions
//----------------------------------------------------------------------
class App: public wxApp {
public:
    bool OnInit();
};

bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;
    // parse the cmd line
    int x = 50,
        y = 50;
    if(argc == 3) {
        wxSscanf(wxString(argv[1]), wxT("%d"), &x);
        wxSscanf(wxString(argv[2]), wxT("%d"), &y);
    }

#if wxUSE_HELP
    wxHelpProvider::Set( new wxSimpleHelpProvider );
#endif // wxUSE_HELP

    // Create the main CFrame window
    CFrame *frame = new CFrame(wxT("Controls wxWidgets App"), x, y);
    frame->Show(true);

    return true;
}
IMPLEMENT_APP(App)