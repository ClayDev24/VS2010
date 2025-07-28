#pragma once
#include "wx/dialog.h"
#include "wx/artprov.h"

class WXDLLIMPEXP_FWD_CORE wxListCtrl;
class WXDLLIMPEXP_FWD_CORE wxListEvent;
class WXDLLIMPEXP_FWD_CORE wxStaticBitmap;

class MyFrame : public wxFrame {
    // event handlers (these functions should _not_ be virtual)
    void OnQuit(   wxCommandEvent &event);
    void OnAbout(  wxCommandEvent &event);
#if wxUSE_LOG
    void OnLogs(  wxCommandEvent  &event);
#endif // wxUSE_LOG
    void OnBrowser(wxCommandEvent &event);
    void OnPlugProvider(wxCommandEvent &event);
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);

private:
    wxDECLARE_EVENT_TABLE();
};

class wxArtBrowserDialog : public wxDialog {
    wxListCtrl     *m_list;
    wxStaticBitmap *m_canvas;
    wxStaticText   *m_text;
    wxString        m_client;
	void OnChooseClient(wxCommandEvent &event);
    void OnSelectItem(  wxListEvent    &event);
public:
    wxArtBrowserDialog(wxWindow *parent);

    void SetArtClient(const wxArtClient& client);
    void SetArtBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size = wxDefaultSize);

private:
    wxDECLARE_EVENT_TABLE();
};
