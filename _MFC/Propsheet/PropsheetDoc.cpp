// PropsheetDoc.cpp : implementation of the CPropsheetDoc class
//

#include "stdafx.h"
#include "Propsheet.h"

#include "PropsheetDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropsheetDoc

IMPLEMENT_DYNCREATE(CPropsheetDoc, CDocument)

BEGIN_MESSAGE_MAP(CPropsheetDoc, CDocument)
	//{{AFX_MSG_MAP(CPropsheetDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropsheetDoc construction/destruction

CPropsheetDoc::CPropsheetDoc()
{
	// TODO: add one-time construction code here

}

CPropsheetDoc::~CPropsheetDoc()
{
}

BOOL CPropsheetDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPropsheetDoc serialization

void CPropsheetDoc::Serialize(CArchive& ar)
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
// CPropsheetDoc diagnostics

#ifdef _DEBUG
void CPropsheetDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPropsheetDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropsheetDoc commands
