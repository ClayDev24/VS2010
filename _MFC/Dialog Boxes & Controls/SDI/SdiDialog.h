#if !defined(AFX_SDIDIALOG_H__910D9224_C473_47ED_9D56_A7962BA248CD__INCLUDED_)
#define AFX_SDIDIALOG_H__910D9224_C473_47ED_9D56_A7962BA248CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SdiDialog.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CSdiDialog dialog

class CSdiDialog : public CDialog
{
// Construction
public:
	CString m_selected;
	CSdiDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSdiDialog)
	enum { IDD = IDD_DIALOG1 };
	CListBox	m_listbox;
	BOOL	m_check;
	CString	m_edit;
	int		m_radio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdiDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSdiDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIDIALOG_H__910D9224_C473_47ED_9D56_A7962BA248CD__INCLUDED_)
