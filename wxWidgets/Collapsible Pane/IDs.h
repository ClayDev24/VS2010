#pragma once
// ID for the menu commands

enum {
	// frane
    PANE_COLLAPSE = 100,
    PANE_EXPAND,
    PANE_SETLABEL,
    PANE_SHOWDLG,
    PANE_ABOUT = wxID_ABOUT,
    PANE_QUIT  = wxID_EXIT,

    PANE_BUTTON,
    PANE_TEXTCTRL,
	// dialog:
    PANEDLG_TOGGLESTATUS_BTN = wxID_HIGHEST
};
