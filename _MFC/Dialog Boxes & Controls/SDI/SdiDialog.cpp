// SdiDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SDI.h"
#include "SdiDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSdiDialog dialog


CSdiDialog::CSdiDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSdiDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSdiDialog)
	m_check = FALSE;
	m_edit = _T("");
	m_radio = -1;
	//}}AFX_DATA_INIT
}


void CSdiDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSdiDialog)
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDV_MaxChars(pDX, m_edit, 10);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSdiDialog, CDialog)
	//{{AFX_MSG_MAP(CSdiDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSdiDialog message handlers

BOOL CSdiDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_listbox.AddString("First String");
	m_listbox.AddString("Second String");
	m_listbox.AddString("Yet Another String");
	m_listbox.AddString("String Number Four");
	m_listbox.SetCurSel(2);
	m_radio = 1;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSdiDialog::OnOK() 
{
	int index = m_listbox.GetCurSel();
     if(index != LB_ERR)
     {
          m_listbox.GetText(index, m_selected);
     }
     else
     {
          m_selected = "";
     }
     CDialog::OnOK();
}

void CSdiDialog::OnCancel() 
{
	m_selected = "";
	CDialog::OnCancel();
}
