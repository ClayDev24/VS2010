// App3Doc.cpp : implementation of the CApp3Doc class
//

#include "stdafx.h"
#include "App3.h"

#include "App3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp3Doc

IMPLEMENT_DYNCREATE(CApp3Doc, CDocument)

BEGIN_MESSAGE_MAP(CApp3Doc, CDocument)
	//{{AFX_MSG_MAP(CApp3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp3Doc construction/destruction

CApp3Doc::CApp3Doc()
{
	// TODO: add one-time construction code here

}

CApp3Doc::~CApp3Doc()
{
}

BOOL CApp3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CApp3Doc serialization

void CApp3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CApp3Doc diagnostics

#ifdef _DEBUG
void CApp3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CApp3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp3Doc commands
