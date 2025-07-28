// ClayStat2View.cpp : implementation of the ClayStat2View class
//

#include "stdafx.h"
#include "ClayStat2.h"
#include "MainFrm.h"
#include "Statistics.h"
#include "DialogSearch.h"
#include "ClayStat2Doc.h"
#include "DateDlg.h"
#include "ConfSheet.h"
#include "Title.h"
#include "Article.h"
#include "nntp.h"
#include "socket.h"
#include "ClayStat2View.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ClayStat2View

IMPLEMENT_DYNCREATE(ClayStat2View, CScrollView)

BEGIN_MESSAGE_MAP(ClayStat2View, CScrollView)
	//{{AFX_MSG_MAP(ClayStat2View)
	ON_COMMAND(ID_SHOWHEADERS_BY_NAME, OnExibirNome)
	ON_COMMAND(ID_STATISTICS_START, OnEstatGerar)
	ON_COMMAND(ID_SHOWHEADERS_BY_QUANTITY, OnExibirPorQuantidade)
	ON_COMMAND(ID_VIEW_MOSTRAR, OnViewMostrar)
	ON_COMMAND(ID_VIEW_OCULTAR, OnViewOcultar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOSTRAR, OnUpdateViewMostrar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OCULTAR, OnUpdateViewOcultar)
	ON_COMMAND(ID_GROUP_ESPECIFIC, OnGrupoEspecifico)
	ON_UPDATE_COMMAND_UI(ID_GROUP_ESPECIFIC, OnUpdateGrupoEspecifico)
	ON_COMMAND(ID_GROUP_GENERAL, OnGrupoGeral)
	ON_UPDATE_COMMAND_UI(ID_GROUP_GENERAL, OnUpdateGrupoGeral)
	ON_COMMAND(ID_MODE_NICK, OnModoPseudo)
	ON_COMMAND(ID_MODE_NICK_E_EMAIL, OnModoPseudoEEmail)
	ON_COMMAND(ID_MODE_NICK_E_IP, OnModoPseudoEIp)
	ON_UPDATE_COMMAND_UI(ID_MODE_NICK, OnUpdateModoPseudo)
	ON_UPDATE_COMMAND_UI(ID_MODE_NICK_E_EMAIL, OnUpdateModoPseudoEEmail)
	ON_UPDATE_COMMAND_UI(ID_MODE_NICK_E_IP, OnUpdateModoPseudoEIp)
	ON_COMMAND(ID_STATISTICS_ADVANCEDRESEARCH, OnEstatPesquisa)
	ON_COMMAND(ID_TOOLS_SETUP, OnFerramentasConfiguracoes)
	ON_COMMAND(ID_VIEW_CLEAR_SCREEN, OnViewClearScreen)
	ON_COMMAND(ID_TOOLS_LANGUAGE_PORTUGUESE, OnToolsLanguagePortuguese)
	ON_COMMAND(ID_TOOLS_LANGUAGE_ENGLISH, OnToolsLanguageEnglish)
	ON_COMMAND(ID_STATISTICS_DOWNLOAD, OnStatisticsDownload)
	ON_COMMAND(ID_PERIOD_DAYLY, OnPeriodDayly)
	ON_UPDATE_COMMAND_UI(ID_PERIOD_DAYLY, OnUpdatePeriodDayly)
	ON_COMMAND(ID_PERIOD_BY_PERIOD, OnPeriodByPeriod)
	ON_UPDATE_COMMAND_UI(ID_PERIOD_BY_PERIOD, OnUpdatePeriodByPeriod)
	ON_COMMAND(ID_SEND_SELECTED, OnSendSelected)
	ON_UPDATE_COMMAND_UI(ID_STATISTICS_DOWNLOAD, OnUpdateStatisticsDownload)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_HEADER_NICK_E_EMAIL_E_GROUP, ID_HEADER_IP, OnButtonCabecalho)
	ON_UPDATE_COMMAND_UI_RANGE(ID_HEADER_NICK_E_EMAIL_E_GROUP, ID_HEADER_IP, OnUpdateButtonCabecalho)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_CALENDAR, OnDatetimechangeDate)
	ON_CBN_CLOSEUP(IDC_COMBO, OnCloseupCombo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ClayStat2View construction/destruction

ClayStat2View::ClayStat2View()
{
	m_setup = new CConfSheet("Configurações", this, 0);
	m_downloadComplete = true;
	m_preenchido       = false;
	m_down_date = _T("");
}

ClayStat2View::~ClayStat2View() {
	delete m_setup;
}

BOOL ClayStat2View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}
/////////////////////////////////////////////////////////////////////////////
// ClayStat2View drawing
void ClayStat2View::OnDraw(CDC* pDC)
{
	pDoc = GetDocument();
	ASSERT_VALID(pDoc);
// get the number of lines from the document
	pDoc->m_numLines = 0;
// Initialize a LOGFONT structure for the fonts.
     LOGFONT logFont;
    logFont.lfHeight = 24;
    logFont.lfWidth = 0;
    logFont.lfEscapement = 0;
    logFont.lfOrientation = 0;
    logFont.lfWeight = FW_NORMAL;
    logFont.lfItalic = 0;
    logFont.lfUnderline = 0;
    logFont.lfStrikeOut = 0;
    logFont.lfCharSet = ANSI_CHARSET;
    logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    logFont.lfQuality = PROOF_QUALITY;
    logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
     strcpy(logFont.lfFaceName, "Times New Roman");
     // Create a new font and select it into the DC.
    CFont* font = new CFont();
     font->CreateFontIndirect(&logFont);
     CFont* oldFont = pDC->SelectObject(font);
	 delete font;

	CString str = pDoc->saida();
	CTokenizer tokens((string)str, "\n");

	int n_tok = tokens.get_size();
	UINT position = 0;
	for(int i = 1; i <= n_tok; i++) {
		pDoc->m_numLines++;
		CString ch = tokens.get_at(i).c_str();
		pDC->TextOut(10, position, ch);	
		position += logFont.lfHeight;
	}
	// Calculate the document size.
	CSize docSize(100, pDoc->m_numLines * logFont.lfHeight);
	// Calculate the page size.
	CRect rect;
	GetClientRect(&rect);
	CSize pageSize(rect.right, rect.bottom);
	// Calculate the line size.
	CSize lineSize(100, logFont.lfHeight);
	// Adjust the scrollers.	
	SetScrollSizes(MM_TEXT, docSize, pageSize, lineSize);		
}

