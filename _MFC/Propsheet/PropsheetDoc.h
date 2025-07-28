// PropsheetDoc.h : interface of the CPropsheetDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPSHEETDOC_H__939FEFD5_6198_41CC_B779_DD3F9BCB10D7__INCLUDED_)
#define AFX_PROPSHEETDOC_H__939FEFD5_6198_41CC_B779_DD3F9BCB10D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropsheetDoc : public CDocument
{
protected: // create from serialization only
	CPropsheetDoc();
	DECLARE_DYNCREATE(CPropsheetDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropsheetDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropsheetDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropsheetDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEETDOC_H__939FEFD5_6198_41CC_B779_DD3F9BCB10D7__INCLUDED_)
