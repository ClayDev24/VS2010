#if !defined(AFX_OPTIONSDIALOG_H__6AF84594_3752_4985_93F5_24AE40131D0C__INCLUDED_)
#define AFX_OPTIONSDIALOG_H__6AF84594_3752_4985_93F5_24AE40131D0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsDialog dialog

#define HIDD_OPTIONS_STRING 2
#define HIDD_OPTIONS_BLACK 3
#define HIDD_OPTIONS_RED 4
#define HIDD_OPTIONS_GREEN 5
#define HIDD_OPTIONS_HORIZCENTER 6
#define HIDD_OPTIONS_VERTCENTER 7
#define HIDD_OPTIONS_OK 8
#define HIDD_OPTIONS_CANCEL 9

class COptionsDialog : public CDialog
{
// Construction
public:
	COptionsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDialog)
	enum { IDD = IDD_OPTIONS };
	CString	m_string;
	int		m_color;
	BOOL	m_horizcenter;
	BOOL	m_vertcenter;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDIALOG_H__6AF84594_3752_4985_93F5_24AE40131D0C__INCLUDED_)
