// MainView.cpp : implementation of the CMainView class
//

#include "stdafx.h"
#include "DateClass.h"

#include "Doc.h"
#include "MainView.h"
#include "mainfrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SimpleDate.h"

/////////////////////////////////////////////////////////////////////////////
// CMainView

IMPLEMENT_DYNCREATE(CMainView, CFormView)

BEGIN_MESSAGE_MAP(CMainView, CFormView)
	//{{AFX_MSG_MAP(CMainView)
	ON_EN_KILLFOCUS(IDC_THEDATE, OnKillfocusThedate)
	ON_BN_CLICKED(IDC_BUTTONADD, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTONSUB, OnButtonsub)
	ON_BN_CLICKED(IDC_BUTTONADD2, OnButtonadd2)
	ON_BN_CLICKED(IDC_BUTTONSUB2, OnButtonsub2)
	ON_BN_CLICKED(IDC_BUTTONADD3, OnButtonadd3)
	ON_BN_CLICKED(IDC_BUTTONSUB3, OnButtonsub3)
	ON_EN_KILLFOCUS(IDC_THEDATE2, OnKillfocusThedate2)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainView construction/destruction

CMainView::CMainView()
	: CFormView(CMainView::IDD)
{
	//{{AFX_DATA_INIT(CMainView)
	m_TheDate = _T("");
	m_R1 = _T("");
	m_R2 = _T("");
	m_SubNum = 0;
	m_AddNum = 0;
	m_AddNum2 = 0;
	m_AddNum3 = 0;
	m_SumNum2 = 0;
	m_SumNum3 = 0;
	m_Time1 = _T("");
	m_Time2 = _T("");
	m_Date2 = 0;
	m_R3 = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMainView::~CMainView()
{
}

void CMainView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainView)
	DDX_SimpleDate(pDX, IDC_THEDATE, m_TheDate);	// string or cstring
	DDX_Text(pDX, IDC_RESULTS, m_R1);
	DDX_Text(pDX, IDC_RESULTS2, m_R2);
	DDX_Text(pDX, IDC_SUBNUM, m_SubNum);
	DDX_Text(pDX, IDC_ADDNUM, m_AddNum);
	DDX_Text(pDX, IDC_ADDNUM2, m_AddNum2);
	DDX_Text(pDX, IDC_ADDNUM3, m_AddNum3);
	DDX_Text(pDX, IDC_SUBNUM2, m_SumNum2);
	DDX_Text(pDX, IDC_SUBNUM3, m_SumNum3);
	DDX_Text(pDX, IDC_TIME, m_Time1);
	DDX_Text(pDX, IDC_TIME2, m_Time2);
	DDX_SimpleDate(pDX, IDC_THEDATE2, m_Date2);		// long
	DDX_Text(pDX, IDC_RESULTS3, m_R3);
	//}}AFX_DATA_MAP
}

BOOL CMainView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMainView::OnInitialUpdate()
{
    static  BOOL FirstTime=TRUE;
    CMainFrame* pFrame;
    CRect rectFrame, rectView;

    CFormView::OnInitialUpdate();

	pFrame = (CMainFrame*)GetParentFrame();
    if(FirstTime==TRUE)
    {
                    FirstTime=FALSE;
            // Resize parent to fit dialog template exactly
            // while not resizing beyond size of screen
            
            pFrame->GetClientRect( rectFrame );
            GetClientRect( rectView );
            if ( rectFrame.Width() > rectView.Width()
                     || rectFrame.Height() < rectView.Height() )
            {
                    pFrame->MoveWindow( 0, 0,
					GetSystemMetrics(SM_CXSCREEN),
					GetSystemMetrics(SM_CYSCREEN), FALSE );
            }
            pFrame->RecalcLayout();
            ResizeParentToFit(TRUE);    // Shrink to fit template
            pFrame->CenterWindow();


	}
	

}

/////////////////////////////////////////////////////////////////////////////
// CMainView printing

BOOL CMainView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMainView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMainView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMainView::OnPrint(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMainView diagnostics

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDoc* CMainView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoc)));
	return (CDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainView message handlers

void CMainView::OnKillfocusThedate() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	CSimpleDate s2(s);
	CString dd=(LPCSTR)s2;
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
}

void CMainView::OnButtonadd() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.AddDays(m_AddNum);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
}

void CMainView::OnButtonsub() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.SubtractDays(m_SubNum);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
}

void CMainView::OnButtonadd2() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.AddMonths(m_AddNum2);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
	
}

void CMainView::OnButtonsub2() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.SubtractMonths(m_SumNum2);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
}

void CMainView::OnButtonadd3() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.AddYears(m_AddNum3);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
	s="12/09/1946";
}

void CMainView::OnButtonsub3() 
{
	UpdateData();
	CSimpleDate s(m_TheDate);
	s=s.SubtractYears(m_SumNum3);
	m_R1=s;
	m_R2=s.GetFullDateString();
	m_R3=s.GetFullDateStringLong();
	UpdateData(FALSE);
	UpdateTime();
}

void CMainView::UpdateTime()
{
	CSimpleDate D;
	D.GetTimeString(m_Time1);
	D.GetTimeStringShort(m_Time2);
	UpdateData(FALSE);


}

void CMainView::OnKillfocusThedate2() 
{
	UpdateData();	
}

void CMainView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    CMainFrame* pFrame;
	pFrame = (CMainFrame*)GetParentFrame();
	pFrame->SetWindowText("CSimpleDate Demo Program Version 2098.90");	
	
	// Do not call CFormView::OnPaint() for painting messages
}
