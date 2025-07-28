#include "../wxWidgets/_Framework/headers.h"

#include "wx/caret.h"
#include "wx/numdlg.h"

#include "IDs.h"

// MyCanvas is a canvas on which you can type
class Canvas: public wxScrolledWindow {
	wxChar *m_text;
    wxFont  m_font;
    // move the caret to m_xCaret, m_yCaret
    void DoMoveCaret();
    // update the geometry
    void ChangeSize();
    // the margin around the text (looks nicer)
    int  m_xMargin,   m_yMargin;
    // size (in pixels) of one character
    long m_widthChar, m_heightChar;
    // position (in text coords) of the caret
    int  m_xCaret,    m_yCaret;
    // the size (in text coords) of the window
    int  m_xChars,    m_yChars;
    // the text
public:
    Canvas() {}
    Canvas( wxWindow *parent );
	~Canvas() { free(m_text); }

    wxChar& CharAt(int x, int y) { return *(m_text + x + m_xChars * y); }

    // operations
    void SetFontSize(int fontSize);
	void MoveCaret(  int x, int y);
    void CreateCaret();

    // caret movement
    void Home()      { m_xCaret = 0; }
    void End()       { m_xCaret = m_xChars - 1; }
    void FirstLine() { m_yCaret = 0; }
    void LastLine()  { m_yCaret = m_yChars - 1; }
    void PrevChar()  { if ( !m_xCaret-- ) { End(); PrevLine(); } }
    void NextChar()  { if ( ++m_xCaret == m_xChars ) { Home(); NextLine(); } }
    void PrevLine()  { if ( !m_yCaret-- ) LastLine(); }
    void NextLine()  { if ( ++m_yCaret == m_yChars ) FirstLine(); }
    // event handlers
    void OnPaint( wxPaintEvent &event);
    void OnSize(  wxSizeEvent  &event);
    void OnChar(  wxKeyEvent   &event);

private:
    wxDECLARE_DYNAMIC_CLASS(Canvas);
    wxDECLARE_EVENT_TABLE();
};

// Define a new frame type: this is going to be our main frame
class Frame : public wxFrame {
	Canvas *m_canvas;
public:
    Frame(const wxString &title, const wxPoint &pos, const wxSize &size);

    // event handlers (these functions should _not_ be virtual)
	void OnQuit(        wxCommandEvent& event) { Close(true); }
    void OnAbout(       wxCommandEvent& event);
    void OnSetBlinkTime(wxCommandEvent& event);
    void OnSetFontSize( wxCommandEvent& event);
    void OnCaretMove(   wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
};
// ----------------------------------------------------------------------------
// main frame implementation
// ----------------------------------------------------------------------------
Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
       : wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size)
{
    // set the frame icon
    SetIcon(wxICON(sample));
    // create a menu bar
    wxMenu *menuFile = new wxMenu;

    menuFile->Append(Caret_SetBlinkTime, wxT("&Blink time...\tCtrl-B"));
    menuFile->Append(Caret_SetFontSize, wxT("&Font size...\tCtrl-S"));
    menuFile->Append(Caret_Move,  wxT("&Move caret\tCtrl-C"));
    menuFile->AppendSeparator();
    menuFile->Append(Caret_About, wxT("&About\tCtrl-A"), wxT("Show about dialog"));
    menuFile->AppendSeparator();
    menuFile->Append(Caret_Quit,  wxT("E&xit\tAlt-X"), wxT("Quit this program"));

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, wxT("&File"));
    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

    m_canvas = new Canvas(this);

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to wxWidgets!"));
#endif // wxUSE_STATUSBAR
}

void Frame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
    wxMessageBox(wxT("The caret wxWidgets sample.\n(c) 1999 Vadim Zeitlin"),
                 wxT("About Caret"), wxOK | wxICON_INFORMATION, this);
}

void Frame::OnCaretMove(wxCommandEvent &WXUNUSED(event)) {
    m_canvas->MoveCaret(10, 10);
}

void Frame::OnSetBlinkTime(wxCommandEvent &WXUNUSED(event)) {
    long blinkTime = wxGetNumberFromUser(
                      wxT("The caret blink time is the time between two blinks"),
                      wxT("Time in milliseconds:"),
                      wxT("wxCaret sample"),
                      wxCaret::GetBlinkTime(), 0, 10000,
                      this);
    if(blinkTime != -1) {
        wxCaret::SetBlinkTime((int)blinkTime);
        m_canvas->CreateCaret();
        wxLogStatus(this, wxT("Blink time set to %ld milliseconds."), blinkTime);
    }
}

void Frame::OnSetFontSize(wxCommandEvent &WXUNUSED(event)) {
    long fontSize = wxGetNumberFromUser(
                        wxT("The font size also determines the caret size so\nthis demonstrates resizing the caret."),
                        wxT("Font size (in points):"),
                        wxT("wxCaret sample"),
                        12, 1, 100,
                        this);
    if(fontSize != -1)
        m_canvas->SetFontSize((int)fontSize);
}

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(Caret_Quit,         Frame::OnQuit)
    EVT_MENU(Caret_About,        Frame::OnAbout)
    EVT_MENU(Caret_SetBlinkTime, Frame::OnSetBlinkTime)
    EVT_MENU(Caret_SetFontSize,  Frame::OnSetFontSize)
    EVT_MENU(Caret_Move,         Frame::OnCaretMove)
