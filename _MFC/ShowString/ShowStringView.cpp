// ShowStringView.cpp : implementation of the CShowStringView class
//

#include "stdafx.h"
#include "ShowString.h"

#include "ShowStringDoc.h"
#include "ShowStringView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowStringView

IMPLEMENT_DYNCREATE(CShowStringView, CView)

BEGIN_MESSAGE_MAP(CShowStringView, CView)
	//{{AFX_MSG_MAP(CShowStringView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowStringView construction/destruction

CShowStringView::CShowStringView()
{
	// TODO: add construction code here

}

CShowStringView::~CShowStringView()
{
}

BOOL CShowStringView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowStringView drawing

void CShowStringView::OnDraw(CDC* pDC)
{
	CShowStringDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

//Setting up Device Context color:
    COLORREF oldcolor;
    switch (pDoc->GetColor())
    {
    case 0:
        oldcolor = pDC->SetTextColor(RGB(0,0,0)); //black
        break;
    case 1:
        oldcolor = pDC->SetTextColor(RGB(0xFF,0,0)); //red
        break;
    case 2:
        oldcolor = pDC->SetTextColor(RGB(0,0xFF,0)); //green
        break;
    }	

    int DTflags = 0;
    if (pDoc->GetHorizcenter())
    {
        DTflags |= DT_CENTER;
    }
    if (pDoc->GetVertcenter())
    {
        DTflags |= (DT_VCENTER|DT_SINGLELINE);
    }

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->GetString(), &rect, DTflags);//DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	
	pDC->SetTextColor(oldcolor);
}

/////////////////////////////////////////////////////////////////////////////
// CShowStringView printing

BOOL CShowStringView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowStringView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowStringView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowStringView diagnostics

#ifdef _DEBUG
void CShowStringView::AssertValid() const
{
	CView::AssertValid();
}

void CShowStringView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowStringDoc* CShowStringView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowStringDoc)));
	return (CShowStringDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowStringView message handlers
