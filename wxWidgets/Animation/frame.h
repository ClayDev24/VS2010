#pragma once
#include "wx/animate.h"
#include "../wxWidgets/_Framework/IDs.h"
// -----------------------------------------------------------
// frame definition
// -----------------------------------------------------------
class Frame : public wxFrame {
protected:
    wxAnimationCtrl *m_animationCtrl;
private:
    wxAnimationCtrl *GetAnimationCtrl() const { return m_animationCtrl; }
public:
    Frame(wxWindow       *parent,
          wxWindowID      id,
          const wxString &title,
          const wxPoint  &pos   = wxDefaultPosition,
          const wxSize   &size  = wxDefaultSize,
          long            style = wxDEFAULT_FRAME_STYLE,
          const wxString &name  = wxFrameNameStr);
	~Frame() {}
	inline void OnQuit(wxCommandEvent& event) { Close(true); }
    void OnAbout(wxCommandEvent& event);

    void OnPlay(wxCommandEvent& event);
    void OnSetNullAnimation( wxCommandEvent& event);
    void OnSetInactiveBitmap(wxCommandEvent& event);
    void OnSetNoAutoResize(  wxCommandEvent& event);
    void OnSetBgColor(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);

    void OnUpdateUI(wxUpdateUIEvent& event);

#if wxUSE_FILEDLG
    void OnOpen(wxCommandEvent& event);
#endif // wxUSE_FILEDLG

private:
    wxDECLARE_EVENT_TABLE();
};
// ---------------------------------------------------------------------------
// event tables
// ---------------------------------------------------------------------------
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(ID_SET_NULL_ANIMATION,  Frame::OnSetNullAnimation)
    EVT_MENU(ID_SET_INACTIVE_BITMAP, Frame::OnSetInactiveBitmap)
    EVT_MENU(ID_SET_NO_AUTO_RESIZE,  Frame::OnSetNoAutoResize)
    EVT_MENU(ID_SET_BGCOLOR,         Frame::OnSetBgColor)

	EVT_MENU(ID_PLAY,      Frame::OnPlay)

    EVT_MENU(wxID_STOP,    Frame::OnStop)
    EVT_MENU(wxID_ABOUT,   Frame::OnAbout)
    EVT_MENU(wxID_EXIT,    Frame::OnQuit)

#if wxUSE_FILEDLG
    EVT_MENU(wxID_OPEN,    Frame::OnOpen)
#endif // wxUSE_FILEDLG

    EVT_SIZE(               Frame::OnSize)
    EVT_UPDATE_UI(wxID_ANY, Frame::OnUpdateUI)
wxEND_EVENT_TABLE()
// -----------------------------------------------------------
// frame implementation
// -----------------------------------------------------------
Frame::Frame(wxWindow *parent, // Constructor
                 const wxWindowID id,
                 const wxString  &title,
                 const wxPoint   &pos,
                 const wxSize    &size,
                 const long       style,
				 const wxString  &name): wxFrame(parent, id, title, pos, size,
                            style | wxNO_FULL_REPAINT_ON_RESIZE, name)
{
    SetIcon(wxICON(sample));
    // Make a menubar
    wxMenu *file_menu = new wxMenu;

#if wxUSE_FILEDLG
    file_menu->Append(wxID_OPEN, wxT("&Open Animation...\tCtrl+O"), wxT("Loads an animation"));
#endif // wxUSE_FILEDLG
    file_menu->Append(wxID_EXIT);

    wxMenu *play_menu = new wxMenu;
    play_menu->Append(ID_PLAY,   wxT("Play\tCtrl+P"), wxT("Play the animation"));
    play_menu->Append(wxID_STOP, wxT("Stop\tCtrl+S"), wxT("Stop the animation"));
    play_menu->AppendSeparator();
    play_menu->Append(ID_SET_NULL_ANIMATION, wxT("Set null animation"), wxT("Sets the empty animation in the control"));
    play_menu->AppendCheckItem(ID_SET_INACTIVE_BITMAP, wxT("Set inactive bitmap"), wxT("Sets an inactive bitmap for the control"));
    play_menu->AppendCheckItem(ID_SET_NO_AUTO_RESIZE, wxT("Set no autoresize"), wxT("Tells the control not to resize automatically"));
    play_menu->Append(ID_SET_BGCOLOR, wxT("Set background colour..."), wxT("Sets the background colour of the control"));

    wxMenu *help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);

    wxMenuBar *menu_bar = new wxMenuBar;

    menu_bar->Append(file_menu, wxT("&File"));
    menu_bar->Append(play_menu, wxT("&Animation"));
    menu_bar->Append(help_menu, wxT("&Help"));

    // Associate the menu bar with this frame
    SetMenuBar(menu_bar);

#if wxUSE_STATUSBAR
    CreateStatusBar();
