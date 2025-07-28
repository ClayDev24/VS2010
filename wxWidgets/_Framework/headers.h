#pragma once
// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#include "wx/aboutdlg.h" // wxAboutBox() / wxAboutDialogInfo

#ifdef __BORLANDC__
    #pragma hdrstop
#endif
// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
// ----------------------------------------------------------
// resources
// ----------------------------------------------------------
#ifndef wxHAS_IMAGES_IN_RESOURCES
    #include "../sample.xpm"
#endif

/*
#if wxUSE_SPINCTRL
    #include "wx/spinctrl.h"
#endif // wxUSE_SPINCTRL

#include "wx/spinbutt.h"
#include "wx/tglbtn.h"
#include "wx/bookctrl.h"
#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/gbsizer.h"

#if wxUSE_TOOLTIPS
    #include "wx/tooltip.h"
#ifdef __WXMSW__
    #include "wx/numdlg.h"
#endif // __WXMSW__
#endif // wxUSE_TOOLTIPS

#ifndef __WXMSW__
    #include "icons/choice.xpm"
    #include "icons/combo.xpm"
    #include "icons/list.xpm"
    #include "icons/radio.xpm"
    #include "icons/text.xpm"
    #include "icons/gauge.xpm"
#endif

#ifndef wxUSE_SPINBTN
    #define wxUSE_SPINBTN 1
#endif

#include "wx/progdlg.h"

#if !wxUSE_TOGGLEBTN
    #define wxToggleButton wxCheckBox
    #define EVT_TOGGLEBUTTON EVT_CHECKBOX
#endif
	*/