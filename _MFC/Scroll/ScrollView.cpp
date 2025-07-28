// ScrollView.cpp : implementation of the CMyScrollView class
//

#include "stdafx.h"
#include "Scroll.h"

#include "ScrollDoc.h"
#include "ScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView

IMPLEMENT_DYNCREATE(CMyScrollView, CScrollView)

BEGIN_MESSAGE_MAP(CMyScrollView, CScrollView)
	//{{AFX_MSG_MAP(CMyScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView construction/destruction

CMyScrollView::CMyScrollView()
{
	// TODO: add construction code here

}

CMyScrollView::~CMyScrollView()
{
}

BOOL CMyScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView drawing

void CMyScrollView::OnDraw(CDC* pDC)
{
	CScrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	// get the number of lines from the document
	int numLines = pDoc->m_NumLines;
	// Initialize a LOGFONT structure for the fonts.
	LOGFONT lfont;
    lfont.lfHeight      = 24;
    lfont.lfWidth       = 0;
    lfont.lfEscapement  = 0;
    lfont.lfOrientation = 0;
    lfont.lfWeight      = FW_NORMAL;
    lfont.lfItalic      = 0;
    lfont.lfUnderline   = 0;
    lfont.lfStrikeOut   = 0;
    lfont.lfCharSet     = ANSI_CHARSET;
    lfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lfont.lfQuality        = PROOF_QUALITY;
    lfont.lfPitchAndFamily  = VARIABLE_PITCH | FF_ROMAN;
	strcpy(lfont.lfFaceName, "Times New Roman");
	// Create a new font and select it into the DC.
    CFont* font = new CFont();
	font->CreateFontIndirect(&lfont);
	CFont* oldFont = pDC->SelectObject(font);
	// Initialize the position of text in the window.
	UINT pos = 0;
	// Create and display eight example lines.
	for (int i=0; i<numLines; i++) {
		// Create the string to display.
		char str[25];
		wsprintf(str, "This is line #%d", i+1);
		// Print text with the new font.
		pDC->TextOut(20, pos, str);
		pos += lfont.lfHeight;
	}	
// To Scroolbar appears:
	// Calculate the document size.
	CSize docSize(100, numLines*lfont.lfHeight);
	// Calculate the page size.
	CRect rect;
	GetClientRect(&rect);
	CSize pageSize(rect.right, rect.bottom);
	// Calculate the line size.
	CSize lineSize(0, lfont.lfHeight); // (width, height) 0 prevents horizontal scrolling.
	// Adjust the scrollers.
	SetScrollSizes(MM_TEXT, docSize, pageSize, lineSize);

	pDC->SelectObject(oldFont); // Restore the old font to the DC, and
	delete font;				// delete the font the program created.
}

void CMyScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView diagnostics

#ifdef _DEBUG
void CMyScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMyScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollDoc* CMyScrollView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollDoc)));
	return (CScrollDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView message handlers

void CMyScrollView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    CScrollDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // Increase number of lines to display.
    pDoc->m_NumLines += 5;
    // Redraw the window.
    Invalidate();

	CScrollView::OnLButtonDown(nFlags, point);
}

void CMyScrollView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CScrollDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // Decrease number of lines to display.
    pDoc->m_NumLines -= 5;
    if (pDoc->m_NumLines < 0) {
		pDoc->m_NumLines = 0;
    }
    // Redraw the window.
    Invalidate();
	
	CScrollView::OnRButtonDown(nFlags, point);
}
