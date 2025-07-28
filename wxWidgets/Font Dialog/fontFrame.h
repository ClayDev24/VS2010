#pragma once
#include <wx/frame.h>
#include <wx/fontdlg.h>

#include <wx/menu.h>
#include <wx/dcclient.h>
#include "IDs.h"

class FontFrame : public wxFrame {
	wxFontData m_fontData;
    void OnPaint(wxPaintEvent& evt);
    void OnSelectFont(wxCommandEvent& evt);

public:
    FontFrame(const wxString& title);

private:
    wxDECLARE_EVENT_TABLE();
};

// Add the event handler for the Select Font menu item
// to the event table and for the paint event
wxBEGIN_EVENT_TABLE(FontFrame, wxFrame)
    EVT_PAINT(FontFrame::OnPaint)
    EVT_MENU(ID_FONT, FontFrame::OnSelectFont)
wxEND_EVENT_TABLE()

FontFrame::FontFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // The Open dialog is usually accessible from
    // the "File" menu so we create one.
    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_FONT, "Select Font...");
    menuBar->Append(menuFile, "&Options");
    SetMenuBar(menuBar);

    SetBackgroundColour(*wxWHITE);
}

// Event handler for the paint event
void FontFrame::OnPaint(wxPaintEvent& evt) {
    wxPaintDC dc(this);

    // Set the font and text color based on the user
    // selection and draw some text
    dc.SetFont(m_fontData.GetChosenFont());
    dc.SetTextForeground(m_fontData.GetColour());
    dc.DrawText("Hello World!", 20, 20);
}

// Event handler for the Select Font menu item. It will
// display a wxFontDialog.
void FontFrame::OnSelectFont(wxCommandEvent& evt) {
    // Create a new wxFontDialog dialog
    wxFontDialog* fontDialog = new wxFontDialog(this);

    // Display the dLg:
    if(fontDialog->ShowModal() == wxID_OK) {
        m_fontData = fontDialog->GetFontData();
        Refresh();
    }
    fontDialog->Destroy();
}