#endif // wxUSE_STATUSBAR

    // use a wxBoxSizer otherwise wxFrame will automatically
    // resize the m_animationCtrl to fill its client area on
    // user resizes
    wxSizer *sz = new wxBoxSizer(wxVERTICAL);
    sz->Add(new wxStaticText(this, wxID_ANY, wxT("wxAnimationCtrl:")),
            wxSizerFlags().Centre().Border());

    m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY);
    if(m_animationCtrl->LoadFile(wxT("animado-18.gif")))
        m_animationCtrl->Play();

    sz->Add(m_animationCtrl, wxSizerFlags().Centre().Border());
    SetSizer(sz);
}

void Frame::OnPlay(wxCommandEvent& WXUNUSED(event)) {
    if(!m_animationCtrl->Play())
        wxLogError(wxT("Invalid animation"));
}

void Frame::OnStop(wxCommandEvent& WXUNUSED(event)) {
    m_animationCtrl->Stop();
}

void Frame::OnSetNullAnimation(wxCommandEvent& WXUNUSED(event)) {
    m_animationCtrl->SetAnimation(wxNullAnimation);
}

void Frame::OnSetInactiveBitmap(wxCommandEvent& event) {
    if(event.IsChecked()) {
        // set a dummy bitmap as the inactive bitmap
        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_MISSING_IMAGE);
        m_animationCtrl->SetInactiveBitmap(bmp);
    }
    else
        m_animationCtrl->SetInactiveBitmap(wxNullBitmap);
}

void Frame::OnSetNoAutoResize(wxCommandEvent& event) {
    // recreate the control with the new flag if necessary
    long style = wxAC_DEFAULT_STYLE |
                    (event.IsChecked() ? wxAC_NO_AUTORESIZE : 0);

    if(style != m_animationCtrl->GetWindowStyle()) {
        // save status of the control before destroying it
        wxAnimation curr  = m_animationCtrl->GetAnimation();
        wxBitmap inactive = m_animationCtrl->GetInactiveBitmap();
        wxColour bg       = m_animationCtrl->GetBackgroundColour();

        // destroy & rebuild
        wxAnimationCtrl *old = m_animationCtrl;
        m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY, curr, wxDefaultPosition, wxDefaultSize, style);

        GetSizer()->Replace(old, m_animationCtrl);
        delete old;

        // load old status in new control
        m_animationCtrl->SetInactiveBitmap(inactive);
        m_animationCtrl->SetBackgroundColour(bg);

        GetSizer()->Layout();
    }
}

void Frame::OnSetBgColor(wxCommandEvent& WXUNUSED(event)) {
    wxColour clr = wxGetColourFromUser(this, m_animationCtrl->GetBackgroundColour(),
                                       wxT("Choose the background colour"));
    if(clr.IsOk())
        m_animationCtrl->SetBackgroundColour(clr);
}

void Frame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxString msg;
    wxAboutDialogInfo info;
    info.SetName(_("wxAnimationCtrl and wxAnimation sample"));
    info.SetDescription(_("This sample program demonstrates the usage of wxAnimationCtrl"));
    info.SetCopyright(wxT("(C) 2021 claybom"));

    info.AddDeveloper(wxT("claybom"));
    wxAboutBox(info);
}

#if wxUSE_FILEDLG
void Frame::OnOpen(wxCommandEvent& WXUNUSED(event)) {
    wxFileDialog dialog(this, wxT("Please choose an animation"),
                        wxEmptyString, wxEmptyString, wxT("*.gif;*.ani"), wxFD_OPEN);
    if(dialog.ShowModal() == wxID_OK) {
        wxString filename(dialog.GetPath());

        // enable one of the two chunk of codes to test different parts of wxAnimation/wxAnimationCtrl
#if 0
        if(m_animationCtrl->LoadFile(filename))
            m_animationCtrl->Play();
        else
            wxMessageBox(wxT("Sorry, this animation is not a valid format for wxAnimation."));
#else
    #if 0
        wxAnimation temp;
        if(!temp.LoadFile(filename)) {
            wxLogError(wxT("Sorry, this animation is not a valid format for wxAnimation."));
            return;
        }

        m_animationCtrl->SetAnimation(temp);
        m_animationCtrl->Play();
    #else
        wxFileInputStream stream(filename);
        if(!stream.IsOk()) {
            wxLogError(wxT("Sorry, this animation is not a valid format for wxAnimation."));
            return;
        }

        wxAnimation temp;
        if(!temp.Load(stream)) {
            wxLogError(wxT("Sorry, this animation is not a valid format for wxAnimation."));
            return;
        }

        m_animationCtrl->SetAnimation(temp);
        m_animationCtrl->Play();
    #endif
#endif
        GetSizer()->Layout();
    }
}
#endif // wxUSE_FILEDLG

void Frame::OnUpdateUI(wxUpdateUIEvent& WXUNUSED(event)) {
    GetMenuBar()->FindItem(wxID_STOP)->Enable(m_animationCtrl->IsPlaying());
    GetMenuBar()->FindItem(ID_PLAY)->Enable(!m_animationCtrl->IsPlaying());
    GetMenuBar()->FindItem(ID_SET_NO_AUTO_RESIZE)->Enable(!m_animationCtrl->IsPlaying());
}
