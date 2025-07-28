#if !defined(AFX_CONFPAGE2_H__90A83045_7F70_45A9_9085_BBEBCA5F7D1D__INCLUDED_)
#define AFX_CONFPAGE2_H__90A83045_7F70_45A9_9085_BBEBCA5F7D1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfPage2.h : header file
//

#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CConfPage2 dialog

class CConfPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CConfPage2)

// Construction
public:
	CConfPage2();
	~CConfPage2();

// Dialog Data
	//{{AFX_DATA(CConfPage2)
	enum { IDD = IDD_PAGE2DLG };
	CString	m_email;
	CString	m_nick;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CConfPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CConfPage2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFPAGE2_H__90A83045_7F70_45A9_9085_BBEBCA5F7D1D__INCLUDED_)
