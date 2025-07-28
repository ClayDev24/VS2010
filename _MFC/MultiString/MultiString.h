// MultiString.h : main header file for the MULTISTRING application
//

#if !defined(AFX_MULTISTRING_H__B265CA3F_76F5_48F5_AA3B_E8D5677A87F1__INCLUDED_)
#define AFX_MULTISTRING_H__B265CA3F_76F5_48F5_AA3B_E8D5677A87F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiStringApp:
// See MultiString.cpp for the implementation of this class
//

class CMultiStringApp : public CWinApp
{
public:
	CMultiStringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiStringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiStringApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISTRING_H__B265CA3F_76F5_48F5_AA3B_E8D5677A87F1__INCLUDED_)
