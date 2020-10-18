// Graph.h : main header file for the GRAPH application
//

#if !defined(AFX_GRAPH_H__1D4DF5A8_C907_4EB2_BFD1_34D3405FCA60__INCLUDED_)
#define AFX_GRAPH_H__1D4DF5A8_C907_4EB2_BFD1_34D3405FCA60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraphApp:
// See Graph.cpp for the implementation of this class
//

class CGraphApp : public CWinApp
{
public:
	CGraphApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGraphApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPH_H__1D4DF5A8_C907_4EB2_BFD1_34D3405FCA60__INCLUDED_)
