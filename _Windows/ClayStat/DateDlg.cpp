// DateDlg.cpp: implementation of the CDateDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClayStat2.h"
#include "ClayStat2View.h"
#include "MainFrm.h"
#include <fstream>
#include "DateDlg.h"

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDateDlg::CDateDlg() {}

CDateDlg::~CDateDlg() {}

BEGIN_MESSAGE_MAP(CDateDlg,  CDialogBarEx)
	//{{AFX_MSG_MAP(CDateDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateDlg message handlers

void CDateDlg::DoDataExchange(CDataExchange* pDX) 
{
	DDX_Control(pDX, IDC_CALENDAR, m_date);
	DDX_Control(pDX, IDC_COMBO, m_combo);
	CDialogBarEx::DoDataExchange(pDX);
}

void CDateDlg::OnInitDialogBar()
{
	CString strFontName = "Arial"  ;
	m_date.SetFormat("dd-MMM-yyyy");

	HWND hCtrl;
	GetDlgItem(IDC_CALENDAR, &hCtrl);
	ASSERT(hCtrl != NULL);
	DateTime_SetSystemtime(hCtrl, GDT_NONE, NULL);
	//settin'up today's date:
	MainFrame *pMain = (MainFrame*) ::AfxGetMainWnd();
	ClayStat2Doc *pDoc = (ClayStat2Doc*)pMain->GetActiveDocument();
	ClayStat2View *pView = (ClayStat2View*)pMain->GetActiveView();
	ASSERT_VALID(pDoc);
	//m_date.GetTime(pDoc->m_estat->m_date);
	m_date.GetTime(pView->m_date);

	//settin'up m_combo list:
	ifstream inFile;
	inFile.open("list.txt");
	if(inFile.fail() == 1) {// 1 if not exists
	} else {//0 exists:
		char buf[150];
		int total = 0;
		while((inFile.eof() == 0)) {
			inFile.getline(buf, 149); 
			CString ng = buf;
			if(ng != "" && ng != "\r") {
				m_combo.AddString(ng);	
				total++;
			}
		}
		m_combo.SetCurSel(0);
		pDoc->m_estat->m_totalGroups = total;
	}
}
