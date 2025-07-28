////////////////////////////////////////////////////////////////////////////
// File:	DateTimeEditCtrl.h
// Version:	3.3
// Created:	09-Jul-2003
//
// Author:	Paul S. Vickery
// E-mail:	paul@vickeryhome.freeserve.co.uk
//
// Class to provide an editable Date picker control. Based on CDateTimeCtrl.
//
// You are free to use or modify this code, with no restrictions, other than
// you continue to acknowledge me as the original author in this source code,
// or any code derived from it.
//
// If you use this code, or use it as a base for your own code, it would be 
// nice to hear from you simply so I know it's not been a waste of time!
//
// Copyright (c) 2003 Paul S. Vickery
//
////////////////////////////////////////////////////////////////////////////
// Version History:
//
// Version 3.3 - 09-Jul-2003
// =========================
// Updated to support Unicode.
//
// Version 3.2 - 15-Apr-2003
// =========================
// - Extended control to accept the DTM_SETRANGE and DTM_GETRANGE messages.
// - Fixed incorrect implementation of DTS_RIGHTALIGN.
// - Added facility to use a bitmap for the button instead of a down arrow
// - WM_NOTIFY notifications now passed to parent window from date control's 
//   children
// - Fixed bug where clicking on current (circled) day when edit control is 
//   empty closed the calendar did not put the selected day in the edit control
//
// Version 3.1 - 20-Jan-2003
// =========================
// - Fixed bug where, if new date text is set in the DTN_DATETIMECHANGE handler 
//   (for instance to constrain the date within some boundary), and the user 
//   selects a date which is 'out-of-bounds', and the calendar closes, the 
//   selected date is copied to the edit control, overwriting the 'fixed' date.
// 
// Version 3 - 17-Jan-2003
// =======================
// - Fixed bug where a call to Get/SetWindowText, SetFont, or any function 
//   which resulted in a sending of a DTM_XXX message caused an assertion the 
//   first time round, if called from the OnInitDialog of a parent dialog, or 
//   equivalent.
// 
// Version 2 - 07-Jan-2003
// =======================
// - Edit control notifications (eg EN_CHANGE) now get sent to date control's 
//   parent window
// - Added features as suggested by Marc Clifton on CodeProject:
//   - Added function to validate a date string (IsValidDate)
//   - Added function to only allow valid chars to be typed into the edit control.
//     Also a function to set the valid characters. The default valid characters 
//     are 0-9 and the current user's locale's date separator. If the user changes 
//     the locale settings then the control will automatically pick this up and 
//     use the new separator.
//   - Added ability to use up/down keys to edit portions of the date text
// 
// Version 1 - 03-Jan-2003
// =======================
// Initial version
// 
////////////////////////////////////////////////////////////////////////////
// PLEASE LEAVE THIS HEADER INTACT
////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATETIMEEDITCTRL_H__737F6EBA_CC75_11D6_8634_0000B48746CF__INCLUDED_)
#define AFX_DATETIMEEDITCTRL_H__737F6EBA_CC75_11D6_8634_0000B48746CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxdtctl.h" // only needed for date/time controls

#define DTCEM_DESTROY_CALENDAR	(WM_USER+1)
#define DTCEM_RECREATE		(WM_USER+2)

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlButton window
class CDateTimeEditCtrlButton : public CButton
{
public:
  CDateTimeEditCtrlButton() { m_bRestoreFocus = FALSE; m_pWndLastFocus = NULL; m_bNonEditable = FALSE; }
  void RestoreFocus(BOOL bRestore = TRUE) { m_bRestoreFocus = bRestore; }
  void SetNonEditable(BOOL bNonEditable = TRUE) { m_bNonEditable = bNonEditable; }
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CDateTimeEditCtrlButton)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

  // Generated message map functions
