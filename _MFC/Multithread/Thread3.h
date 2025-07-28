// Thread3.h : main header file for the THREAD3 application
//

#if !defined(AFX_THREAD3_H__C89A3110_43A8_4C4A_86A9_C4350B98E4D6__INCLUDED_)
#define AFX_THREAD3_H__C89A3110_43A8_4C4A_86A9_C4350B98E4D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CThread3App:
// See Thread3.cpp for the implementation of this class
//

class CThread3App : public CWinApp
{
public:
	CThread3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThread3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CThread3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREAD3_H__C89A3110_43A8_4C4A_86A9_C4350B98E4D6__INCLUDED_)
