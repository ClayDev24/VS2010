#pragma once
#include <wx/defs.h>

// IDs for the controls and the menu commands
enum {
    ComboCtrl_Compare = wxID_HIGHEST,
    // menu items
    ComboCtrl_Quit    = wxID_EXIT,
    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    ComboCtrl_About   = wxID_ABOUT
};