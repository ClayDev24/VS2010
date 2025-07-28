// Char ListingView.h : interface of the CCharListingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARLISTINGVIEW_H__250FF46E_87AD_4E7A_A67A_C85FA5CBC54B__INCLUDED_)
#define AFX_CHARLISTINGVIEW_H__250FF46E_87AD_4E7A_A67A_C85FA5CBC54B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCharListingView : public CFormView
{
protected: // create from serialization only
	CCharListingView();
	DECLARE_DYNCREATE(CCharListingView)

public:
	//{{AFX_DATA(CCharListingView)
	enum { IDD = IDD_CHARLISTING_FORM };
	CButton	m_list;
	CButton	m_clear;
	CListBox	m_console;
	int		m_radio;
	//}}AFX_DATA

// Attributes
public:
	CCharListingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharListingView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCharListingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCharListingView)
	afx_msg void OnList();
	afx_msg void OnClear();
	afx_msg void OnRadio128();
	afx_msg void OnRadio256();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Char ListingView.cpp
inline CCharListingDoc* CCharListingView::GetDocument()
   { return (CCharListingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARLISTINGVIEW_H__250FF46E_87AD_4E7A_A67A_C85FA5CBC54B__INCLUDED_)
