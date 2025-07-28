// DateTimeEditCtrlDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DateTimeEditCtrlDemo.h"
#include "DateTimeEditCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlDemoDlg dialog

CDateTimeEditCtrlDemoDlg::CDateTimeEditCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateTimeEditCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDateTimeEditCtrlDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDateTimeEditCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDateTimeEditCtrlDemoDlg)
	DDX_Control(pDX, IDC_BTN_SPECIFIED, m_btnSpecified);
	DDX_Control(pDX, IDC_BTN_DEFAULT, m_btnDefault);
	DDX_Control(pDX, IDC_BTN_VALID_CHARS_ONLY, m_btnValidCharsOnly);
	DDX_Control(pDX, IDC_EDIT_VALID_CHARS, m_editValidChars);
	DDX_Control(pDX, IDC_LABEL_VALIDITY_RESULTS, m_labelResults);
	DDX_Control(pDX, IDC_LIST_NOTIFY, m_listNotify);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDateTimeEditCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDateTimeEditCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(DTN_FORMAT, IDC_DATETIMEPICKER1, OnFormatDatetimepicker1)
	ON_NOTIFY(DTN_FORMATQUERY, IDC_DATETIMEPICKER1, OnFormatqueryDatetimepicker1)
	ON_NOTIFY(DTN_WMKEYDOWN, IDC_DATETIMEPICKER1, OnWmkeydownDatetimepicker1)
	ON_NOTIFY(DTN_USERSTRING, IDC_DATETIMEPICKER1, OnUserstringDatetimepicker1)
	ON_NOTIFY(DTN_CLOSEUP, IDC_DATETIMEPICKER1, OnCloseupDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DROPDOWN, IDC_DATETIMEPICKER1, OnDropdownDatetimepicker1)
	ON_BN_CLICKED(IDC_BTN_CLEAR_LIST, OnBtnClearList)
	ON_BN_CLICKED(IDC_BTN_VALID_CHARS_ONLY, OnBtnValidCharsOnly)
	ON_EN_CHANGE(IDC_EDIT_VALID_CHARS, OnChangeEditValidChars)
	ON_BN_CLICKED(IDC_BTN_DEFAULT, OnBtnDefault)
	ON_BN_CLICKED(IDC_BTN_SPECIFIED, OnBtnSpecified)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_DATETIMEPICKER1, OnChangeDatetimepicker1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeEditCtrlDemoDlg message handlers

BOOL CDateTimeEditCtrlDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
#ifdef USE_DATETIMEEDITCTRL
	m_date.SetButtonImageID(IDB_CALENDAR);
#endif

#if 0 // use this block to limit the dates entered
	// limit the control to 3 months (90 days) either side of now
	COleDateTimeSpan span(90, 0, 0, 0);
	COleDateTime dateMin(COleDateTime::GetCurrentTime());
	COleDateTime dateMax(dateMin);
	dateMin -= span;
	dateMax += span;
	m_date.SetRange(&dateMin, &dateMax);
#endif

	m_editValidChars.SetWindowText(_T("0123456789/-."));
	m_btnValidCharsOnly.SetCheck(TRUE);
	OnBtnValidCharsOnly();
	m_btnDefault.SetCheck(TRUE);
	OnBtnDefault();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDateTimeEditCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDateTimeEditCtrlDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDateTimeEditCtrlDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDateTimeEditCtrlDemoDlg::OnFormatDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_FORMAT"));
  LPNMDATETIMEFORMAT lpnmdtf = (LPNMDATETIMEFORMAT)pNMHDR;
  COleDateTime date(lpnmdtf->st);
  CString sDate;
  if (date.GetStatus() == COleDateTime::valid)
    sDate = date.Format(VAR_DATEVALUEONLY);
  else
    sDate = "None";
  TRACE(_T("Setting date as %s\n"), sDate);
  lstrcpy(lpnmdtf->szDisplay, sDate);
}

void CDateTimeEditCtrlDemoDlg::OnFormatqueryDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_FORMATQUERY"));
  LPNMDATETIMEFORMATQUERY lpnmdtfq = (LPNMDATETIMEFORMATQUERY)pNMHDR;

  CDC* pDC = GetDC();
  CFont* pFont = GetFont();
  if (! pFont)
    pFont->CreateStockObject(DEFAULT_GUI_FONT);
  CFont* pOrigFont = pDC->SelectObject(pFont);

  // Check to see if this is the callback segment desired. If so,
  // use the longest text segment to determine the maximum 
  // width of the callback field, and then place the information into 
  // the NMDATETIMEFORMATQUERY structure.
  ::GetTextExtentPoint32 (pDC->m_hDC, _T("MM:MM:MM"), 10, &lpnmdtfq->szMax);

//  lpnmdtfq->szMax.cx = 20;
  //lpnmdtfq->szMax.cy = 0;

  // Reset the font in the device context then release the context.
  pDC->SelectObject(pOrigFont);
  ReleaseDC(pDC);
}

void CDateTimeEditCtrlDemoDlg::OnWmkeydownDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_WMKEYDOWN"));
}

void CDateTimeEditCtrlDemoDlg::OnUserstringDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_USERSTRING"));
}

void CDateTimeEditCtrlDemoDlg::OnCloseupDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_CLOSEUP"));
}

void CDateTimeEditCtrlDemoDlg::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_DATETIMECHANGE"));
#ifdef USE_DATETIMEEDITCTRL
  if (m_date.IsValidDate())
    m_labelResults.SetWindowText(_T("The current text is a valid date string"));
  else
    m_labelResults.SetWindowText(_T("The current text is not a valid date string"));
#endif
}

void CDateTimeEditCtrlDemoDlg::OnDropdownDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
  *pResult = 0;
  m_listNotify.AddString(_T("DTN_DROPDOWN"));
}

void CDateTimeEditCtrlDemoDlg::OnBtnClearList() 
{
  m_listNotify.ResetContent();
}

void CDateTimeEditCtrlDemoDlg::OnChangeDatetimepicker1() 
{
#ifdef USE_DATETIMEEDITCTRL
//  if (m_date.IsValidDate())
//    m_labelResults.SetWindowText(_T("The current text is a valid date string"));
//  else
//    m_labelResults.SetWindowText(_T("The current text is not a valid date string"));
#endif
}

void CDateTimeEditCtrlDemoDlg::OnBtnValidCharsOnly() 
{
#ifdef USE_DATETIMEEDITCTRL
  m_date.SetValidCharsOnly(m_btnValidCharsOnly.GetCheck());
#endif
}

void CDateTimeEditCtrlDemoDlg::OnChangeEditValidChars() 
{
#ifdef USE_DATETIMEEDITCTRL
  CString sChars;
  m_editValidChars.GetWindowText(sChars);
  m_date.SetValidChars(sChars);
#endif
}

void CDateTimeEditCtrlDemoDlg::OnBtnDefault() 
{
#ifdef USE_DATETIMEEDITCTRL
  m_date.SetValidChars(NULL);
#endif
}

void CDateTimeEditCtrlDemoDlg::OnBtnSpecified() 
{
#ifdef USE_DATETIMEEDITCTRL
  CString sChars;
  m_editValidChars.GetWindowText(sChars);
  m_date.SetValidChars(sChars);
#endif
}
