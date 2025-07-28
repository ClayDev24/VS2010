#pragma once
#include <wx/window.h>
#include <wx/aboutdlg.h> // wxAboutBox()
#include <vector>

typedef void (*fPtr)(wxWindow *); // no args for this func.
static std::vector<fPtr> vFuncBtn;
static std::vector<fPtr> vFuncMen;

//******************<<_Button Functions_>>*******************
static void Btn1Click(wxWindow *_hwd) {
	_hwd->Close();
}
//      ---------------------x------------------------
static void Btn2Click(wxWindow *_w) {
	wxAboutDialogInfo m_info;
	wxAboutBox(m_info);
}

//******************<<_Menu Functions_>>*******************
static void Men1Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu1 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
static void Men2Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu2 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
static void Men3Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu3 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
static void Men4Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu4 Clicked!"));
	wxAboutBox(m_info);
}
//      ---------------------x------------------------
static void Men5Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu5 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
static void Men6Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu6 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
static void Men7Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu7 Clicked!"));
	wxAboutBox(m_info);
}//      ---------------------x------------------------
static void Men8Click(wxWindow *_hwd) {
	wxAboutDialogInfo m_info;
	m_info.SetDescription(wxT("Menu8 Clicked!"));
	wxAboutBox(m_info);
}