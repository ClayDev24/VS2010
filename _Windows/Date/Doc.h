// Doc.h : interface of the CDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOC_H__3DD52FEA_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
#define AFX_DOC_H__3DD52FEA_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDoc : public CDocument
{
protected: // create from serialization only
	CDoc();
	DECLARE_DYNCREATE(CDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOC_H__3DD52FEA_4E78_11D3_82D6_00A0CC28BFE2__INCLUDED_)
