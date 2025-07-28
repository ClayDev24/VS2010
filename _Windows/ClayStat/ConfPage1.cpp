// ConfPage1.cpp : implementation file
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "ConfPage1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfPage1 property page

IMPLEMENT_DYNCREATE(CConfPage1, CPropertyPage)

CConfPage1::CConfPage1() : CPropertyPage(CConfPage1::IDD)
{
	//{{AFX_DATA_INIT(CConfPage1)
	m_period = 7;
	m_pack = 500;
	//}}AFX_DATA_INIT
}

CConfPage1::~CConfPage1()
{
}

void CConfPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfPage1)
	DDX_Text(pDX, IDC_PERIOD, m_period);
	DDX_Text(pDX, IDC_PACKAGE, m_pack);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CConfPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfPage1 message handlers
