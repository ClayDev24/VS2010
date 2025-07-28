// EmployeeDoc.h : interface of the CEmployeeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEEDOC_H__3EDC6312_5E2C_4DDC_A4BB_8086CD852EFE__INCLUDED_)
#define AFX_EMPLOYEEDOC_H__3EDC6312_5E2C_4DDC_A4BB_8086CD852EFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "EmployeeSet.h"


class CEmployeeDoc : public CDocument
{
protected: // create from serialization only
	CEmployeeDoc();
	DECLARE_DYNCREATE(CEmployeeDoc)

// Attributes
public:
	CEmployeeSet m_employeeSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEmployeeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEmployeeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEDOC_H__3EDC6312_5E2C_4DDC_A4BB_8086CD852EFE__INCLUDED_)
