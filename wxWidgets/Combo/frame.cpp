#include "frame.h"

// ---------------------------------------------------------
// main frame
// ---------------------------------------------------------
// frame constructor
Frame::Frame(const wxString &title)
       : wxFrame(NULL, wxID_ANY, title)
{
    wxBoxSizer *topSizer;
    wxBoxSizer *topRowSizer;
    wxBoxSizer *colSizer;
    wxBoxSizer *rowSizer;
    // set the frame icon
    SetIcon(wxICON(sample));

#if wxUSE_MENUS
    // create a menu bar
    wxMenu *fileMenu = new wxMenu;
    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(ComboCtrl_About, wxT("&About\tF1"), wxT("Show about dialog"));

    fileMenu->Append(ComboCtrl_Compare, wxT("&Compare against wxComboBox..."),
        wxT("Show some wxOwnerDrawnComboBoxes side-by-side with native wxComboBoxes."));
    fileMenu->AppendSeparator();
    fileMenu->Append(ComboCtrl_Quit, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#endif // wxUSE_MENUS

    wxPanel *panel = new wxPanel(this);

    // Prepare log window right away since it shows EVT_TEXTs
    m_logWin = new wxTextCtrl(panel, 105, wxEmptyString,
                              wxDefaultPosition,
                              wxSize(-1, 125),
                              wxTE_MULTILINE);
    wxLogTextCtrl *logger = new wxLogTextCtrl(m_logWin);
    m_logOld = logger->SetActiveTarget(logger);
    logger->DisableTimestamp();

    topSizer    = new wxBoxSizer( wxVERTICAL );

    topRowSizer = new wxBoxSizer( wxHORIZONTAL );

    colSizer    = new wxBoxSizer( wxVERTICAL );

    wxComboCtrl* cc;
    wxGenericComboCtrl* gcc;
    wxOwnerDrawnComboBox* odc;
    // Create common strings array
    m_arrItems.Add( wxT("Solid") );
    m_arrItems.Add( wxT("Transparent") );
    m_arrItems.Add( wxT("Dot") );
    m_arrItems.Add( wxT("Long Dash") );
    m_arrItems.Add( wxT("Short Dash") );
    m_arrItems.Add( wxT("Dot Dash") );
    m_arrItems.Add( wxT("Backward Diagonal Hatch") );
    m_arrItems.Add( wxT("Cross-diagonal Hatch") );
    m_arrItems.Add( wxT("Forward Diagonal Hatch") );
    m_arrItems.Add( wxT("Cross Hatch") );
    m_arrItems.Add( wxT("Horizontal Hatch") );
    m_arrItems.Add( wxT("Vertical Hatch") );

    // Create pen selector ODComboBox with owner-drawn items
    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    rowSizer->Add( new wxStaticText(panel,wxID_ANY,
                   wxT("OwnerDrawnComboBox with owner-drawn items:")), 1,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    rowSizer = new wxBoxSizer( wxHORIZONTAL );

    // When defining derivative class for callbacks, we need
    // to use two-stage creation (or redefine the common wx
    // constructor).
    odc = new wxPenStyleComboBox();
    odc->Create(panel,wxID_ANY,wxEmptyString,
                wxDefaultPosition, wxDefaultSize,
                m_arrItems,
                wxCB_READONLY //wxNO_BORDER | wxCB_READONLY
               );
    odc->SetSelection(0);

    rowSizer->Add( odc, 1, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
    rowSizer->AddStretchSpacer(1);
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    // Same but with changed button position
    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    rowSizer->Add( new wxStaticText(panel,wxID_ANY,
                   wxT("OwnerDrawnComboBox with owner-drawn items and button on the left:")), 1,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    rowSizer = new wxBoxSizer( wxHORIZONTAL );

    // When defining derivative class for callbacks, we need
    // to use two-stage creation (or redefine the common wx
    // constructor).
    odc = new wxPenStyleComboBox();
    odc->Create(panel,wxID_ANY,wxEmptyString,
                wxDefaultPosition, wxDefaultSize,
                m_arrItems,
                wxCB_READONLY //wxNO_BORDER | wxCB_READONLY
               );
    odc->SetSelection(0);

    // Use button size that is slightly smaller than the default.
    wxSize butSize = odc->GetButtonSize();
    odc->SetButtonPosition(butSize.x - 2, // button width
                           butSize.y - 6, // button height
                           wxLEFT, // side
                           2 // horizontal spacing
                          );
    rowSizer->Add( odc, 1, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
    rowSizer->AddStretchSpacer(1);
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    // List View wxComboCtrl
    
    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    rowSizer->Add( new wxStaticText(panel,
                        wxID_ANY,
                        "List View wxComboCtrl (custom animation):"),
                   1, wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );
    rowSizer->Add( new wxStaticText(panel,wxID_ANY,wxT("Tree Ctrl wxComboCtrl:")), 1,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    cc = new wxComboCtrlWithCustomPopupAnim();

    // Let's set a custom style for the contained wxTextCtrl. We need to
    // use two-step creation for it to work properly.
    cc->SetTextCtrlStyle(wxTE_RIGHT);

    cc->Create(panel, wxID_ANY, wxEmptyString);

    // Make sure we use popup that allows focusing the listview.
    cc->UseAltPopupWindow();
    cc->SetPopupMinWidth(300);

    ListViewComboPopup* iface = new ListViewComboPopup();
    cc->SetPopupControl(iface);

    int i;
    for ( i=0; i<100; i++ )
        iface->AddSelection( wxString::Format(wxT("Item %02i"),i));

    rowSizer->Add( cc, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    // Tree Ctrl wxComboCtrl
    // Note that we test that wxGenericComboCtrl works
    gcc = new wxGenericComboCtrl(panel,wxID_ANY,wxEmptyString,
                                 wxDefaultPosition, wxDefaultSize);
    // Make sure we use popup that allows focusing the treectrl.
    gcc->UseAltPopupWindow();

    // Set popup interface right away, otherwise some of the calls
    // below may fail
    TreeCtrlComboPopup* tcPopup = new TreeCtrlComboPopup();
    gcc->SetPopupControl(tcPopup);
    // Add items using wxTreeCtrl methods directly
    wxTreeItemId rootId = tcPopup->AddRoot(wxT("<hidden_root>"));

    wxTreeItemId groupId;

    for(i=0; i<4; i++) {
        groupId = tcPopup->AppendItem(rootId,
            wxString::Format(wxT("Branch %02i"),i));
        int n;
        for ( n=0; n<25; n++ )
            tcPopup->AppendItem(groupId,
                wxString::Format(wxT("Subitem %02i"),(i*25)+n));
    }
    gcc->SetValue(wxT("Subitem 05"));

    // Move button to left - it makes more sense for a tree ctrl
    gcc->SetButtonPosition(-1, // button width
                           -1, // button height
                           wxLEFT, // side
                           0); // horizontal spacing

    rowSizer->Add( gcc, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

#if wxUSE_IMAGE
    wxInitAllImageHandlers();

    // Custom Dropbutton Bitmaps
    // (second one uses blank button background)
    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    rowSizer->Add( new wxStaticText(panel,wxID_ANY,
                   wxT("OwnerDrawnComboBox with simple dropbutton graphics:")), 1,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );

    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    rowSizer = new wxBoxSizer( wxHORIZONTAL );

    odc = new wxOwnerDrawnComboBox(panel,wxID_ANY,wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   (long)0); // wxCB_SORT // wxNO_BORDER | wxCB_READONLY
    wxOwnerDrawnComboBox* odc2;
    odc2 = new wxOwnerDrawnComboBox(panel,wxID_ANY,wxEmptyString,
                                    wxDefaultPosition, wxDefaultSize,
                                    m_arrItems,
                                    (long)0 // wxCB_SORT // wxNO_BORDER | wxCB_READONLY
                                   );
    // Load images from disk
    wxImage imgNormal( wxT("dropbutn.png"));
    wxImage imgPressed(wxT("dropbutp.png"));
    wxImage imgHover(  wxT("dropbuth.png"));

    if(imgNormal.IsOk() && imgPressed.IsOk() && imgHover.IsOk()) {
        wxBitmap bmpNormal(imgNormal);
        wxBitmap bmpPressed(imgPressed);
        wxBitmap bmpHover(imgHover);
        odc->SetButtonBitmaps(bmpNormal,false,bmpPressed,bmpHover);
        odc2->SetButtonBitmaps(bmpNormal,true,bmpPressed,bmpHover);
    } else
        wxLogError(wxT("Dropbutton images not found"));

    //odc2->SetButtonPosition(0, // width adjustment
    //                        0, // height adjustment
    //                        wxLEFT, // side
    //                        0 // horizontal spacing
    //                       );
    rowSizer->Add( odc,  1, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
    rowSizer->Add( odc2, 1, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );
#endif

    // wxComboCtrl with totally custom button action (open file dialog)
    
    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    rowSizer->Add( new wxStaticText(panel,wxID_ANY,
                        wxT("wxComboCtrl with custom button action:")), 1,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, 4 );

    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    rowSizer = new wxBoxSizer( wxHORIZONTAL );
    wxFileSelectorCombo* fsc;

    fsc = new wxFileSelectorCombo(panel,wxID_ANY,wxEmptyString,
                                  wxDefaultPosition, wxDefaultSize,
                                  (long)0);

    rowSizer->Add( fsc, 1, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
    colSizer->Add( rowSizer, 0, wxEXPAND|wxALL, 5 );

    // Make sure GetFeatures is implemented
    wxComboCtrl::GetFeatures();
    topRowSizer->Add( colSizer, 1, wxALL, 2 );
    colSizer = new wxBoxSizer( wxVERTICAL );

    colSizer->AddSpacer(8);
    colSizer->Add( new wxStaticText(panel, wxID_ANY, wxT("Log Messages:")), 0, wxTOP|wxLEFT, 3 );
    colSizer->Add( m_logWin, 1, wxEXPAND|wxALL, 3 );

    topRowSizer->Add( colSizer, 1, wxEXPAND|wxALL, 2 );
    topSizer->Add( topRowSizer, 1, wxEXPAND );

    panel->SetSizer( topSizer );
    topSizer->SetSizeHints( panel );

    Fit();
    Centre();
}
//**********************************************************
void Frame::OnComboBoxUpdate( wxCommandEvent &event ) {
    // Don't show messages for the log output window (it'll crash)
    if(!event.GetEventObject()->IsKindOf(CLASSINFO(wxComboCtrl)) )
        return;

    if(event.GetEventType() == wxEVT_COMBOBOX) {
        wxLogDebug(wxT("EVT_COMBOBOX(id=%i,selection=%i)"),event.GetId(),event.GetSelection());
    }
    else if(event.GetEventType() == wxEVT_TEXT) {
        wxLogDebug(wxT("EVT_TEXT(id=%i,string=\"%s\")"),event.GetId(),event.GetString().c_str());
    }
    else if(event.GetEventType() == wxEVT_TEXT_ENTER) {
		wxLogDebug("EVT_TEXT_ENTER(id=%i,string=\"%s\")",
                   event.GetId(), event.GetString().c_str());
    }
}

void Frame::OnShowComparison( wxCommandEvent &WXUNUSED(event)) {
    
    // Show some wxOwnerDrawComboBoxes for comparison
    wxBoxSizer       *colSizer;
    wxBoxSizer       *rowSizer;
    wxStaticBoxSizer *groupSizer;

    wxComboBox *cb;
    wxOwnerDrawnComboBox *odc;

    const int border = 4;

    wxDialog *dlg = new wxDialog(this,wxID_ANY,
                                 wxT("Compare against wxComboBox"),
                                 wxDefaultPosition,wxDefaultSize,
                                 wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

    colSizer   = new wxBoxSizer( wxVERTICAL );

    rowSizer   = new wxBoxSizer(wxHORIZONTAL);

    groupSizer = new wxStaticBoxSizer(new wxStaticBox(dlg,wxID_ANY,wxT(" wxOwnerDrawnComboBox ")),
                                      wxVERTICAL);

    groupSizer->Add( new wxStaticText(dlg, wxID_ANY,
                     wxT("Writable, with margins, sorted:")), 0,
                     wxALIGN_CENTER_VERTICAL|wxRIGHT|wxEXPAND, border );

    odc = new wxOwnerDrawnComboBox(dlg,wxID_ANY,wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   wxCB_SORT // wxNO_BORDER|wxCB_READONLY
                                  );

    odc->Append(wxT("H - Appended Item")); // test sorting in append

    odc->SetValue(wxT("Dot Dash"));
    odc->SetMargins(15, 10);
    groupSizer->Add( odc, 0, wxALIGN_CENTER_VERTICAL|wxALL, border );
    groupSizer->AddStretchSpacer();

    //
    // Readonly ODComboBox
    groupSizer->Add( new wxStaticText(dlg, wxID_ANY,
                     wxT("Read-only, big font:")), 0,
                     wxALIGN_CENTER_VERTICAL|wxRIGHT, border );

    odc = new wxOwnerDrawnComboBox(dlg,wxID_ANY,wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   wxCB_SORT|wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
                                  );

    odc->SetFont(odc->GetFont().Scale(1.5));
    odc->SetValue(wxT("Dot Dash"));
    odc->SetText(wxT("Dot Dash (Testing SetText)"));

    groupSizer->Add( odc, 0, wxALL, border );
    groupSizer->AddStretchSpacer();

    //
    // Disabled ODComboBox
    groupSizer->Add( new wxStaticText(dlg,wxID_ANY,wxT("Disabled:")), 0,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, border );

    odc = new wxOwnerDrawnComboBox(dlg,wxID_ANY,wxEmptyString,
                                     wxDefaultPosition, wxDefaultSize,
                                     m_arrItems,
                                     wxCB_SORT|wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
                                     );

    odc->SetValue(wxT("Dot Dash"));
    odc->Enable(false);

    groupSizer->Add( odc, 3, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, border );

    rowSizer->Add( groupSizer, 1, wxEXPAND|wxALL, border );


    groupSizer = new wxStaticBoxSizer(new wxStaticBox(dlg,wxID_ANY,wxT(" wxComboBox ")),
                                      wxVERTICAL);

    //
    // wxComboBox
    //
    groupSizer->Add( new wxStaticText(dlg,wxID_ANY,
                     wxT("Writable, with margins, sorted:")), 0,
                     wxALIGN_CENTER_VERTICAL|wxRIGHT|wxEXPAND, border );

    cb = new wxComboBox(dlg,wxID_ANY,wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_SORT // wxNO_BORDER|wxCB_READONLY
                       );

    cb->Append(wxT("H - Appended Item")); // test sorting in append

    cb->SetValue(wxT("Dot Dash"));
    cb->SetMargins(15, 10);
    groupSizer->Add( cb, 0, wxALIGN_CENTER_VERTICAL|wxALL, border );
    groupSizer->AddStretchSpacer();

    //
    // Readonly wxComboBox
    groupSizer->Add( new wxStaticText(dlg, wxID_ANY,
                     wxT("Read-only, big font:")), 0,
                     wxALIGN_CENTER_VERTICAL|wxRIGHT, border );

    cb = new wxComboBox(dlg,wxID_ANY,wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_SORT|wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
                       );

    cb->SetFont(cb->GetFont().Scale(1.5));
    cb->SetValue(wxT("Dot Dash"));

    groupSizer->Add( cb, 0, wxALL, border );
    groupSizer->AddStretchSpacer();

    //
    // Disabled wxComboBox
    groupSizer->Add( new wxStaticText(dlg,wxID_ANY,wxT("Disabled:")), 0,
                   wxALIGN_CENTER_VERTICAL|wxRIGHT, border );

    cb = new wxComboBox(dlg,wxID_ANY,wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_SORT|wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
                       );

    cb->SetValue(wxT("Dot Dash"));
    cb->Enable(false);

    groupSizer->Add( cb, 3, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, border );

    rowSizer->Add( groupSizer, 1, wxEXPAND|wxALL, border );

    colSizer->Add( rowSizer, 1, wxEXPAND|wxALL, border );

    dlg->SetSizer( colSizer );
    colSizer->SetSizeHints( dlg );

    dlg->SetSize(60,240);
    dlg->Centre();
    dlg->ShowModal();
}

Frame::~Frame() {
    delete wxLog::SetActiveTarget(m_logOld);
}

void Frame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    // true is to force the frame to close
    Close(true);
}

void Frame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(wxString::Format(
                    wxT("Welcome to %s!\n")
                    wxT("\n")
                    wxT("This is the wxWidgets wxComboCtrl and wxOwnerDrawnComboBox sample\n")
                    wxT("running under %s."),
                    wxVERSION_STRING,
                    wxGetOsDescription().c_str()
                 ),
                 wxT("About wxComboCtrl sample"),
                 wxOK | wxICON_INFORMATION,
                 this);
}

void Frame::OnIdle(wxIdleEvent& event)
{
    // This code is useful for debugging focus problems
    // (which are plentiful when dealing with popup windows).
#if 0
    static wxWindow* lastFocus = (wxWindow*) NULL;

    wxWindow* curFocus = ::wxWindow::FindFocus();

    if ( curFocus != lastFocus )
    {
        const wxChar* className = wxT("<none>");
        if ( curFocus )
            className = curFocus->GetClassInfo()->GetClassName();
        lastFocus = curFocus;
        wxLogDebug( wxT("FOCUSED: %s %X"),
            className,
            (unsigned int)curFocus);
    }
#endif

    event.Skip();
}

// ---------------------------------------------------------
// wxTreeCtrl EventTABLE
// ---------------------------------------------------------

wxBEGIN_EVENT_TABLE(TreeCtrlComboPopup, wxTreeCtrl)
    EVT_MOTION(   TreeCtrlComboPopup::OnMouseMove)
    // NOTE: Left down event is used instead of left up right now
    //       since MSW wxTreeCtrl doesn't seem to emit left ups
    //       consistently.
    EVT_LEFT_DOWN(TreeCtrlComboPopup::OnMouseClick)
wxEND_EVENT_TABLE()

// ---------------------------------------------------------
// wxListView EventTABLE
// ---------------------------------------------------------

wxBEGIN_EVENT_TABLE(ListViewComboPopup, wxListView)
    EVT_MOTION(   ListViewComboPopup::OnMouseMove)
    // NOTE: Left down event is used instead of left up right now
    //       since MSW wxListCtrl doesn't seem to emit left ups
    //       consistently.
    EVT_LEFT_DOWN(ListViewComboPopup::OnMouseClick)
wxEND_EVENT_TABLE()

// ---------------------------------------------------------
// wxFrame EventTABLE
// ---------------------------------------------------------
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_TEXT(      wxID_ANY,    Frame::OnComboBoxUpdate)
    EVT_TEXT_ENTER(wxID_ANY,    Frame::OnComboBoxUpdate)
    EVT_COMBOBOX(  wxID_ANY,    Frame::OnComboBoxUpdate)

    EVT_MENU(ComboCtrl_Compare, Frame::OnShowComparison)
    EVT_MENU(ComboCtrl_Quit,    Frame::OnQuit)
    EVT_MENU(ComboCtrl_About,   Frame::OnAbout)

    EVT_IDLE(Frame::OnIdle)
wxEND_EVENT_TABLE()

