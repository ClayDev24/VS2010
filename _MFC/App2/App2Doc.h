// App2Doc.h : interface of the CApp2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APP2DOC_H__34310312_9D66_459F_A656_8C324B230B4D__INCLUDED_)
#define AFX_APP2DOC_H__34310312_9D66_459F_A656_8C324B230B4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CApp2Doc : public CDocument
{
protected: // create from serialization only
	CApp2Doc();
	DECLARE_DYNCREATE(CApp2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CApp2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CApp2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP2DOC_H__34310312_9D66_459F_A656_8C324B230B4D__INCLUDED_)
