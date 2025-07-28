#include "accessibility.h"
// Define a new application type, each program should derive a class from wxApp

class App : public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(App)

// 'Main program' equivalent: the program execution "starts" here
bool App::OnInit() {
    if(!App::OnInit())
        return false;

#if wxUSE_ACCESSIBILITY

    wxHelpProvider::Set(new wxSimpleHelpProvider());
    // create the main application window
    FrameAccess *access = new FrameAccess(wxT("Accessibility Application Sample"), wxPoint(50, 50), wxSize(450, 340));
    access->Show(true);

    return true;
#else
    wxMessageBox( wxT("This sample has to be compiled with wxUSE_ACCESSIBILITY"), wxT("Building error"), wxOK);
    return false;
#endif // wxUSE_ACCESSIBILITY
}
