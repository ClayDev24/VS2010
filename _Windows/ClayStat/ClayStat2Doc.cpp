// ClayStat2Doc.cpp : implementation of the ClayStat2Doc class
//

#include "stdafx.h"
#include "ClayStat2View.h"
#include "ClayStat2.h"
#include "ClayStat2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ClayStat2Doc

IMPLEMENT_DYNCREATE(ClayStat2Doc, CDocument)

BEGIN_MESSAGE_MAP(ClayStat2Doc, CDocument)
	//{{AFX_MSG_MAP(ClayStat2Doc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ClayStat2Doc construction/destruction

ClayStat2Doc::ClayStat2Doc()
{
	m_estat = new CStatistics();
}

ClayStat2Doc::~ClayStat2Doc()
{
	delete m_estat;
}

BOOL ClayStat2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	m_saida = " ";

	m_uCurrentBtnGrp  = ID_GROUP_GENERAL;
	m_uCurrentBtnView = ID_VIEW_OCULTAR;
	m_uCurrentBtnMod  = ID_MODE_NICK;
	m_uCurrentBtnPer  = ID_PERIOD_DAYLY;
	m_uCurrentBtnHdr  = ID_HEADER_NICKNAME;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// ClayStat2Doc serialization

void ClayStat2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_saida;
	}
	else
	{
		ar >> m_saida;
	}
}

/////////////////////////////////////////////////////////////////////////////
// ClayStat2Doc diagnostics

#ifdef _DEBUG
void ClayStat2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void ClayStat2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ClayStat2Doc commands

CString ClayStat2Doc::saida()
{
	return m_saida;
}
