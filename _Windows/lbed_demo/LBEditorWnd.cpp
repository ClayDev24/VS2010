// LBEditorWnd.cpp : implementation file
//
//@doc

#include "stdafx.h"
#include "LBEditorWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/*
 *		@mfunc Constructor
 */
CLBEditorWnd::CLBEditorWnd( 
		CListBox* pLB	// @parm Pointer to list box containing item to edit
	)
{
	m_pLB = pLB ;
	m_edit_ended = false ;
}

/*
 *		Destructor -- protected to prevent allocation on the stack
 *			since object will be deleted when window is destroyed
 */
CLBEditorWnd::~CLBEditorWnd()
{
}


BEGIN_MESSAGE_MAP(CLBEditorWnd, CEdit)
	//{{AFX_MSG_MAP(CLBEditorWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_NCDESTROY()
	ON_WM_KEYDOWN()
	ON_WM_GETDLGCODE()
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/*
 *		@mfunc Starts editing item
 *
 *		@rdesc True if editing was started. False if n is not a valid index for the
 *			list box being edited
 */
bool CLBEditorWnd::Edit(
		int n		// @parm Index of item in list box to edit
	)
{
	// 
	//	Invalid index, return false, deletes object
	//
	if ( n < 0 || n >= m_pLB->GetCount() )
	{
		delete this ;
		return false ;
	}

	m_edit_index = n ;

	CString s ;
	m_pLB->GetText( n, s ) ;

	CRect r ;
	m_pLB->GetItemRect( n, &r ) ;
	r.InflateRect( 1, 1 ) ;

	Create( WS_BORDER | WS_CHILD | WS_VISIBLE | ES_WANTRETURN, r, m_pLB, 1 ) ;
	SetFont( m_pLB->GetFont()) ;

	SetWindowText( s ) ;
	SetCapture() ;
	SetFocus() ;

	return true ;
}

/*
 *		Handler for mouse click, end editing if outside this window
 */
void CLBEditorWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	ClientToScreen( &point ) ;
	if ( WindowFromPoint( point ) != this )
		EndEditing() ;
	else
		CEdit::OnLButtonDown(nFlags, point);
}

/*
 *		Delete C++ object when window is destroyed
 */
void CLBEditorWnd::OnNcDestroy() 
{
	CEdit::OnNcDestroy();
	
	delete this ;
}

/*
 *		Handler for keyboard, ends editing on tab, return, or escape key
 *		leaving listbox entry unchanged for escape key only
 */
void CLBEditorWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar )
	{
	case VK_ESCAPE:
		EndEditing( false ) ;
	case VK_TAB:
	case VK_RETURN:
		EndEditing() ;
		break ;
	default:
		CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
		break ;
	}
}

/*
 *		@mfunc Ends editing sequence
 */
void CLBEditorWnd::EndEditing(
		bool b		// @parmopt bool | b | true | If true, the list box item is updated
	)
{
	// Prevent multiple calls.  
	//
	//		EndEditing() may cause loss of focus, but so may other actions in which case
	//		we need to call EndEditing().  Even though we try to clear the message queue below
	//		we can't completely eliminate the possibility of recursion, so we use a flag
	//		to stop it.
	//
	if ( m_edit_ended )
		return ;

	m_edit_ended = true ;
	ReleaseCapture() ;
	if (b )
	{
		//
		//		Update the list box
		//
		CString s ;
		GetWindowText( s ) ;

		m_pLB->DeleteString( m_edit_index ) ;
		m_pLB->InsertString( m_edit_index, s ) ;
		m_pLB->SetCurSel( m_edit_index ) ;
	}

	MSG msg ;
	while ( ::PeekMessage( &msg, m_hWnd, 0, 0, PM_REMOVE ) )
		;

	DestroyWindow() ;
}

/*
 *		Tell Windows that we need to get all WM_KEYDOWN messages
 */
UINT CLBEditorWnd::OnGetDlgCode() 
{
	return DLGC_WANTALLKEYS ;
}

/*
 *		Handler for kill focus reflection, ends edit sequence.  Things like Alt-tabbing to 
 *			another program will cause this to happen in a way which can't be trapped by any
 *			other method
 */
void CLBEditorWnd::OnKillfocus() 
{
	EndEditing() ;
}
