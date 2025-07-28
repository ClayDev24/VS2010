#pragma once
#include "..\_Framework\headers.h"
#include "..\_Framework\frame.h"
#include "..\_Framework\menus.h"

//#include "..\wxWidgets\headers.h"
#include "wx/config.h"
#include "wx/log.h"

class CFrame: public Frame {
	wxTextCtrl *m_text;
	wxCheckBox *m_check;
public:
	CFrame();
	virtual ~CFrame();
	// callbacks
	void OnDelete(wxCommandEvent &event);

private:
	wxDECLARE_EVENT_TABLE();
};
// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------
wxBEGIN_EVENT_TABLE(CFrame, wxFrame)
	EVT_MENU(wxID_EXIT,   Frame::OnQuit)
	EVT_MENU(wxID_ABOUT,  Frame::OnAbout)
	EVT_MENU(wxID_DELETE, CFrame::OnDelete)
	EVT_MENU(wxID_PASTE,  Frame::OnPaste)
wxEND_EVENT_TABLE()
	// ----------------------------------------------------------------------------
	// frame implementation
	// ----------------------------------------------------------------------------
CFrame::CFrame() // constructor
	: Frame(nullptr, wxID_ANY, wxT("wxConfig Demo"))
{
	SetIcon(wxICON(sample));
	// menu
	wxMenu *file_menu = new wxMenu;

	    file_menu->Append(wxID_DELETE, wxT("&Delete"), wxT("Delete config file"));
	    file_menu->AppendSeparator();
//    wxMenuBar *menu_bar = new wxMenuBar;
	    m_menuBar->Append(file_menu, wxT("Del"));
	//SetMenuBar(menu_bar);

#if wxUSE_STATUSBAR
	CreateStatusBar();
#endif // wxUSE_STATUSBAR

	// child controls
	wxPanel *panel = new wxPanel(this);
	(void)new wxStaticText(panel, wxID_ANY, wxT("These controls remember their values!"),
		wxPoint(10, 10), wxSize(300, 20));
	m_text  = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(10, 40), wxSize(300, 20));
	m_check = new wxCheckBox(panel, wxID_ANY, wxT("show welcome message box at startup"),
		wxPoint(10, 70), wxSize(300, 20));

	// restore the control's values from the config

	// NB: in this program, the config object is already created at this moment
	// because we had called Get() from MyApp::OnInit(). However, if you later
	// change the code and don't create it before this line, it won't break
	// anything - unlike if you manually create wxConfig object with Create()
	// or in any other way (then you must be sure to create it before using it!).
	wxConfigBase *pConfig = wxConfigBase::Get();

	// we could write Read("/Controls/Text") as well, it's just to show SetPath()
	pConfig->SetPath(wxT("/Controls"));

	m_text->SetValue( pConfig->Read(wxT("Text"), wxT("")));
	m_check->SetValue(pConfig->Read(wxT("Check"), 1l) != 0);

	// SetPath() understands ".."
	pConfig->SetPath(wxT("../MainFrame"));

	// restore frame position and size
	int x = pConfig->Read(wxT("x"), 50),
		y = pConfig->Read(wxT("y"), 50),
		w = pConfig->Read(wxT("w"), 350),
		h = pConfig->Read(wxT("h"), 200);
	Move(x, y);
	SetClientSize(w, h);

	pConfig->SetPath(wxT("/"));
	wxString s;
	if(pConfig->Read(wxT("TestValue"), &s))
		wxLogStatus(this, wxT("TestValue from config is '%s'"), s.c_str());
	else
		wxLogStatus(this, wxT("TestValue not found in the config"));
}

//void CFrame::OnAbout(wxCommandEvent&) {
//   wxMessageBox(wxT("wxConfig demo\n(c) 1998-2001 Vadim Zeitlin"), wxT("About"),
//                 wxICON_INFORMATION | wxOK);
//}

void CFrame::OnDelete(wxCommandEvent&) {
	wxConfigBase *pConfig = wxConfigBase::Get();
	if(pConfig == NULL) {
		wxLogError(wxT("No config to delete!"));
		return;
	}
	if(pConfig->DeleteAll()) {
		wxLogMessage(wxT("Config file/registry key successfully deleted."));

		delete wxConfigBase::Set(NULL);
		wxConfigBase::DontCreateOnDemand();
	}
	else
		wxLogError(wxT("Deleting config file/registry key failed."));
}

CFrame::~CFrame() {
	wxConfigBase *pConfig = wxConfigBase::Get();
	if(pConfig == NULL)
		return;

	// save the control's values to the config
	pConfig->Write(wxT("/Controls/Text"),  m_text->GetValue());
	pConfig->Write(wxT("/Controls/Check"), m_check->GetValue());

	// save the frame position
	int x, y, w, h;
	GetClientSize(&w, &h);
	GetPosition(&x, &y);
	pConfig->Write(wxT("/MainFrame/x"), (long) x);
	pConfig->Write(wxT("/MainFrame/y"), (long) y);
	pConfig->Write(wxT("/MainFrame/w"), (long) w);
	pConfig->Write(wxT("/MainFrame/h"), (long) h);

	pConfig->Write(wxT("/TestValue"), wxT("A test value"));
}
