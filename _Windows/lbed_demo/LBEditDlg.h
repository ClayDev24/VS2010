// LBEditDlg.h : header file
//

#if !defined(AFX_LBEDITDLG_H__1FCF0929_B99A_436A_B1C0_23BA3DADAD1B__INCLUDED_)
#define AFX_LBEDITDLG_H__1FCF0929_B99A_436A_B1C0_23BA3DADAD1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLBEditDlg dialog

class CLBEditDlg : public CDialog
{
// Construction
public:
	CLBEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLBEditDlg)
	enum { IDD = IDD_LBEDIT_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLBEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_cursel ;

	// Generated message map functions
	//{{AFX_MSG(CLBEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LBEDITDLG_H__1FCF0929_B99A_436A_B1C0_23BA3DADAD1B__INCLUDED_)
