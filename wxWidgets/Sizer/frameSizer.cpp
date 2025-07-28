#include "frameSizer.h"
#include "wx/sizer.h"
#include "wx/stattext.h"

FrameSizer::FrameSizer(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
	wxStaticText *text   = new wxStaticText(this, wxID_STATIC, wxT("static text box"));
	//wxStaticText *text = new wxStaticText(this, wxID_STATIC, wxT("A static text box"),
	//					wxDefaultPosition, wxSize(100, 200));
	// Sizer Code:
    wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL); 
    topSizer->Add(text); // Let the sizer know the content of the window its about to resize.
    SetSizer(topSizer);
    //topSizer->Fit(this);

	// Use this to prevent resizes beyond the minimu size.
	topSizer->SetSizeHints(this);
	// end Sizer Code.
}