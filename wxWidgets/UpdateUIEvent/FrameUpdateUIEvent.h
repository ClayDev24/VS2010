#pragma once
#include <wx/frame.h>
#include <wx/checkbox.h>

class FrameUpdateUIEvent : public wxFrame {
public:
    FrameUpdateUIEvent(const wxString& title);

private:
	inline void OnExit(wxCommandEvent& event) { Close(true); }
    void OnExitUpdate(wxUpdateUIEvent& evt);

private:
    wxCheckBox* m_checkbox;

    wxDECLARE_EVENT_TABLE();
};