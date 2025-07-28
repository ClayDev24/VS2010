// SrvrItem.h : interface of the CShowStringSrvrItem class
//

#if !defined(AFX_SRVRITEM_H__EA5C8F0F_474D_457E_8698_8945E1113F15__INCLUDED_)
#define AFX_SRVRITEM_H__EA5C8F0F_474D_457E_8698_8945E1113F15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShowStringSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CShowStringSrvrItem)

// Constructors
public:
	CShowStringSrvrItem(CShowStringDoc* pContainerDoc);

// Attributes
	CShowStringDoc* GetDocument() const
		{ return (CShowStringDoc*)COleServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowStringSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CShowStringSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVRITEM_H__EA5C8F0F_474D_457E_8698_8945E1113F15__INCLUDED_)
