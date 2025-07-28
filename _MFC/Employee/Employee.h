// Employee.h : main header file for the EMPLOYEE application
//

#if !defined(AFX_EMPLOYEE_H__6EFF1560_BB73_47DC_BF3E_B9E18EBEC345__INCLUDED_)
#define AFX_EMPLOYEE_H__6EFF1560_BB73_47DC_BF3E_B9E18EBEC345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmployeeApp:
// See Employee.cpp for the implementation of this class
//

class CEmployeeApp : public CWinApp
{
public:
	CEmployeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEmployeeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEE_H__6EFF1560_BB73_47DC_BF3E_B9E18EBEC345__INCLUDED_)
