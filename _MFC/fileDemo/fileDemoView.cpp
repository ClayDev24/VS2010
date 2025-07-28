// fileDemoView.cpp : implementation of the CFileDemoView class
//

#include "stdafx.h"
#include "fileDemo.h"

#include "fileDemoDoc.h"
#include "fileDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView

IMPLEMENT_DYNCREATE(CFileDemoView, CView)

BEGIN_MESSAGE_MAP(CFileDemoView, CView)
	//{{AFX_MSG_MAP(CFileDemoView)
	ON_COMMAND(ID_FILE_CHANGEMESSAGE, OnFileChangemessage)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView construction/destruction

CFileDemoView::CFileDemoView()
{
	// TODO: add construction code here

}

CFileDemoView::~CFileDemoView()
{
}

BOOL CFileDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView drawing

void CFileDemoView::OnDraw(CDC* pDC)
{
	CFileDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDC->TextOut(20, 20, pDoc->get_message());
}

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView printing

BOOL CFileDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView diagnostics

#ifdef _DEBUG
void CFileDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CFileDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDemoDoc* CFileDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDemoDoc)));
	return (CFileDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileDemoView message handlers

void CFileDemoView::OnFileChangemessage() 
{
	CTime now = CTime::GetCurrentTime();
	CString changetime = now.Format("Changed at %B %d %H:%M:%S");
	GetDocument()->set_message(changetime);
	Invalidate();	
}
