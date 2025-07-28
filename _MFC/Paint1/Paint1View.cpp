// Paint1View.cpp : implementation of the CPaint1View class
//

#include "stdafx.h"
#include "Paint1.h"

#include "Paint1Doc.h"
#include "Paint1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaint1View

IMPLEMENT_DYNCREATE(CPaint1View, CView)

BEGIN_MESSAGE_MAP(CPaint1View, CView)
//{{AFX_MSG_MAP(CPaint1View)
ON_WM_LBUTTONDOWN()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaint1View construction/destruction

CPaint1View::CPaint1View()
{
	// TODO: add construction code here
	m_Display = Fonts;
}

CPaint1View::~CPaint1View()
{
}

BOOL CPaint1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaint1View drawing

void CPaint1View::OnDraw(CDC* pDC)
{
	CPaint1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	switch(m_Display) {
	case Fonts:
		ShowFonts(pDC);
		break;
	case Pens:
		ShowPens(pDC);
		break;
	case Brushes:
		ShowBrushes(pDC);
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPaint1View diagnostics

#ifdef _DEBUG
void CPaint1View::AssertValid() const
{
	CView::AssertValid();
}

void CPaint1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaint1Doc* CPaint1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaint1Doc)));
	return (CPaint1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaint1View message handlers

void CPaint1View::ShowFonts(CDC *pDC)
{
	// Initialize a LOGFONT structure for the fonts.
    LOGFONT lfont;
    lfont.lfHeight      = 8;
    lfont.lfWidth       = 0;
    lfont.lfEscapement  = 0;
    lfont.lfOrientation = 0;
    lfont.lfWeight      = FW_NORMAL;
    lfont.lfItalic      = 1;
    lfont.lfUnderline   = 0;
    lfont.lfStrikeOut   = 0;
    lfont.lfCharSet     = ANSI_CHARSET;
    lfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lfont.lfQuality        = PROOF_QUALITY;
    lfont.lfPitchAndFamily  = VARIABLE_PITCH | FF_ROMAN;
    strcpy(lfont.lfFaceName, "Times New Roman");
    // Initialize the position of text in the window.
    UINT pos = 0;
    // Create and display eight example fonts.
	CFont* oldFont;
    for (UINT i=0; i<8; i++) {
		// Set the new font's height.
		lfont.lfHeight = 16 + (i * 8);
		// Create a new font and select it into the DC.
		CFont font;
		font.CreateFontIndirect(&lfont);
		oldFont = pDC->SelectObject(&font);
		// Print text with the new font.
		pos += lfont.lfHeight;		
		pDC->TextOut(20, pos, "A sample font."); // (x, y, str);
    }
	// Restore the old font to the DC.		
	pDC->SelectObject(oldFont);
}

void CPaint1View::ShowPens(CDC *pDC)
{
	// Initialize the line position.
	UINT pos = 10;
	CPen *oldPen;
	// Draw sixteen lines in the window.
	for (UINT i=0; i<16; i++) {
		// Create a new pen and select it into the DC.
		// PS_DASH PS_DASHDOT PS_DASHDOTDOT PS_DOT PS_INSIDEFRAME PS_NULL.=> Only works w/ thickness == 1.
		CPen pen(PS_DASHDOT, i*2+1, RGB(0, 0, 255)); // (lnStyle, thickness, color(0-255))
		oldPen = pDC->SelectObject(&pen);
		// Draw a line with the new pen.
		pos +=  i*2+10;
		pDC->MoveTo(20,  pos);
		pDC->LineTo(400, pos);
	}
	// Restore the old pen to the DC.
	pDC->SelectObject(oldPen);	
}

void CPaint1View::ShowBrushes(CDC *pDC)
{
	// Initialize the rectangle position.
	UINT pos = 0;
	// Select pen to use for rectangle borders
	CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);
	// Draw seven rectangles.
	for (UINT i=0; i<7; i++) {
		CBrush* brush;
		// Create a solid or hatched brush.
		if(i == 6)
			brush = new CBrush(RGB(0,255,0));    // 1-arg creates a solid brush
		else
			brush = new CBrush(i, RGB(0,160,0)); // 2-args create a hatched brush. 6 differents styles (0-5)
		// Select the new brush into the DC.
		CBrush* oldBrush = pDC->SelectObject(brush);
		// Draw the rectangle.
		pos += 50;
		pDC->Rectangle(20, pos, 400, pos + 40);
		// Restore the DC and delete the brush.
		pDC->SelectObject(oldBrush);
		delete brush;
	}
	// Restore the old pen to the DC.
	pDC->SelectObject(oldPen);
}

void CPaint1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Display == Fonts)
		m_Display = Pens;
	else if(m_Display == Pens)
		m_Display = Brushes;
	else
		m_Display = Fonts;
	Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
