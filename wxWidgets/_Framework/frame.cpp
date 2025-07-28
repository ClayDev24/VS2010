#include <wx/artprov.h> // SetBitmap() to set the icon
#include "button.h"
#include "frame.h"

#define FUNC(a, b, c) m_menuBar->addFunction(&a##b##c);
//	for(int i=1; i<9; i++)
//		FUNC(Men, n[i], Click)
int Button::id=0; // Initialize de static member function

MenuBar* CreateMenuBar(wxPanel*);

CFrame::CFrame(wxWindow *parent,
	wxWindowID id,
	const wxString &title,
	const wxPoint  &pos,
	const wxSize   &size,
	long  style,
	const wxString &name):wxFrame(parent, id, title, pos, size, style, name)
{
	wxPanel *panel1 = new wxPanel(this, wxID_ANY);

	m_menuBar = CreateMenuBar(panel1);

	// Create a button:
	Button *bt1 = new Button(panel1, wxT("Quit"),  wxPoint(20, 20));
	Button *bt2 = new Button(panel1, wxT("About"), wxPoint(20, 20));
	bt1->addFunction(&Btn1Click);
	bt1->addFunction(&Btn2Click);

	//wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
	//button_sizer->Add(bt1);
	//button_sizer->Add(bt2);
	//panel1->SetSizer(button_sizer);

	int ID_Text=0;
	m_textctrl = new TextControl(panel1, ID_Text, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    wxBoxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(bt1);
	main_sizer->AddSpacer(15);
    main_sizer->Add(bt2);
	main_sizer->AddSpacer(15);
    main_sizer->Add(m_textctrl, 1, wxGROW);
	panel1->SetSizer(main_sizer);

	bt2->SetFocus();
	Centre(); // Centered on monitor screen.
	//SetIcon(wxIcon(wxT("web.xpm")));
	SetMenuBar(m_menuBar); // Must be place at botton
}

wxBEGIN_EVENT_TABLE(CFrame, wxFrame)
	// Button Event Table:
	EVT_BUTTON(IDS::ID_1, CFrame::OnClicked)
	EVT_BUTTON(IDS::ID_2, CFrame::OnClicked)
	// Menu Event Table:
	EVT_MENU(IDS::ID_1,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_2,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_3,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_4,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_5,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_6,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_7,  CFrame::OnClicked)
	EVT_MENU(IDS::ID_8,  CFrame::OnClicked)

	EVT_MENU(wxID_EXIT, CFrame::OnExit)
wxEND_EVENT_TABLE()

MenuBar* CreateMenuBar(wxPanel* panel1) {
	MenuBar *m_menuBar = new MenuBar(panel1);
	m_menuBar->CreateMenu(NULL, 5, "menu1", "_", "menu2", "menu3", "File");
	wxMenu *help = m_menuBar->CreateMenu(NULL, 5, "help1", "help2", "help3", "_", "Help");
	m_menuBar->CreateMenu(help, 4, "sub1", "_", "sub2", "SubMenu");

	wxMenuItem *quit = new wxMenuItem(help, wxID_EXIT);
	quit->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
	help->Append(quit);

	m_menuBar->addFunction(&Men1Click);
	m_menuBar->addFunction(&Men2Click);
	m_menuBar->addFunction(&Men3Click);
	m_menuBar->addFunction(&Men4Click);
	m_menuBar->addFunction(&Men5Click);
	m_menuBar->addFunction(&Men6Click);
	m_menuBar->addFunction(&Men7Click);
	m_menuBar->addFunction(&Men8Click);
	return m_menuBar;
}
	