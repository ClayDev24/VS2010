////////////////////////////////////////////////////////////////////////////
// File:	DateTimeEditCtrl.cpp
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

#include "stdafx.h"
#include "DateTimeEditCtrl.h"

#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ID_EDIT		1
#define ID_BUTTON	2
#define ID_CALENDAR	3
#define ID_DROPWND	4

#define CALENDAR_AS_POPUP 1

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlButton

BEGIN_MESSAGE_MAP(CDateTimeEditCtrlButton, CButton)
	//{{AFX_MSG_MAP(CDateTimeEditCtrlButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlButton message handlers

void CDateTimeEditCtrlButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
  CButton::OnLButtonUp(nFlags, point);
  // set the focus back to the parent, and stop it looking like the default button
  ModifyStyle(BS_DEFPUSHBUTTON, 0);
  if (! m_bNonEditable && m_bRestoreFocus && m_pWndLastFocus != NULL && ::IsWindow(m_pWndLastFocus->m_hWnd))
    m_pWndLastFocus->SetFocus();
  else
    GetParent()->SetFocus();
}

void CDateTimeEditCtrlButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
  if (! m_bNonEditable && m_bRestoreFocus)
    m_pWndLastFocus = CWnd::GetFocus();
  else
    m_pWndLastFocus = NULL;
  CButton::OnLButtonDown(nFlags, point);
  // stop it looking like the default button
  ModifyStyle(BS_DEFPUSHBUTTON, 0);
}

void CDateTimeEditCtrlButton::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  CButton::OnKeyDown(nChar, nRepCnt, nFlags);

  if (nChar == VK_F4)
    // hide or show cal ctrl, by simulating a button click
    GetParent()->PostMessage(WM_COMMAND, MAKEWPARAM(ID_BUTTON, BN_CLICKED), (LPARAM)GetNextWindow()->GetSafeHwnd());
}

BOOL CDateTimeEditCtrlButton::PreTranslateMessage(MSG* pMsg) 
{
  if (pMsg->message == WM_KEYDOWN && 
	(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
  {
    // destroy calendar
    if (GetParent()->SendMessage(DTCEM_DESTROY_CALENDAR, (pMsg->wParam == VK_ESCAPE)))
      return TRUE;
  }
  return CButton::PreTranslateMessage(pMsg);
}

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlEditCtrl

BEGIN_MESSAGE_MAP(CDateTimeEditCtrlEditCtrl, CEdit)
	//{{AFX_MSG_MAP(CDateTimeEditCtrlEditCtrl)
	ON_WM_GETDLGCODE()
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_SETTINGCHANGE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlEditCtrl message handlers

static TCHAR s_chDateSep = _T('/');
static TCHAR s_szDateFormat[81] = { _T('\0') };

CDateTimeEditCtrlEditCtrl::CDateTimeEditCtrlEditCtrl()
{
  m_bNonEditable = FALSE;
  m_bValidCharsOnly = FALSE;
  m_bAllowUpDownKeys = TRUE;

  int nLen = ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDATE, &s_chDateSep, 0);
  if (nLen != 0)
    ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDATE, &s_chDateSep, nLen);
  nLen = ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SSHORTDATE, s_szDateFormat, 0);
  if (nLen != 0)
    ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SSHORTDATE, s_szDateFormat, nLen);
}

UINT CDateTimeEditCtrlEditCtrl::OnGetDlgCode() 
{
  if (m_bNonEditable)
    return DLGC_STATIC;
  return CEdit::OnGetDlgCode();
}

BOOL CDateTimeEditCtrlEditCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
  // if we are non-editable, we want the cursor to look like an arrow
  // not like an I-bar
  if (m_bNonEditable && nHitTest == HTCLIENT)
  {
    AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    return TRUE;
  }
  return CEdit::OnSetCursor(pWnd, nHitTest, message);
}

HBRUSH CDateTimeEditCtrlEditCtrl::CtlColor(CDC* pDC, UINT nCtlColor) 
{
  // if we are non-editable, we want the edit to be readonly, but look
  // like editable (ie with white (standard 'window') background)
  if (m_bNonEditable)
  {
    pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
    return GetSysColorBrush(COLOR_WINDOW);
  }
  return NULL;
}

