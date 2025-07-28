// RecsDoc.h : interface of the CRecsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECSDOC_H__EDC2C811_D054_4B10_9E4B_725317AEE8F8__INCLUDED_)
#define AFX_RECSDOC_H__EDC2C811_D054_4B10_9E4B_725317AEE8F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRecsDoc : public CDocument
{
protected: // create from serialization only
	CRecsDoc();
	DECLARE_DYNCREATE(CRecsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT m_pointIndex;
	CPoint m_points[10];
	virtual ~CRecsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRecsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECSDOC_H__EDC2C811_D054_4B10_9E4B_725317AEE8F8__INCLUDED_)
