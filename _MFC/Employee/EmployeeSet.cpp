// EmployeeSet.cpp : implementation of the CEmployeeSet class
//

#include "stdafx.h"
#include "Employee.h"
#include "EmployeeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeSet implementation

IMPLEMENT_DYNAMIC(CEmployeeSet, CRecordset)

CEmployeeSet::CEmployeeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CEmployeeSet)
	m_C_DIGOEmployee = 0;
	m_Nome = _T("");
	m_Endere_o = _T("");
	m_Cidade = _T("");
	m_Estado = _T("");
	m_CEP = _T("");
	m_TelefoneResidencial = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CEmployeeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Departament Store");
}

CString CEmployeeSet::GetDefaultSQL()
{
	return _T("[Employee]");
}

void CEmployeeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CEmployeeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CÓDIGOEmployee]"), m_C_DIGOEmployee);
	RFX_Text(pFX, _T("[Nome]"), m_Nome);
	RFX_Text(pFX, _T("[Endereço]"), m_Endere_o);
	RFX_Text(pFX, _T("[Cidade]"), m_Cidade);
	RFX_Text(pFX, _T("[Estado]"), m_Estado);
	RFX_Text(pFX, _T("[CEP]"), m_CEP);
	RFX_Text(pFX, _T("[TelefoneResidencial]"), m_TelefoneResidencial);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeSet diagnostics

#ifdef _DEBUG
void CEmployeeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEmployeeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
