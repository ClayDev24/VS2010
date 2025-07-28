// using dllView.h : interface of the CUsingdllView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USINGDLLVIEW_H__2D92CC96_FF1F_4A90_B72B_562430745397__INCLUDED_)
#define AFX_USINGDLLVIEW_H__2D92CC96_FF1F_4A90_B72B_562430745397__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUsingdllView : public CView
{
protected: // create from serialization only
	CUsingdllView();
	DECLARE_DYNCREATE(CUsingdllView)

// Attributes
public:
	CUsingdllDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsingdllView)
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
	virtual ~CUsingdllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUsingdllView)
	afx_msg void OnEditUndo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in using dllView.cpp
inline CUsingdllDoc* CUsingdllView::GetDocument()
   { return (CUsingdllDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USINGDLLVIEW_H__2D92CC96_FF1F_4A90_B72B_562430745397__INCLUDED_)
