// fileDemoDoc.cpp : implementation of the CFileDemoDoc class
//

#include "stdafx.h"
#include "fileDemo.h"

#include "fileDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileDemoDoc

IMPLEMENT_DYNCREATE(CFileDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CFileDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileDemoDoc construction/destruction

CFileDemoDoc::CFileDemoDoc()
{
	// TODO: add one-time construction code here

}

CFileDemoDoc::~CFileDemoDoc()
{
}

BOOL CFileDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	m_message = "Default Message";

	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFileDemoDoc serialization

void CFileDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_message;
	}
	else
	{
		ar >> m_message;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFileDemoDoc diagnostics

#ifdef _DEBUG
void CFileDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileDemoDoc commands

CString CFileDemoDoc::get_message()
{
	return m_message;
}

void CFileDemoDoc::set_message(CString cs)
{
	m_message = cs;
	SetModifiedFlag();
}
