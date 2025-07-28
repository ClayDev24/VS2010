#include <wx/app.h>
#include "frameWizard.h"
#include "validatorDlg.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// RadioBox Example:
    FrameWizard *wizard = new FrameWizard("Frame Wizard DlgBox Control Sample");
    wizard->Show(true);

    FrameValidator *validator = new FrameValidator("Frame Validator DlgBox Control Sample");
    validator->Show(true);

    return true;
}