protected:
  CWnd* m_pWndLastFocus;
  BOOL m_bRestoreFocus;
  BOOL m_bNonEditable;

  //{{AFX_MSG(CDateTimeEditCtrlButton)
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlEditCtrl window
class CDateTimeEditCtrlEditCtrl : public CEdit
{
public:
  BOOL GetAllowUpDownKeys();
  void SetAllowUpDownKeys(BOOL bAllow = TRUE);
  CString GetValidChars();
  void SetValidChars(LPCTSTR lpszValidChars = NULL);
  BOOL GetValidCharsOnly();
  void SetValidCharsOnly(BOOL bValidCharsOnly = TRUE);
  CDateTimeEditCtrlEditCtrl();
  void SetNonEditable(BOOL bNonEditable = TRUE) { m_bNonEditable = bNonEditable; }
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CDateTimeEditCtrlEditCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

  // Generated message map functions
protected:
	void SendDateTimeChange();
  BOOL m_bNonEditable;
  BOOL m_bValidCharsOnly;
  CString m_sValidChars;
  BOOL m_bAllowUpDownKeys;

	//{{AFX_MSG(CDateTimeEditCtrlEditCtrl)
	afx_msg UINT OnGetDlgCode();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	//}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlMonthCalCtrl window

class CDateTimeEditCtrlMonthCalCtrl : public CMonthCalCtrl
{
// Construction
public:
	CDateTimeEditCtrlMonthCalCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeEditCtrlMonthCalCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDateTimeEditCtrlMonthCalCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDateTimeEditCtrlMonthCalCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlCalendarWnd window

class CDateTimeEditCtrlCalendarWnd : public CWnd
{
// Construction
public:
  CDateTimeEditCtrlCalendarWnd(CWnd* pComboParent, DWORD dwMCStyle = 0);

// Attributes
public:
  CDateTimeEditCtrlMonthCalCtrl* GetMonthCalCtrl() { return m_pCalendar; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeEditCtrlCalendarWnd)
	public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDateTimeEditCtrlCalendarWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDateTimeEditCtrlCalendarWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CDateTimeEditCtrlMonthCalCtrl* m_pCalendar;

	CWnd* m_pComboParent;

	DWORD m_dwMCStyle;
};

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrl window

class CDateTimeEditCtrl : public CDateTimeCtrl
{
  DECLARE_DYNAMIC(CDateTimeEditCtrl)

// Construction
public:
	CDateTimeEditCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeEditCtrl)
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
  BOOL SetButtonImageID(UINT nID);
  BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
  virtual ~CDateTimeEditCtrl();
  CEdit* GetEditControl() const { return m_pEdit; }
  void EnableButton(BOOL bEnable = TRUE);
  void RestoreFocus(BOOL bRestore = TRUE) { if (m_pBtn != NULL) m_pBtn->RestoreFocus(bRestore); }
  void SetNonEditable(BOOL bNonEditable = TRUE);
  BOOL GetNonEditable() { return m_bNonEditable; }
  virtual BOOL IsValidDate(LPCTSTR lpszDate = NULL);
  void SetValidCharsOnly(BOOL bValidCharsOnly = TRUE);
  BOOL GetValidCharsOnly();
  void SetValidChars(LPCTSTR lpszValidChars = NULL);
  CString GetValidChars();
  void SetAllowUpDownKeys(BOOL bAllow = TRUE);
  BOOL GetAllowUpDownKeys();

	// Generated message map functions
protected:
  BOOL DestroyCalendar(BOOL bDiscard = FALSE);
  BOOL CreateCalendar();
  CDateTimeEditCtrlEditCtrl* m_pEdit;
  CDateTimeEditCtrlButton* m_pBtn;
  UINT m_nBtnImageID;
  BOOL m_bNonEditable;
  BOOL m_bRightAlign;

  CSpinButtonCtrl* m_pSpin;

  CDateTimeEditCtrlCalendarWnd* m_pCalWnd;
  CString m_sOrigDate;

  BOOL m_bInCreate;

  COleDateTime* m_pDateMin;
  COleDateTime* m_pDateMax;

  // monthcal properties
  HFONT m_hMCFont;
  COLORREF m_acrMonthCal[6];

	//{{AFX_MSG(CDateTimeEditCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	afx_msg LONG OnDestroyCalendar(WPARAM wParam, LPARAM lParam);
	afx_msg void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg LONG OnRecreate(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATETIMEEDITCTRL_H__737F6EBA_CC75_11D6_8634_0000B48746CF__INCLUDED_)
