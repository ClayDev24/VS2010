#pragma once
#include <wx/dcclient.h> // wxPaintDC class
#include <wx/graphics.h> // wxGraphicsContext class
#include <wx/frame.h>

class FrameDrawing : public wxFrame {
	void OnPaint(wxPaintEvent &evt);
public:
    FrameDrawing(const wxString &title);

private:
    wxDECLARE_EVENT_TABLE();
};
//***************************************************
FrameDrawing::FrameDrawing(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetBackgroundColour(*wxBLUE);
//	 wxBLACK     
//	 wxBLUE      
//	 wxCYAN      
//	 wxGREEN     
//	 wxYELLOW    
//	 wxLIGHT_GREY
//	 wxRED       
//	 wxWHITE     
}

void FrameDrawing::OnPaint(wxPaintEvent &evt) {
	// Drawing using wxPaintDC:
    wxPaintDC dc(this);

    dc.SetPen(  *wxGREY_PEN);
    dc.SetBrush(*wxLIGHT_GREY_BRUSH);
    dc.DrawRectangle(10, 10, 50, 50);
	dc.DrawEllipse(  70, 10, 50, 50);

    dc.SetTextForeground(*wxRED);
    dc.DrawText("Hello World!", 150, 50);

	// Drawing using wxGraphicsContext:
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc); // still uses wxPaintDC
    if(gc) {
        gc->SetPen(  *wxGREY_PEN);
        gc->SetBrush(*wxLIGHT_GREY_BRUSH);
        gc->DrawRectangle(10, 80, 50, 50);
        gc->DrawEllipse(  70, 80, 50, 50);

        delete gc;
    }
}

wxBEGIN_EVENT_TABLE(FrameDrawing, wxFrame)
    EVT_PAINT(FrameDrawing::OnPaint)
wxEND_EVENT_TABLE()