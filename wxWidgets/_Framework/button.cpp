#include "button.h"

void Button::OnButtonClicked(wxCommandEvent &evt) {
	//OnAbout(evt);
	//evt.GetId();
	//fPtr f = vFuncBtn.at(evt.GetId());
	//(*f)(m_parent);
}

Button::Button(wxWindow *hwd, const wxString &title, wxPoint &Point)
		:wxButton(hwd, id++, title, Point)	
{
	m_parent = hwd->GetParent();
}


