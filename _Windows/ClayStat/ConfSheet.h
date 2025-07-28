#if !defined(AFX_CONFSHEET_H__60356F54_1725_4261_850F_A26355C574BF__INCLUDED_)
#define AFX_CONFSHEET_H__60356F54_1725_4261_850F_A26355C574BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfSheet

#include "ConfPage1.h"
#include "ConfPage2.h"

class CConfSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CConfSheet)

// Construction
public:
	CConfSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CConfSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CConfPage1 m_page1;
	CConfPage2 m_page2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CConfSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CConfSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFSHEET_H__60356F54_1725_4261_850F_A26355C574BF__INCLUDED_)
