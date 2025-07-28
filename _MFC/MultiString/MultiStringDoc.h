// MultiStringDoc.h : interface of the CMultiStringDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTISTRINGDOC_H__85E68850_3307_43F1_92DB_7E184D785D32__INCLUDED_)
#define AFX_MULTISTRINGDOC_H__85E68850_3307_43F1_92DB_7E184D785D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Messages.h"

class CMultiStringDoc : public CDocument
{
protected: // create from serialization only
	CMultiStringDoc();
	DECLARE_DYNCREATE(CMultiStringDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiStringDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CMessages m_messages;
	virtual ~CMultiStringDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiStringDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISTRINGDOC_H__85E68850_3307_43F1_92DB_7E184D785D32__INCLUDED_)
