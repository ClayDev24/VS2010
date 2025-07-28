// App4Doc.cpp : implementation of the CApp4Doc class
//

#include "stdafx.h"
#include "App4.h"

#include "App4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CApp4Doc

IMPLEMENT_DYNCREATE(CApp4Doc, CDocument)

BEGIN_MESSAGE_MAP(CApp4Doc, CDocument)
	//{{AFX_MSG_MAP(CApp4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApp4Doc construction/destruction

CApp4Doc::CApp4Doc()
{
	// TODO: add one-time construction code here

}

CApp4Doc::~CApp4Doc()
{
}

BOOL CApp4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CApp4Doc serialization

void CApp4Doc::Serialize(CArchive& ar)
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
// CApp4Doc diagnostics

#ifdef _DEBUG
void CApp4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CApp4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CApp4Doc commands
