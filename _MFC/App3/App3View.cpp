// App3View.cpp : implementation of the CApp3View class
//

#include "stdafx.h"
#include "App3.h"

#include "App3Doc.h"
#include "App3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp3View

IMPLEMENT_DYNCREATE(CApp3View, CView)

BEGIN_MESSAGE_MAP(CApp3View, CView)
	//{{AFX_MSG_MAP(CApp3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp3View construction/destruction

CApp3View::CApp3View()
{
	// TODO: add construction code here

}

CApp3View::~CApp3View()
{
}

BOOL CApp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CApp3View drawing

void CApp3View::OnDraw(CDC* pDC)
{
	CApp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CApp3View printing

BOOL CApp3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CApp3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CApp3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CApp3View diagnostics

#ifdef _DEBUG
void CApp3View::AssertValid() const
{
	CView::AssertValid();
}

void CApp3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CApp3Doc* CApp3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CApp3Doc)));
	return (CApp3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp3View message handlers
