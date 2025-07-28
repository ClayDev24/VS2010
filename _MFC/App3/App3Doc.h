// App3Doc.h : interface of the CApp3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_APP3DOC_H__AD4D1E80_23DC_4CE2_A272_92F30A1C7E7D__INCLUDED_)
#define AFX_APP3DOC_H__AD4D1E80_23DC_4CE2_A272_92F30A1C7E7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CApp3Doc : public CDocument
{
protected: // create from serialization only
	CApp3Doc();
	DECLARE_DYNCREATE(CApp3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CApp3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CApp3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APP3DOC_H__AD4D1E80_23DC_4CE2_A272_92F30A1C7E7D__INCLUDED_)
