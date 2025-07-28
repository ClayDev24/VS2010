// Thread3View.h : interface of the CThread3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD3VIEW_H__EBD1BECD_F40F_4143_939E_B306808EA0BE__INCLUDED_)
#define AFX_THREAD3VIEW_H__EBD1BECD_F40F_4143_939E_B306808EA0BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CThread3View : public CView
{
protected: // create from serialization only
	CThread3View();
	DECLARE_DYNCREATE(CThread3View)

// Attributes
public:
	CThread3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThread3View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CThread3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CThread3View)
	afx_msg void OnThreadStartthread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Thread3View.cpp
inline CThread3Doc* CThread3View::GetDocument()
   { return (CThread3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREAD3VIEW_H__EBD1BECD_F40F_4143_939E_B306808EA0BE__INCLUDED_)
