// App4View.h : interface of the CApp4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_)
#define AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CApp4View : public CView
{
protected: // create from serialization only
	CApp4View();
	DECLARE_DYNCREATE(CApp4View)

// Attributes
public:
	CApp4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp4View)
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
	virtual ~CApp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CApp4View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in App4View.cpp
inline CApp4Doc* CApp4View::GetDocument()
   { return (CApp4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_)
