// EmployeeView.h : interface of the CEmployeeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEEVIEW_H__0B54A473_2A81_4995_8C6F_F127B7800566__INCLUDED_)
#define AFX_EMPLOYEEVIEW_H__0B54A473_2A81_4995_8C6F_F127B7800566__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmployeeSet;

class CEmployeeView : public CRecordView
{
protected: // create from serialization only
	CEmployeeView();
	DECLARE_DYNCREATE(CEmployeeView)

public:
	//{{AFX_DATA(CEmployeeView)
	enum{ IDD = IDD_EMPLOYEE_FORM };
	CEmployeeSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CEmployeeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEmployeeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEmployeeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EmployeeView.cpp
inline CEmployeeDoc* CEmployeeView::GetDocument()
   { return (CEmployeeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEVIEW_H__0B54A473_2A81_4995_8C6F_F127B7800566__INCLUDED_)
