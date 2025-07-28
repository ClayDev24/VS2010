// fileDemoView.h : interface of the CFileDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEDEMOVIEW_H__9FE301CB_E5B2_47E1_A312_BB35444FE692__INCLUDED_)
#define AFX_FILEDEMOVIEW_H__9FE301CB_E5B2_47E1_A312_BB35444FE692__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFileDemoView : public CView
{
protected: // create from serialization only
	CFileDemoView();
	DECLARE_DYNCREATE(CFileDemoView)

// Attributes
public:
	CFileDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDemoView)
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
	virtual ~CFileDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFileDemoView)
	afx_msg void OnFileChangemessage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in fileDemoView.cpp
inline CFileDemoDoc* CFileDemoView::GetDocument()
   { return (CFileDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDEMOVIEW_H__9FE301CB_E5B2_47E1_A312_BB35444FE692__INCLUDED_)
