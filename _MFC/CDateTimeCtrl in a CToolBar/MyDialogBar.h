// MyDialogBar.h: interface for the MyDialogBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYDIALOGBAR_H__D614B259_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
#define AFX_MYDIALOGBAR_H__D614B259_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Label.h"
#include "DateTimeCtrl.h"
#include "DialogBarEx.h"

 
#endif // !defined(AFX_MYDIALOGBAR_H__D614B259_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
/////////////////////////////////////////////////////////////////////////////
// CMyDialogBar window

class CMyDialogBar : public  CDialogBarEx 
{
// Construction
public:
	CMyDialogBar();

// Attributes
public:
	CDateTimeCtrl m_DateTimeCtrl ;
	CLabel m_Label ;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDialogBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void OnInitDialogBar();
	virtual ~CMyDialogBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyDialogBar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