BOOL CDateTimeEditCtrlEditCtrl::PreTranslateMessage(MSG* pMsg) 
{
  if (pMsg->message == WM_KEYDOWN && 
	(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
  {
    // destroy calendar
    if (GetParent()->SendMessage(DTCEM_DESTROY_CALENDAR, (pMsg->wParam == VK_ESCAPE)))
      return TRUE;
  }
  return CEdit::PreTranslateMessage(pMsg);
}

int ReverseFindOneOf(const CString& sString, LPCTSTR lpszCharSet)
{
#ifdef _UNICODE
  wstring s;
#else
  string s;
#endif
  s = sString;
  return s.find_last_of(lpszCharSet);
}

int FindOneOf(const CString& sString, LPCTSTR lpszCharSet, int nStart)
{
#ifdef _UNICODE
  wstring s;
#else
  string s;
#endif
  s = sString;
  return s.find_first_of(lpszCharSet, nStart);
}

void CDateTimeEditCtrlEditCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  if (m_bAllowUpDownKeys && nChar == VK_UP || nChar == VK_DOWN)
  {
    BOOL bInc = (nChar == VK_UP);
    // increment part of date in which cursor is positioned
    int nStart, nEnd;
    GetSel(nStart, nEnd);
    CString sText;
    GetWindowText(sText);
    CString sSeps = s_chDateSep;

    // find portion of text we're in, and select
    // between two separators
    if (! m_sValidChars.IsEmpty())
    {
      sSeps = m_sValidChars;
      for (TCHAR chRemove = _T('0'); chRemove <= _T('9'); chRemove++)
	sSeps.Remove(chRemove);
      // sSeps just contains the separators now
    }

    int nSep2 = FindOneOf(sText, sSeps, nEnd);
    CString sStart = sText;
    if (nSep2 >= 0)
      sStart = sText.Left(nSep2);
    int nPos = ReverseFindOneOf(sStart, sSeps);

    BOOL bLeftPos = TRUE;
    BOOL bMidPos = FALSE;
    int nSep1 = 0;
    if (nPos >= 0)
    {
      // mid position
      if (nSep2 >= 0)
      {
	bLeftPos = FALSE;
	bMidPos = TRUE;
      }
      nSep1 = nPos + 1;
    }
    if (nSep2 < 0)
    {
      // right-most portion
      nSep2 = sText.GetLength();
      bLeftPos = FALSE;
    }

    CString sDateFormat = s_szDateFormat;
    CString sPortion;

    int nFirstSep = sDateFormat.FindOneOf(sSeps);
    // find out which part of the format we are in
    if (bLeftPos)
    {
      // get bit before first sep
      if (nFirstSep > 0)
	sPortion = sDateFormat.Left(nFirstSep);
    }
    else if (bMidPos)
    {
      // get bit after first sep, and before last
      if (nFirstSep > 0)
      {
	nFirstSep++;
	int nPos = FindOneOf(sDateFormat, sSeps, nFirstSep);
	if (nPos >= nFirstSep)
	  sPortion = sDateFormat.Mid(nFirstSep, nPos - nFirstSep);
      }
    }
    else
    {
      // get bit after last sep
      int nPos = ReverseFindOneOf(sDateFormat, sSeps);
      if (nPos >= 0)
	sPortion = sDateFormat.Right(sDateFormat.GetLength() - (nPos+1));
    }

    // select new portion
    SetSel(nSep1, nSep2);
    CString sVal = sStart.GetLength() > nSep1 ? sStart.Mid(nSep1) : sStart;

    LPTSTR lpszFormat = _T("%02d");
    int nVal = _ttoi(sVal);
    int nMin = 1;
    int nMax = 12;

    // make sure the number is within bounds depending on portion
    if (! sPortion.IsEmpty())
    {
      int nLen = sPortion.GetLength();
      if (nLen != 2)
	lpszFormat = _T("%0d");
      switch (sPortion.GetAt(0))
      {
      case _T('d'):	// day
      case _T('D'):	// day
	nMax = 31;
	break;

      case _T('M'):	// month
      case _T('m'):	// month
	nMax = 12;
	break;

      case _T('y'):	// year
      case _T('Y'):	// year
	{
	  nMin = 0;
	  if (nLen == 1)
	    nMax = 9;
	  else if (nLen == 2)
	    nMax = 99;
	  else if (nLen == 4)
	  {
	    lpszFormat = _T("%04d");
	    nMax = 9999;
	  }
	}
	break;
      };
    }

    if (bInc)
      nVal++;
    else
      nVal--;

    // wrap values
    if (nVal < nMin)
      nVal = nMax;
    else if (nVal > nMax)
      nVal = nMin;

    sVal.Format(lpszFormat, nVal);

    // replace and re-select new portion
    ReplaceSel(sVal);

    BOOL bInvalid = FALSE;

    // if this takes the value out of range, correct it
    CDateTimeEditCtrl* pCtrl = DYNAMIC_DOWNCAST(CDateTimeEditCtrl, GetParent());
    if (pCtrl != NULL)
    {
      CString sTextNew;
      GetWindowText(sTextNew);
      COleDateTime dateMin, dateMax;
      DWORD dwFlags = pCtrl->GetRange(&dateMin, &dateMax);
      COleDateTime date;
      date.ParseDateTime(sTextNew);
      if (dwFlags & GDTR_MIN && date < dateMin)
      {
	bInvalid = TRUE;
	date = dateMin;
      }
      else if (dwFlags & GDTR_MAX && date > dateMax)
      {
	bInvalid = TRUE;
	date = dateMax;
      }
      sText = date.Format(VAR_DATEVALUEONLY/*s_szDateFormat*/);
    }

    if (bInvalid)
    {
      SetWindowText(sText);
      SetSel(nStart, nEnd);
    }
    else
    {
      nSep2 = nSep1 + sVal.GetLength();
      SetSel(nSep1, nSep2);
    }

    SendDateTimeChange();

    return;
  }

  CEdit::OnKeyDown(nChar, nRepCnt, nFlags);

  if (nChar == VK_F4)
    // hide or show cal ctrl, by simulating a button click
    GetParent()->PostMessage(WM_COMMAND, MAKEWPARAM(ID_BUTTON, BN_CLICKED), (LPARAM)GetNextWindow()->GetSafeHwnd());
}

void CDateTimeEditCtrlEditCtrl::SendDateTimeChange()
{
  CDateTimeEditCtrl* pCtrl = DYNAMIC_DOWNCAST(CDateTimeEditCtrl, GetParent());
  if (pCtrl != NULL)
  {
    CWnd* pParent = pCtrl->GetParent();
    if (pParent != NULL)
    {
      COleDateTime date;
      CString sText;
      GetWindowText(sText);
      date.ParseDateTime(sText);
      SYSTEMTIME st = { '\0' };
      date.GetAsSystemTime(st);
      // tell parent about it (DTN_DATETIMECHANGE)
      NMDATETIMECHANGE nmdtc;
      nmdtc.nmhdr.code = DTN_DATETIMECHANGE;
      nmdtc.nmhdr.hwndFrom = pCtrl->GetSafeHwnd();
      nmdtc.nmhdr.idFrom = pCtrl->GetDlgCtrlID();
      nmdtc.dwFlags = GDT_VALID;
      nmdtc.st = st;
      pParent->SendMessage(WM_NOTIFY, (WPARAM)nmdtc.nmhdr.idFrom, (LPARAM)&nmdtc);
    }
  }
}

// set whether the user can only enter chars that are valid
void CDateTimeEditCtrlEditCtrl::SetValidCharsOnly(BOOL bValidCharsOnly/*=TRUE*/)
{
  m_bValidCharsOnly = bValidCharsOnly;
}

// returns whether the user can only enter valid chars into the edit control
BOOL CDateTimeEditCtrlEditCtrl::GetValidCharsOnly()
{
  return m_bValidCharsOnly;
}

// sets the chars that are valid for the user to type into the edit control
// if NULL is specified, then the default chars are used (0-9 and current 
// user's locale's date separator). If the user changes the locale settings 
// then the control will automatically pick this up and use the new separator.
void CDateTimeEditCtrlEditCtrl::SetValidChars(LPCTSTR lpszValidChars/*=NULL*/)
{
  m_sValidChars = lpszValidChars;
}

// returns the chars that are valid for the user to type into the edit control
CString CDateTimeEditCtrlEditCtrl::GetValidChars()
{
  return m_sValidChars;
}

void CDateTimeEditCtrlEditCtrl::SetAllowUpDownKeys(BOOL bAllow/*=TRUE*/)
{
  m_bAllowUpDownKeys = bAllow;
}

BOOL CDateTimeEditCtrlEditCtrl::GetAllowUpDownKeys()
{
  return m_bAllowUpDownKeys;
}

void CDateTimeEditCtrlEditCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  if (m_bValidCharsOnly && nChar >= 0x20)
  {
    BOOL bValid = TRUE;
    if (m_sValidChars.IsEmpty())
    {
      // only allow numeric or date separator
      if (nChar >= 0x20 && (nChar < _T('0') || nChar > _T('9')) && nChar != (UINT)s_chDateSep)
	bValid = FALSE;
    }
    else
    {
      // see if the char is in the valid chars list
      if (m_sValidChars.Find((TCHAR)nChar) == -1)
	bValid = FALSE;
    }
    if (! bValid)
    {
      // don't allow it
      MessageBeep(MB_ICONEXCLAMATION);
      return;
    }
  }
  CEdit::OnChar(nChar, nRepCnt, nFlags);

  // tell the parent dialog of the change
  SendDateTimeChange();
}

