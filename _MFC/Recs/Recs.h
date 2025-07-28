// Recs.h : main header file for the RECS application
//

#if !defined(AFX_RECS_H__8D0AB455_6CBB_4C46_8530_28EDDD12F79D__INCLUDED_)
#define AFX_RECS_H__8D0AB455_6CBB_4C46_8530_28EDDD12F79D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecsApp:
// See Recs.cpp for the implementation of this class
//

class CRecsApp : public CWinApp
{
public:
	CRecsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRecsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECS_H__8D0AB455_6CBB_4C46_8530_28EDDD12F79D__INCLUDED_)
