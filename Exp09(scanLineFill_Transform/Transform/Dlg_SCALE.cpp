// Dlg_SCALE.cpp : implementation file
//

#include "stdafx.h"
#include "Transform.h"
#include "Dlg_SCALE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_SCALE dialog


Dlg_SCALE::Dlg_SCALE(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_SCALE::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_SCALE)
	m_Sx = 0.0;
	m_Sy = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_SCALE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_SCALE)
	DDX_Text(pDX, IDC_EDIT1, m_Sx);
	DDX_Text(pDX, IDC_EDIT2, m_Sy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_SCALE, CDialog)
	//{{AFX_MSG_MAP(Dlg_SCALE)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_SCALE message handlers