/////////////////////////////////////////////////////////////////////////////
// ClayStat2View diagnostics

#ifdef _DEBUG
void ClayStat2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void ClayStat2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

ClayStat2Doc* ClayStat2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClayStat2Doc)));
	return (ClayStat2Doc*)m_pDocument;
}

#endif //_DEBUG

void ClayStat2View::OnInitialUpdate()
{
	pDoc = GetDocument();
	pDoc->m_saida = _T("");

	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// ClayStat2View message handlers

void ClayStat2View::OnExibirNome() 
{
	BeginWaitCursor();
	pDoc->m_saida = pDoc->m_estat->show(pDoc->m_uCurrentBtnHdr, "name");
	pDoc->m_saida += "\n";
	Invalidate();
	EndWaitCursor();
}

void ClayStat2View::OnExibirPorQuantidade() 
{
	BeginWaitCursor();
	pDoc->m_saida = pDoc->m_estat->show(pDoc->m_uCurrentBtnHdr, "quantity");
	pDoc->m_saida += "\n";
	Invalidate();
	EndWaitCursor();
}

void ClayStat2View::OnEstatGerar() 
{
	BeginWaitCursor();
	
	CString file_name;
	CString period = m_date.Format("%d/%m");
	pDoc->m_estat->m_period = period;

	if(m_down_date == m_date.Format("%y%m%d") && !m_downloadComplete) {
		AfxMessageBox("Download em andamento.\nEscolha outra data.\n");
		return;
	}
	if(pDoc->m_estat->m_dayly) {
		file_name = m_date.Format("Message%d%b.txt");	
	} else {
		try {
			if(!m_preenchido)
			    make_tempFile();
		} catch(NoFile nf) {
			pDoc->m_saida = nf.get_message();
			Invalidate();
			AfxMessageBox(nf.get_message());
			return;
		}
		file_name = m_date.Format(".\\tempSemanal.txt");
	}
	if(!m_preenchido) {
		try {
			pDoc->m_estat->readFile(file_name);
		} catch(NoFile nf) {
			AfxMessageBox(nf.get_message());
			return;
		}
		m_preenchido = true;
	} else {
		pDoc->m_estat->bar = new CProgressBar();
		pDoc->m_estat->bar->Create(_T("Processando"), 80, 180);
		pDoc->m_estat->bar->SetStep(10);
		pDoc->m_estat->bar->StepIt();
		pDoc->m_estat->define_partial();
		pDoc->m_estat->bar->Clear();
		delete pDoc->m_estat->bar;
	}

	if(pDoc->m_estat->is_empty()) { 
		pDoc->m_saida = "Nenhuma msg para o grupo na data...\n";
		Invalidate();
		return;
	}

	pDoc->m_saida = pDoc->m_estat->modelo1(5);
	Invalidate();
	EndWaitCursor();
}

void ClayStat2View::make_tempFile() 
{
	CString status = "";
	CString tmp;

	CTime hoje = m_date;
	CString s_vigente = hoje.Format("%y%m%d");

	CString salva  = "tempSemanal.txt";
	ofstream outFile;
	outFile.open(salva, ios::out);// | ios::app); //append
	if(!outFile) {
		AfxMessageBox("Arquivo nao pode ser salvo");
		return;
	}

	CString dia;	
	CTime t1( 1999, 3, 19, 22, 15, 0 ); // 10:15 PM March 19, 1999
	CTime t2( 1999, 3, 20, 22, 15, 0 ); // 10:15 PM March 20, 1999
	CTimeSpan ts = t2 - t1;             // Subtract 2 CTimes

	status += "Verificando a existencia dos arquivos...\n";
	TRACE(status);

	CTime ontem = hoje;
	ontem -= ts;
	CString period = ontem.Format(" a %d/%m");

	for(int i = 0; i < m_setup->m_page1.m_period; i++) {
		dia = "Message" + ontem.Format("%d%b") + ".txt";		

		FILE *fp;
		if((fp = fopen(dia, "r")) == NULL) {
			tmp = "\narquivo requerido: " + dia + (CString)" faltando...\nFavor executar o download.\n";
			TRACE(tmp);
			status += tmp;
			outFile.close();
			throw NoFile(status);
		}
		tmp = "arquivo: " + dia + " OK!\n";
		TRACE(tmp);
		status += tmp;
		pDoc->m_saida = status;
		Invalidate();

		char ch;
		while(true) {
			CString line;
			while(((ch = getc(fp)) != '\n') && ch != EOF)
				line += ch;
			if(ch == EOF)
				break;
			outFile.write(line, line.GetLength());
			outFile.write("\n", 1);
		}
		ontem -= ts;
		fclose(fp);
	}//for
	ontem += ts;
	period = ontem.Format("%d/%m") + period;
	TRACE(period + "\n");
	pDoc->m_estat->m_period = period;

	outFile.close();
	TRACE("ta quase...");
}

void ClayStat2View::OnEstatPesquisa() 
{
	CDialogSearch dialog(this);
    int result = dialog.DoModal();
	CString campo;
	int     radio;
    if(result == IDOK)
    {
		campo = dialog.m_campo;
		radio = dialog.m_radio;
	}
	if(radio == 0) {
		campo = pDoc->m_estat->advanced_search(campo, ID_HEADER_NICKNAME);
		pDoc->m_saida = campo;
	} else if(radio == 1) {
		campo = pDoc->m_estat->advanced_search(campo, ID_HEADER_SUBJECT);
		pDoc->m_saida = campo;
	} else if(radio == 2) {
		campo = pDoc->m_estat->advanced_search(campo, ID_HEADER_GROUPS);
		pDoc->m_saida = campo;
	} else if(radio == 3) {
		campo = pDoc->m_estat->advanced_search(campo, ID_HEADER_IP);
		pDoc->m_saida = campo;
	}
	Invalidate();
}

void ClayStat2View::OnDatetimechangeDate(NMHDR* pNMHDR, LRESULT* pResult) 
{
	MainFrame* pMain = (MainFrame*) ::AfxGetMainWnd();
	//pMain->m_wndDialogBar.m_date.GetTime(pDoc->m_estat->m_date);
	pMain->m_wndDialogBar.m_date.GetTime(m_date);
	m_preenchido = false;
	*pResult = 0;
}

void ClayStat2View::OnFerramentasConfiguracoes() 
{
    int result = m_setup->DoModal();
    if(result == IDOK) {}     
}

void ClayStat2View::OnViewClearScreen() 
{
	pDoc->m_saida = "\n";	
	Invalidate();
}

void ClayStat2View::OnToolsLanguagePortuguese() 
{
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAMEPORT);
	AfxGetMainWnd()->SetMenu(&menu);
	AfxGetMainWnd()->DrawMenuBar();
	menu.Detach();
}

