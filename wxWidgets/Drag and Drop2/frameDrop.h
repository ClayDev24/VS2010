#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dnd.h>

class FrameDrop : public wxFrame {
    class DropTarget : public wxTextDropTarget {
    public:
		DropTarget(wxTextCtrl& dropTarget);

        virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& data);

    private:
        wxTextCtrl& m_dropTarget;
    };

	void OnLeftButtonDown(wxMouseEvent& evt);
    wxStaticText* m_sourceTextCtrl;

public:
    FrameDrop(const wxString& title);
	
	wxDECLARE_EVENT_TABLE();
};

