// ClayStat2Doc.h : interface of the ClayStat2Doc class
//
/////////////////////////////////////////////////////////////////////////////
#include "Statistics.h"

#if !defined(AFX_CLAYSTAT2DOC_H__0B02224F_0147_464F_BD42_CB34A26D4E52__INCLUDED_)
#define AFX_CLAYSTAT2DOC_H__0B02224F_0147_464F_BD42_CB34A26D4E52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class ClayStat2Doc : public CDocument
{
protected: // create from serialization only
	ClayStat2Doc();
	DECLARE_DYNCREATE(ClayStat2Doc)

// Attributes
public:

	CString     m_saida;
	CStatistics *m_estat;
	UINT        m_uCurrentBtn;
	UINT        m_uCurrentBtnGrp;
	UINT        m_uCurrentBtnHdr;
	UINT        m_uCurrentBtnView;
	UINT        m_uCurrentBtnMod;
	UINT        m_uCurrentBtnPer;
	//bool        m_downloadComplete;
    int         m_numLines;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ClayStat2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString saida();
	virtual ~ClayStat2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(ClayStat2Doc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLAYSTAT2DOC_H__0B02224F_0147_464F_BD42_CB34A26D4E52__INCLUDED_)
