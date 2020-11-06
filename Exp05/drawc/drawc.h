// drawc.h : main header file for the DRAWC application
//

#if !defined(AFX_DRAWC_H__D33C634B_6492_4422_9E79_461A1BF11190__INCLUDED_)
#define AFX_DRAWC_H__D33C634B_6492_4422_9E79_461A1BF11190__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawcApp:
// See drawc.cpp for the implementation of this class
//

class CDrawcApp : public CWinApp
{
public:
	CDrawcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWC_H__D33C634B_6492_4422_9E79_461A1BF11190__INCLUDED_)
