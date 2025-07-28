// App2View.cpp : implementation of the CApp2View class
//

#include "stdafx.h"
#include "App2.h"

#include "App2Doc.h"
#include "App2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp2View

IMPLEMENT_DYNCREATE(CApp2View, CView)

BEGIN_MESSAGE_MAP(CApp2View, CView)
	//{{AFX_MSG_MAP(CApp2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp2View construction/destruction

CApp2View::CApp2View()
{
	// TODO: add construction code here

}

CApp2View::~CApp2View()
{
}

BOOL CApp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CApp2View drawing

void CApp2View::OnDraw(CDC* pDC)
{
	CApp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CApp2View printing

BOOL CApp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CApp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CApp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CApp2View diagnostics

#ifdef _DEBUG
void CApp2View::AssertValid() const
{
	CView::AssertValid();
}

void CApp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CApp2Doc* CApp2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CApp2Doc)));
	return (CApp2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp2View message handlers
