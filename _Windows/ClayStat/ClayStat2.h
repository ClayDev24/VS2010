// ClayStat2.h : main header file for the CLAYSTAT2 application
//

#if !defined(AFX_CLAYSTAT2_H__63BB53BE_2407_4D5E_B0F4_476BE829C924__INCLUDED_)
#define AFX_CLAYSTAT2_H__63BB53BE_2407_4D5E_B0F4_476BE829C924__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// ClayStat2App:
// See ClayStat2.cpp for the implementation of this class
//

class ClayStat2App : public CWinApp
{
public:
	ClayStat2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ClayStat2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(ClayStat2App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLAYSTAT2_H__63BB53BE_2407_4D5E_B0F4_476BE829C924__INCLUDED_)
