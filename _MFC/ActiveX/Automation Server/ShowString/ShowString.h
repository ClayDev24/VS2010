// ShowString.h : main header file for the SHOWSTRING application
//

#if !defined(AFX_SHOWSTRING_H__27D8419E_2EFF_4543_9845_756C25A20377__INCLUDED_)
#define AFX_SHOWSTRING_H__27D8419E_2EFF_4543_9845_756C25A20377__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowStringApp:
// See ShowString.cpp for the implementation of this class
//

class CShowStringApp : public CWinApp
{
public:
	CShowStringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CShowStringApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRING_H__27D8419E_2EFF_4543_9845_756C25A20377__INCLUDED_)
