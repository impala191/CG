// Drawb.h : main header file for the DRAWB application
//

#if !defined(AFX_DRAWB_H__F5D6DC92_8513_46C2_A71F_15FF09DEA3AD__INCLUDED_)
#define AFX_DRAWB_H__F5D6DC92_8513_46C2_A71F_15FF09DEA3AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawbApp:
// See Drawb.cpp for the implementation of this class
//

class CDrawbApp : public CWinApp
{
public:
	CDrawbApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawbApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawbApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWB_H__F5D6DC92_8513_46C2_A71F_15FF09DEA3AD__INCLUDED_)
