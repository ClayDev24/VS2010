// Paint1Doc.h : interface of the CPaint1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINT1DOC_H__BD4448C3_F51D_4F27_9FCE_D920B1A52332__INCLUDED_)
#define AFX_PAINT1DOC_H__BD4448C3_F51D_4F27_9FCE_D920B1A52332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPaint1Doc : public CDocument
{
protected: // create from serialization only
	CPaint1Doc();
	DECLARE_DYNCREATE(CPaint1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaint1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaint1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaint1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT1DOC_H__BD4448C3_F51D_4F27_9FCE_D920B1A52332__INCLUDED_)
