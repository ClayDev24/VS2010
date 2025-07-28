// App4View.cpp : implementation of the CApp4View class
//

#include "stdafx.h"
#include "App4.h"

#include "App4Doc.h"
#include "App4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp4View

IMPLEMENT_DYNCREATE(CApp4View, CView)

BEGIN_MESSAGE_MAP(CApp4View, CView)
	//{{AFX_MSG_MAP(CApp4View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp4View construction/destruction

CApp4View::CApp4View()
{
	// TODO: add construction code here

}

CApp4View::~CApp4View()
{
}

BOOL CApp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CApp4View drawing

void CApp4View::OnDraw(CDC* pDC)
{
	CApp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CApp4View printing

BOOL CApp4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CApp4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CApp4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CApp4View diagnostics

#ifdef _DEBUG
void CApp4View::AssertValid() const
{
	CView::AssertValid();
}

void CApp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CApp4Doc* CApp4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CApp4Doc)));
	return (CApp4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp4View message handlers
