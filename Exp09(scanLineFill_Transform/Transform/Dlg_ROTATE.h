#if !defined(AFX_DLG_ROTATE_H__BD7B311F_686A_47CB_B857_FA86895A4F81__INCLUDED_)
#define AFX_DLG_ROTATE_H__BD7B311F_686A_47CB_B857_FA86895A4F81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_ROTATE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dlg_ROTATE dialog

class Dlg_ROTATE : public CDialog
{
// Construction
public:
	Dlg_ROTATE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_ROTATE)
	enum { IDD = IDD_DIALOG2 };
	double	m_RotateAngle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_ROTATE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_ROTATE)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_ROTATE_H__BD7B311F_686A_47CB_B857_FA86895A4F81__INCLUDED_)
