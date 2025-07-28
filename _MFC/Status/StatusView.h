// StatusView.h : interface of the CStatusView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSVIEW_H__E9AD5D0A_DBD8_4369_9CBB_8BCC5AEA6A1C__INCLUDED_)
#define AFX_STATUSVIEW_H__E9AD5D0A_DBD8_4369_9CBB_8BCC5AEA6A1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusView : public CView
{
protected: // create from serialization only
	CStatusView();
	DECLARE_DYNCREATE(CStatusView)

// Attributes
public:
	CStatusDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusView)
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
	virtual ~CStatusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StatusView.cpp
inline CStatusDoc* CStatusView::GetDocument()
   { return (CStatusDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSVIEW_H__E9AD5D0A_DBD8_4369_9CBB_8BCC5AEA6A1C__INCLUDED_)
