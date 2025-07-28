// Messages.h: interface for the CMessages class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESSAGES_H__A164E04E_A25D_4DE8_B2B6_B944F16EB41F__INCLUDED_)
#define AFX_MESSAGES_H__A164E04E_A25D_4DE8_B2B6_B944F16EB41F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMessages : public CObject  
{
public:
	CMessages();
	virtual ~CMessages();
	DECLARE_SERIAL(CMessages)
protected:
    CString m_message1;
    CString m_message2;
    CString m_message3;
public:
    void SetMessage(UINT msgNum, CString msg);
    CString GetMessage(UINT msgNum);
    void Serialize(CArchive& ar);

};

#endif // !defined(AFX_MESSAGES_H__A164E04E_A25D_4DE8_B2B6_B944F16EB41F__INCLUDED_)
