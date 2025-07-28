// DialogbarDemoDoc.cpp : implementation of the CDialogbarDemoDoc class
//

#include "stdafx.h"
#include "DialogbarDemo.h"

#include "DialogbarDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoDoc

IMPLEMENT_DYNCREATE(CDialogbarDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogbarDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDialogbarDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoDoc construction/destruction

CDialogbarDemoDoc::CDialogbarDemoDoc()
{
	// TODO: add one-time construction code here

}

CDialogbarDemoDoc::~CDialogbarDemoDoc()
{
}

BOOL CDialogbarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoDoc serialization

void CDialogbarDemoDoc::Serialize(CArchive& ar)
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
// CDialogbarDemoDoc diagnostics

#ifdef _DEBUG
void CDialogbarDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogbarDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogbarDemoDoc commands
