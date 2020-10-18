#if !defined(AFX_DLDIMOND_H__F08CA967_1E45_4407_AF64_A765DAC51C8A__INCLUDED_)
#define AFX_DLDIMOND_H__F08CA967_1E45_4407_AF64_A765DAC51C8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLDimond.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLDimond dialog

class DLDimond : public CDialog
{
// Construction
public:
	DLDimond(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLDimond)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLDimond)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLDimond)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLDIMOND_H__F08CA967_1E45_4407_AF64_A765DAC51C8A__INCLUDED_)
