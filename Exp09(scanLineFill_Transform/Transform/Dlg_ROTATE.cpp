// Dlg_ROTATE.cpp : implementation file
//

#include "stdafx.h"
#include "Transform.h"
#include "Dlg_ROTATE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_ROTATE dialog


Dlg_ROTATE::Dlg_ROTATE(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_ROTATE::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_ROTATE)
	m_RotateAngle = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_ROTATE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_ROTATE)
	DDX_Text(pDX, IDC_EDIT1, m_RotateAngle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_ROTATE, CDialog)
	//{{AFX_MSG_MAP(Dlg_ROTATE)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_ROTATE message handlers
