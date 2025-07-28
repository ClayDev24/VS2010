// App2Doc.cpp : implementation of the CApp2Doc class
//

#include "stdafx.h"
#include "App2.h"

#include "App2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp2Doc

IMPLEMENT_DYNCREATE(CApp2Doc, CDocument)

BEGIN_MESSAGE_MAP(CApp2Doc, CDocument)
	//{{AFX_MSG_MAP(CApp2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp2Doc construction/destruction

CApp2Doc::CApp2Doc()
{
	// TODO: add one-time construction code here

}

CApp2Doc::~CApp2Doc()
{
}

BOOL CApp2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CApp2Doc serialization

void CApp2Doc::Serialize(CArchive& ar)
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
// CApp2Doc diagnostics

#ifdef _DEBUG
void CApp2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CApp2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp2Doc commands
