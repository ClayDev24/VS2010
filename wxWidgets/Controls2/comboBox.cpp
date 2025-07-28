#pragma once
#include "comboBox.h"

void ComboBox::OnChar(wxKeyEvent& event) {
    wxLogMessage(wxT("MyComboBox::OnChar"));

    if(event.GetKeyCode() == 'w')
        wxLogMessage(wxT("MyComboBox: 'w' will be ignored."));
    else
        event.Skip();
}

void ComboBox::OnKeyDown(wxKeyEvent& event) {
    wxLogMessage(wxT("MyComboBox::OnKeyDown"));

    if(event.GetKeyCode() == 'w')
        wxLogMessage(wxT("MyComboBox: 'w' will be ignored."));
    else
        event.Skip();
}

void ComboBox::OnKeyUp(wxKeyEvent& event) {
    wxLogMessage(wxT("MyComboBox::OnKeyUp"));
    event.Skip();
}
