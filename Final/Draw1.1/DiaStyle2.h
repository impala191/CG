#if !defined(AFX_DIASTYLE2_H__62EF7248_8CB7_43D2_B6CC_384075006738__INCLUDED_)
#define AFX_DIASTYLE2_H__62EF7248_8CB7_43D2_B6CC_384075006738__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaStyle2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaStyle2 dialog

class DiaStyle2 : public CDialog
{
// Construction
public:
	DiaStyle2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaStyle2)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaStyle2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaStyle2)
	afx_msg void OnEditDash();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIASTYLE2_H__62EF7248_8CB7_43D2_B6CC_384075006738__INCLUDED_)
