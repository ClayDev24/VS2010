// DateTimeEditCtrlDemoDlg.h : header file
//

#if !defined(AFX_DATETIMEEDITCTRLDEMODLG_H__5A689EAF_25E0_4F71_BA43_16D8107FF233__INCLUDED_)
#define AFX_DATETIMEEDITCTRLDEMODLG_H__5A689EAF_25E0_4F71_BA43_16D8107FF233__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define USE_DATETIMEEDITCTRL 1

#ifdef USE_DATETIMEEDITCTRL
#include "DateTimeEditCtrl.h"
#endif

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlDemoDlg dialog

class CDateTimeEditCtrlDemoDlg : public CDialog
{
// Construction
public:
	CDateTimeEditCtrlDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDateTimeEditCtrlDemoDlg)
	enum { IDD = IDD_DATETIMEEDITCTRLDEMO_DIALOG };
	CButton	m_btnSpecified;
	CButton	m_btnDefault;
	CButton	m_btnValidCharsOnly;
	CEdit	m_editValidChars;
	CStatic	m_labelResults;
	CListBox	m_listNotify;
#ifdef USE_DATETIMEEDITCTRL
	CDateTimeEditCtrl	m_date;
#else
	CDateTimeCtrl	m_date;
#endif
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeEditCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDateTimeEditCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFormatDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFormatqueryDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnWmkeydownDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUserstringDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCloseupDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDropdownDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnClearList();
	afx_msg void OnBtnValidCharsOnly();
	afx_msg void OnChangeEditValidChars();
	afx_msg void OnBtnDefault();
	afx_msg void OnBtnSpecified();
	//}}AFX_MSG
	afx_msg void OnChangeDatetimepicker1();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATETIMEEDITCTRLDEMODLG_H__5A689EAF_25E0_4F71_BA43_16D8107FF233__INCLUDED_)
