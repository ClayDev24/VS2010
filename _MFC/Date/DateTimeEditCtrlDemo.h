// DateTimeEditCtrlDemo.h : main header file for the DATETIMEEDITCTRLDEMO application
//

#if !defined(AFX_DATETIMEEDITCTRLDEMO_H__0DB4FDED_D589_488C_A4A0_0BF2308E80D5__INCLUDED_)
#define AFX_DATETIMEEDITCTRLDEMO_H__0DB4FDED_D589_488C_A4A0_0BF2308E80D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlDemoApp:
// See DateTimeEditCtrlDemo.cpp for the implementation of this class
//

class CDateTimeEditCtrlDemoApp : public CWinApp
{
public:
	CDateTimeEditCtrlDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeEditCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDateTimeEditCtrlDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATETIMEEDITCTRLDEMO_H__0DB4FDED_D589_488C_A4A0_0BF2308E80D5__INCLUDED_)
