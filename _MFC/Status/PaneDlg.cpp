// PaneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Status.h"
#include "PaneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaneDlg dialog


CPaneDlg::CPaneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPaneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPaneDlg)
	m_paneString = _T("");
	//}}AFX_DATA_INIT
}


void CPaneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPaneDlg)
	DDX_Text(pDX, IDC_EDIT1, m_paneString);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPaneDlg, CDialog)
	//{{AFX_MSG_MAP(CPaneDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaneDlg message handlers
