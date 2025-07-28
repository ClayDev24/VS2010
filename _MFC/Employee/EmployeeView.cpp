// EmployeeView.cpp : implementation of the CEmployeeView class
//

#include "stdafx.h"
#include "Employee.h"

#include "EmployeeSet.h"
#include "EmployeeDoc.h"
#include "EmployeeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView

IMPLEMENT_DYNCREATE(CEmployeeView, CRecordView)

BEGIN_MESSAGE_MAP(CEmployeeView, CRecordView)
	//{{AFX_MSG_MAP(CEmployeeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView construction/destruction

CEmployeeView::CEmployeeView()
	: CRecordView(CEmployeeView::IDD)
{
	//{{AFX_DATA_INIT(CEmployeeView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CEmployeeView::~CEmployeeView()
{
}

void CEmployeeView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployeeView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CEmployeeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CEmployeeView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_employeeSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView printing

BOOL CEmployeeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEmployeeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEmployeeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView diagnostics

#ifdef _DEBUG
void CEmployeeView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEmployeeView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEmployeeDoc* CEmployeeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEmployeeDoc)));
	return (CEmployeeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEmployeeView database support
CRecordset* CEmployeeView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CEmployeeView message handlers