void CDateTimeEditCtrlEditCtrl::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
  if (lpszSection != NULL && lstrcmpi(lpszSection, _T("intl")) == 0)
  {
    int nLen = ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDATE, &s_chDateSep, 0);
    if (nLen != 0)
      ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDATE, &s_chDateSep, nLen);
  }
  CEdit::OnSettingChange(uFlags, lpszSection);
}

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlMonthCalCtrl

CDateTimeEditCtrlMonthCalCtrl::CDateTimeEditCtrlMonthCalCtrl()
{
}

CDateTimeEditCtrlMonthCalCtrl::~CDateTimeEditCtrlMonthCalCtrl()
{
}

BEGIN_MESSAGE_MAP(CDateTimeEditCtrlMonthCalCtrl, CMonthCalCtrl)
	//{{AFX_MSG_MAP(CDateTimeEditCtrlMonthCalCtrl)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlMonthCalCtrl message handlers

LRESULT CDateTimeEditCtrlMonthCalCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  if (message == WM_LBUTTONDOWN || 
      message == WM_MBUTTONDOWN || 
      message == WM_RBUTTONDOWN)
  {
    // Is mouse within control
    CPoint point(lParam);
    CRect rcClient;
    GetClientRect(rcClient);
    if (! rcClient.PtInRect(point))
    {
      ReleaseCapture();
      GetOwner()->PostMessage(DTCEM_DESTROY_CALENDAR);
    }
    else
      SetCapture();
  }
  else if (message == WM_LBUTTONUP || 
	   message == WM_MBUTTONUP || 
	   message == WM_RBUTTONUP)
  {
    CMonthCalCtrl::WindowProc(message, wParam, lParam);
    // we seem to lose capture on Xbuttonup, which stops us catching
    // out-of-rect messages after changing, for instance, the month
    // so we need to re-capture messages. However, if the Xbuttondown
    // was out-of-rect, then we won't exist by this point, so test validity
    if (::IsWindow(m_hWnd))
      SetCapture();
    return 0;
  }
  else if (message == WM_PARENTNOTIFY)
  {
    if (LOWORD(wParam) == WM_DESTROY)
      // just destroyed the 'year' edit/updown, but this makes us lose capture
      SetCapture();
  }
  return CMonthCalCtrl::WindowProc(message, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlCalendarWnd

CDateTimeEditCtrlCalendarWnd::CDateTimeEditCtrlCalendarWnd(CWnd* pComboParent, DWORD dwMCStyle/*=0*/)
{
  m_pComboParent = pComboParent;
  m_dwMCStyle = dwMCStyle;
  m_pCalendar = NULL;
}

CDateTimeEditCtrlCalendarWnd::~CDateTimeEditCtrlCalendarWnd()
{
  delete m_pCalendar;
}

BEGIN_MESSAGE_MAP(CDateTimeEditCtrlCalendarWnd, CWnd)
	//{{AFX_MSG_MAP(CDateTimeEditCtrlCalendarWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ACTIVATEAPP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlCalendarWnd message handlers

BOOL CDateTimeEditCtrlCalendarWnd::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
  return CWnd::Create(0, 0, dwStyle, rect, pParentWnd, nID, pContext);
}

int CDateTimeEditCtrlCalendarWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  if (CWnd::OnCreate(lpCreateStruct) == -1)
    return -1;

  // hide the taskbar button
  if (!(lpCreateStruct->style & WS_POPUP))
    ModifyStyleEx(0, WS_EX_TOOLWINDOW);

  // Create calendar control
  m_pCalendar = new CDateTimeEditCtrlMonthCalCtrl;
  DWORD dwStyle = m_dwMCStyle & ~(WS_VISIBLE);
  VERIFY(m_pCalendar->Create(dwStyle | WS_CHILD, CPoint(0, 0), this, ID_CALENDAR));
  m_pCalendar->SizeMinReq();
  m_pCalendar->SetOwner(m_pComboParent);

  // size self to fit calendar
  // and make us top-most, so we're seen
  CRect rcCal;
  m_pCalendar->GetWindowRect(&rcCal);
  CalcWindowRect(&rcCal);
  SetWindowPos(&wndTopMost, 0, 0, rcCal.Width(), rcCal.Height(), SWP_NOMOVE | SWP_NOACTIVATE);

  m_pCalendar->ShowWindow(SW_SHOW);

  // the calendar needs to catch all mouse messages, so it can respond to
  // changes in the visible month etc
  m_pCalendar->SetCapture();

  return 0;
}

BOOL CDateTimeEditCtrlCalendarWnd::DestroyWindow() 
{
  ReleaseCapture();
  m_pCalendar->DestroyWindow();
  return CWnd::DestroyWindow();
}

