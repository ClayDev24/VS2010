// ToolView.h : interface of the CToolView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLVIEW_H__D9623B4A_7048_459E_B788_CD2E0F9FBC48__INCLUDED_)
#define AFX_TOOLVIEW_H__D9623B4A_7048_459E_B788_CD2E0F9FBC48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolView : public CView
{
protected: // create from serialization only
	CToolView();
	DECLARE_DYNCREATE(CToolView)

// Attributes
public:
	CToolDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolView)
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
	virtual ~CToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolView)
	afx_msg void OnCircle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolView.cpp
inline CToolDoc* CToolView::GetDocument()
   { return (CToolDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLVIEW_H__D9623B4A_7048_459E_B788_CD2E0F9FBC48__INCLUDED_)
