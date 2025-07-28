#pragma once

// IDs for the controls and the menu commands
enum {
    // menu items
    Display_FromPoint = wxID_HIGHEST + 1,
    Display_FullScreen,
    // controls
    Display_ChangeMode,
    Display_ResetMode,
    Display_CurrentMode,

    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    Display_Quit  = wxID_EXIT,
    Display_About = wxID_ABOUT
};