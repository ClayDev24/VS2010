#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	wxButton   *m_btn1;
	wxTextCtrl *m_txt1;
	wxListBox  *m_list;
};