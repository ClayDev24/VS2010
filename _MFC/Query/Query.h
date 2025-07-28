// Query.h : main header file for the QUERY application
//

#if !defined(AFX_QUERY_H__D1C6222F_3F1C_4191_B18A_B39D68A99655__INCLUDED_)
#define AFX_QUERY_H__D1C6222F_3F1C_4191_B18A_B39D68A99655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQueryApp:
// See Query.cpp for the implementation of this class
//

class CQueryApp : public CWinApp
{
public:
	CQueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERY_H__D1C6222F_3F1C_4191_B18A_B39D68A99655__INCLUDED_)
