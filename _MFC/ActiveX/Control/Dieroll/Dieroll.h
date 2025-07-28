#if !defined(AFX_DIEROLL_H__513592F2_295C_4144_B7EA_99D6083A4795__INCLUDED_)
#define AFX_DIEROLL_H__513592F2_295C_4144_B7EA_99D6083A4795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Dieroll.h : main header file for DIEROLL.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDierollApp : See Dieroll.cpp for implementation.

class CDierollApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIEROLL_H__513592F2_295C_4144_B7EA_99D6083A4795__INCLUDED)
