#pragma once
#include <wx/frame.h>
#include <wx/dcclient.h>

class FrameText : public wxFrame
{
public:
    FrameText(const wxString& title);

private:
    void OnPaint(wxPaintEvent& evt);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(FrameText, wxFrame)
    EVT_PAINT(FrameText::OnPaint)
wxEND_EVENT_TABLE()

FrameText::FrameText(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetBackgroundColour(*wxBLACK);
	// wxBLACK     
	// wxBLUE      
	// wxCYAN      
	// wxGREEN     
	// wxYELLOW    
	// wxLIGHT_GREY
	// wxRED       
	// wxWHITE     
}

void FrameText::OnPaint(wxPaintEvent& evt) {
    wxPaintDC dc(this);

    dc.SetTextForeground(*wxRED);
    dc.DrawText("Hello World!", 150, 50);
	//dc.Clear();
}