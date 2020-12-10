#if !defined(AFX_WIDTHDLG_H__DABBCF77_0A1F_4B67_82BF_F30DC68330C0__INCLUDED_)
#define AFX_WIDTHDLG_H__DABBCF77_0A1F_4B67_82BF_F30DC68330C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WidthDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWidthDlg dialog

class CWidthDlg : public CDialog
{
// Construction
public:
	CWidthDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWidthDlg)
	enum { IDD = IDD_DIALOG1 };
	UINT	m_widthDlg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWidthDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWidthDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIDTHDLG_H__DABBCF77_0A1F_4B67_82BF_F30DC68330C0__INCLUDED_)
