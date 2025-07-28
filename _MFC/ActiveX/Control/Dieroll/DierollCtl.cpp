// DierollCtl.cpp : Implementation of the CDierollCtrl ActiveX Control class.

#include "stdafx.h"
#include "Dieroll.h"
#include "DierollCtl.h"
#include "DierollPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDierollCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDierollCtrl, COleControl)
	//{{AFX_MSG_MAP(CDierollCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CDierollCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CDierollCtrl)
	DISP_PROPERTY_NOTIFY(CDierollCtrl, "Number", m_number, OnNumberChanged, VT_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CDierollCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CDierollCtrl, COleControl)
	//{{AFX_EVENT_MAP(CDierollCtrl)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CDierollCtrl, 1)
	PROPPAGEID(CDierollPropPage::guid)
END_PROPPAGEIDS(CDierollCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDierollCtrl, "DIEROLL.DierollCtrl.1",
	0x6af91dc8, 0x8c86, 0x4754, 0x95, 0x5e, 0x20, 0xfd, 0x46, 0x25, 0x4b, 0xfc)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CDierollCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DDieroll =
		{ 0x60567333, 0xe7f, 0x4ad2, { 0x95, 0xc0, 0xa9, 0, 0xcd, 0xa9, 0x5f, 0xd1 } };
const IID BASED_CODE IID_DDierollEvents =
		{ 0xcf1d0253, 0xe941, 0x4f58, { 0xa5, 0x35, 0xf4, 0x1, 0xbc, 0x6b, 0x51, 0x94 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwDierollOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CDierollCtrl, IDS_DIEROLL, _dwDierollOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::CDierollCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CDierollCtrl

BOOL CDierollCtrl::CDierollCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegInsertable | afxRegApartmentThreading to afxRegInsertable.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_DIEROLL,
			IDB_DIEROLL,
			afxRegInsertable | afxRegApartmentThreading,
			_dwDierollOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::CDierollCtrl - Constructor

CDierollCtrl::CDierollCtrl()
{
	InitializeIIDs(&IID_DDieroll, &IID_DDierollEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::~CDierollCtrl - Destructor

CDierollCtrl::~CDierollCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::OnDraw - Drawing function

void CDierollCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	
	//CString val; //character representation of the short value
    //val.Format("%i",m_number);
    //pdc->ExtTextOut( 0, 0, ETO_OPAQUE, rcBounds, val, NULL );
	//int Xunit = rcBounds.Width()/16;
    //int Yunit = rcBounds.Height()/16;
    //int Top = rcBounds.top;
    //int Left = rcBounds.left;

//more accurate one:
	//dots are 4 units wide and high, one unit from the edge
    int Xunit = rcBounds.Width()/16;
    int Yunit = rcBounds.Height()/16;
    int Xleft = rcBounds.Width()%16;
    int Yleft = rcBounds.Height()%16;
    // adjust top left by amount left over
    int Top = rcBounds.top + Yleft/2;
    int Left = rcBounds.left + Xleft/2; 

    CBrush Black;
    Black.CreateSolidBrush(RGB(0x00,0x00,0x00)); //solid black brush
    CBrush* savebrush = pdc->SelectObject(&Black);
	
	switch(m_number)
     {
     case 1:
          pdc->Ellipse(Left+6*Xunit, Top+6*Yunit,
                        Left+10*Xunit, Top + 10*Yunit); //center
          break;
     case 2:
          pdc->Ellipse(Left+Xunit, Top+Yunit,
                        Left+5*Xunit, Top + 5*Yunit);   //upper left
          pdc->Ellipse(Left+11*Xunit, Top+11*Yunit,
                        Left+15*Xunit, Top + 15*Yunit); //lower right
          break;
     case 3:
          pdc->Ellipse(Left+Xunit, Top+Yunit,
                        Left+5*Xunit, Top + 5*Yunit);   //upper left
          pdc->Ellipse(Left+6*Xunit, Top+6*Yunit,
                        Left+10*Xunit, Top + 10*Yunit); //center
          pdc->Ellipse(Left+11*Xunit, Top+11*Yunit,
                        Left+15*Xunit, Top + 15*Yunit); //lower right
          break;
     case 4:
          pdc->Ellipse(Left+Xunit, Top+Yunit,
                        Left+5*Xunit, Top + 5*Yunit);   //upper left
          pdc->Ellipse(Left+11*Xunit, Top+Yunit,
                        Left+15*Xunit, Top + 5*Yunit);  //upper right
          pdc->Ellipse(Left+Xunit, Top+11*Yunit,
                        Left+5*Xunit, Top + 15*Yunit);  //lower left
          pdc->Ellipse(Left+11*Xunit, Top+11*Yunit,
                        Left+15*Xunit, Top + 15*Yunit); //lower right
          break;
     case 5:
          pdc->Ellipse(Left+Xunit, Top+Yunit,
                        Left+5*Xunit, Top + 5*Yunit);   //upper left
          pdc->Ellipse(Left+11*Xunit, Top+Yunit,
                        Left+15*Xunit, Top + 5*Yunit);  //upper right
          pdc->Ellipse(Left+6*Xunit, Top+6*Yunit,
                        Left+10*Xunit, Top + 10*Yunit); //center
          pdc->Ellipse(Left+Xunit, Top+11*Yunit,
                        Left+5*Xunit, Top + 15*Yunit);  //lower left
          pdc->Ellipse(Left+11*Xunit, Top+11*Yunit,
                        Left+15*Xunit, Top + 15*Yunit); //lower right
          break;
       case 6:
               pdc->Ellipse(Left+Xunit, Top+Yunit,
                Left+5*Xunit, Top + 5*Yunit);   //upper left
               pdc->Ellipse(Left+11*Xunit, Top+Yunit,
                Left+15*Xunit, Top + 5*Yunit);  //upper right
               pdc->Ellipse(Left+Xunit, Top+6*Yunit,
                Left+5*Xunit, Top + 10*Yunit);  //center left
               pdc->Ellipse(Left+11*Xunit, Top+6*Yunit,
                  Left+15*Xunit, Top + 10*Yunit); //center right
               pdc->Ellipse(Left+Xunit, Top+11*Yunit,
                Left+5*Xunit, Top + 15*Yunit);  //lower left
               pdc->Ellipse(Left+11*Xunit, Top+11*Yunit,
                Left+15*Xunit, Top + 15*Yunit); //lower right
               break;
	}

     pdc->SelectObject(savebrush);
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::DoPropExchange - Persistence support

void CDierollCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	
	srand( (unsigned)time( NULL ) );
	PX_Short( pPX, "Number",  m_number, Roll());
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::OnResetState - Reset control to default state

void CDierollCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl::AboutBox - Display an "About" box to the user

void CDierollCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_DIEROLL);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CDierollCtrl message handlers

void CDierollCtrl::OnNumberChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CDierollCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_number = Roll();
	InvalidateControl();
	
	COleControl::OnLButtonDown(nFlags, point);
}

short CDierollCtrl::Roll()
{
	double number = rand();
    number /= RAND_MAX + 1;
    number *= 6;
    return (short)number + 1;
}
