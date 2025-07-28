#include <wx/app.h>
#include "fontFrame.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// File Open Dialog Example:

    FontFrame *font = new FontFrame("File Open Dialog Example");
    font->Show(true);

    return true;
}