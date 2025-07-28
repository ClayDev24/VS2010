// PropsheetView.cpp : implementation of the CPropsheetView class
//

#include "stdafx.h"
#include "Propsheet.h"
#include "propsheet1.h"
#include "PropsheetDoc.h"
#include "PropsheetView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropsheetView

IMPLEMENT_DYNCREATE(CPropsheetView, CView)

BEGIN_MESSAGE_MAP(CPropsheetView, CView)
	//{{AFX_MSG_MAP(CPropsheetView)
	ON_COMMAND(ID_PROPSHEET, OnPropsheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropsheetView construction/destruction

CPropsheetView::CPropsheetView()
{
	m_edit  = "Default";
	m_check = FALSE;
}

CPropsheetView::~CPropsheetView()
{
}

BOOL CPropsheetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPropsheetView drawing

void CPropsheetView::OnDraw(CDC* pDC)
{
	CPropsheetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    pDC->TextOut(20, 20, m_edit);
    if(m_check)
        pDC->TextOut(20, 50, "TRUE");
    else
        pDC->TextOut(20, 50, "FALSE");
}

/////////////////////////////////////////////////////////////////////////////
// CPropsheetView diagnostics

#ifdef _DEBUG
void CPropsheetView::AssertValid() const
{
	CView::AssertValid();
}

void CPropsheetView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropsheetDoc* CPropsheetView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropsheetDoc)));
	return (CPropsheetDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropsheetView message handlers

void CPropsheetView::OnPropsheet() 
{
	CPropSheet propSheet("Property Sheet", this, 0);
    propSheet.m_page1.m_edit     = m_edit;
    propSheet.m_page2.m_check = m_check;
    int result = propSheet.DoModal();
    if(result == IDOK)
    {
        m_edit  = propSheet.m_page1.m_edit;
        m_check = propSheet.m_page2.m_check;
        Invalidate();
    }     
}
