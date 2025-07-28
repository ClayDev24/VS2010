#include "../_Framework/headers.h"
#include "wx/odcombo.h"
#include "IDs.h"

// Define a new frame type: this is going to be our main frame
class Frame : public wxFrame {
public:
    Frame(const wxString &title);
    ~Frame();

    // event handlers (these functions should _not_ be virtual)
    void OnQuit( wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    void OnShowComparison( wxCommandEvent &event );
    // log wxComboCtrl events
    void OnComboBoxUpdate( wxCommandEvent &event );

    void OnIdle( wxIdleEvent &event );

protected:
    wxTextCtrl *m_logWin;
    wxLog      *m_logOld;
    // Common list of items for all dialogs.
    wxArrayString m_arrItems;

private:
    wxDECLARE_EVENT_TABLE();
};


// ============================================================================
// implementation
// ============================================================================
class wxPenStyleComboBox : public wxOwnerDrawnComboBox
{
public:
    virtual void OnDrawItem( wxDC& dc,
                             const wxRect& rect,
                             int item,
                             int flags ) const
    {
        if ( item == wxNOT_FOUND )
            return;

        wxRect r(rect);
        r.Deflate(3);
        r.height -= 2;

        wxPenStyle penStyle = wxPENSTYLE_SOLID;
        if ( item == 1 )
            penStyle = wxPENSTYLE_TRANSPARENT;
        else if ( item == 2 )
            penStyle = wxPENSTYLE_DOT;
        else if ( item == 3 )
            penStyle = wxPENSTYLE_LONG_DASH;
        else if ( item == 4 )
            penStyle = wxPENSTYLE_SHORT_DASH;
        else if ( item == 5 )
            penStyle = wxPENSTYLE_DOT_DASH;
        else if ( item == 6 )
            penStyle = wxPENSTYLE_BDIAGONAL_HATCH;
        else if ( item == 7 )
            penStyle = wxPENSTYLE_CROSSDIAG_HATCH;
        else if ( item == 8 )
            penStyle = wxPENSTYLE_FDIAGONAL_HATCH;
        else if ( item == 9 )
            penStyle = wxPENSTYLE_CROSS_HATCH;
        else if ( item == 10 )
            penStyle = wxPENSTYLE_HORIZONTAL_HATCH;
        else if ( item == 11 )
            penStyle = wxPENSTYLE_VERTICAL_HATCH;

        wxPen pen( dc.GetTextForeground(), 3, penStyle );

        // Get text colour as pen colour
        dc.SetPen( pen );

        if ( !(flags & wxODCB_PAINTING_CONTROL) )
        {
            dc.DrawText(GetString( item ),
                        r.x + 3,
                        (r.y + 0) + ( (r.height/2) - dc.GetCharHeight() )/2
                       );

            dc.DrawLine( r.x+5, r.y+((r.height/4)*3), r.x+r.width - 5, r.y+((r.height/4)*3) );
        }
        else
        {
            dc.DrawLine( r.x+5, r.y+r.height/2, r.x+r.width - 5, r.y+r.height/2 );
        }
    }

    virtual void OnDrawBackground( wxDC& dc, const wxRect& rect,
                                   int item, int flags ) const
    {

        // If item is selected or even, or we are painting the
        // combo control itself, use the default rendering.
        if ( (flags & (wxODCB_PAINTING_CONTROL|wxODCB_PAINTING_SELECTED)) ||
             (item & 1) == 0 )
        {
            wxOwnerDrawnComboBox::OnDrawBackground(dc,rect,item,flags);
            return;
        }

        // Otherwise, draw every other background with different colour.
        wxColour bgCol(240,240,250);
        dc.SetBrush(wxBrush(bgCol));
        dc.SetPen(wxPen(bgCol));
        dc.DrawRectangle(rect);
    }

    virtual wxCoord OnMeasureItem( size_t item ) const
    {
        // Simply demonstrate the ability to have variable-height items
        if ( item & 1 )
            return 36;
        else
            return 24;
    }

    virtual wxCoord OnMeasureItemWidth( size_t WXUNUSED(item) ) const
    {
        return -1; // default - will be measured from text width
    }

};
// ---------------------------------------------------------
// wxListView Custom popup interface
// ---------------------------------------------------------
#include <wx/listctrl.h>

class ListViewComboPopup : public wxListView, public wxComboPopup
{
public:

    virtual void Init()
    {
        m_value = -1;
        m_itemHere = -1; // hot item in list
    }

    virtual bool Create( wxWindow* parent )
    {
        return wxListView::Create(parent,1,
                                  wxPoint(0,0),wxDefaultSize,
                                  wxLC_LIST|wxLC_SINGLE_SEL|
                                  wxLC_SORT_ASCENDING|wxSIMPLE_BORDER);
    }

    virtual wxWindow *GetControl() { return this; }

    virtual void SetStringValue( const wxString& s )
    {
        int n = wxListView::FindItem(-1,s);
        if ( n >= 0 && n < GetItemCount() )
            wxListView::Select(n);
    }

    virtual wxString GetStringValue() const
    {
        if ( m_value >= 0 )
            return wxListView::GetItemText(m_value);
        return wxEmptyString;
    }

    //
    // Popup event handlers
    //

    // Mouse hot-tracking
    void OnMouseMove(wxMouseEvent& event)
    {
        // Move selection to cursor if it is inside the popup

        int resFlags;
        int itemHere = HitTest(event.GetPosition(),resFlags);
        if ( itemHere >= 0 )
        {
            wxListView::Select(itemHere,true);
            m_itemHere = itemHere;
        }
        event.Skip();
    }

    // On mouse left, set the value and close the popup
    void OnMouseClick(wxMouseEvent& WXUNUSED(event))
    {
        m_value = m_itemHere;
        // TODO: Send event
        Dismiss();
    }

    //
    // Utilies for item manipulation
    //

    void AddSelection( const wxString& selstr )
    {
        wxListView::InsertItem(GetItemCount(),selstr);
    }

protected:

    int             m_value; // current item index
    int             m_itemHere; // hot item in popup

private:
    wxDECLARE_EVENT_TABLE();
};
// ---------------------------------------------------------
// wxTreeCtrl Custom popup interface
// ---------------------------------------------------------
#include <wx/treectrl.h>

class TreeCtrlComboPopup : public wxTreeCtrl, public wxComboPopup
{
public:

    virtual void Init()
    {
    }
    virtual ~TreeCtrlComboPopup()
    {
        if (!m_isBeingDeleted)
        {
            wxMessageBox("error wxTreeCtrl::Destroy() was not called");
        }
        SendDestroyEvent();
    }

    virtual bool Create( wxWindow* parent )
    {
        return wxTreeCtrl::Create(parent,1,
                                  wxPoint(0,0),wxDefaultSize,
                                  wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT | wxSIMPLE_BORDER );
    }

    virtual void OnShow()
    {
        // make sure selected item is visible
        if ( m_value.IsOk() )
            EnsureVisible(m_value);
    }

    virtual wxSize GetAdjustedSize( int minWidth,
                                    int WXUNUSED(prefHeight),
                                    int maxHeight )
    {
        return wxSize(wxMax(300,minWidth),wxMin(250,maxHeight));
    }

    virtual wxWindow *GetControl() { return this; }

    // Needed by SetStringValue
    wxTreeItemId FindItemByText( wxTreeItemId parent, const wxString& text )
    {
        wxTreeItemIdValue cookie;
        wxTreeItemId child = GetFirstChild(parent,cookie);
        while ( child.IsOk() )
        {
            if ( GetItemText(child) == text )
            {
                return child;
            }
            if ( ItemHasChildren(child) )
            {
                wxTreeItemId found = FindItemByText(child,text);
                if ( found.IsOk() )
                    return found;
            }
            child = GetNextChild(parent,cookie);
        }
        return wxTreeItemId();
    }

    virtual void SetStringValue( const wxString& s )
    {
        wxTreeItemId root = GetRootItem();
        if ( !root.IsOk() )
            return;

        wxTreeItemId found = FindItemByText(root,s);
        if ( found.IsOk() )
        {
            m_value = m_itemHere = found;
            wxTreeCtrl::SelectItem(found);
        }
    }

    virtual wxString GetStringValue() const
    {
        if ( m_value.IsOk() )
            return wxTreeCtrl::GetItemText(m_value);
        return wxEmptyString;
    }

