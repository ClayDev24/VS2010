// App2View.h : interface of the CApp2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APP2VIEW_H__F319A7EC_C53F_4DC4_A338_1127ACB08E91__INCLUDED_)
#define AFX_APP2VIEW_H__F319A7EC_C53F_4DC4_A338_1127ACB08E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CApp2View : public CView
{
protected: // create from serialization only
	CApp2View();
	DECLARE_DYNCREATE(CApp2View)

// Attributes
public:
	CApp2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp2View)
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
	virtual ~CApp2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CApp2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in App2View.cpp
inline CApp2Doc* CApp2View::GetDocument()
   { return (CApp2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP2VIEW_H__F319A7EC_C53F_4DC4_A338_1127ACB08E91__INCLUDED_)
