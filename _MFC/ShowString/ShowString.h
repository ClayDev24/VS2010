// ShowString.h : main header file for the SHOWSTRING application
//

#if !defined(AFX_SHOWSTRING_H__DB4F9E17_C46D_4E49_9E57_EF7087EBD0A3__INCLUDED_)
#define AFX_SHOWSTRING_H__DB4F9E17_C46D_4E49_9E57_EF7087EBD0A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#define HID_CENTERING 0x01

/////////////////////////////////////////////////////////////////////////////
// CShowStringApp:
// See ShowString.cpp for the implementation of this class
//

class CShowStringApp : public CWinApp
{
public:
	CShowStringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowStringApp)
	afx_msg void OnAppAbout();
	afx_msg void OnHelpUnderstandingcentering();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRING_H__DB4F9E17_C46D_4E49_9E57_EF7087EBD0A3__INCLUDED_)
