#pragma once
#include <wx/file.h> // Creste()
#include <wx/textfile.h> // Open()

void _files() {
	// Creste file:
	wxString str = wxT("You make me want to be a better man.\n");

	wxFile file;
	file.Create(wxT("quote"), true);

	if (file.IsOpened())
		wxPuts(wxT("the file is opened"));

	file.Write(str);
	file.Close();

	if (!file.IsOpened())
		wxPuts(wxT("the file is not opened"));

	// Read file:
	wxTextFile file2(wxT("main.cpp"));

	file2.Open();

	wxPrintf(wxT("Number of lines: %d\n"), file2.GetLineCount());
	wxPrintf(wxT("First line: %s\n"),    file2.GetFirstLine().c_str());
	wxPrintf(wxT("Last line: %s\n"),   file2.GetLastLine().c_str());

	wxPuts(wxT("-------------------------------------"));

	wxString s;

	for(s=file2.GetFirstLine(); !file2.Eof(); s=file2.GetNextLine())
		wxPuts(s);

	file2.Close();
}