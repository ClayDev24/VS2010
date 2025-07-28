// fileDemo.h : main header file for the FILEDEMO application
//

#if !defined(AFX_FILEDEMO_H__3AC372F9_49CF_487D_823E_FEF93F608242__INCLUDED_)
#define AFX_FILEDEMO_H__3AC372F9_49CF_487D_823E_FEF93F608242__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileDemoApp:
// See fileDemo.cpp for the implementation of this class
//

class CFileDemoApp : public CWinApp
{
public:
	CFileDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFileDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDEMO_H__3AC372F9_49CF_487D_823E_FEF93F608242__INCLUDED_)
