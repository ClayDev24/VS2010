// Thread3View.cpp : implementation of the CThread3View class
//

#include "stdafx.h"
#include "Thread3.h"

#include "Thread3Doc.h"
#include "Thread3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThread3View

IMPLEMENT_DYNCREATE(CThread3View, CView)

BEGIN_MESSAGE_MAP(CThread3View, CView)
	//{{AFX_MSG_MAP(CThread3View)
	ON_COMMAND(ID_THREAD_STARTTHREAD, OnThreadStartthread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThread3View construction/destruction

CThread3View::CThread3View()
{
	// TODO: add construction code here

}

CThread3View::~CThread3View()
{
}

BOOL CThread3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CThread3View drawing

void CThread3View::OnDraw(CDC* pDC)
{
	CThread3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CThread3View diagnostics

#ifdef _DEBUG
void CThread3View::AssertValid() const
{
	CView::AssertValid();
}

void CThread3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThread3Doc* CThread3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThread3Doc)));
	return (CThread3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CThread3View message handlers

struct th
{
	int a;
	HWND hWnd;
	HDC hDC;
};
th obj;


UINT Threadproc(LPVOID param);

UINT Threadproc(LPVOID param)
{
	th *temp= (th*)param;

	HDC dc= GetDC(temp->hWnd);
	int kk=temp->a;
	CRect rect;
	RECT re;
	HBRUSH hbr;

	hbr = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(dc,hbr);
   for(int i=1;i<=600;i=i+10)
   {
		GetClientRect(NULL,rect);
		int old = SetROP2(dc,R2_COPYPEN);
		GetClientRect(temp->hWnd,&re);
		Ellipse(dc,50+i,kk,100+i,kk+50);
		Sleep(100);
		//HBRUSH brh;
		//brh = CreateSolidBrush(RGB(255,255,255));
		//FillRect(dc,&re,brh);
   }
	return 0;
}

void CThread3View::OnThreadStartthread() 
{
	for(int i=0;i<=400;i=i+50)
	{
		obj.a = i;
		obj.hWnd = GetSafeHwnd();	
		AfxBeginThread(Threadproc,&obj.a);
	}	
}
