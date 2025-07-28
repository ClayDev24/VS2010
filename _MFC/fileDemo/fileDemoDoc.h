// fileDemoDoc.h : interface of the CFileDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEDEMODOC_H__1FA1F798_B522_4FE4_8393_2AB5BFAEB31B__INCLUDED_)
#define AFX_FILEDEMODOC_H__1FA1F798_B522_4FE4_8393_2AB5BFAEB31B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFileDemoDoc : public CDocument
{
protected: // create from serialization only
	CFileDemoDoc();
	DECLARE_DYNCREATE(CFileDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void set_message(CString);
	CString get_message(void);
	virtual ~CFileDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString m_message;

// Generated message map functions
protected:
	//{{AFX_MSG(CFileDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDEMODOC_H__1FA1F798_B522_4FE4_8393_2AB5BFAEB31B__INCLUDED_)
