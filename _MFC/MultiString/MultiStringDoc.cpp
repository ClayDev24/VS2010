// MultiStringDoc.cpp : implementation of the CMultiStringDoc class
//

#include "stdafx.h"
#include "MultiString.h"
#include "MultiStringDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiStringDoc

IMPLEMENT_DYNCREATE(CMultiStringDoc, CDocument)

BEGIN_MESSAGE_MAP(CMultiStringDoc, CDocument)
	//{{AFX_MSG_MAP(CMultiStringDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiStringDoc construction/destruction

CMultiStringDoc::CMultiStringDoc()
{
	// TODO: add one-time construction code here

}

CMultiStringDoc::~CMultiStringDoc()
{
}

BOOL CMultiStringDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	m_messages.SetMessage(1, "Default Message 1");
    m_messages.SetMessage(2, "Default Message 2");
    m_messages.SetMessage(3, "Default Message 3");

	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiStringDoc serialization

void CMultiStringDoc::Serialize(CArchive& ar)
{
	m_messages.Serialize(ar);
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
// CMultiStringDoc diagnostics

#ifdef _DEBUG
void CMultiStringDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultiStringDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiStringDoc commands
