// ScrollDoc.h : interface of the CScrollDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCROLLDOC_H__A7DD932C_9209_4DC3_9E23_37FF3D72F257__INCLUDED_)
#define AFX_SCROLLDOC_H__A7DD932C_9209_4DC3_9E23_37FF3D72F257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CScrollDoc : public CDocument
{
protected: // create from serialization only
	CScrollDoc();
	DECLARE_DYNCREATE(CScrollDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_NumLines;
	virtual ~CScrollDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScrollDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLDOC_H__A7DD932C_9209_4DC3_9E23_37FF3D72F257__INCLUDED_)
