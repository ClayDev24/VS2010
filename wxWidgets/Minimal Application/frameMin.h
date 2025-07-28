#pragma once
#include <wx/frame.h>

class FrameMinimal : public wxFrame {
public:
    FrameMinimal(const wxString& title);
};

FrameMinimal::FrameMinimal(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{}
