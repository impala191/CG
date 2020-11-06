#if !defined(AFX_DIALOGSTYLE_H__833B12DA_F6E0_4DA1_8955_9045D3C935BC__INCLUDED_)
#define AFX_DIALOGSTYLE_H__833B12DA_F6E0_4DA1_8955_9045D3C935BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogStyle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogStyle dialog

class CDialogStyle : public CDialog
{
// Construction
public:
	CDialogStyle(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogStyle)
	enum { IDD = IDD_STYLEDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogStyle)
	afx_msg void OnDash();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSTYLE_H__833B12DA_F6E0_4DA1_8955_9045D3C935BC__INCLUDED_)
