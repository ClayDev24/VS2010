// Scroll.h : main header file for the SCROLL application
//

#if !defined(AFX_SCROLL_H__2CE20534_FA6F_45FF_B1DF_B271B5437938__INCLUDED_)
#define AFX_SCROLL_H__2CE20534_FA6F_45FF_B1DF_B271B5437938__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CScrollApp:
// See Scroll.cpp for the implementation of this class
//

class CScrollApp : public CWinApp
{
public:
	CScrollApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CScrollApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLL_H__2CE20534_FA6F_45FF_B1DF_B271B5437938__INCLUDED_)
