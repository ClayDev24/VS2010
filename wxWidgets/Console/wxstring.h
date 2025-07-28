#pragma once
#include "..\wxWidgets\headers.h"

#include <wx/cmdline.h>
#include <wx/string.h>
#include <wx/utils.h> // wxShell()

void _wxString() {

	wxString str1 = wxT("Windows");
	wxString str2 = wxT("Operating");
	wxString str3 = wxT("System");

	wxString str4 = str1 + wxT(" ") + str2 + wxT(" ") + str3;
	wxPuts(str4);

	int flowers = 21;
	str1.Printf(wxT("There are %d red roses."), flowers);
	wxPuts(str1);

	str1 = wxT("The history of my life");

	if(str1.Contains(wxT("history")))
		wxPuts(wxT("Contains!"));

	if(!str1.Contains(wxT("plain")))
		wxPuts(wxT("Does not contain!"));

	wxPrintf(wxT("%s=> %d characters\n"), str1, str1.Len());

	wxPuts(str1.MakeLower());
	wxPuts(str1.MakeUpper());
}