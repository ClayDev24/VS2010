#include <wx/artprov.h> // SetBitmap() to set the icon
#include "frame.h"

#define FUNC(a, b, c) m_menuBar->addFunction(&a##b##c);

Frame::Frame(wxWindow *parent,
	wxWindowID id,
	const wxString &title,
	const wxPoint  &pos,
	const wxSize   &size,
	long  style,
	const wxString &name):wxFrame(parent, id, title, pos, size, style, name)
{
	idmn = IDS::ID_1;
	wxPanel *panel1  = new wxPanel(this, wxID_ANY);

	m_menuBar = new MenuBar(panel1);
	m_menuBar->CreateMenu(5, "menu1", "_", "menu2", "menu3", "File");
	wxMenu *help = m_menuBar->CreateMenu(5, "help1", "help2", "help3", "_", "Help");
	m_menuBar->CreateSubMenu(help, 4, "sub1", "_", "sub2", "SubMenu");

//	for(int i=1; i<4; i++)
//		FUNC(Men, 1, Click)

	m_menuBar->addFunction(&Men1Click);
	m_menuBar->addFunction(&Men2Click);
	m_menuBar->addFunction(&Men3Click);
	m_menuBar->addFunction(&Men4Click);
	m_menuBar->addFunction(&Men5Click);
	m_menuBar->addFunction(&Men6Click);
	m_menuBar->addFunction(&Men7Click);
	m_menuBar->addFunction(&Men8Click);

//	wxButton *bt1 = CreateButton(wxT("Quit"), panel1,20,20);
	//wxPanel  *panel2  = new wxPanel(this, wxID_ANY);
//	wxButton *bt2 = CreateButton(wxT("About"),panel1,100,20);

	// Create a button:
	idbt = IDS::ID_1;
	Button *bt1 = new Button(panel1, idbt++, wxT("Quit"),  wxPoint(20, 20));
	Button *bt2 = new Button(panel1, idbt++, wxT("About"), wxPoint(20, 20));
	bt1->addFunction(&Btn1Click);
	bt1->addFunction(&Btn2Click);

//    wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
//    button_sizer->Add(bt1);
//    button_sizer->Add(bt2);
//	panel1->SetSizer(button_sizer);

	int ID_Text=0;
//    wxPanel *panel2 = new wxPanel(this, wxID_ANY);//10,10,30,30);
	m_textctrl = new wxTextCtrl(panel1, ID_Text, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    wxBoxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(bt1);
    main_sizer->Add(bt2);
    main_sizer->Add(m_textctrl, 1, wxGROW);
	panel1->SetSizer(main_sizer);//

	bt2->SetFocus();
	//SetIcon(wxIcon(wxT("web.xpm")));
	Centre(); // Centered on monitor screen.

	SetMenuBar(m_menuBar); // Must be place at botton
}

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
	// Button Event Table:
	EVT_BUTTON(IDS::ID_1, Frame::OnClicked)
	EVT_BUTTON(IDS::ID_2, Frame::OnClicked)
	// Menu Event Table:
	EVT_MENU( IDS::ID_1,  Frame::OnClicked)
	EVT_MENU( IDS::ID_2,  Frame::OnClicked)
	EVT_MENU( IDS::ID_3,  Frame::OnClicked)
	EVT_MENU( IDS::ID_4,  Frame::OnClicked)
	EVT_MENU( IDS::ID_5,  Frame::OnClicked)
	EVT_MENU( IDS::ID_6,  Frame::OnClicked)
	EVT_MENU( IDS::ID_7,  Frame::OnClicked)
	EVT_MENU( IDS::ID_8,  Frame::OnClicked)
wxEND_EVENT_TABLE()

MenuBar* _createMenu2(wxPanel *panel1) {
	return NULL;
}