void CDateTimeEditCtrlCalendarWnd::OnActivateApp(BOOL bActive, HTASK hTask) 
{
  CWnd::OnActivateApp(bActive, (DWORD)hTask);
  if (! bActive && m_pComboParent != NULL)
    m_pComboParent->PostMessage(DTCEM_DESTROY_CALENDAR, TRUE);
}

BOOL CDateTimeEditCtrlCalendarWnd::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  LPNMHDR lpnmhdr = (LPNMHDR)lParam;
  if (lpnmhdr != NULL && m_pComboParent != NULL && 
	    (lpnmhdr->code == MCN_SELECT || lpnmhdr->code == MCN_SELCHANGE))
  {
    *pResult = m_pComboParent->SendMessage(WM_NOTIFY, wParam, lParam);
    return TRUE;
  }
  return CWnd::OnNotify(wParam, lParam, pResult);
}

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrl

#if _AFXDLL
IMPLEMENT_DYNAMIC(CDateTimeCtrl, CWnd)
#endif

IMPLEMENT_DYNAMIC(CDateTimeEditCtrl, CDateTimeCtrl)

CDateTimeEditCtrl::CDateTimeEditCtrl()
{
  m_pEdit = NULL;
  m_pBtn = NULL;
  m_nBtnImageID = 0;
  m_bNonEditable = FALSE;
  m_bRightAlign = FALSE;
  m_pCalWnd = NULL;
  m_bInCreate = FALSE;
  m_hMCFont = NULL;
  // initial values of cal ctrl colours
  m_acrMonthCal[0] = (COLORREF)-1;		// the background color (between months)
  m_acrMonthCal[1] = GetSysColor(COLOR_BTNTEXT);// the dates
  m_acrMonthCal[2] = GetSysColor(COLOR_ACTIVECAPTION);	// background of the title
  m_acrMonthCal[3] = (COLORREF)-1;		// title text
  m_acrMonthCal[4] = (COLORREF)-1;		// background within the month cal
  m_acrMonthCal[5] = GetSysColor(COLOR_3DSHADOW);// the text color of header & trailing days
  m_pDateMin = NULL;
  m_pDateMax = NULL;
}

CDateTimeEditCtrl::~CDateTimeEditCtrl()
{
    delete m_pEdit;
    delete m_pBtn;
    delete m_pCalWnd;
  delete m_pDateMin;
  delete m_pDateMax;
  ReleaseCapture();
}

BEGIN_MESSAGE_MAP(CDateTimeEditCtrl, CDateTimeCtrl)
	//{{AFX_MSG_MAP(CDateTimeEditCtrl)
	ON_WM_CREATE()
	ON_WM_ENABLE()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_CANCELMODE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(DTCEM_DESTROY_CALENDAR, OnDestroyCalendar)
	ON_WM_STYLECHANGING()
	ON_MESSAGE(DTCEM_RECREATE, OnRecreate)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrl message handlers

LONG CDateTimeEditCtrl::OnDestroyCalendar(WPARAM wParam, LPARAM lParam)
{
  // wParam is the key this is in response to if applicable
  return DestroyCalendar(wParam);
}

BOOL CDateTimeEditCtrl::Create(DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID)
{
  m_bInCreate = TRUE;
  if (! CWnd::Create(NULL, NULL, dwStyle, rect, pParentWnd, nID))
    return FALSE;

  return TRUE;
}

int CDateTimeEditCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  m_bInCreate = TRUE; // we're being created explicitly

  DWORD dwStyleDTS = (lpCreateStruct->style & 0xFF);
  lpCreateStruct->style &= ~0xFF;
  if (CDateTimeCtrl::OnCreate(lpCreateStruct) == -1)
    return -1;

  ASSERT(!(dwStyleDTS & DTS_UPDOWN)); // updown not supported
  // 'show none' style not supported, as this control would be used instead
  ASSERT(!(dwStyleDTS & DTS_SHOWNONE));
  ASSERT(!(dwStyleDTS & DTS_APPCANPARSE));  // app parsing not supported
  ASSERT(!(dwStyleDTS & DTS_LONGDATEFORMAT)); // only short dates supported
  ASSERT(!(dwStyleDTS & DTS_TIMEFORMAT)); // only short dates supported

  if (dwStyleDTS & DTS_RIGHTALIGN)
    m_bRightAlign = TRUE;
  CRect rc(0, 0, 0, 0);

  m_pEdit = new CDateTimeEditCtrlEditCtrl;
  m_pBtn = new CDateTimeEditCtrlButton;

  // Get the edit control styles and create the edit control
  // we want to isolate the edit styles from the style, and
  // visible and disabled if specified
  // then add in WS_CHILD
  DWORD dwStyleEdit = lpCreateStruct->style & (WS_VISIBLE | WS_DISABLED | 0x3DFFL);
  dwStyleEdit |= WS_CHILD | WS_CLIPSIBLINGS;
  if (!m_pEdit->Create(dwStyleEdit, rc, this, ID_EDIT))
    return -1;

  // Get the button styles and create the button
  // just allow visible and disabled from the specified style
  // and add WS_CHILD and BS_PUSHBUTTON
  DWORD dwStyleBtn = lpCreateStruct->style & (WS_VISIBLE | WS_DISABLED);
  dwStyleBtn |= WS_CHILD | WS_CLIPSIBLINGS | BS_PUSHBUTTON;
  if (! m_pBtn->Create(_T("6"), dwStyleBtn, rc, this, ID_BUTTON))
    return -1;

  SetButtonImageID(m_nBtnImageID);

  // if the edit control is readonly, disable the button
  if (dwStyleEdit & ES_READONLY)
    m_pBtn->EnableWindow(FALSE);

  // get parent's font, and apply to this control
  CWnd* pParent = GetParent();
  if (pParent != NULL)
  {
    CFont* pFont = pParent->GetFont();
    SetFont(pFont);
  }

  CFont font;
  font.CreatePointFont(100, _T("Marlett"));
  HFONT hFont = (HFONT)font.Detach();
  m_pBtn->SendMessage(WM_SETFONT, (WPARAM)hFont, (LPARAM)TRUE);

  return 0;
}

