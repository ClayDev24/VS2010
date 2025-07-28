#if !defined(AFX_DIEROLLPPG_H__D6A15A74_BC0C_4809_9B8F_23ABF9E7C45B__INCLUDED_)
#define AFX_DIEROLLPPG_H__D6A15A74_BC0C_4809_9B8F_23ABF9E7C45B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DierollPpg.h : Declaration of the CDierollPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CDierollPropPage : See DierollPpg.cpp.cpp for implementation.

class CDierollPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDierollPropPage)
	DECLARE_OLECREATE_EX(CDierollPropPage)

// Constructor
public:
	CDierollPropPage();

// Dialog Data
	//{{AFX_DATA(CDierollPropPage)
	enum { IDD = IDD_PROPPAGE_DIEROLL };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CDierollPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIEROLLPPG_H__D6A15A74_BC0C_4809_9B8F_23ABF9E7C45B__INCLUDED)
