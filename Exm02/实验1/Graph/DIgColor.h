#if !defined(AFX_DIGCOLOR_H__0E823D51_1588_484F_A2C0_B1A04E5F93C8__INCLUDED_)
#define AFX_DIGCOLOR_H__0E823D51_1588_484F_A2C0_B1A04E5F93C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIgColor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIgColor dialog

class CDIgColor : public CDialog
{
// Construction
public:
	CDIgColor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDIgColor)
	enum { IDD = IDD_DIALOG1 };
	int		m_DlgRed;
	int		m_DlgGreen;
	int		m_DlgBlue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIgColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIgColor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGCOLOR_H__0E823D51_1588_484F_A2C0_B1A04E5F93C8__INCLUDED_)
