// Char Listing.h : main header file for the CHAR LISTING application
//

#if !defined(AFX_CHARLISTING_H__360F867B_6CCD_4C52_A6B7_DC88C85D27FF__INCLUDED_)
#define AFX_CHARLISTING_H__360F867B_6CCD_4C52_A6B7_DC88C85D27FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCharListingApp:
// See Char Listing.cpp for the implementation of this class
//

class CCharListingApp : public CWinApp
{
public:
	CCharListingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharListingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCharListingApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARLISTING_H__360F867B_6CCD_4C52_A6B7_DC88C85D27FF__INCLUDED_)
