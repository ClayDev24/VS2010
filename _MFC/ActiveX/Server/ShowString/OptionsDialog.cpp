// OptionsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ShowString.h"
#include "OptionsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDialog dialog


COptionsDialog::COptionsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDialog)
	m_string = _T("");
	m_color = -1;
	m_horizcenter = FALSE;
	m_vertcenter = FALSE;
	//}}AFX_DATA_INIT
}


void COptionsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDialog)
	DDX_Text(pDX, IDC_OPTONS_STRING, m_string);
	DDX_Radio(pDX, IDC_OPTIONS_BLACK, m_color);
	DDX_Check(pDX, IDC_OPTIONS_HORIZCENTER, m_horizcenter);
	DDX_Check(pDX, IDC_OPTIONS_VERTCENTER, m_vertcenter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDialog, CDialog)
	//{{AFX_MSG_MAP(COptionsDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDialog message handlers
