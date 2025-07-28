#include <wx/app.h>
#include "frame.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

bool App::OnInit() {

    Frame *check = new Frame("WxCheckBox1");
    check->Show(true);

    return true;
}

wxIMPLEMENT_APP(App);