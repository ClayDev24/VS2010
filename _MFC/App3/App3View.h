// App3View.h : interface of the CApp3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APP3VIEW_H__ACB2F9C1_F82C_4140_BD33_F6187EF404AD__INCLUDED_)
#define AFX_APP3VIEW_H__ACB2F9C1_F82C_4140_BD33_F6187EF404AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CApp3View : public CView
{
protected: // create from serialization only
	CApp3View();
	DECLARE_DYNCREATE(CApp3View)

// Attributes
public:
	CApp3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp3View)
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
	virtual ~CApp3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CApp3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in App3View.cpp
inline CApp3Doc* CApp3View::GetDocument()
   { return (CApp3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP3VIEW_H__ACB2F9C1_F82C_4140_BD33_F6187EF404AD__INCLUDED_)
