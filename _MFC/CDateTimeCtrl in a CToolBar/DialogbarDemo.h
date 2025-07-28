// DialogbarDemo.h : main header file for the DIALOGBARDEMO application
//

#if !defined(AFX_DIALOGBARDEMO_H__D614B244_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
#define AFX_DIALOGBARDEMO_H__D614B244_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoApp:
// See DialogbarDemo.cpp for the implementation of this class
//

class CDialogbarDemoApp : public CWinApp
{
public:
	CDialogbarDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogbarDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogbarDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBARDEMO_H__D614B244_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
