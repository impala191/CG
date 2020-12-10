#if !defined(AFX_DLG_SCALE_H__85A29B80_498E_44ED_94B0_3D0B5F46589B__INCLUDED_)
#define AFX_DLG_SCALE_H__85A29B80_498E_44ED_94B0_3D0B5F46589B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_SCALE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dlg_SCALE dialog

class Dlg_SCALE : public CDialog
{
// Construction
public:
	Dlg_SCALE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_SCALE)
	enum { IDD = IDD_DIALOG1 };
	double	m_Sx;
	double	m_Sy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_SCALE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_SCALE)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_SCALE_H__85A29B80_498E_44ED_94B0_3D0B5F46589B__INCLUDED_)