void CDateTimeEditCtrl::OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
  ASSERT(lpStyleStruct != NULL);

  if (nStyleType & GWL_STYLE && !(nStyleType & GWL_EXSTYLE))
  {
    DWORD dwStyleDTSOld = (lpStyleStruct->styleOld & 0xFF);
    DWORD dwStyleDTSNew = (lpStyleStruct->styleNew & 0xFF);
    // isolate bits which have changed (xor old and new)
    DWORD dwStyleDTS = dwStyleDTSOld ^ dwStyleDTSNew;
    ASSERT(!(dwStyleDTS & DTS_UPDOWN));
    ASSERT(!(dwStyleDTS & DTS_SHOWNONE));
    ASSERT(!(dwStyleDTS & DTS_APPCANPARSE));
    ASSERT(!(dwStyleDTS & DTS_LONGDATEFORMAT));
    ASSERT(!(dwStyleDTS & DTS_TIMEFORMAT));

    if (dwStyleDTS & DTS_RIGHTALIGN)
      m_pEdit->ModifyStyle(dwStyleDTSOld & ES_RIGHT, dwStyleDTSNew & ES_RIGHT);
  }
}

void CDateTimeEditCtrl::OnEnable(BOOL bEnable) 
{
  CDateTimeCtrl::OnEnable(bEnable);

  if (m_pEdit != NULL)
    m_pEdit->EnableWindow(bEnable);
  if (m_pBtn != NULL)
    m_pBtn->EnableWindow(bEnable);
}

void CDateTimeEditCtrl::EnableButton(BOOL bEnable/*=TRUE*/)
{
  if (m_pBtn != NULL)
    m_pBtn->EnableWindow(bEnable);
}

void CDateTimeEditCtrl::OnSetFocus(CWnd* pOldWnd) 
{
  CDateTimeCtrl::OnSetFocus(pOldWnd);

  if (m_bNonEditable && m_pBtn != NULL && ::IsWindow(m_pBtn->m_hWnd))
  {
    // set the focus to the button control
    m_pBtn->SetFocus();
  }
  else if (m_pEdit != NULL && ::IsWindow(m_pEdit->m_hWnd))
  {
    // set the focus to the edit control
    m_pEdit->SetFocus();
    m_pEdit->SetSel(0, -1);
  }
}

void CDateTimeEditCtrl::OnSize(UINT nType, int cx, int cy) 
{
  CDateTimeCtrl::OnSize(nType, cx, cy);

  // size the child controls
  m_pEdit->MoveWindow(0, 0, cx - cy, cy);
  m_pBtn->MoveWindow(cx - cy, 0, cy, cy);
}

BOOL CDateTimeEditCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  NMHDR* pnmhdr = (NMHDR*)lParam;
  if (pnmhdr != NULL)
  {
    // if notification from cal ctrl then act on them, and destroy cal ctrl
    if (m_pCalWnd != NULL && pnmhdr->idFrom == ID_CALENDAR)
    {
      if (pnmhdr->code == MCN_SELECT || 
	  pnmhdr->code == MCN_SELCHANGE || 
	  pnmhdr->code == MCN_GETDAYSTATE)
      {
	if (pnmhdr->code == MCN_SELCHANGE || pnmhdr->code == MCN_SELECT)
	{
	  // get date, and put in edit ctrl
	  LPNMSELCHANGE lpnmsc = (LPNMSELCHANGE)pnmhdr;
	  COleDateTime date(lpnmsc->stSelStart);
	  ASSERT(date.GetStatus() == COleDateTime::valid);
	  CString sDate = date.Format(VAR_DATEVALUEONLY);
	  m_pEdit->SetWindowText(sDate);

	  // tell parent about it (DTN_DATETIMECHANGE)
	  CWnd* pParent = GetParent();
	  if (pParent != NULL)
	  {
	    NMDATETIMECHANGE nmdtc;
	    nmdtc.nmhdr.code = DTN_DATETIMECHANGE;
	    nmdtc.nmhdr.hwndFrom = GetSafeHwnd();
	    nmdtc.nmhdr.idFrom = GetDlgCtrlID();
	    nmdtc.dwFlags = GDT_VALID;
	    nmdtc.st = lpnmsc->stSelStart;
	    pParent->SendMessage(WM_NOTIFY, (WPARAM)nmdtc.nmhdr.idFrom, (LPARAM)&nmdtc);
	  }
	  if (pnmhdr->code == MCN_SELECT)
	  {
	    // we want to close the calendar when the user selects a date
	    DestroyCalendar();
	  }
	}
	return TRUE;
      }
    }
    // pass generic notifications from the controls to the parent
    CWnd* pParent = GetParent();
    if (pParent != NULL)
    {
      pnmhdr->idFrom = GetDlgCtrlID();
      pnmhdr->hwndFrom = GetSafeHwnd();
      *pResult = pParent->SendMessage(WM_NOTIFY, (WPARAM)pnmhdr->idFrom, lParam);
      return TRUE;
    }
  }
  return CDateTimeCtrl::OnNotify(wParam, lParam, pResult);
}

BOOL CDateTimeEditCtrl::OnCommand(WPARAM wParam, LPARAM lParam) 
{
  // if button clicked, show calendar control
  if (HIWORD(wParam) == BN_CLICKED && LOWORD(wParam) == ID_BUTTON)
  {
    if (m_pCalWnd != NULL)
      DestroyCalendar();
    else
      CreateCalendar();
    return TRUE;
  }
  return CDateTimeCtrl::OnCommand(wParam, lParam);
}

void CDateTimeEditCtrl::SetNonEditable(BOOL bNonEditable/*=TRUE*/)
{
  if (m_pEdit == NULL)
    return;
  m_bNonEditable = bNonEditable;
  DWORD dwStyleEdit = m_pEdit->GetStyle();
  CFont* pFont = m_pEdit->GetFont();
  CString sText;
  m_pEdit->GetWindowText(sText);
  m_pEdit->DestroyWindow();
  if (m_bNonEditable)
    dwStyleEdit |= ES_READONLY;
  else
    dwStyleEdit &= ~ES_READONLY;
  if (! m_pEdit->Create(dwStyleEdit, CRect(0, 0, 0, 0), this, ID_EDIT))
    return;
  m_pEdit->SetNonEditable(m_bNonEditable);
  m_pEdit->SetFont(pFont);
  m_pEdit->SetWindowText(sText);
  CRect rc;
  GetClientRect(&rc);
  m_pEdit->MoveWindow(0, 0, rc.Width() - rc.Height(), rc.Height());
  // tell the button whether we are non-editable, so it can decide
  // whether to try and restore the focus
  m_pBtn->SetNonEditable(m_bNonEditable);
}

