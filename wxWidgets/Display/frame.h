#pragma once
#include "..\_Framework\headers.h"

#include "wx/bookctrl.h"
#include "wx/sysopt.h"

#include "wx/display.h"
#include "IDs.h"

// Define a new frame type: this is going to be our main frame
class Frame : public wxFrame {
    // GUI controls
    wxBookCtrl *m_book;
#if wxUSE_DISPLAY
    // convert video mode to textual description
    wxString VideoModeToText(const wxVideoMode &mode);
#endif // wxUSE_DISPLAY

public:
    Frame(const wxString &title, const wxPoint &pos, const wxSize &size,
            long style = wxDEFAULT_FRAME_STYLE);

    // event handlers (these functions should _not_ be virtual)
	void OnQuit(      wxCommandEvent &event) { Close(true); }
    void OnFromPoint( wxCommandEvent &event);
    void OnFullScreen(wxCommandEvent &event);
    void OnAbout(     wxCommandEvent &event);

#if wxUSE_DISPLAY
    void OnChangeMode(wxCommandEvent &event);
    void OnResetMode( wxCommandEvent &event);

    void OnDisplayChanged(wxDisplayChangedEvent &event);
#endif // wxUSE_DISPLAY

    void OnLeftClick(wxMouseEvent &event);

private:
    wxDECLARE_EVENT_TABLE();
};

// Client data class for the choice control containing the video modes
class VideoModeClientData : public wxClientData {
public:
	const wxVideoMode mode;
public:
    VideoModeClientData(const wxVideoMode & m) : mode(m) {}
};