void ClayStat2View::OnToolsLanguageEnglish() 
{
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	AfxGetMainWnd()->SetMenu(&menu);
	AfxGetMainWnd()->DrawMenuBar();
	menu.Detach();
}

UINT Threadproc(LPVOID param);

void ClayStat2View::OnStatisticsDownload() 
{
	MainFrame *pMain = (MainFrame*) ::AfxGetMainWnd();
	
	pMain->m_wndStatusBar.SetPaneText(4, "downloading...");

	m_downloadComplete = false;

	AfxBeginThread(Threadproc, pMain);
}

UINT Threadproc(LPVOID param)
{
	MainFrame *pMain = (MainFrame*)param;
	ClayStat2View *pView = (ClayStat2View*)pMain->GetActiveView();
	ClayStat2Doc *pDoc = (ClayStat2Doc*)pView->GetDocument();
	
	pView->m_downloadComplete = false;
	//CMenu *menu = pMain->GetMenu();
	//CMenu *submenu = menu->GetSubMenu(5);
	//submenu->EnableMenuItem(0, MF_BYPOSITION|MF_DISABLED|MF_GRAYED);
	CTime t1( 1999, 3, 19, 22, 15, 0 ); // 10:15 PM March 19, 1999
	CTime t2( 1999, 3, 20, 22, 15, 0 ); // 10:15 PM March 20, 1999
	CTimeSpan ts = t2 - t1;             // Subtract 2 CTimes
	//ATLASSERT( ts.GetTotalSeconds() == 86400L );
	CTime   t_vigente = pView->m_date;//pDoc->m_estat->m_date;	
	CString s_vigente = t_vigente.Format("%y%m%d");	
	pView->m_down_date = s_vigente;

    CTime   t_posterior = t_vigente + ts;
	CString s_posterior = t_posterior.Format("%y%m%d");

	CString s_date_file = t_vigente.Format("%d%b");

	try {
		CNNTP nntp(s_vigente, s_posterior, s_date_file, pView->m_setup->m_page1.m_pack, "news.abusar.org", pMain);
	} catch(char *err) {
		TRACE(err);
	}
	pView->m_downloadComplete = true;

	AfxEndThread(0, true);//terminates the thread.	

	//pMain->m_wndStatusBar.SetPaneText(4, "done!");
	//pMain->m_wndStatusBar.SetWindowText("Maria");
	return 0;
}