BOOL CDateTimeEditCtrl::CreateCalendar()
{
  CRect rc;
  ASSERT(m_pCalWnd == NULL);
  m_pCalWnd = new CDateTimeEditCtrlCalendarWnd(this);
  GetWindowRect(&rc);
  rc.top = rc.bottom;

  // Get screen size
  CRect rcWorkArea;
  SystemParametersInfo(SPI_GETWORKAREA, 0, (LPRECT)rcWorkArea, 0);
  if (rc.bottom >= rcWorkArea.bottom)
    rc.bottom = rcWorkArea.bottom;

#if CALENDAR_AS_POPUP
  m_pCalWnd->CreateEx(0, NULL, NULL, WS_CHILD | WS_POPUP | WS_BORDER | WS_CLIPSIBLINGS, rc, this, 0);
#else
  m_pCalWnd->Create(WS_CHILD | WS_BORDER, rc, GetDesktopWindow(), ID_DROPWND);
#endif // CALENDAR_AS_POPUP

  // line calendar window up with appropriate edge of control
  CRect rcCal, rcEdit;
  GetClientRect(&rc);
  ClientToScreen(&rc);
  rc.top = rc.bottom;
  m_pCalWnd->GetWindowRect(&rcCal);
  m_pEdit->GetClientRect(&rcEdit);
  m_pEdit->ClientToScreen(&rcEdit);
  rc.bottom = rc.top + rcCal.Height();
  if (m_bRightAlign)
  {
    rc.right = rcEdit.right;
    rc.left = rc.right - rcCal.Width();
  }
  else
  {
    rc.left = rcEdit.left;
    rc.right = rc.left + rcCal.Width();
  }

  // if it goes off the bottom of the screen, then put it above this control
  if (rc.bottom > rcWorkArea.bottom)
  {
    CRect rcWnd;
    GetWindowRect(&rcWnd);
    rc.OffsetRect(0, -(rcCal.Height() + rcWnd.Height()));
  }
  // if it's off the left, then nudge it over
  if (rc.left < rcWorkArea.left)
  {
    rc.OffsetRect(rcWorkArea.left - rc.left, 0);
  }
  m_pCalWnd->SetWindowPos(NULL, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  m_pCalWnd->ShowWindow(SW_SHOWNA);

  CDateTimeEditCtrlMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();

  // set the min/max range if they've been set
  if (pCal != NULL)
    pCal->SetRange(m_pDateMin, m_pDateMax);

  // get edit's current date/time, and set ctrl accordingly
  m_pEdit->GetWindowText(m_sOrigDate);
  if (pCal != NULL)
  {
    COleDateTime dateInit(COleDateTime::GetCurrentTime());
    COleDateTime date;
    if (! m_sOrigDate.IsEmpty() && date.ParseDateTime(m_sOrigDate))
      dateInit = date;
    if (m_pDateMin != NULL && dateInit < *m_pDateMin)
      dateInit = *m_pDateMin;
    else if (m_pDateMax != NULL && dateInit > *m_pDateMax)
      dateInit = *m_pDateMax;
    if (dateInit.GetStatus() == GDT_VALID)
      pCal->SetCurSel(dateInit);
  }

  // set font of cal ctrl if font is non-NULL
  // set colours of cal ctrl if colours are not -1
  if (pCal != NULL)
  {
    if (m_hMCFont != NULL)
    {
      CFont* pFont = CFont::FromHandle(m_hMCFont);
      if (pFont != NULL)
	pCal->SetFont(pFont);
    }
    for (int n = 0; n < 6; n++)
    {
      if (m_acrMonthCal[n] != -1)
	pCal->SetColor(n, m_acrMonthCal[n]);
    }
  }

  // tell parent about it (DTN_DROPDOWN)
  CWnd* pParent = GetParent();
  if (pParent != NULL)
  {
    NMHDR nmhdr;
    nmhdr.code = DTN_DROPDOWN;
    nmhdr.hwndFrom = GetSafeHwnd();
    nmhdr.idFrom = GetDlgCtrlID();
    pParent->SendMessage(WM_NOTIFY, (WPARAM)nmhdr.idFrom, (LPARAM)&nmhdr);
  }

  return TRUE;
}

// destroy the cal ctrl if shown
// returns TRUE if destroyed, else FALSE if not shown
BOOL CDateTimeEditCtrl::DestroyCalendar(BOOL bDiscard/*=FALSE*/)
{
  if (m_pCalWnd == NULL)
    return FALSE;
  if (::IsWindow(m_pCalWnd->m_hWnd))
    m_pCalWnd->DestroyWindow();
  delete m_pCalWnd;
  m_pCalWnd = NULL;
  m_pEdit->SetFocus();
  CWnd* pParent = GetParent();
  // if we canceled, set the original time string, and send change
  if (bDiscard)
  {
    m_pEdit->SetWindowText(m_sOrigDate);
    // tell parent about it (DTN_DATETIMECHANGE)
    if (pParent != NULL)
    {
      NMDATETIMECHANGE nmdtc;
      nmdtc.nmhdr.code = DTN_DATETIMECHANGE;
      nmdtc.nmhdr.hwndFrom = GetSafeHwnd();
      nmdtc.nmhdr.idFrom = GetDlgCtrlID();
      COleDateTime date;
      date.ParseDateTime(m_sOrigDate);
      if (date.GetStatus() == COleDateTime::valid)
	nmdtc.dwFlags = GDT_VALID;
      else
	nmdtc.dwFlags = GDT_NONE;
      date.GetAsSystemTime(nmdtc.st);
      pParent->SendMessage(WM_NOTIFY, (WPARAM)nmdtc.nmhdr.idFrom, (LPARAM)&nmdtc);
    }
  }
  // tell parent about it (DTN_CLOSEUP)
  if (pParent != NULL)
  {
    NMHDR nmhdr;
    nmhdr.code = DTN_CLOSEUP;
    nmhdr.hwndFrom = GetSafeHwnd();
    nmhdr.idFrom = GetDlgCtrlID();
    pParent->SendMessage(WM_NOTIFY, (WPARAM)nmhdr.idFrom, (LPARAM)&nmhdr);
  }
  return TRUE;
}

void CDateTimeEditCtrl::OnCancelMode() 
{
  CDateTimeCtrl::OnCancelMode();
  DestroyCalendar();
}

#define MAP_DTM(dtm) case dtm: s = #dtm;

CString FormatDTM(UINT message)
{
  CString s("<unknown>");
  switch (message)
  {
  MAP_DTM(DTM_GETSYSTEMTIME)
  MAP_DTM(DTM_SETSYSTEMTIME)
  MAP_DTM(DTM_GETRANGE)
  MAP_DTM(DTM_SETRANGE)
  MAP_DTM(DTM_SETFORMAT)
  MAP_DTM(DTM_SETMCCOLOR)
  MAP_DTM(DTM_GETMCCOLOR)
  MAP_DTM(DTM_GETMONTHCAL)
  MAP_DTM(DTM_SETMCFONT)
  MAP_DTM(DTM_GETMCFONT)
  };
  return s;
}

LRESULT CDateTimeEditCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  // if a recreate message is pending, then we won't have created 
  // the edit control etc yet, so deal with it now
  if (m_pEdit == NULL)
  {
    MSG msg;
    if (PeekMessage(&msg, NULL, DTCEM_RECREATE, DTCEM_RECREATE, PM_REMOVE))
    {
      DispatchMessage(&msg);
      ASSERT(m_pEdit != NULL);
      ASSERT(m_pBtn != NULL);
    }
  }
  switch (message)
  {
  case WM_SETTEXT:
  case WM_GETTEXT:
  case WM_GETTEXTLENGTH:
    {
      ASSERT(m_pEdit != NULL);
      return m_pEdit->SendMessage(message, wParam, lParam);
    }
    break;

  case WM_SETFONT:
    {
      ASSERT(m_pEdit != NULL);
      ASSERT(m_pBtn != NULL);
      m_pEdit->SendMessage(WM_SETFONT, wParam, lParam);

      CFont font;
      font.CreatePointFont(100, _T("Marlett"));
      HFONT hFont = (HFONT)font.Detach();
      m_pBtn->SendMessage(WM_SETFONT, (WPARAM)hFont, lParam);
    }
    break;

  case WM_COMMAND:
    {
      // send notifications from the edit control to the parent
      if (LOWORD(wParam) == ID_EDIT)
      {
	CWnd* pParent = GetParent();
	if (pParent != NULL)
	  return pParent->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), HIWORD(wParam)), (LPARAM)GetSafeHwnd());
      }
    }
    break;

  case DTM_GETSYSTEMTIME:
    {
      // get the time from the current edit text
      // and return whether it's valid
      CString sDate;
      ASSERT(m_pEdit != NULL);
      m_pEdit->GetWindowText(sDate);
      if (sDate.IsEmpty())
	return GDT_NONE;
      else
      {
	LPSYSTEMTIME lpst = (LPSYSTEMTIME)lParam;
	ASSERT(lpst != NULL);
	COleDateTime date;
	date.ParseDateTime(sDate);
	ASSERT(date.GetStatus() == COleDateTime::valid);
	date.GetAsSystemTime(*lpst);
	return GDT_VALID;
      }
    }
    break;

  case DTM_SETSYSTEMTIME:
    {
      // set the control's time to the time specified
      ASSERT(m_pEdit != NULL);
      if (wParam == GDT_NONE)
	m_pEdit->SetWindowText(_T(""));
      else if (wParam == GDT_VALID)
      {
	if (lParam == 0)
	  return FALSE;
	LPSYSTEMTIME lpst = (LPSYSTEMTIME)lParam;
	COleDateTime date(*lpst);
	if (date.GetStatus() != COleDateTime::valid)
	  return FALSE;
	CString sDate = date.Format(VAR_DATEVALUEONLY);
	m_pEdit->SetWindowText(sDate);
      }
      else
	return FALSE;
      return TRUE;
    }
    break;

  case DTM_GETMONTHCAL:
    {
      if (m_pCalWnd != NULL)
      {
	CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
	if (pCal != NULL)
	  return (LRESULT)pCal->m_hWnd;
      }
      return (LRESULT)NULL;
    }
    break;

  case DTM_SETMCFONT:
    {
      m_hMCFont = (HFONT)wParam;
      BOOL bRedraw = (BOOL)lParam;
      if (m_pCalWnd == NULL)
	return 0;
      CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
      if (pCal == NULL)
	return 0;
      CFont* pFont = CFont::FromHandle(m_hMCFont);
      pCal->SetFont(pFont, bRedraw);
    }
    break;

  case DTM_GETMCFONT:
    {
      if (m_pCalWnd == NULL)
	return (LRESULT)m_hMCFont;
      CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
      if (pCal == NULL)
	return (LRESULT)m_hMCFont;
      CFont* pFont = pCal->GetFont();
      return (LRESULT)pFont->m_hObject;
    }
    break;

  case DTM_SETMCCOLOR:
    {
      // set the colour accordingly
      int nIndex = (int)wParam;
      ASSERT(nIndex >= 0 && nIndex < 6);
      COLORREF crOld = m_acrMonthCal[nIndex];
      m_acrMonthCal[nIndex] = (COLORREF)lParam;
      // if the cal ctrl is present, set its colours
      if (m_pCalWnd != NULL)
      {
	CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
	if (pCal != NULL)
	  return (LRESULT)pCal->SetColor(nIndex, m_acrMonthCal[nIndex]);
      }
      return (LRESULT)crOld;
    }
    break;

  case DTM_GETMCCOLOR:
    {
      // get the colour accordingly
      int nIndex = (int)wParam;
      ASSERT(nIndex >= 0 && nIndex < 6);
      // if the cal ctrl is present, get its colours
      if (m_pCalWnd != NULL)
      {
	CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
	if (pCal != NULL)
	  return (LRESULT)pCal->GetColor(nIndex);
      }
      return (LRESULT)m_acrMonthCal[nIndex];
    }
    break;

  case DTM_SETRANGE:
    {
      int nFlags = (int)wParam;
      LPSYSTEMTIME ast = (LPSYSTEMTIME)lParam;
      delete m_pDateMin;
      delete m_pDateMax;
      if (ast != NULL)
      {
	if (nFlags & GDTR_MIN)
	  m_pDateMin = new COleDateTime(ast[0]);
	if (nFlags & GDTR_MAX)
	  m_pDateMax = new COleDateTime(ast[1]);
      }
      // if we're showing calendar control, apply to it now
      if (m_pCalWnd != NULL)
      {
	CMonthCalCtrl* pCal = m_pCalWnd->GetMonthCalCtrl();
	if (pCal != NULL)
	  pCal->SendMessage(DTM_SETRANGE, wParam, lParam);
      }
      return 0;
    }
    break;

  case DTM_GETRANGE:
    {
      int nFlags = 0;
      LPSYSTEMTIME ast = (LPSYSTEMTIME)lParam;
      if (ast != NULL)
      {
	if (m_pDateMin != NULL)
	{
	  m_pDateMin->GetAsSystemTime(ast[0]);
	  nFlags |= GDTR_MIN;
	}
	if (m_pDateMax != NULL)
	{
	  m_pDateMax->GetAsSystemTime(ast[1]);
	  nFlags |= GDTR_MAX;
	}
      }
      return nFlags;
    }
    break;

  case DTM_SETFORMAT:
    TRACE(_T("Got DTM: %s\n"), FormatDTM(message));
    ASSERT(FALSE);  // not supported
    AfxThrowNotSupportedException();
    break;

  }
  return CDateTimeCtrl::WindowProc(message, wParam, lParam);
}

