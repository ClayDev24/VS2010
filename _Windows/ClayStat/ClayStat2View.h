// ClayStat2View.h : interface of the ClayStat2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLAYSTAT2VIEW_H__75379D88_14A0_491B_A089_DEEE55DBF8C0__INCLUDED_)
#define AFX_CLAYSTAT2VIEW_H__75379D88_14A0_491B_A089_DEEE55DBF8C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClayStat2Doc.h"
#include "ConfSheet.h"

class ClayStat2View : public CScrollView
{
protected: // create from serialization only
	ClayStat2View();
	DECLARE_DYNCREATE(ClayStat2View)

	//afx_msg void OnButtonCabecalho(UINT);
	//afx_msg void OnUpdateButtonCabecalho(CCmdUI* pCmdUI);

	ClayStat2Doc* pDoc;
	CConfSheet*   m_setup;
	CTime         m_date;
	CString       m_down_date;
	bool          m_downloadComplete;
	bool          m_preenchido;

// Attributes
public:
	ClayStat2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ClayStat2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ClayStat2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(ClayStat2View)
	afx_msg void OnExibirNome();
	afx_msg void OnEstatGerar();
	afx_msg void OnExibirPorQuantidade();
	afx_msg void OnViewMostrar();
	afx_msg void OnViewOcultar();
	afx_msg void OnUpdateViewMostrar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewOcultar(CCmdUI* pCmdUI);
	afx_msg void OnGrupoEspecifico();
	afx_msg void OnUpdateGrupoEspecifico(CCmdUI* pCmdUI);
	afx_msg void OnGrupoGeral();
	afx_msg void OnUpdateGrupoGeral(CCmdUI* pCmdUI);
	afx_msg void OnModoPseudo();
	afx_msg void OnModoPseudoEEmail();
	afx_msg void OnModoPseudoEIp();
	afx_msg void OnUpdateModoPseudo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateModoPseudoEEmail(CCmdUI* pCmdUI);
	afx_msg void OnUpdateModoPseudoEIp(CCmdUI* pCmdUI);
	afx_msg void OnEstatPesquisa();
	afx_msg void OnFerramentasConfiguracoes();
	afx_msg void OnViewClearScreen();
	afx_msg void OnToolsLanguagePortuguese();
	afx_msg void OnToolsLanguageEnglish();
	afx_msg void OnStatisticsDownload();
	afx_msg void OnPeriodDayly();
	afx_msg void OnUpdatePeriodDayly(CCmdUI* pCmdUI);
	afx_msg void OnPeriodByPeriod();
	afx_msg void OnUpdatePeriodByPeriod(CCmdUI* pCmdUI);
	afx_msg void OnSendSelected();
	afx_msg void OnUpdateStatisticsDownload(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnButtonCabecalho(UINT);
	afx_msg void OnUpdateButtonCabecalho(CCmdUI* pCmdUI);
	afx_msg void OnDatetimechangeDate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCloseupCombo();
	afx_msg void make_tempFile();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ClayStat2View.cpp
inline ClayStat2Doc* ClayStat2View::GetDocument()
   { return (ClayStat2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLAYSTAT2VIEW_H__75379D88_14A0_491B_A089_DEEE55DBF8C0__INCLUDED_)
