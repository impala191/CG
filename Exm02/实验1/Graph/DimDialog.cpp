// DimDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "DimDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DimDialog dialog


DimDialog::DimDialog(CWnd* pParent /*=NULL*/)
	: CDialog(DimDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(DimDialog)
	m_n = 0.0;
	m_r = 0.0;
	//}}AFX_DATA_INIT
}


void DimDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DimDialog)
	DDX_Text(pDX, IDC_EDIT1, m_n);
	DDX_Text(pDX, IDC_EDIT2, m_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DimDialog, CDialog)
	//{{AFX_MSG_MAP(DimDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DimDialog message handlers
