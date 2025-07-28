#if !defined(AFX_DIEROLLCTL_H__11554E62_79AD_43B5_A5DD_B1DAB50EC87A__INCLUDED_)
#define AFX_DIEROLLCTL_H__11554E62_79AD_43B5_A5DD_B1DAB50EC87A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DierollCtl.h : Declaration of the CDierollCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl : See DierollCtl.cpp for implementation.

class CDierollCtrl : public COleControl
{
	DECLARE_DYNCREATE(CDierollCtrl)

// Constructor
public:
	CDierollCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDierollCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CDierollCtrl();

	DECLARE_OLECREATE_EX(CDierollCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CDierollCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CDierollCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CDierollCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CDierollCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CDierollCtrl)
	short m_number;
	afx_msg void OnNumberChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CDierollCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	short Roll();
	enum {
	//{{AFX_DISP_ID(CDierollCtrl)
	dispidNumber = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIEROLLCTL_H__11554E62_79AD_43B5_A5DD_B1DAB50EC87A__INCLUDED)
