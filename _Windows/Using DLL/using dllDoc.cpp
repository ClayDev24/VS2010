// using dllDoc.cpp : implementation of the CUsingdllDoc class
//

#include "stdafx.h"
#include "using dll.h"

#include "using dllDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUsingdllDoc

IMPLEMENT_DYNCREATE(CUsingdllDoc, CDocument)

BEGIN_MESSAGE_MAP(CUsingdllDoc, CDocument)
	//{{AFX_MSG_MAP(CUsingdllDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsingdllDoc construction/destruction

CUsingdllDoc::CUsingdllDoc()
{
	// TODO: add one-time construction code here

}

CUsingdllDoc::~CUsingdllDoc()
{
}

BOOL CUsingdllDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUsingdllDoc serialization

void CUsingdllDoc::Serialize(CArchive& ar)
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
// CUsingdllDoc diagnostics

#ifdef _DEBUG
void CUsingdllDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUsingdllDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUsingdllDoc commands
