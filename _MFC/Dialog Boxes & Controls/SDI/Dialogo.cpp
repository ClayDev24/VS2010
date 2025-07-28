// Dialogo.cpp : implementation file
//

#include "stdafx.h"
#include "SDI.h"
#include "Dialogo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogo dialog


Dialogo::Dialogo(CWnd* pParent /*=NULL*/)
	: CDialog(Dialogo::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialogo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Dialogo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialogo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialogo, CDialog)
	//{{AFX_MSG_MAP(Dialogo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialogo message handlers
