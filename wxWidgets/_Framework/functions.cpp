#pragma once
#include "../Advanced User Interface/frame.h"
#include <wx/aboutdlg.h> // wxAboutBox()
#include "frame.h"
#include "functions.h"

//******************<<_Button Functions_>>*******************
void Btn1Click(CFrame *_hwd) {
	_hwd->Close();
}
//      ---------------------x------------------------
void Btn2Click(CFrame *_w) {
	wxAboutDialogInfo m_info;
	//wxAboutBox(m_info);
	
    Frame *calendar = new Frame("Calendar wxWidgets sample"
                               ,wxPoint(50, 50), wxSize(450, 340));
    calendar->Show(true);
	wxString s = calendar->m_logWindow->GetName();
	_w->GetTextCtrl()->SetValue(s);
}

//******************<<_Menu Functions_>>*******************
void Men1Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu1 Clicked!"));
	wxAboutBox(m_info);
	_hwd->GetTextCtrl()->SetValue("Men1Click()");
}
//      ---------------------x------------------------
void Men2Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu2 Clicked!"));
	wxAboutBox(m_info);
	_hwd->GetTextCtrl()->SetValue("Men2Click()");
}
//      ---------------------x------------------------
void Men3Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu3 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
void Men4Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu4 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
void Men5Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu5 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
void Men6Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu6 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
void Men7Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu7 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
void Men8Click(CFrame *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu8 Clicked!"));
	wxAboutBox(m_info);
}