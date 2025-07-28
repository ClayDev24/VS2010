// ShowStringDoc.h : interface of the CShowStringDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWSTRINGDOC_H__CF4B81AE_627C_4D6E_AE46_167626C9A725__INCLUDED_)
#define AFX_SHOWSTRINGDOC_H__CF4B81AE_627C_4D6E_AE46_167626C9A725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowStringSrvrItem;

class CShowStringDoc : public COleServerDoc
{
protected: // create from serialization only
	CShowStringDoc();
	DECLARE_DYNCREATE(CShowStringDoc)

// Attributes
public:
	CShowStringSrvrItem* GetEmbeddedItem()
		{ return (CShowStringSrvrItem*)COleServerDoc::GetEmbeddedItem(); }
    CString GetString() {return string;}
    int    GetColor() {return color;}
    BOOL GetHorizcenter() {return horizcenter;}

    BOOL GetVertcenter() {return vertcenter;}

private:
    CString string;
    int    color;
    BOOL horizcenter;
    BOOL vertcenter;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
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

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowStringDoc)
	afx_msg void OnToolsOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSTRINGDOC_H__CF4B81AE_627C_4D6E_AE46_167626C9A725__INCLUDED_)
