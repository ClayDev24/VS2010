// $$root$$View.h : interface of the C$$Safe_root$$View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_)
#define AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class C$$Safe_root$$View : public CView
{
protected: // create from serialization only
	C$$Safe_root$$View();
	DECLARE_DYNCREATE(C$$Safe_root$$View)

// Attributes
public:
	C$$Safe_root$$Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C$$Safe_root$$View)
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
	virtual ~C$$Safe_root$$View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C$$Safe_root$$View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in $$root$$View.cpp
inline C$$Safe_root$$Doc* C$$Safe_root$$View::GetDocument()
   { return (C$$Safe_root$$Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORIGINALVIEW_H__E18509B1_3077_4360_B178_CE2757C2C12C__INCLUDED_)
