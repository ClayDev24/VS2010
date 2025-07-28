// using dllView.cpp : implementation of the CUsingdllView class
//

#include "stdafx.h"
#include "using dll.h"

#include "using dllDoc.h"
#include "using dllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView

IMPLEMENT_DYNCREATE(CUsingdllView, CView)

BEGIN_MESSAGE_MAP(CUsingdllView, CView)
	//{{AFX_MSG_MAP(CUsingdllView)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView construction/destruction

CUsingdllView::CUsingdllView()
{
	// TODO: add construction code here

}

CUsingdllView::~CUsingdllView()
{
}

BOOL CUsingdllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView drawing

void CUsingdllView::OnDraw(CDC* pDC)
{
	CUsingdllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView printing

BOOL CUsingdllView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUsingdllView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUsingdllView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView diagnostics

#ifdef _DEBUG
void CUsingdllView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingdllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingdllDoc* CUsingdllView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingdllDoc)));
	return (CUsingdllDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUsingdllView message handlers

void CUsingdllView::OnEditUndo() 
{
	HINSTANCE hDll; // dll handler
	hDll = LoadLibrary("C:\\Documents and Settings\\claybom.MICRO1\\my stuff\\Linguagens\\delphi\\progs\\Teach Yourself\\DLL with Forms\\SDI Form\\MyForms.dll"); // load dll
	// handle error while loading dll handler
	if (!hDll) {
		TRACE("Error while loading DLL handler");
		exit(1);
	}
	// function pointers equivalent to dll functions
	int (WINAPI * c_dllTest)();
	// link function pointers to dll functions
	c_dllTest = (int (WINAPI *)())GetProcAddress(hDll, "ShowForm");
//	c_plus_1 = (int (WINAPI *)(int))GetProcAddress(hDll, "plus_1");

// handle error while loading functions
	if(!c_dllTest) {
		TRACE("Error while loading functions from DLL");
		exit(1);
	}
	// now, use the functions freely
	c_dllTest();
}
