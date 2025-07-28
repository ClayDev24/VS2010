// ShowStringDoc.cpp : implementation of the CShowStringDoc class
//

#include "stdafx.h"
#include "ShowString.h"
#include "OptionsDialog.h"
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
	ON_COMMAND(ID_TOOLS_OPTIONS, OnToolsOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc construction/destruction

CShowStringDoc::CShowStringDoc()
{
	// TODO: add one-time construction code here

}

CShowStringDoc::~CShowStringDoc()
{
}

BOOL CShowStringDoc::OnNewDocument()
{
   if (!CDocument::OnNewDocument())
        return FALSE;
    string = "Hello, world!";
    color  = 0;     //black
    horizcenter = TRUE;
    vertcenter  = TRUE;
    return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowStringDoc serialization

void CShowStringDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
        ar << string;
        ar << color;
        ar << horizcenter;
        ar << vertcenter;
	}
	else
	{
        ar >> string;
        ar >> color;
        ar >> horizcenter;
        ar >> vertcenter;
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

void CShowStringDoc::OnToolsOptions() 
{
	COptionsDialog dlg;
    dlg.m_string = string;
    dlg.m_color  = color;
    dlg.m_horizcenter = horizcenter;
    dlg.m_vertcenter  = vertcenter;
    
    if(dlg.DoModal() == IDOK)
    {
        string = dlg.m_string;
        color = dlg.m_color;
        horizcenter = dlg.m_horizcenter;
        vertcenter = dlg.m_vertcenter;
        SetModifiedFlag();
        UpdateAllViews(NULL);
    }
}
