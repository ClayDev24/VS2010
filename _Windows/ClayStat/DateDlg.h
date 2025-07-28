// DateDlg.h: interface for the CDateDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATEDLG_H__F83F3790_7CE3_4ED3_AAD4_9D213A1EB032__INCLUDED_)
#define AFX_DATEDLG_H__F83F3790_7CE3_4ED3_AAD4_9D213A1EB032__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DialogBarEx.h"

class CDateDlg : public CDialogBarEx  
{
public:
	CDateDlg();

// Attributes
public:
	CDateTimeCtrl m_date;
	CComboBox     m_combo;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void OnInitDialogBar();
	virtual ~CDateDlg();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDateDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // !defined(AFX_DATEDLG_H__F83F3790_7CE3_4ED3_AAD4_9D213A1EB032__INCLUDED_)
