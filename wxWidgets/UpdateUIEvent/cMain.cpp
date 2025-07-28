#include <wx/app.h>
#include "FrameUpdateUIEvent.h"

class UpdateUIEvent1App : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(UpdateUIEvent1App);

bool UpdateUIEvent1App::OnInit()
{
    FrameUpdateUIEvent* frame = new FrameUpdateUIEvent("UpdateUIEvent1");
    frame->Show(true);
    return true;
}