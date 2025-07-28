// ConfSheet.cpp : implementation file
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "ConfSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfSheet

IMPLEMENT_DYNAMIC(CConfSheet, CPropertySheet)

CConfSheet::CConfSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}

CConfSheet::CConfSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}

CConfSheet::~CConfSheet()
{
}


BEGIN_MESSAGE_MAP(CConfSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CConfSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfSheet message handlers
