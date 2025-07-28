#include "frame.h"
// ----------------------------------------------------------------------------
// classes
// ----------------------------------------------------------------------------
class App: public wxApp {
public:
  // implement base class virtuals
  virtual bool OnInit();
  virtual int  OnExit();
};
// ============================================================================
// application implementation
// ============================================================================
IMPLEMENT_APP(App)
// Main program' equivalent, creating windows and returning main app frame
bool App::OnInit() {
    if(!wxApp::OnInit())
        return false;

    // we're using wxConfig's "create-on-demand" feature: it will create the
    // config object when it's used for the first time. It has a number of
    // advantages compared with explicitly creating our wxConfig:
    //  1) we don't pay for it if we don't use it
    //  2) there is no danger to create it twice

    // application and vendor name are used by wxConfig to construct the name
    // of the config file/registry key and must be set before the first call
    // to Get() if you want to override the default values (the application
    // name is the name of the executable and the vendor name is the same)
    SetVendorName(wxT("wxWidgets"));
    SetAppName(wxT("conftest")); // not needed, it's the default value

    wxConfigBase *pConfig = wxConfigBase::Get();

    // uncomment this to force writing back of the defaults for all values
    // if they're not present in the config - this can give the user an idea
    // of all possible settings for this program
    pConfig->SetRecordDefaults();

    // or you could also write something like this:
    //  wxFileConfig *pConfig = new wxFileConfig("conftest");
    //  wxConfigBase::Set(pConfig);
    // where you can also specify the file names explicitly if you wish.
    // Of course, calling Set() is optional and you only must do it if
    // you want to later retrieve this pointer with Get().

    // create the main program window
    CFrame *frame = new CFrame;
	//frame->SetMenuBar(LoadMenuClipBoard());
    frame->Show(true);

    // use our config object...
    if(pConfig->Read(wxT("/Controls/Check"), 1l) != 0) {
        wxMessageBox(wxT("You can disable this message box by unchecking\n")
                     wxT("the checkbox in the main window (of course, a real\n")
                     wxT("program would have a checkbox right here but we\n")
                     wxT("keep it simple)"), wxT("Welcome to wxConfig demo"),
                     wxICON_INFORMATION | wxOK);
    }
    return true;
}

int App::OnExit() {
    // clean up: Set() returns the active config object as Get() does, but unlike
    // Get() it doesn't try to create one if there is none (definitely not what
    // we want here!)
    delete wxConfigBase::Set((wxConfigBase *) NULL);

    return 0;
}