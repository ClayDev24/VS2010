#if !defined(AFX_DIALOGSEARCH_H__743CBC07_8A8A_4719_A6BC_1AD71DA4AB01__INCLUDED_)
#define AFX_DIALOGSEARCH_H__743CBC07_8A8A_4719_A6BC_1AD71DA4AB01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSearch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogSearch dialog

class CDialogSearch : public CDialog
{
// Construction
public:
	CDialogSearch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogSearch)
	enum { IDD = IDD_SEARCH };
	CString	m_campo;
	int		m_radio;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogSearch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogSearch)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSEARCH_H__743CBC07_8A8A_4719_A6BC_1AD71DA4AB01__INCLUDED_)
