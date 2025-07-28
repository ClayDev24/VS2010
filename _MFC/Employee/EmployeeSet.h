// EmployeeSet.h : interface of the CEmployeeSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEESET_H__7D2274FC_1381_4AD1_99D9_B00EC99B66F2__INCLUDED_)
#define AFX_EMPLOYEESET_H__7D2274FC_1381_4AD1_99D9_B00EC99B66F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmployeeSet : public CRecordset
{
public:
	CEmployeeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CEmployeeSet)

// Field/Param Data
	//{{AFX_FIELD(CEmployeeSet, CRecordset)
	long	m_C_DIGOEmployee;
	CString	m_Nome;
	CString	m_Endere_o;
	CString	m_Cidade;
	CString	m_Estado;
	CString	m_CEP;
	CString	m_TelefoneResidencial;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEESET_H__7D2274FC_1381_4AD1_99D9_B00EC99B66F2__INCLUDED_)

