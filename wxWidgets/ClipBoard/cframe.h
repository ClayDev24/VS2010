//#pragma once
#include "..\_Framework\headers.h"
#include "IDs.h"
// -----------------------------------------------------------
// frame declaration
// -----------------------------------------------------------
class CFrame : public Frame {
public:
    CFrame(const wxString &title);
    void OnUpdateUI(wxUpdateUIEvent &event);
#if USE_ASYNCHRONOUS_CLIPBOARD_REQUEST
    void OnClipboardChange(wxClipboardEvent &event);
#endif

private:
    wxDECLARE_EVENT_TABLE();
};
// -----------------------------------------------------------
// event tables
// -----------------------------------------------------------
wxBEGIN_EVENT_TABLE(CFrame, wxFrame)
    EVT_MENU(     ID_Quit,  Frame::OnQuit)
    EVT_MENU(     ID_About, Frame::OnAbout)
    EVT_MENU(   wxID_PASTE, Frame::OnPaste)
    EVT_BUTTON(   ID_Write, Frame::OnPaste)
    EVT_UPDATE_UI(ID_Write, CFrame::OnUpdateUI)
#if USE_ASYNCHRONOUS_CLIPBOARD_REQUEST
    EVT_CLIPBOARD_CHANGED(  CFrame::OnClipboardChange)
#endif
wxEND_EVENT_TABLE()

// -----------------------------------------------------------
// frame implementation / definition
// -----------------------------------------------------------
CFrame::CFrame(const    wxString& title)
       : Frame(nullptr, wxID_ANY, title)
{
    // set the frame icon
    SetIcon(wxICON(sample));

#if USE_ASYNCHRONOUS_CLIPBOARD_REQUEST
    m_request = Idle;
    m_clipboardSupportsText = false;
#endif
//	wxString msg;
    wxAboutDialogInfo info;
    info.SetName(_("<<_Clipboard Sample_>>"));
    info.SetDescription(_("This is the About dialog of the Clipboard sample."));
    info.SetCopyright(wxT("(C) 2021 claybom"));
    info.AddDeveloper(wxT("claybom"));	
	// parent's info:
	m_info = info;
}
//***********************************************************
#if USE_ASYNCHRONOUS_CLIPBOARD_REQUEST
void CFrame::OnClipboardChange(wxClipboardEvent&event) {
    m_clipboardSupportsText = event.SupportsFormat( wxDF_UNICODETEXT );
    m_request = Finished;
}
#endif
//***********************************************************
void CFrame::OnUpdateUI(wxUpdateUIEvent&event) {
#if USE_ASYNCHRONOUS_CLIPBOARD_REQUEST
    if(m_request == Idle) {
        if (!wxTheClipboard->IsSupportedAsync( this )) {
            // request failed, try again later
            event.Enable( m_clipboardSupportsText ); // not yet known, assume last value
            return;
        }
        m_request = Waiting;
        event.Enable( m_clipboardSupportsText ); // not yet known, assume last value
    }
    else if (m_request == Waiting) {
        event.Enable( m_clipboardSupportsText ); // not yet known, assume last value
    }
    else if (m_request == Finished) {
        event.Enable( m_clipboardSupportsText );
        m_request = Idle;
    }
#else
    event.Enable(wxTheClipboard->IsSupported(wxDF_UNICODETEXT));
#endif
}

//void Frame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
//    wxMessageBox("Clipboard sample", "About clipboard", wxOK|wxICON_INFORMATION, this);
//}
