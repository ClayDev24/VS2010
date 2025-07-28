#if !defined(AFX_CONFPAGE1_H__4BC95E3A_A8D5_4E18_8468_F4655F5DD08A__INCLUDED_)
#define AFX_CONFPAGE1_H__4BC95E3A_A8D5_4E18_8468_F4655F5DD08A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfPage1.h : header file
//

#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CConfPage1 dialog

class CConfPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CConfPage1)

// Construction
public:
	CConfPage1();
	~CConfPage1();

// Dialog Data
	//{{AFX_DATA(CConfPage1)
	enum { IDD = IDD_PAGE1DLG };
	int		m_period;
	int		m_pack;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CConfPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CConfPage1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFPAGE1_H__4BC95E3A_A8D5_4E18_8468_F4655F5DD08A__INCLUDED_)
