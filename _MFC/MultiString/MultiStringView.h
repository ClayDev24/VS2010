// MultiStringView.h : interface of the CMultiStringView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTISTRINGVIEW_H__198A06E2_64B3_4F3D_8C73_EFF01399B440__INCLUDED_)
#define AFX_MULTISTRINGVIEW_H__198A06E2_64B3_4F3D_8C73_EFF01399B440__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiStringView : public CView
{
protected: // create from serialization only
	CMultiStringView();
	DECLARE_DYNCREATE(CMultiStringView)

// Attributes
public:
	CMultiStringDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiStringView)
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
	virtual ~CMultiStringView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiStringView)
	afx_msg void OnFileChangemessage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiStringView.cpp
inline CMultiStringDoc* CMultiStringView::GetDocument()
   { return (CMultiStringDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISTRINGVIEW_H__198A06E2_64B3_4F3D_8C73_EFF01399B440__INCLUDED_)
