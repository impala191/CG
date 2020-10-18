#if !defined(AFX_DIMDIALOG_H__4AB3B579_20BE_485B_90F4_E3A881D13FA9__INCLUDED_)
#define AFX_DIMDIALOG_H__4AB3B579_20BE_485B_90F4_E3A881D13FA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DimDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DimDialog dialog

class DimDialog : public CDialog
{
// Construction
public:
	DimDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DimDialog)
	enum { IDD = IDD_DIALOG2 };
	double	m_n;
	double	m_r;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DimDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DimDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIMDIALOG_H__4AB3B579_20BE_485B_90F4_E3A881D13FA9__INCLUDED_)
