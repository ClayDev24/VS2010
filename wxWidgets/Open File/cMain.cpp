#include <wx/app.h>
#include "fileOpenDlg.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// File Open Dialog Example:

    fileOpenDlg *file = new fileOpenDlg("File Open Dialog Example");
    file->Show(true);

    return true;
}