// using dll.h : main header file for the USING DLL application
//

#if !defined(AFX_USINGDLL_H__D6477D36_AF90_4086_870A_37DAE23231F9__INCLUDED_)
#define AFX_USINGDLL_H__D6477D36_AF90_4086_870A_37DAE23231F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUsingdllApp:
// See using dll.cpp for the implementation of this class
//

class CUsingdllApp : public CWinApp
{
public:
	CUsingdllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsingdllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUsingdllApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USINGDLL_H__D6477D36_AF90_4086_870A_37DAE23231F9__INCLUDED_)
