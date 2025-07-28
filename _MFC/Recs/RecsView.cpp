// RecsView.cpp : implementation of the CRecsView class
//

#include "stdafx.h"
#include "Recs.h"

#include "RecsDoc.h"
#include "RecsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecsView

IMPLEMENT_DYNCREATE(CRecsView, CView)

BEGIN_MESSAGE_MAP(CRecsView, CView)
	//{{AFX_MSG_MAP(CRecsView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecsView construction/destruction

CRecsView::CRecsView()
{
	// TODO: add construction code here

}

CRecsView::~CRecsView()
{
}

BOOL CRecsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRecsView drawing

void CRecsView::OnDraw(CDC* pDC)
{
	CRecsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	for(UINT i=0; i<pDoc->m_pointIndex; i++) {
		UINT x = pDoc->m_points[i].x;
		UINT y = pDoc->m_points[i].y;
		pDC->Rectangle(x, y, x+20, y+20);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRecsView printing

BOOL CRecsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRecsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRecsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRecsView diagnostics

#ifdef _DEBUG
void CRecsView::AssertValid() const
{
	CView::AssertValid();
}

void CRecsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRecsDoc* CRecsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRecsDoc)));
	return (CRecsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRecsView message handlers

void CRecsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRecsDoc *pDoc = GetDocument();
	if(pDoc->m_pointIndex == 10)
		return;
	// Store the click location:
	pDoc->m_points[pDoc->m_pointIndex++] = point;
	pDoc->SetModifiedFlag(); // Stes this doc as 'dirty' (modified). MFC prompts to save it on exit
	Invalidate(); // Cause MFC to call OnDraw(). Invalidate(FALSE) dont clear the screen b4 redraws it.
	// END TODO
	CView::OnLButtonDown(nFlags, point); // Takes care of the rest
}
