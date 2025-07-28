// Paint1.h : main header file for the PAINT1 application
//

#if !defined(AFX_PAINT1_H__C8B34B66_DF6A_4588_85CA_0E55CDBC4806__INCLUDED_)
#define AFX_PAINT1_H__C8B34B66_DF6A_4588_85CA_0E55CDBC4806__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPaint1App:
// See Paint1.cpp for the implementation of this class
//

class CPaint1App : public CWinApp
{
public:
	CPaint1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaint1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPaint1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT1_H__C8B34B66_DF6A_4588_85CA_0E55CDBC4806__INCLUDED_)
