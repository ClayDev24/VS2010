// Messages.cpp: implementation of the CMessages class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MultiString.h"
#include "Messages.h"

IMPLEMENT_SERIAL(CMessages, CObject, 0)

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMessages::CMessages()
{
}

CMessages::~CMessages()
{
}

void CMessages::SetMessage(UINT msgNum, CString msg)
{
     switch (msgNum)
     {
     case 1:
          m_message1 = msg;
          break;
     case 2:
        m_message2 = msg;
          break;
     case 3:
        m_message3 = msg;
          break;
     }
	 //SetModifiedFlag();
}

CString CMessages::GetMessage(UINT msgNum)
{
   switch (msgNum)
   {
      case 1:
         return m_message1;
      case 2:
         return m_message2;
      case 3:
         return m_message3;
      default:
         return "";
   }
}
void CMessages::Serialize(CArchive& ar)
{
    CObject::Serialize(ar);
    if (ar.IsStoring())
    {
        ar << m_message1 << m_message2 << m_message3;
    }
    else
    {
        ar >> m_message1 >> m_message2 >> m_message3;
    }

}