void ClayStat2View::OnCloseupCombo() 
{
	MainFrame *pMain = (MainFrame*) ::AfxGetMainWnd();

	CString szStr;
	int nSel;
	nSel = pMain->m_wndDialogBar.m_combo.GetCurSel();
	if(nSel != CB_ERR)
	{
		pMain->m_wndDialogBar.m_combo.GetLBText(nSel, szStr);
	}
	pDoc->m_estat->m_selected_ng = szStr;
}

void ClayStat2View::OnSendSelected() 
{
	CTitle dialog(this);
    int result = dialog.DoModal();
    if(result == IDOK)    
		pDoc->m_estat->m_subject = dialog.m_title;
	else if(result == IDCANCEL)
		return;
	
	CTime   now     = CTime::GetCurrentTime(); 
	CString date    = now.Format("%a, %d %b %Y %X +0000 (UTC)");
	CString subject = pDoc->m_estat->m_subject;
	subject = subject.Left(subject.GetLength() - 1);
	CString newsgroup = pDoc->m_estat->m_selected_ng;
	CString from = "\"" + m_setup->m_page2.m_nick + "\" <" + m_setup->m_page2.m_email + ">";
	
	int heads[5] =
	{
		ID_HEADER_NICKNAME, ID_HEADER_GROUPS, ID_HEADER_SUBJECT, ID_HEADER_HOUR, ID_HEADER_NEWSREADER
	};
	CString heads2[5] =
	{
		from,               newsgroup,        subject,           date,           "ClayStat v0.0"
	};

	vtPair *hd = new vtPair();
	for(int i = 0; i < 5; i++) {
		CPair *pair = new CPair(heads[i], new CString(heads2[i]));
		hd->push_back(pair);
	}
	//return;
	CString body = pDoc->m_saida;
	CArticle *message = NULL;//new CArticle(hd, false, body);
	CSocketClient nntp("news.abusar.org", 119);
	nntp.ReceiveLine();
	try {
		nntp.sendMessage(*message);
	} catch(string err) {
		TRACE(err.c_str());
	}
	//delete message;	
}

