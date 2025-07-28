// MultiStringView.cpp : implementation of the CMultiStringView class
//

#include "stdafx.h"
#include "MultiString.h"

#include "MultiStringDoc.h"
#include "MultiStringView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView

IMPLEMENT_DYNCREATE(CMultiStringView, CView)

BEGIN_MESSAGE_MAP(CMultiStringView, CView)
	//{{AFX_MSG_MAP(CMultiStringView)
	ON_COMMAND(ID_FILE_CHANGEMESSAGE, OnFileChangemessage)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView construction/destruction

CMultiStringView::CMultiStringView()
{
	// TODO: add construction code here

}

CMultiStringView::~CMultiStringView()
{
}

BOOL CMultiStringView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView drawing

void CMultiStringView::OnDraw(CDC* pDC)
{
	CMultiStringDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    pDC->TextOut(20, 20, pDoc->m_messages.GetMessage(1));
    pDC->TextOut(20, 40, pDoc->m_messages.GetMessage(2));
    pDC->TextOut(20, 60, pDoc->m_messages.GetMessage(3));
}

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView printing

BOOL CMultiStringView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultiStringView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiStringView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView diagnostics

#ifdef _DEBUG
void CMultiStringView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiStringView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiStringDoc* CMultiStringView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiStringDoc)));
	return (CMultiStringDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiStringView message handlers

void CMultiStringView::OnFileChangemessage() 
{
	CMultiStringDoc* pDoc = GetDocument();
   CTime now = CTime::GetCurrentTime();
   CString changetime = now.Format("Changed at %B %d %H:%M:%S");
   pDoc->m_messages.SetMessage(1, CString("String 1 ") + changetime);
   pDoc->m_messages.SetMessage(2, CString("String 2 ") + changetime);
   pDoc->m_messages.SetMessage(3, CString("String 3 ") + changetime);
   pDoc->SetModifiedFlag();
   Invalidate();	
}
