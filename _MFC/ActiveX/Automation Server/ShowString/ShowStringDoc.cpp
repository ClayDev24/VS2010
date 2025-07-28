// ShowStringDoc.cpp : implementation of the CShowStringDoc class
//

#include "stdafx.h"
#include "ShowString.h"

#include "ShowStringDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc

IMPLEMENT_DYNCREATE(CShowStringDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowStringDoc, CDocument)
	//{{AFX_MSG_MAP(CShowStringDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CShowStringDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CShowStringDoc)
	DISP_PROPERTY_NOTIFY(CShowStringDoc, "String", m_string, OnStringChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CShowStringDoc, "Color", m_color, OnColorChanged, VT_I2)
	DISP_PROPERTY_EX(CShowStringDoc, "horizcenter", GetHorizcenter, SetHorizcenter, VT_BOOL)
	DISP_PROPERTY_EX(CShowStringDoc, "vertcenter", GetVertcenter, SetVertcenter, VT_BOOL)
	DISP_FUNCTION(CShowStringDoc, "ShowWindow", ShowWindow, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CShowStringDoc, "RefreshWindow", RefreshWindow, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IShowString to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {1D64E12F-079E-4507-8662-4B2B65B7BFE3}
static const IID IID_IShowString =
{ 0x1d64e12f, 0x79e, 0x4507, { 0x86, 0x62, 0x4b, 0x2b, 0x65, 0xb7, 0xbf, 0xe3 } };

BEGIN_INTERFACE_MAP(CShowStringDoc, CDocument)
	INTERFACE_PART(CShowStringDoc, IID_IShowString, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc construction/destruction

CShowStringDoc::CShowStringDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CShowStringDoc::~CShowStringDoc()
{
	AfxOleUnlockApp();
}

BOOL CShowStringDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
     m_string = "Hello, world!";
     m_color = 0;     //black
     m_horizcenter = TRUE;
     m_vertcenter = TRUE;
     return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc serialization

void CShowStringDoc::Serialize(CArchive& ar)
{
     if (ar.IsStoring())
     {
          ar << m_string;
          ar << m_color;
          ar << m_horizcenter;
          ar << m_vertcenter;
     }
     else
     {
          ar >> m_string;
          ar >> m_color;
          ar >> m_horizcenter;
          ar >> m_vertcenter;
     }
}

/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc diagnostics

#ifdef _DEBUG
void CShowStringDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowStringDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc commands

void CShowStringDoc::OnStringChanged() 
{
	RefreshWindow();
}

void CShowStringDoc::OnColorChanged() 
{
	RefreshWindow();
}

void CShowStringDoc::SetHorizcenter(BOOL bNewValue) 
{
	m_horizcenter = bNewValue;
	RefreshWindow();
}

void CShowStringDoc::SetVertcenter(BOOL bNewValue) 
{
     m_vertcenter = bNewValue;
	 RefreshWindow();
}

void CShowStringDoc::ShowWindow() 
{
    POSITION pos = GetFirstViewPosition();
    CView* pView = GetNextView(pos);
    if (pView != NULL)
    {
        CFrameWnd* pFrameWnd = pView->GetParentFrame();
        pFrameWnd->ActivateFrame(SW_SHOW);
        pFrameWnd = pFrameWnd->GetParentFrame();
        if (pFrameWnd != NULL)
            pFrameWnd->ActivateFrame(SW_SHOW);
    }
}

void CShowStringDoc::RefreshWindow() 
{
	UpdateAllViews(NULL);
	SetModifiedFlag();
}
