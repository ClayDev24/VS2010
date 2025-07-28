// Char ListingView.cpp : implementation of the CCharListingView class
//

#include "stdafx.h"
#include "Char Listing.h"

#include "Char ListingDoc.h"
#include "Char ListingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharListingView

IMPLEMENT_DYNCREATE(CCharListingView, CFormView)

BEGIN_MESSAGE_MAP(CCharListingView, CFormView)
//{{AFX_MSG_MAP(CCharListingView)
ON_BN_CLICKED(IDC_LIST, OnList)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_RADIO128, OnRadio128)
	ON_BN_CLICKED(IDC_RADIO256, OnRadio256)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharListingView construction/destruction

CCharListingView::CCharListingView()
: CFormView(CCharListingView::IDD)
{
	//{{AFX_DATA_INIT(CCharListingView)
	m_radio = -1;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}

CCharListingView::~CCharListingView()
{
}

void CCharListingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharListingView)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_CLEAR, m_clear);
	DDX_Control(pDX, IDC_CONSOLE, m_console);
	DDX_Radio(pDX, IDC_RADIO128, m_radio);
	//}}AFX_DATA_MAP
}

BOOL CCharListingView::PreCreateWindow(CREATESTRUCT& cs)
{	
	return CFormView::PreCreateWindow(cs);
}

void CCharListingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_radio = 0;
	GetDlgItem(IDC_CLEAR)->EnableWindow(FALSE);//true/false == Enables/Disables
}

/////////////////////////////////////////////////////////////////////////////
// CCharListingView diagnostics

#ifdef _DEBUG
void CCharListingView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCharListingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCharListingDoc* CCharListingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCharListingDoc)));
	return (CCharListingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCharListingView message handlers

void CCharListingView::OnList() 
{
	char str[25];
	int bits;
	if(m_radio==0)
		bits = 128;
	else if(m_radio==1)
		bits = 256;
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
	for(int i=0; i<bits; i++) {
			wsprintf(str, "%i- char: %c", i, i);
			m_console.SetFont(font);
			m_console.AddString(str);  
	}
	GetDlgItem(IDC_CLEAR)->EnableWindow(TRUE);//true/false == Enables/Disables
	GetDlgItem(IDC_LIST)->EnableWindow(FALSE);//true/false == Enables/Disables
}

void CCharListingView::OnClear() 
{
	GetDlgItem(IDC_CLEAR)->EnableWindow(FALSE);//true/false == Enables/Disables
	GetDlgItem(IDC_LIST)->EnableWindow(TRUE);//true/false == Enables/Disables

	m_console.ResetContent();
}

void CCharListingView::OnRadio128() 
{
	m_radio = 0;	
}

void CCharListingView::OnRadio256() 
{
	m_radio = 1;	
}
