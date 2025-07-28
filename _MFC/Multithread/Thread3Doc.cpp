// Thread3Doc.cpp : implementation of the CThread3Doc class
//

#include "stdafx.h"
#include "Thread3.h"

#include "Thread3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThread3Doc

IMPLEMENT_DYNCREATE(CThread3Doc, CDocument)

BEGIN_MESSAGE_MAP(CThread3Doc, CDocument)
	//{{AFX_MSG_MAP(CThread3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThread3Doc construction/destruction

CThread3Doc::CThread3Doc()
{
	// TODO: add one-time construction code here

}

CThread3Doc::~CThread3Doc()
{
}

BOOL CThread3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CThread3Doc serialization

void CThread3Doc::Serialize(CArchive& ar)
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
// CThread3Doc diagnostics

#ifdef _DEBUG
void CThread3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThread3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CThread3Doc commands
