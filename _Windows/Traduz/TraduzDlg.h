// TraduzDlg.h : header file
//

#if !defined(AFX_TRADUZDLG_H__5CA8FE06_2D4D_444E_B1E7_81D5568B5BFA__INCLUDED_)
#define AFX_TRADUZDLG_H__5CA8FE06_2D4D_444E_B1E7_81D5568B5BFA__INCLUDED_

#include <vector>
#include "OpenFile.h"
#include "Legend.h"	// Added by ClassView
#include "legendsub.h"
#include "LegendSrt.h"

using namespace std;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTraduzDlg dialog

class CTraduzDlg : public CDialog
{
// Construction
public:
	CString m_lingua;
	CString translate(CString fala);
	CTraduzDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTraduzDlg)
	enum { IDD = IDD_TRADUZ_DIALOG };
	CButton	m_open;
	CComboBox	m_combo;
	CString	m_in;
	CString	m_out;
	CString	m_path;
	int		m_vigente;
	CString	m_status;
	//}}AFX_DATA
	int contador;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraduzDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTraduzDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnNext();
	afx_msg void OnPrevious();
	afx_msg void OnTranslate();
	afx_msg void OnFirst();
	afx_msg void OnLast();
	afx_msg void OnGo();
	afx_msg void OnCloseupCombo1();
	afx_msg void OnSave();
	afx_msg void OnChangePath();
	afx_msg void OnChangeEdit2();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//private:
public:
	
	CLegend *legend_original;
	CLegend *legend_altered;
private:
	void update(int cur, CString orig);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRADUZDLG_H__5CA8FE06_2D4D_444E_B1E7_81D5568B5BFA__INCLUDED_)
