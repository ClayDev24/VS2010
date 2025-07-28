// Char ListingDoc.cpp : implementation of the CCharListingDoc class
//

#include "stdafx.h"
#include "Char Listing.h"

#include "Char ListingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharListingDoc

IMPLEMENT_DYNCREATE(CCharListingDoc, CDocument)

BEGIN_MESSAGE_MAP(CCharListingDoc, CDocument)
	//{{AFX_MSG_MAP(CCharListingDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharListingDoc construction/destruction

CCharListingDoc::CCharListingDoc()
{
	// TODO: add one-time construction code here

}

CCharListingDoc::~CCharListingDoc()
{
}

BOOL CCharListingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code herE	(SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCharListingDoc serialization

void CCharListingDoc::Serialize(CArchive& ar)
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
// CCharListingDoc diagnostics

#ifdef _DEBUG
void CCharListingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCharListingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCharListingDoc commands
