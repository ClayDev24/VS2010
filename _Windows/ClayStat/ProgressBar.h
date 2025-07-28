// ProgressBar.h : header file
//
// Drop-in status bar progress control
//
// Written by Chris Maunder (Chris.Maunder@cbr.clw.csiro.au)
// Copyright (c) 1998.
//
// This code may be used in compiled form in any way you desire. This
// file may be redistributed unmodified by any means PROVIDING it is 
// not sold for profit without the authors written consent, and 
// providing that this notice and the authors name is included. If 
// the source code in  this file is used in any commercial application 
// then acknowledgement must be made to the author of this file 
// (in whatever form you wish).
//
// This file is provided "as is" with no expressed or implied warranty.
// The author accepts no liability if it causes any damage to your
// computer, causes your pet cat to fall ill, increases baldness or
// makes you car start emitting strange noises when you start it up.
//
// Expect bugs.
// 
// Please use and enjoy. Please let me know of any bugs/mods/improvements 
// that you have found/implemented and I will fix/incorporate them into this
// file. 
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _INCLUDE_PROGRESSBAR_H_
#define _INCLUDE_PROGRESSBAR_H_


/////////////////////////////////////////////////////////////////////////////
// CProgressBar -  status bar progress control
//
// Copyright (c) Chris Maunder, 1997
// Please feel free to use and distribute.

class CProgressBar: public CProgressCtrl
// Creates a ProgressBar in the status bar
{
public:
    CProgressBar();
    CProgressBar(LPCTSTR strMessage, int nSize=100, int MaxValue=100, BOOL bSmooth=FALSE);
    ~CProgressBar();
    BOOL Create(LPCTSTR strMessage, int nSize=100, int MaxValue=100, BOOL bSmooth=FALSE);

    DECLARE_DYNCREATE(CProgressBar)

// operations
public:
    BOOL Success() {return m_bSuccess;}			// Was the creation successful?

    void SetRange(int nLower, int nUpper, int nStep = 1);
    void SetText(LPCTSTR strMessage);
    void SetSize(int nSize);
    int  SetPos(int nPos);
    int  OffsetPos(int nPos);
    int  SetStep(int nStep);
    int  StepIt();
    void Clear();

// Overrides
    //{{AFX_VIRTUAL(CProgressBar)
    //}}AFX_VIRTUAL

// implementation
protected:
    BOOL      m_bSuccess;     // Successfully created?
    int       m_nSize;        // Percentage size of control
    CString   m_strMessage;   // Message to display to left of control
    CRect     m_Rect;         // Dimensions of the whole thing

    CStatusBar *GetStatusBar();
    void Resize();

// Generated message map functions
protected:
    //{{AFX_MSG(CProgressBar)
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

};

#endif
/////////////////////////////////////////////////////////////////////////////

