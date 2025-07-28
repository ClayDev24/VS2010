// DialogbarDemoView.h : interface of the CDialogbarDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIALOGBARDEMOVIEW_H__D614B24E_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
#define AFX_DIALOGBARDEMOVIEW_H__D614B24E_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDialogbarDemoView : public CView
{
protected: // create from serialization only
	CDialogbarDemoView();
	DECLARE_DYNCREATE(CDialogbarDemoView)

// Attributes
public:
	CDialogbarDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogbarDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogbarDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDialogbarDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DialogbarDemoView.cpp
inline CDialogbarDemoDoc* CDialogbarDemoView::GetDocument()
   { return (CDialogbarDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBARDEMOVIEW_H__D614B24E_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
