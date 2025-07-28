// ShowStringDoc.h : interface of the CShowStringDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSTRINGDOC_H__0D49A68A_A455_4DD4_832E_7B95E6F507C4__INCLUDED_)
#define AFX_SHOWSTRINGDOC_H__0D49A68A_A455_4DD4_832E_7B95E6F507C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowStringDoc : public CDocument
{
protected: // create from serialization only
	CShowStringDoc();
	DECLARE_DYNCREATE(CShowStringDoc)

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
	CString GetString()  { return string; }
    int    GetColor()     { return color; }
    BOOL  GetHorizcenter() { return horizcenter; }
    BOOL GetVertcenter()  { return vertcenter; }

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowStringDoc)
	afx_msg void OnToolsOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString string;
    int     color;
    BOOL    horizcenter;
    BOOL    vertcenter;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRINGDOC_H__0D49A68A_A455_4DD4_832E_7B95E6F507C4__INCLUDED_)
