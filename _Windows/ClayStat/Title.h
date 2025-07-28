#if !defined(AFX_TITLE_H__AC6789A3_B6F6_4F52_A67E_5DAAF522A0F4__INCLUDED_)
#define AFX_TITLE_H__AC6789A3_B6F6_4F52_A67E_5DAAF522A0F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Title.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTitle dialog

class CTitle : public CDialog
{
// Construction
public:
	CTitle(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTitle)
	enum { IDD = IDD_TITLE };
	CString	m_title;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTitle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLE_H__AC6789A3_B6F6_4F52_A67E_5DAAF522A0F4__INCLUDED_)
