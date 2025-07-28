// DateClass.h : main header file for the DATECLASS application
//

#if !defined(AFX_DATECLASS_H__3DD52FE4_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
#define AFX_DATECLASS_H__3DD52FE4_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDateClassApp:
// See DateClass.cpp for the implementation of this class
//

class CDateClassApp : public CWinApp
{
public:
	CDateClassApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateClassApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDateClassApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATECLASS_H__3DD52FE4_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
