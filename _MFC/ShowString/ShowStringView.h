// ShowStringView.h : interface of the CShowStringView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSTRINGVIEW_H__E5CAB904_C408_4176_A091_938CB5161BDE__INCLUDED_)
#define AFX_SHOWSTRINGVIEW_H__E5CAB904_C408_4176_A091_938CB5161BDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowStringView : public CView
{
protected: // create from serialization only
	CShowStringView();
	DECLARE_DYNCREATE(CShowStringView)

// Attributes
public:
	CShowStringDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringView)
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
	virtual ~CShowStringView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowStringView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowStringView.cpp
inline CShowStringDoc* CShowStringView::GetDocument()
   { return (CShowStringDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRINGVIEW_H__E5CAB904_C408_4176_A091_938CB5161BDE__INCLUDED_)
