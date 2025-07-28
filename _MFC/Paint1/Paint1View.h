// Paint1View.h : interface of the CPaint1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINT1VIEW_H__3D813877_EA80_4BD1_800E_1217BE9EA796__INCLUDED_)
#define AFX_PAINT1VIEW_H__3D813877_EA80_4BD1_800E_1217BE9EA796__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPaint1View : public CView
{
protected: // create from serialization only
	CPaint1View();
	DECLARE_DYNCREATE(CPaint1View)

// Attributes
protected:
	enum {Fonts, Pens, Brushes} m_Display;
public:
	CPaint1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaint1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaint1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void ShowBrushes(CDC* pDC);
	void ShowPens(CDC* pDC);
	void ShowFonts(CDC* pDC);
	//{{AFX_MSG(CPaint1View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Paint1View.cpp
inline CPaint1Doc* CPaint1View::GetDocument()
   { return (CPaint1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT1VIEW_H__3D813877_EA80_4BD1_800E_1217BE9EA796__INCLUDED_)
