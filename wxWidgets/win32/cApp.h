#pragma once
#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp
{
private:
	cMain *m_frame1;
public:
	cApp();
	~cApp();

	virtual bool OnInit();
};