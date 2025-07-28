// PropsheetView.h : interface of the CPropsheetView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPSHEETVIEW_H__137B08BA_2C9A_4A2E_AF11_4CA1145BDB16__INCLUDED_)
#define AFX_PROPSHEETVIEW_H__137B08BA_2C9A_4A2E_AF11_4CA1145BDB16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropsheetView : public CView
{
protected: // create from serialization only
	CPropsheetView();
	DECLARE_DYNCREATE(CPropsheetView)

// Attributes
public:
	CPropsheetDoc* GetDocument();

protected:
	CString m_edit;
    BOOL    m_check;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropsheetView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropsheetView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropsheetView)
	afx_msg void OnPropsheet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PropsheetView.cpp
inline CPropsheetDoc* CPropsheetView::GetDocument()
   { return (CPropsheetDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEETVIEW_H__137B08BA_2C9A_4A2E_AF11_4CA1145BDB16__INCLUDED_)
