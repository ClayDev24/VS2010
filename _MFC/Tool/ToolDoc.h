// ToolDoc.h : interface of the CToolDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDOC_H__8AB6196E_4FF9_48C3_95D0_3187F473505A__INCLUDED_)
#define AFX_TOOLDOC_H__8AB6196E_4FF9_48C3_95D0_3187F473505A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolDoc : public CDocument
{
protected: // create from serialization only
	CToolDoc();
	DECLARE_DYNCREATE(CToolDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLDOC_H__8AB6196E_4FF9_48C3_95D0_3187F473505A__INCLUDED_)