    //
    // Popup event handlers
    //

    // Mouse hot-tracking
    void OnMouseMove(wxMouseEvent& event)
    {
        int resFlags;
        wxTreeItemId itemHere = HitTest(event.GetPosition(),resFlags);
        if ( itemHere.IsOk() && (resFlags & wxTREE_HITTEST_ONITEMLABEL) )
        {
            wxTreeCtrl::SelectItem(itemHere,true);
            m_itemHere = itemHere;
        }
        event.Skip();
    }

    // On mouse left, set the value and close the popup
    void OnMouseClick(wxMouseEvent& event)
    {
        int resFlags;
        wxTreeItemId itemHere = HitTest(event.GetPosition(),resFlags);
        if ( itemHere.IsOk() && (resFlags & wxTREE_HITTEST_ONITEMLABEL) )
        {
            m_itemHere = itemHere;
            m_value = itemHere;
            Dismiss();
            // TODO: Send event
        }
        event.Skip();
    }

protected:

    wxTreeItemId        m_value; // current item index
    wxTreeItemId        m_itemHere; // hot item in popup

private:
    wxDECLARE_EVENT_TABLE();
};
// ---------------------------------------------------------
// wxComboCtrl with custom popup animation, using wxWindow::ShowWithEffect().
// ---------------------------------------------------------

class wxComboCtrlWithCustomPopupAnim : public wxComboCtrl
{
protected:
    virtual bool AnimateShow( const wxRect& rect, int WXUNUSED(flags) )
    {
        wxWindow* win = GetPopupWindow();
        win->SetSize(rect);
        win->Raise();  // This is needed
        win->ShowWithEffect(wxSHOW_EFFECT_BLEND);
        return true;
    }
};

// ---------------------------------------------------------
// wxComboCtrl with entirely custom button action (opens file dialog)
// ---------------------------------------------------------

class wxFileSelectorCombo : public wxComboCtrl
{
public:
    wxFileSelectorCombo() : wxComboCtrl() { Init(); }

    wxFileSelectorCombo(wxWindow *parent,
                        wxWindowID id = wxID_ANY,
                        const wxString& value = wxEmptyString,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = 0,
                        const wxValidator& validator = wxDefaultValidator,
                        const wxString& name = wxComboBoxNameStr)
        : wxComboCtrl()
    {
        Init();
        Create(parent,id,value,
               pos,size,
               // Style flag wxCC_STD_BUTTON makes the button
               // behave more like a standard push button.
               style | wxCC_STD_BUTTON,
               validator,name);

        //
        // Prepare custom button bitmap (just '...' text)
        wxMemoryDC dc;
        wxBitmap bmp(12,16);
        dc.SelectObject(bmp);

        // Draw transparent background
        wxColour magic(255,0,255);
        wxBrush magicBrush(magic);
        dc.SetBrush( magicBrush );
        dc.SetPen( *wxTRANSPARENT_PEN );
        dc.DrawRectangle(0,0,bmp.GetWidth(),bmp.GetHeight());

        // Draw text
        wxString str = wxT("...");
        int w,h;
        dc.GetTextExtent(str, &w, &h, 0, 0);
        dc.DrawText(str, (bmp.GetWidth()-w)/2, (bmp.GetHeight()-h)/2);

        dc.SelectObject( wxNullBitmap );

        // Finalize transparency with a mask
        wxMask *mask = new wxMask( bmp, magic );
        bmp.SetMask( mask );

        SetButtonBitmaps(bmp,true);
    }

    virtual void OnButtonClick()
    {
        // Show standard wxFileDialog on button click

        wxFileDialog dlg(this,
                         wxT("Choose File"),
                         wxEmptyString,
                         GetValue(),
                         wxT("All files (*.*)|*.*"),
                         wxFD_OPEN);

        if ( dlg.ShowModal() == wxID_OK )
        {
            SetValue(dlg.GetPath());
        }
    }
    // Implement empty DoSetPopupControl to prevent assertion failure.
    virtual void DoSetPopupControl(wxComboPopup* WXUNUSED(popup))
    {}

private:
	void Init() {} // Initialize member variables here
};

