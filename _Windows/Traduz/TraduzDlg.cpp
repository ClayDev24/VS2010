// TraduzDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vbstring.h"
#include "afxinet.h" //Wininet classes
#include "Traduz.h"
#include "TraduzDlg.h"
#include "..\..\utils\Tokenizer\tokenizer.h"
#include <fstream>

using namespace std;
using namespace clb;

typedef vector<CString*> vetorStr;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT Threadproc(LPVOID param);

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
// CTraduzDlg dialog

CTraduzDlg::CTraduzDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTraduzDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTraduzDlg)
	m_in      = _T("");
	m_out     = _T("");
	m_path    = _T("");
	m_vigente = 0;
	m_status  = _T("");
	m_lingua  = _T("en_pt");
	legend_original = NULL;
	legend_altered  = NULL;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);	
}

void CTraduzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTraduzDlg)
	DDX_Control(pDX, IDC_OPEN, m_open);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_in);
	DDX_Text(pDX, IDC_EDIT2, m_out);
	DDX_Text(pDX, IDC_PATH, m_path);
	DDX_Text(pDX, IDC_CURRENT, m_vigente);
	DDV_MinMaxInt(pDX, m_vigente, 0, 5000);
	DDX_Text(pDX, IDC_STATUSBAR, m_status);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTraduzDlg, CDialog)
	//{{AFX_MSG_MAP(CTraduzDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PREVIOUS, OnPrevious)
	ON_BN_CLICKED(IDC_TRANSLATE, OnTranslate)
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_CBN_CLOSEUP(IDC_COMBO1, OnCloseupCombo1)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_EN_CHANGE(IDC_PATH, OnChangePath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraduzDlg message handlers

BOOL CTraduzDlg::OnInitDialog()
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

	m_combo.SetCurSel(0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTraduzDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTraduzDlg::OnPaint() 
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
HCURSOR CTraduzDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTraduzDlg::OnOpen() 
{
	CFileDialog dlg(TRUE, NULL, "*.sub", OFN_OVERWRITEPROMPT,
        "Arquivos legendas (*.sub)|*.sub|Arquivos legendas (*.srt)|*.srt||");
    if (dlg.DoModal())
    {
		m_path = dlg.GetPathName();
		UpdateData(FALSE);
		//AfxMessageBox(dlg.GetFileExt());
		//AfxMessageBox(dlg.GetFileTitle());
		//AfxMessageBox(dlg.GetPathName());		
	}	
	string alter;
	string path = m_path;

	if(m_path.Right(4) == ".srt") {
		alter = m_path.Left(m_path.GetLength() - 4) + "Copia.srt";
		legend_original = new CLegendSrt(path);
		legend_altered  = new CLegendSrt(alter);
	} else if(m_path.Right(4) == ".sub") {
		alter = m_path.Left(m_path.GetLength() - 4) + "Copia.sub";
		legend_original = new CLegendSub(path);
		legend_altered  = new CLegendSub(alter);
	}

	try  {
		legend_original->open();
	} catch(char* c) {
		AfxMessageBox(c + m_path);
		return;
	}

	try {
		legend_altered->open();
		int tam1 = legend_original->get_size();
		int tam2 = legend_altered->get_size();
		if(tam1 != tam2)
			legend_altered->complete_vetor(tam1 - tam2);

		tam1 = legend_original->get_size();
		tam2 = legend_altered->get_size();
		if(tam1 != tam2)
			AfxMessageBox("Numero de legendas originais difere do numero de legendas traduzidas.");

	} catch(char* c)
	{
		TRACE(c);
		legend_altered->nova(legend_original->get_size());
	}	
	//Case exists:
	m_in = legend_original->get_line(0);
	m_vigente = 0;
	update(0, m_in);

	//HWND hWnd = GetSafeHwnD();	
	AfxBeginThread(Threadproc, this);
}

UINT Threadproc(LPVOID param)
{
	CTraduzDlg *dlg = (CTraduzDlg*)param;
	vetorStr *vt_orig  = dlg->legend_original->get_vetor();
	vetorStr *vt_alter = dlg->legend_altered->get_vetor();

	vetorStr *vt_origTm = dlg->legend_original->get_vetorTm();
	vetorStr *vt_alterTm = dlg->legend_altered->get_vetorTm();

	for(int i = 1; i < (vt_orig->size() - 1); i++) {
		CString *c3 = (CString*)vt_alter->at(i);
		if(*c3 != "NULL\n")
			continue;
		CString *c = (CString*)vt_orig->at(i);
		CString c2 = dlg->translate(*c);
		*c3 = c2;

		c  = (CString*)vt_origTm->at(i);
		c3 = (CString*)vt_alterTm->at(i);
		*c3 = *c;
	}
	dlg->legend_altered->save();
	AfxEndThread(0, true); // terminates the thread.
	return 0;
}

void CTraduzDlg::OnTranslate() 
{
	UpdateData(TRUE);

	m_out = translate(m_out + "\n");
	UpdateData(FALSE);

	int cur = legend_original->get_current();
	legend_altered->set_line(m_out, cur);

	CString tm = legend_original->get_time(cur);
	legend_altered->set_time(tm, cur);
}

CString CTraduzDlg::translate(CString fala)
{
    CString http = "http://babelfish.altavista.com/babelfish/tr?lp=" + m_lingua + "&urltext=";

	fala = " " + fala;

	if(fala.Find('|') != -1)
		fala.Replace("|", " | ");
	if(fala.Find("can't") != -1) 
		fala.Replace("can't", "cannot");
	if(fala.Find("Can't") != -1) 
		fala.Replace("Can't", "Cannot");
	if(fala.Find("Can") != -1) 
		fala.Replace("Can't", "Cannot");
	if(fala.Find("I'm") != -1) 
		fala.Replace("I'm", "I am");
	if(fala.Find("'re") != -1) 
		fala.Replace("'re", " are");	
	if(fala.Find("n't") != -1) 
		fala.Replace("n't", " not");	
	if(fala.Find("'ve") != -1) 
		fala.Replace("'ve", " have");	
	if(fala.Find("'ll") != -1) 
		fala.Replace("'ll", " will");	
	if(fala.Find("'d") != -1) 
		fala.Replace("'d", " would");	
	if(fala.Find("today's") != -1) 
		fala.Replace("today's", "todays");
	if(fala.Find("Today's") != -1) 
		fala.Replace("Today's", "Todays");
	if(fala.Find("he's") != -1) 
		fala.Replace("he's", "he is");
	if(fala.Find("He's") != -1) 
		fala.Replace("He's", "He is");
	if(fala.Find("it's") != -1) 
		fala.Replace("it's", "it is");
	if(fala.Find("Let's") != -1) 
		fala.Replace("Let's", "Let us");
	if(fala.Find("let's") != -1) 
		fala.Replace("let's", "let us");
	if(fala.Find("That's") != -1) 
		fala.Replace("That's", "That is");
	if(fala.Find("that's") != -1) 
		fala.Replace("that's", "that is");
	if(fala.Find("There's") != -1) 
		fala.Replace("There's", "There is");
	if(fala.Find("there's") != -1) 
		fala.Replace("there's", "there is");
	if(fala.Find("What's") != -1) 
		fala.Replace("What's", "What is");
	if(fala.Find("what's") != -1) 
		fala.Replace("what's", "what is");
	if(fala.Find("...") != -1) 
		fala.Replace("...", " ... ");
	if(fala.Find("/") != -1) 
		fala.Replace("/", " / ");
	if(fala.Find("\"") != -1) 
		fala.Replace("\"", " ");
	if(fala.Find("'") != -1) 
		fala.Replace("'", " ");

	VBString f = fala;
	CString result = "";

	//Dividir por linhas: \n
	char tok = '\n';
	int n_tok = f.tokCount(tok);

	string c = "|" + (char)13;
	string fala3 = fala;
	CTokenizer *token = new CTokenizer(fala3, c);//"aeiou ");
	n_tok = token->get_size();

	string s = "";	
	for(int i = 0; i <= (n_tok - 1); i++) {
		//s = f.strtok(tok, i);
		s = token->get_at(i);
	
	//Add '+' to string:
	 char tok2 = ' ';
	 int n_tok2 = f.tokCount(tok2);
	 CString s3 = "";	
	for(int i2 = 0; i2 <= n_tok2; i2++)
		s3 += s.strtok(tok2, i2) + "+";	
	//-->
	CString URL = http + s3;
		URL = URL.Left(URL.GetLength());
	//char ch[20];
	//m_status = "Downloading... " + (CString)itoa(contador++, ch, 10);// + URL;			
    CInternetSession session;
	CInternetFile* file = NULL;    
	try
    {    //We know for sure this is an Internet file, so the cast is safe				         
         file = (CInternetFile*) session.OpenURL(URL);
    }
    catch (CInternetException* pEx)
    {    //if anything went wrong, just set file to NULL
         file = NULL;
         pEx->Delete();
    }	
    if (file)
    {    //m_status += "Connection established.";			  		          
         CString line;		  		  
         for (int i3 = 0; i3 < 500 && file->ReadString(line); i3++) {
			 VBString s2 = line;
			 if(line.Find("padding:10px;>") != -1)
			 {
				 s2 = s2.afterFind("10px;>");
				 s2 = s2.beforeFind("</div>");
				 result += s2 + "\n";
				 break;
			 }
         }
         file->Close();
         delete file;
	} else
		return "NULL\n"; // "Falha na conexao.");

	} // for
	return result;
}

void CTraduzDlg::OnNext() 
{
	m_in = legend_original->get_next();
	update(legend_original->get_current(), m_in);
}

void CTraduzDlg::OnPrevious() 
{	
	m_in = legend_original->get_previous();
	update(legend_original->get_current(), m_in);
}

void CTraduzDlg::OnFirst() 
{	
	m_in = legend_original->go(0);
	update(0, m_in);
}

void CTraduzDlg::OnLast() 
{
	int last = (legend_original->get_size() - 1);
	m_in = legend_original->go(last);
	update(last, m_in);
}

void CTraduzDlg::OnGo() 
{
	UpdateData(TRUE);
	m_in = legend_original->go(m_vigente);
	update(m_vigente, m_in);
}

void CTraduzDlg::update(int cur, CString orig)
{
	if((CString)legend_altered->get_line(cur) == "NULL\n") {
		m_out = translate(orig);

	    legend_altered->set_line(m_out, cur);
	    CString tm = legend_original->get_time(cur);
	    legend_altered->set_time(tm, cur);
	} else 
		m_out = legend_altered->get_line(cur);

	m_vigente = legend_original->get_current();
	UpdateData(FALSE);
}

void CTraduzDlg::OnSave() 
{
	legend_altered->save();
}

void CTraduzDlg::OnChangePath() 
{
	UpdateData(TRUE);
}

BEGIN_EVENTSINK_MAP(CTraduzDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CTraduzDlg)
	ON_EVENT(CTraduzDlg, IDC_EDIT2, 1 /* Change */, OnChangeEdit2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CTraduzDlg::OnChangeEdit2() 
{
	if(legend_altered == NULL) return;
	UpdateData(TRUE);
	CString s = m_out + "\n";
	
	int cur = legend_original->get_current();
	legend_altered->set_line(s, cur);
	s = legend_original->get_time(cur);
	legend_altered->set_time(s, cur);
}

void CTraduzDlg::OnCloseupCombo1() 
{
	CString szStr;
	int nSel;
	nSel = m_combo.GetCurSel();
	if(nSel != CB_ERR)
	{
		m_combo.GetLBText(nSel, szStr);
	}

	if(szStr == "Inglês para português")
		m_lingua = "en_pt";
	else if(szStr == "Inglês para chinês simplificado")
		m_lingua = "en_zh";
	else if(szStr == "Inglês para chinês tradicional")
		m_lingua = "en_zt";
	else if(szStr == "Inglês para holandês")
		m_lingua = "en_nl";
	else if(szStr == "Inglês para francês")
		m_lingua = "en_fr";
	else if(szStr == "Inglês para alemão")
		m_lingua = "en_de";
	else if(szStr == "Inglês para grego")
		m_lingua = "en_el";
	else if(szStr == "Inglês para italiano")
		m_lingua = "en_it";
	else if(szStr == "Inglês para japonês")
		m_lingua = "en_ja";
	else if(szStr == "Inglês para coreano")
		m_lingua = "en_ko";
	else if(szStr == "Inglês para russo")
		m_lingua = "en_ru";
	else if(szStr == "Inglês para espanhol")
		m_lingua = "en_es";
	else if(szStr == "Holandês para inglês")
		m_lingua = "nl_en";
	else if(szStr == "Holandês para francês")
		m_lingua = "nl_fr";
	else if(szStr == "Francês para holandês")
		m_lingua = "fr_nl";
	else if(szStr == "Francês para inglês")
		m_lingua = "fr_en";
	else if(szStr == "Francês para alemão")
		m_lingua = "fr_de";
	else if(szStr == "Francês para grego")
		m_lingua = "fr_el";
	else if(szStr == "Francês para italiano")
		m_lingua = "fr_it";
	else if(szStr == "Francês para português")
		m_lingua = "fr_pt";
	else if(szStr == "Francês para espanhol")
		m_lingua = "fr_es";
	else if(szStr == "Alemão para inglês")
		m_lingua = "de_en";
	else if(szStr == "Alemão para francês")
		m_lingua = "de_fr";
	else if(szStr == "Grego para inglês")
		m_lingua = "el_en";
	else if(szStr == "Grego para francês")
		m_lingua = "el_fr";
	else if(szStr == "Italiano para inglês")
		m_lingua = "it_en";
	else if(szStr == "Italiano para francês")
		m_lingua = "it_fr";
	else if(szStr == "Japonês para inglês")
		m_lingua = "ja_en";
	else if(szStr == "Coreano para inglês")
		m_lingua = "ko_en";
	else if(szStr == "Português para inglês")
		m_lingua = "pt_en";
	else if(szStr == "Português para francês")
		m_lingua = "pt_fr";
	else if(szStr == "Russo para inglês")
		m_lingua = "ru_en";
	else if(szStr == "Espanhol para inglês")
		m_lingua = "es_en";
	else if(szStr == "Espanhol para francês")
		m_lingua = "es_fr";
}
