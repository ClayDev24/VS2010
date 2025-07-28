// ConfPage2.cpp : implementation file
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "ConfPage2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfPage2 property page

IMPLEMENT_DYNCREATE(CConfPage2, CPropertyPage)

CConfPage2::CConfPage2() : CPropertyPage(CConfPage2::IDD)
{
	//{{AFX_DATA_INIT(CConfPage2)
	m_email = _T("seu_email@zzz.zz.z");
	m_nick = _T("Kenny");
	//}}AFX_DATA_INIT
}

CConfPage2::~CConfPage2()
{
}

void CConfPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfPage2)
	DDX_Text(pDX, IDC_EMAIL, m_email);
	DDX_Text(pDX, IDC_NICK, m_nick);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CConfPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfPage2 message handlers
