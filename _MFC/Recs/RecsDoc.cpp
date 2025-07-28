// RecsDoc.cpp : implementation of the CRecsDoc class
//

#include "stdafx.h"
#include "Recs.h"

#include "RecsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecsDoc

IMPLEMENT_DYNCREATE(CRecsDoc, CDocument)

BEGIN_MESSAGE_MAP(CRecsDoc, CDocument)
	//{{AFX_MSG_MAP(CRecsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecsDoc construction/destruction

CRecsDoc::CRecsDoc()
{
	// TODO: add one-time construction code here

}

CRecsDoc::~CRecsDoc()
{
}

BOOL CRecsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_pointIndex = 0;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRecsDoc serialization

void CRecsDoc::Serialize(CArchive& ar)
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
// CRecsDoc diagnostics

#ifdef _DEBUG
void CRecsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRecsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRecsDoc commands
