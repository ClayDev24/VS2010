#include <wx/app.h>
#include "singleLine.h"
#include "multiLine.h"
#include "styledColour.h"

class App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// Single Line:
    FrameTextCtrl* single = new FrameTextCtrl("Single Line Text Control");
    single->Show(true);
	// Multi Line:
	FrameTextCtrl2* multi = new FrameTextCtrl2("Multi Line Text Control");
    multi->Show(true);
 	// (C-)Style coloured textCtrol:
//	FrameTextCtrl3* styled = new FrameTextCtrl3("(C-) Styled Text Control");
//	styled->Show(true);
    return true;
}