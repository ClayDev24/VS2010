// App2.h : main header file for the APP2 application
//

#if !defined(AFX_APP2_H__3E38D471_44D0_41DF_8462_28AA3E65D8E6__INCLUDED_)
#define AFX_APP2_H__3E38D471_44D0_41DF_8462_28AA3E65D8E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CApp2App:
// See App2.cpp for the implementation of this class
//

class CApp2App : public CWinApp
{
public:
	CApp2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CApp2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP2_H__3E38D471_44D0_41DF_8462_28AA3E65D8E6__INCLUDED_)
