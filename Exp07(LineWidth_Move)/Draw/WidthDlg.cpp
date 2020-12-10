// WidthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Draw.h"
#include "WidthDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWidthDlg dialog


CWidthDlg::CWidthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWidthDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWidthDlg)
	m_widthDlg = 0;
	//}}AFX_DATA_INIT
}


void CWidthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWidthDlg)
	DDX_Text(pDX, IDC_EDIT1, m_widthDlg);
	DDV_MinMaxUInt(pDX, m_widthDlg, 1, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWidthDlg, CDialog)
	//{{AFX_MSG_MAP(CWidthDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWidthDlg message handlers
