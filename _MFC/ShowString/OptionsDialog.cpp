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

static DWORD aHelpIDs[] =
{
    IDC_OPTIONS_STRING, HIDD_OPTIONS_STRING,
    IDC_OPTIONS_BLACK, HIDD_OPTIONS_BLACK,
    IDC_OPTIONS_RED, HIDD_OPTIONS_RED,
    IDC_OPTIONS_GREEN, HIDD_OPTIONS_GREEN,
    IDC_OPTIONS_HORIZCENTER, HIDD_OPTIONS_HORIZCENTER,
    IDC_OPTIONS_VERTCENTER, HIDD_OPTIONS_VERTCENTER,
    IDOK, HIDD_OPTIONS_OK,
    IDCANCEL, HIDD_OPTIONS_CANCEL,
    0, 0
};

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
	DDX_Text(pDX, IDC_OPTIONS_STRING, m_string);
	DDX_Radio(pDX, IDC_OPTIONS_BLACK, m_color);
	DDX_Check(pDX, IDC_OPTIONS_HORIZCENTER, m_horizcenter);
	DDX_Check(pDX, IDC_OPTIONS_VERTCENTER, m_vertcenter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDialog, CDialog)
	//{{AFX_MSG_MAP(COptionsDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
    ON_WM_HELPINFO()
    ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDialog message handlers

BOOL COptionsDialog::OnHelpInfo(HELPINFO *lpHelpInfo)
{
    if (lpHelpInfo->iContextType == HELPINFO_WINDOW) // must be for a control
    {
        // have to call SDK WinHelp not CWinApp::WinHelp
        // because CWinApp::WinHelp doesn't take a
        // handle as a parameter.
        ::WinHelp((HWND)lpHelpInfo->hItemHandle, 
            AfxGetApp()->m_pszHelpFilePath, 
            HELP_WM_HELP, (DWORD)aHelpIDs);
    }
    return TRUE;
}

void COptionsDialog::OnContextMenu(CWnd *pWnd, CPoint /*point*/)
{
     ::WinHelp((HWND)*pWnd, AfxGetApp()->m_pszHelpFilePath, 
          HELP_CONTEXTMENU, (DWORD)aHelpIDs);
}

