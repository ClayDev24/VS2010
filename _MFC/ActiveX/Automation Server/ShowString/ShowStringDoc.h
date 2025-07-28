// ShowStringDoc.h : interface of the CShowStringDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSTRINGDOC_H__F2109D01_6F69_40D4_87F2_AA0A35A0F239__INCLUDED_)
#define AFX_SHOWSTRINGDOC_H__F2109D01_6F69_40D4_87F2_AA0A35A0F239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowStringDoc : public CDocument
{
protected: // create from serialization only
	CShowStringDoc();
	DECLARE_DYNCREATE(CShowStringDoc)

// Attributes
private:
     BOOL m_horizcenter;
     BOOL m_vertcenter;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowStringDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
     CString GetDocString() {return m_string;}
     int     GetDocColor() {return m_color;}
     BOOL GetHorizcenter() {return m_horizcenter;}

     BOOL GetVertcenter() {return m_vertcenter;}

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowStringDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CShowStringDoc)
	CString m_string;
	afx_msg void OnStringChanged();
	short m_color;
	afx_msg void OnColorChanged();
	//afx_msg BOOL GetHorizcenter();
	afx_msg void SetHorizcenter(BOOL bNewValue);
	//afx_msg BOOL GetVertcenter();
	afx_msg void SetVertcenter(BOOL bNewValue);
	afx_msg void ShowWindow();
	afx_msg void RefreshWindow();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRINGDOC_H__F2109D01_6F69_40D4_87F2_AA0A35A0F239__INCLUDED_)
