// Cut.h : main header file for the CUT application
//

#if !defined(AFX_CUT_H__9B0143A7_D111_4F8D_9B6F_4E4C1211E584__INCLUDED_)
#define AFX_CUT_H__9B0143A7_D111_4F8D_9B6F_4E4C1211E584__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCutApp:
// See Cut.cpp for the implementation of this class
//

class CCutApp : public CWinApp
{
public:
	CCutApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCutApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUT_H__9B0143A7_D111_4F8D_9B6F_4E4C1211E584__INCLUDED_)
