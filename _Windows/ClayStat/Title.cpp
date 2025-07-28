// Title.cpp : implementation file
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "ClayStat2View.h"
#include "Title.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitle dialog


CTitle::CTitle(CWnd* pParent /*=NULL*/)
	: CDialog(CTitle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTitle)
	ClayStat2View *pai = (ClayStat2View*)pParent;
	CString s = pai->pDoc->m_estat->m_subject;
	m_title = s;//_T("");
	//}}AFX_DATA_INIT
}


void CTitle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTitle)
	DDX_Text(pDX, IDC_TITLE, m_title);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTitle, CDialog)
	//{{AFX_MSG_MAP(CTitle)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitle message handlers
