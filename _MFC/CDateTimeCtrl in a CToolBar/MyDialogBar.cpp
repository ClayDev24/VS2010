// MyDialogBar.cpp: implementation of the MyDialogBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DialogbarDemo.h"
#include "MyDialogBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////
// CMyDialogBar

CMyDialogBar::CMyDialogBar()
{
}

CMyDialogBar::~CMyDialogBar()
{
}


BEGIN_MESSAGE_MAP(CMyDialogBar,  CDialogBarEx)
	//{{AFX_MSG_MAP(CMyDialogBar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyDialogBar message handlers

void CMyDialogBar::DoDataExchange(CDataExchange* pDX) 
{
	// TODO: Add your specialized code here and/or call the base class
	DDX_Control(pDX, IDC_STATIC_WEBSITE ,m_Label) ;
	DDX_Control(pDX, IDC_CUSTOM_DATETIME  ,m_DateTimeCtrl) ;
	CDialogBarEx::DoDataExchange(pDX);
}

void CMyDialogBar::OnInitDialogBar()
{
HWND hCtrl ;
CString strFontName = "Arial"  ;
m_Label.SetLinkURL(_T("http://www.zydusmed.com/vrunda"));
m_Label.SetLink(TRUE)  
.SetTextColor(RGB(0,0,255))
.SetFontUnderline(TRUE)
.SetFontName(strFontName) 
.SetFontSize(12) 
.SetLinkCursor(AfxGetApp()->LoadCursor(IDC_HAND));

m_DateTimeCtrl.SetFormat("dd-MMM-yyyy");
GetDlgItem( IDC_CUSTOM_DATETIME,  &hCtrl)  ;
ASSERT(hCtrl != NULL);
DateTime_SetSystemtime(hCtrl, GDT_NONE, NULL) ;


}