void CDateTimeEditCtrl::PreSubclassWindow() 
{
  CDateTimeCtrl::PreSubclassWindow();

  // if we were created explicitly then everything is hunky-dory
  // else we need to destroy the datetimectrl and create our own stuff
  if (m_bInCreate)
    return;

  PostMessage(DTCEM_RECREATE);
}

LONG CDateTimeEditCtrl::OnRecreate(WPARAM wParam, LPARAM lParam)
{
  // we come in here if we've been subclassed, so we can destroy
  // the existing control, and create our own version
  CWnd* pParentWnd = GetParent();
  if (pParentWnd == NULL)
    pParentWnd = GetDesktopWindow();

  CWnd* pWndFocus = CWnd::GetFocus();
  BOOL bFocus = (pWndFocus == this);

  // get current attributes
  DWORD dwStyle = GetStyle();
  DWORD dwStyleEx = GetExStyle();
  CRect rc;
  GetWindowRect(&rc);
  pParentWnd->ScreenToClient(&rc);	// map to client co-ords
  UINT nID = GetDlgCtrlID();
  CFont* pFont = GetFont();
  CWnd* pWndAfter = GetNextWindow(GW_HWNDPREV);

  DestroyWindow();
  m_hWnd = NULL;

  m_bInCreate = TRUE;

  if (! CWnd::CreateEx(dwStyleEx, NULL, NULL, dwStyle, rc, pParentWnd, nID))
    return -1;
  // re-apply attributes
  if (pFont == NULL)
    pFont = pParentWnd->GetFont();
  SetFont(pFont);

  // re-set focus
  if (bFocus)
    SetFocus();

  // position correctly in z-order
  SetWindowPos(pWndAfter == NULL ? &CWnd::wndBottom : pWndAfter, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

  return 0;
}

// returns whether the date passed is valid
// if NULL is passed, then the date in the edit control is used
BOOL CDateTimeEditCtrl::IsValidDate(LPCTSTR lpszDate/*=NULL*/)
{
  CString sDate = lpszDate;
  if (sDate.IsEmpty())
    GetWindowText(sDate);
  COleDateTime date;
  return date.ParseDateTime(sDate);
}

// set whether the user can only enter chars that are valid
void CDateTimeEditCtrl::SetValidCharsOnly(BOOL bValidCharsOnly/*=TRUE*/)
{
  if (m_pEdit != NULL)
    m_pEdit->SetValidCharsOnly(bValidCharsOnly);
}

// returns whether the user can only enter valid chars into the edit control
BOOL CDateTimeEditCtrl::GetValidCharsOnly()
{
  if (m_pEdit != NULL)
    return m_pEdit->GetValidCharsOnly();
  return FALSE;
}

// sets the chars that are valid for the user to type into the edit control
// if NULL is specified, then the default chars are used (0-9 and current 
// user's locale's date separator). If the user changes the locale settings 
// then the control will automatically pick this up and use the new separator.
void CDateTimeEditCtrl::SetValidChars(LPCTSTR lpszValidChars/*=NULL*/)
{
  if (m_pEdit != NULL)
    m_pEdit->SetValidChars(lpszValidChars);
}

// returns the chars that are valid for the user to type into the edit control
CString CDateTimeEditCtrl::GetValidChars()
{
  if (m_pEdit != NULL)
    return m_pEdit->GetValidChars();
  return "";
}

void CDateTimeEditCtrl::SetAllowUpDownKeys(BOOL bAllow/*=TRUE*/)
{
  if (m_pEdit != NULL)
    m_pEdit->SetAllowUpDownKeys(bAllow);
}

BOOL CDateTimeEditCtrl::GetAllowUpDownKeys()
{
  if (m_pEdit != NULL)
    return m_pEdit->GetAllowUpDownKeys();
  return FALSE;
}

BOOL CDateTimeEditCtrl::SetButtonImageID(UINT nID)
{
  m_nBtnImageID = nID;

  if (m_pBtn != NULL && ::IsWindow(m_pBtn->m_hWnd))
  {
    if (nID == 0)
    {
      m_pBtn->ModifyStyle(BS_BITMAP | BS_CENTER, 0);
      HBITMAP hbmp = m_pBtn->SetBitmap(NULL);
      if (hbmp != NULL)
	DeleteObject(hbmp);
    }
    else
    {
      CBitmap bmp;
      if (! bmp.LoadBitmap(m_nBtnImageID))
	return FALSE;
      m_pBtn->ModifyStyle(0, BS_BITMAP | BS_CENTER);
      m_pBtn->SetBitmap((HBITMAP)bmp.GetSafeHandle());
      bmp.Detach();
    }
  }
  return TRUE;
}
