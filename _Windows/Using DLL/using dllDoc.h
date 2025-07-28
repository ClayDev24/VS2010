// using dllDoc.h : interface of the CUsingdllDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USINGDLLDOC_H__99F648EF_694E_4405_87ED_EDA3A28E2C55__INCLUDED_)
#define AFX_USINGDLLDOC_H__99F648EF_694E_4405_87ED_EDA3A28E2C55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUsingdllDoc : public CDocument
{
protected: // create from serialization only
	CUsingdllDoc();
	DECLARE_DYNCREATE(CUsingdllDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsingdllDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUsingdllDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUsingdllDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USINGDLLDOC_H__99F648EF_694E_4405_87ED_EDA3A28E2C55__INCLUDED_)
