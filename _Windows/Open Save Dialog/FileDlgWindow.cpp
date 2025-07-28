#include<afxwin.h>
#include<afxdlgs.h>
#include<strstrea.h>

#define IDM_BUTTON 101

const char fileDialogFilter[]="C++ File(*.cpp) | *.cpp | Header Files(*.h) | *.h | Resource File(*.rc) | *.rc || ";
const char fileDialogExt[]="cpp";

class CFileDialogTest:public CWinApp
{
public:
	virtual BOOL InitInstance();
};

 CFileDialogTest theApp;

class CFileDialogWindow:public CFrameWnd
{
private:
	CButton * button;
public:
	CFileDialogWindow();
	~CFileDialogWindow();

	afx_msg void HandleButton();
	DECLARE_MESSAGE_MAP()
};

void CFileDialogWindow::HandleButton()
{
	char s[200];
	ostrstream ostr(s,200);
	
	CFileDialog fileDialog(TRUE,fileDialogExt,NULL,OFN_FILEMUSTEXIST,fileDialogFilter);   //Replace "TRUE" with "FALSE" to view "Save As" instead of "Open"

	if( fileDialog.DoModal() == IDOK )
	{
		ostr<<"Path Name:"
			<<fileDialog.GetPathName()
			<<endl
			<<"File Name:"
			<<fileDialog.GetFileName()
			<<endl
			<<"Extension:"
			<<fileDialog.GetFileExt()
			<<endl
			<<"File Title:"
			<<fileDialog.GetFileTitle()
			<<endl
			<<ends;
		
		MessageBox(s,"File Data",MB_ICONINFORMATION);
	}
}

	BEGIN_MESSAGE_MAP(CFileDialogWindow,CFrameWnd)
		ON_COMMAND(IDM_BUTTON,HandleButton)
	END_MESSAGE_MAP()

 BOOL CFileDialogTest::InitInstance()
	{
		m_pMainWnd = new CFileDialogWindow();
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}

	CFileDialogWindow::CFileDialogWindow()
	{
		CRect r;
		
		Create(NULL,"File Dialog Test",WS_OVERLAPPEDWINDOW,CRect(0,0,250,250) );

		GetClientRect(&r);
		r.InflateRect(-50,-50);

		button = new CButton();
		button->Create("Push Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,r,this,IDM_BUTTON );
	}

 CFileDialogWindow::~CFileDialogWindow()
 {
	 delete button;
 }

