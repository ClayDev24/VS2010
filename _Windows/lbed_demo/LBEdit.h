// LBEdit.h : main header file for the LBEDIT application
//

#if !defined(AFX_LBEDIT_H__B11AA1B2_DD6B_48E1_A9F4_B381152D3D50__INCLUDED_)
#define AFX_LBEDIT_H__B11AA1B2_DD6B_48E1_A9F4_B381152D3D50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLBEditApp:
// See LBEdit.cpp for the implementation of this class
//

class CLBEditApp : public CWinApp
{
public:
	CLBEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLBEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLBEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LBEDIT_H__B11AA1B2_DD6B_48E1_A9F4_B381152D3D50__INCLUDED_)