void ClayStat2View::OnViewMostrar() 
{
	pDoc->m_uCurrentBtnView = ID_VIEW_MOSTRAR;
	pDoc->m_estat->m_view = true;	
}

void ClayStat2View::OnViewOcultar() 
{
	pDoc->m_uCurrentBtnView = ID_VIEW_OCULTAR;
	pDoc->m_estat->m_view = false;	
}
void ClayStat2View::OnUpdateViewMostrar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnView);	
}
void ClayStat2View::OnUpdateViewOcultar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnView);	
}

void ClayStat2View::OnGrupoEspecifico() 
{
	pDoc->m_uCurrentBtnGrp = ID_GROUP_ESPECIFIC;
	pDoc->m_estat->m_selection = true;
}

void ClayStat2View::OnGrupoGeral() 
{
	pDoc->m_uCurrentBtnGrp = ID_GROUP_GENERAL;
	pDoc->m_estat->m_selection = false;
}
void ClayStat2View::OnUpdateGrupoEspecifico(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnGrp);
}
void ClayStat2View::OnUpdateGrupoGeral(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnGrp);		
}

void ClayStat2View::OnModoPseudo() 
{
	pDoc->m_uCurrentBtnMod = ID_MODE_NICK;
	pDoc->m_estat->m_mode = ID_HEADER_NICKNAME;
}
void ClayStat2View::OnModoPseudoEEmail() 
{
	pDoc->m_uCurrentBtnMod = ID_MODE_NICK_E_EMAIL;
	pDoc->m_estat->m_mode = ID_HEADER_NICK_E_EMAIL;
}
void ClayStat2View::OnModoPseudoEIp() 
{
	pDoc->m_uCurrentBtnMod = ID_MODE_NICK_E_IP;
	pDoc->m_estat->m_mode = ID_HEADER_NICK_E_IP;
}
void ClayStat2View::OnUpdateModoPseudo(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnMod);		
}
void ClayStat2View::OnUpdateModoPseudoEEmail(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnMod);		
}
void ClayStat2View::OnUpdateModoPseudoEIp(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnMod);		
}

void ClayStat2View::OnPeriodDayly() 
{
	pDoc->m_uCurrentBtnPer = ID_PERIOD_DAYLY;
	pDoc->m_estat->m_dayly = true;
	m_preenchido = false;
}

void ClayStat2View::OnPeriodByPeriod() 
{
	pDoc->m_uCurrentBtnPer = ID_PERIOD_BY_PERIOD;
	pDoc->m_estat->m_dayly = false;
	m_preenchido = false;
}

void ClayStat2View::OnUpdatePeriodByPeriod(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnPer);		
}

void ClayStat2View::OnUpdatePeriodDayly(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnPer);		
}

void ClayStat2View::OnButtonCabecalho(UINT uID)
{
	pDoc->m_uCurrentBtnHdr = uID;
}


void ClayStat2View::OnUpdateButtonCabecalho(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == pDoc->m_uCurrentBtnHdr);
}

void ClayStat2View::OnUpdateStatisticsDownload(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_downloadComplete);

	MainFrame *pMain = (MainFrame*) ::AfxGetMainWnd();
	if(m_downloadComplete)
		pMain->m_wndStatusBar.SetPaneText(4, "PRONTO!");
}

