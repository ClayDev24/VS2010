// DialogbarDemoView.cpp : implementation of the CDialogbarDemoView class
//

#include "stdafx.h"
#include "DialogbarDemo.h"

#include "DialogbarDemoDoc.h"
#include "DialogbarDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoView

IMPLEMENT_DYNCREATE(CDialogbarDemoView, CView)

BEGIN_MESSAGE_MAP(CDialogbarDemoView, CView)
	//{{AFX_MSG_MAP(CDialogbarDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoView construction/destruction

CDialogbarDemoView::CDialogbarDemoView()
{
	// TODO: add construction code here

}

CDialogbarDemoView::~CDialogbarDemoView()
{
}

BOOL CDialogbarDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoView drawing

void CDialogbarDemoView::OnDraw(CDC* pDC)
{
	CDialogbarDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoView diagnostics

#ifdef _DEBUG
void CDialogbarDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogbarDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogbarDemoDoc* CDialogbarDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogbarDemoDoc)));
	return (CDialogbarDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoView message handlers
