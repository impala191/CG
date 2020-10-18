// DIgColor.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "DIgColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIgColor dialog


CDIgColor::CDIgColor(CWnd* pParent /*=NULL*/)
	: CDialog(CDIgColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIgColor)
	m_DlgRed = 0;
	m_DlgGreen = 0;
	m_DlgBlue = 0;
	//}}AFX_DATA_INIT
}


void CDIgColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIgColor)
	DDX_Text(pDX, IDC_EDIT1, m_DlgRed);
	DDV_MinMaxInt(pDX, m_DlgRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_DlgGreen);
	DDV_MinMaxInt(pDX, m_DlgGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_DlgBlue);
	DDV_MinMaxInt(pDX, m_DlgBlue, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIgColor, CDialog)
	//{{AFX_MSG_MAP(CDIgColor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIgColor message handlers
