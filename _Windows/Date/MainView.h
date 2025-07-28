// MainView.h : interface of the CMainView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVIEW_H__3DD52FEC_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
#define AFX_MAINVIEW_H__3DD52FEC_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMainView : public CFormView
{
protected: // create from serialization only
	CMainView();
	DECLARE_DYNCREATE(CMainView)

public:
	//{{AFX_DATA(CMainView)
	enum { IDD = IDD_DATECLASS_FORM };
	CString	m_TheDate;
	CString	m_R1;
	CString	m_R2;
	int		m_SubNum;
	int		m_AddNum;
	int		m_AddNum2;
	int		m_AddNum3;
	int		m_SumNum2;
	int		m_SumNum3;
	CString	m_Time1;
	CString	m_Time2;
	long	m_Date2;
	CString	m_R3;
	//}}AFX_DATA

// Attributes
public:
	CDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateTime();
	virtual ~CMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMainView)
	afx_msg void OnKillfocusThedate();
	afx_msg void OnButtonadd();
	afx_msg void OnButtonsub();
	afx_msg void OnButtonadd2();
	afx_msg void OnButtonsub2();
	afx_msg void OnButtonadd3();
	afx_msg void OnButtonsub3();
	afx_msg void OnKillfocusThedate2();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MainView.cpp
inline CDoc* CMainView::GetDocument()
   { return (CDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINVIEW_H__3DD52FEC_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
