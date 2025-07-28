// App4.h : main header file for the APP4 application
//

#if !defined(AFX_ORIGINAL_H__FC704F84_755F_4663_BB16_7ECFF3F789C3__INCLUDED_)
#define AFX_ORIGINAL_H__FC704F84_755F_4663_BB16_7ECFF3F789C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CApp4App:
// See App4.cpp for the implementation of this class
//

class CApp4App : public CWinApp
{
public:
	CApp4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CApp4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORIGINAL_H__FC704F84_755F_4663_BB16_7ECFF3F789C3__INCLUDED_)
