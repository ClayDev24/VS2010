#if !defined(AFX_ORIGWIZAW_H__E81C5DA4_7236_412A_A3D9_78F6A9BD8E97__INCLUDED_)
#define AFX_ORIGWIZAW_H__E81C5DA4_7236_412A_A3D9_78F6A9BD8E97__INCLUDED_

// OrigWizaw.h : header file
//

class CDialogChooser;

// All function calls made by mfcapwz.dll to this custom AppWizard (except for
//  GetCustomAppWizClass-- see OrigWiz.cpp) are through this class.  You may
//  choose to override more of the CCustomAppWiz virtual functions here to
//  further specialize the behavior of this custom AppWizard.
class COrigWizAppWiz : public CCustomAppWiz
{
public:
	virtual CAppWizStepDlg* Next(CAppWizStepDlg* pDlg);
		
	virtual void InitCustomAppWiz();
	virtual void ExitCustomAppWiz();
	virtual void CustomizeProject(IBuildProject* pProject);
};

// This declares the one instance of the COrigWizAppWiz class.  You can access
//  m_Dictionary and any other public members of this class through the
//  global OrigWizaw.  (Its definition is in OrigWizaw.cpp.)
extern COrigWizAppWiz OrigWizaw;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORIGWIZAW_H__E81C5DA4_7236_412A_A3D9_78F6A9BD8E97__INCLUDED_)
