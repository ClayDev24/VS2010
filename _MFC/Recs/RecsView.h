// RecsView.h : interface of the CRecsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECSVIEW_H__A62E3F65_40F7_4F24_B214_6CCE4B402C2D__INCLUDED_)
#define AFX_RECSVIEW_H__A62E3F65_40F7_4F24_B214_6CCE4B402C2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRecsView : public CView
{
protected: // create from serialization only
	CRecsView();
	DECLARE_DYNCREATE(CRecsView)

// Attributes
public:
	CRecsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRecsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRecsView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RecsView.cpp
inline CRecsDoc* CRecsView::GetDocument()
   { return (CRecsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECSVIEW_H__A62E3F65_40F7_4F24_B214_6CCE4B402C2D__INCLUDED_)
