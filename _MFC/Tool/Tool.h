// Tool.h : main header file for the TOOL application
//

#if !defined(AFX_TOOL_H__D24992D3_3F20_42C1_8B5F_84634045E0BB__INCLUDED_)
#define AFX_TOOL_H__D24992D3_3F20_42C1_8B5F_84634045E0BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolApp:
// See Tool.cpp for the implementation of this class
//

class CToolApp : public CWinApp
{
public:
	CToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CToolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOL_H__D24992D3_3F20_42C1_8B5F_84634045E0BB__INCLUDED_)