wxEND_EVENT_TABLE()

IMPLEMENT_DYNAMIC_CLASS(Canvas, wxScrolledWindow)

wxBEGIN_EVENT_TABLE(Canvas, wxScrolledWindow)
    EVT_PAINT(Canvas::OnPaint)
    EVT_SIZE( Canvas::OnSize)
    EVT_CHAR( Canvas::OnChar)
wxEND_EVENT_TABLE()

// ----------------------------------------------------------------------------
// MyCanvas
// ----------------------------------------------------------------------------
Canvas::Canvas(wxWindow *parent)
        : wxScrolledWindow(parent, wxID_ANY,
                            wxDefaultPosition, wxDefaultSize,
                            wxSUNKEN_BORDER)
{
    m_text = (wxChar *)NULL;

    SetBackgroundColour(*wxWHITE);
    SetFontSize(12);

    m_xCaret = m_yCaret =
    m_xChars = m_yChars = 0;
    m_xMargin = m_yMargin = 5;

    CreateCaret();
}

void Canvas::CreateCaret() {
    wxCaret *caret = new wxCaret(this, m_widthChar, m_heightChar);
    SetCaret(caret);

    caret->Move(m_xMargin, m_yMargin);
    caret->Show();
}

void Canvas::SetFontSize(int fontSize) {
    m_font = wxFont(fontSize, wxFONTFAMILY_TELETYPE,
                    wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    wxClientDC dc(this);
    dc.SetFont(m_font);
    m_heightChar = dc.GetCharHeight();
    m_widthChar  = dc.GetCharWidth();

    wxCaret *caret = GetCaret();
    if(caret) {
        caret->SetSize(m_widthChar, m_heightChar);
        ChangeSize();
    }
}

void Canvas::MoveCaret(int x, int y) {
    m_xCaret = x;
    m_yCaret = y;

    DoMoveCaret();
}

void Canvas::DoMoveCaret() {
    wxLogStatus(wxT("Caret is at (%d, %d)"), m_xCaret, m_yCaret);

    GetCaret()->Move(m_xMargin + m_xCaret * m_widthChar,
                     m_yMargin + m_yCaret * m_heightChar);
}

void Canvas::OnSize(wxSizeEvent &event) {
    ChangeSize();
    event.Skip();
}

void Canvas::ChangeSize() {
    wxSize size = GetClientSize();
    m_xChars  = (size.x - 2*m_xMargin) / m_widthChar;
    m_yChars  = (size.y - 2*m_yMargin) / m_heightChar;
    if(!m_xChars)
        m_xChars = 1;
    if(!m_yChars)
        m_yChars = 1;

    free(m_text);
    m_text = (wxChar *)calloc(m_xChars * m_yChars, sizeof(wxChar));

#if wxUSE_STATUSBAR
    wxFrame *frame = wxDynamicCast(GetParent(), wxFrame);

    if(frame && frame->GetStatusBar()) {
        wxString msg;
        msg.Printf(wxT("Panel size is (%d, %d)"), m_xChars, m_yChars);
        frame->SetStatusText(msg, 1);
    }
#endif // wxUSE_STATUSBAR
}

// NB: this method is horrible inefficient especially because the caret
//     needs to be redrawn often and in this case we only have to redraw
//     the caret location and not the entire window - in a real program we
//     would use GetUpdateRegion() and iterate over rectangles it contains
void Canvas::OnPaint(wxPaintEvent &WXUNUSED(event)) {
    wxCaretSuspend cs(this);
    wxPaintDC dc( this );
    PrepareDC( dc );
    dc.Clear();
    dc.SetFont( m_font );

    for(int y = 0; y < m_yChars; y++) {
        wxString line;
        for(int x = 0; x < m_xChars; x++) {
            wxChar ch = CharAt(x, y);
            if ( !ch )
                ch = wxT(' ');
#ifdef __WXOSX__
            dc.DrawText(ch, m_xMargin + x * m_widthChar, m_yMargin + y * m_heightChar );
#else
            line += ch;
#endif
        }

#ifndef __WXOSX__
        dc.DrawText( line, m_xMargin, m_yMargin + y * m_heightChar );
#endif
    }
}

void Canvas::OnChar(wxKeyEvent &event) {
    switch(event.GetKeyCode()) {
        case WXK_LEFT:
            PrevChar();
            break;
        case WXK_RIGHT:
            NextChar();
            break;
        case WXK_UP:
            PrevLine();
            break;
        case WXK_DOWN:
            NextLine();
            break;
        case WXK_HOME:
            Home();
            break;
        case WXK_END:
            End();
            break;
        case WXK_RETURN:
            Home();
            NextLine();
            break;
        default:
            if(!event.AltDown() && wxIsprint(event.GetKeyCode())) {
                wxChar ch = (wxChar)event.GetKeyCode();
                CharAt(m_xCaret, m_yCaret) = ch;

                wxCaretSuspend cs(this);
                wxClientDC dc(this);
                dc.SetFont(m_font);
                dc.SetBackgroundMode(wxSOLID); // overwrite old value
                dc.DrawText(ch, m_xMargin + m_xCaret * m_widthChar,
                                m_yMargin + m_yCaret * m_heightChar );

                NextChar();
            }
            else
                event.Skip();
    }
    DoMoveCaret();
}
