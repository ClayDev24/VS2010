// DialogbarDemoDoc.h : interface of the CDialogbarDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIALOGBARDEMODOC_H__D614B24C_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
#define AFX_DIALOGBARDEMODOC_H__D614B24C_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDialogbarDemoDoc : public CDocument
{
protected: // create from serialization only
	CDialogbarDemoDoc();
	DECLARE_DYNCREATE(CDialogbarDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogbarDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogbarDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDialogbarDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBARDEMODOC_H__D614B24C_C5EC_11D2_B8C5_B41E04C10000__INCLUDED_)
