// DierollPpg.cpp : Implementation of the CDierollPropPage property page class.

#include "stdafx.h"
#include "Dieroll.h"
#include "DierollPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDierollPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDierollPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CDierollPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDierollPropPage, "DIEROLL.DierollPropPage.1",
	0x436c6dfb, 0xba23, 0x4864, 0xb7, 0x4c, 0x7e, 0x53, 0xea, 0x39, 0xee, 0x65)


/////////////////////////////////////////////////////////////////////////////
// CDierollPropPage::CDierollPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDierollPropPage

BOOL CDierollPropPage::CDierollPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DIEROLL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CDierollPropPage::CDierollPropPage - Constructor

CDierollPropPage::CDierollPropPage() :
	COlePropertyPage(IDD, IDS_DIEROLL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CDierollPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CDierollPropPage::DoDataExchange - Moves data between page and properties

void CDierollPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CDierollPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CDierollPropPage message handlers
