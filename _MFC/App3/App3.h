// App3.h : main header file for the APP3 application
//

#if !defined(AFX_APP3_H__2C65F191_37DD_467C_B7BA_2D09D36BB56D__INCLUDED_)
#define AFX_APP3_H__2C65F191_37DD_467C_B7BA_2D09D36BB56D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CApp3App:
// See App3.cpp for the implementation of this class
//

class CApp3App : public CWinApp
{
public:
	CApp3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CApp3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP3_H__2C65F191_37DD_467C_B7BA_2D09D36BB56D__INCLUDED_)
