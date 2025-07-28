// Paint1Doc.cpp : implementation of the CPaint1Doc class
//

#include "stdafx.h"
#include "Paint1.h"

#include "Paint1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaint1Doc

IMPLEMENT_DYNCREATE(CPaint1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPaint1Doc, CDocument)
	//{{AFX_MSG_MAP(CPaint1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaint1Doc construction/destruction

CPaint1Doc::CPaint1Doc()
{
	// TODO: add one-time construction code here

}

CPaint1Doc::~CPaint1Doc()
{
}

BOOL CPaint1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPaint1Doc serialization

void CPaint1Doc::Serialize(CArchive& ar)
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
// CPaint1Doc diagnostics

#ifdef _DEBUG
void CPaint1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaint1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaint1Doc commands
