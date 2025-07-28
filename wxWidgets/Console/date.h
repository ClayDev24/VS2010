#pragma once
//#include "..\wxWidgets\headers.h"

//#include <wx/cmdline.h>
//#include <wx/string.h>
//#include <wx/utils.h> // wxShell()
#include <wx/datetime.h>

void _date() {

	wxDateTime now = wxDateTime::Now();

	wxString date1 = now.Format();
	wxString date2 = now.Format(wxT("%X"));
	wxString date3 = now.Format(wxT("%x"));

	wxPuts(date1);
	wxPuts(date2);
	wxPuts(date3);

	date1 = now.Format(wxT("%B %d %Y"));
	wxPuts(date1);

	wxDateSpan span(0, 1);
	wxDateTime then = now.Add(span);

	date2 = then.Format(wxT("%B %d %Y"));
	wxPuts(date2);

	/*
	wxPrintf(wxT("   Tokyo: %s\n"), now.Format(wxT("%a %T"), 
	wxDateTime::GMT9).c_str());
	wxPrintf(wxT("  Moscow: %s\n"), now.Format(wxT("%a %T"), 
	wxDateTime::MSD).c_str());
	wxPrintf(wxT("Budapest: %s\n"), now.Format(wxT("%a %T"), 
	wxDateTime::CEST).c_str());
	wxPrintf(wxT("  London: %s\n"), now.Format(wxT("%a %T"), 
	wxDateTime::WEST).c_str());
	wxPrintf(wxT("New York: %s\n"), now.Format(wxT("%a %T"), 
	wxDateTime::EDT).c_str());
	*/
}