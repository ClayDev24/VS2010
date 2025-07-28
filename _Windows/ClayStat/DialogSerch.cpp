// DialogSearch.cpp : implementation file
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "DialogSerch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogSearch dialog


CDialogSearch::CDialogSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSearch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSearch)
	m_campo = _T("");
	m_radio = 0;
	//}}AFX_DATA_INIT
}


void CDialogSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSearch)
	DDX_Text(pDX, IDC_PESQUISA_CAMPO, m_campo);
	DDX_Radio(pDX, IDC_PESQUISA_NICK, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogSearch, CDialog)
	//{{AFX_MSG_MAP(CDialogSearch)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogSearch message handlers
