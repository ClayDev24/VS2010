// Thread3Doc.h : interface of the CThread3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD3DOC_H__3DC375DF_E204_464E_9363_4CE94D2EA180__INCLUDED_)
#define AFX_THREAD3DOC_H__3DC375DF_E204_464E_9363_4CE94D2EA180__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CThread3Doc : public CDocument
{
protected: // create from serialization only
	CThread3Doc();
	DECLARE_DYNCREATE(CThread3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThread3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CThread3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CThread3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREAD3DOC_H__3DC375DF_E204_464E_9363_4CE94D2EA180__INCLUDED_)
