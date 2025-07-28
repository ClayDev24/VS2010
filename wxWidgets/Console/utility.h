#pragma once
#include "..\wxWidgets\headers.h"

#include <wx/cmdline.h>
#include <wx/string.h>
#include <wx/utils.h> // wxShell()

void _utility() {

	//wxShell(wxT("calc.exe"));
	//wxShell(wxT("dir *.cpp"));

	wxPuts(wxGetHomeDir());
	wxPuts(wxGetOsDescription());
	wxPuts(wxGetUserName());
	wxPuts(wxGetFullHostName());

	long mem = wxGetFreeMemory().ToLong();

	wxPrintf(wxT("Memory: %ld\n"), mem);
}