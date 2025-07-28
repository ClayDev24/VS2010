// Char ListingDoc.h : interface of the CCharListingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARLISTINGDOC_H__BA68EA6D_B619_46BE_99D2_6F6F73396E9D__INCLUDED_)
#define AFX_CHARLISTINGDOC_H__BA68EA6D_B619_46BE_99D2_6F6F73396E9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCharListingDoc : public CDocument
{
protected: // create from serialization only
	CCharListingDoc();
	DECLARE_DYNCREATE(CCharListingDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharListingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCharListingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCharListingDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARLISTINGDOC_H__BA68EA6D_B619_46BE_99D2_6F6F73396E9D__INCLUDED_)
