// OrigWiz.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include "OrigWiz.h"
#include "OrigWizaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static AFX_EXTENSION_MODULE OrigWizDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("ORIGWIZ.AWX Initializing!\n");
		
		// Extension DLL one-time initialization
		AfxInitExtensionModule(OrigWizDLL, hInstance);

		// Insert this DLL into the resource chain
		new CDynLinkLibrary(OrigWizDLL);

		// Register this custom AppWizard with MFCAPWZ.DLL
		SetCustomAppWizClass(&OrigWizaw);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("ORIGWIZ.AWX Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(OrigWizDLL);
	}
	return 1;   // ok
}
